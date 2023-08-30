#include "framebuffer.h"
#include "vertexGML.h"
#include "uniform.h"
#include "print.h"
#include <iostream>

glm::vec3 L = glm::vec3(0, 0, 1.0f);

// Función para imprimir un vértice (puede ser de tamaño 2, 3 o 4)
void printVertex(const glm::vec4& vertex) {
    std::cout << "Vertex: (" << vertex.x << ", " << vertex.y;
    if (vertex.length() > 2) {
        std::cout << ", " << vertex.z;
    }
    if (vertex.length() > 3) {
        std::cout << ", " << vertex.w;
    }
    std::cout << ")" << std::endl;
}


// Función para modificar el punto en el framebuffer
inline void point(const glm::vec3& vector) {
    int x = static_cast<int>(vector.x);
    int y = static_cast<int>(vector.y);

    if (x >= 0 && x < pantallaAncho && y >= 0 && y < pantallaAlto) {
        // Modificamos el punto en el framebuffer
        framebuffer[y * pantallaAncho + x] = currentColor;
    }
}


// En vertexGML.cpp, modifica la función line() para que tome en cuenta las coordenadas z de los vértices
void line(const glm::vec3& start, const glm::vec3& end) {
    const int multiply = 3;
    int x1 = round(start.x * multiply), y1 = round(start.y * multiply);
    int x2 = round(end.x * multiply), y2 = round(end.y * multiply);
    float z1 = start.z * multiply, z2 = end.z *multiply;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        float z = ((dx - abs(err)) * z1 + abs(err) * z2) / dx;
        point(glm::vec3(x1, y1, z));

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


#include <glm/gtc/matrix_transform.hpp>

glm::vec3 barycentricCoordinates(const glm::vec3& P, const glm::vec3& A, const glm::vec3& B, const glm::vec3& C) {
    float w = ((B.y - C.y)*(P.x - C.x) + (C.x - B.x)*(P.y - C.y)) /
              ((B.y - C.y)*(A.x - C.x) + (C.x - B.x)*(A.y - C.y));

    float v = ((C.y - A.y)*(P.x - C.x) + (A.x - C.x)*(P.y - C.y)) /
              ((B.y - C.y)*(A.x - C.x) + (C.x - B.x)*(A.y - C.y));

    float u = 1.0f - w - v;

    return glm::vec3(w, v, u);
}


std::vector<Fragment> triangle_F(VertexGML a, VertexGML b, VertexGML c) {
    glm::vec3 A = a.position;
    glm::vec3 B = b.position;
    glm::vec3 C = c.position;

    std::vector<Fragment> triangleFragments;


    // build bounding box

    int minX = std::min(std::min(A.x, B.x), C.x);
    int minY = std::min(std::min(A.y, B.y), C.y);
    int maxX = std::max(std::max(A.x, B.x), C.x);
    int maxY = std::max(std::max(A.y, B.y), C.y);

    for (int y = minY; y <= maxY; y++) {
      for (int x = minX; x <= maxX; x++) {
        if (x<0 && x>pantallaAncho && y<0 && y>pantallaAlto) {
            continue;
        }
        glm::vec3 P = glm::vec3(x, y, 0);

        glm::vec3 bar = barycentricCoordinates(P, A, B, C);

        if (
          bar.x <= 1 && bar.x >= 0 &&
          bar.y <= 1 && bar.y >= 0 &&
          bar.z <= 1 && bar.z >= 0
        ) {
          glm::vec3 normal = a.normal * bar.x + b.normal * bar.y + c.normal * bar.z;
          Color color = a.color * bar.x + b.color * bar.y + c.color * bar.z;

          P.z = a.position.z * bar.x + b.position.z * bar.y + c.position.z * bar.z;

          float intensity = glm::dot(normal, L);
          if (intensity< 0) {
              continue;
            }

          triangleFragments.push_back(
            Fragment{P, color * intensity}
          );
        }
      }
    }

    return triangleFragments;
}



VertexGML vertexShader(const VertexGML& vertex, const Uniform& u) {

  glm::vec4 v = glm::vec4(vertex.position.x, vertex.position.y, vertex.position.z, 1);

  glm::vec4 r = u.viewport * u.projection * u.view * u.model * v;

  return VertexGML{
    glm::vec3( r.x/r.w , r.y/r.w, r.z/r.w),
    vertex.color
  };
};

Fragment fragmentShader(Fragment fragment) {
  return fragment;
};




void triangle(const glm::vec3& A, const glm::vec3& B, const glm::vec3& C) {
    line(A, B);
    line(B, C);
    line(C, A);
}



void triangulateAndDrawCube(const std::vector<VertexGML>& vertices, const std::vector<Face>& faces) {
    std::vector<Fragment> fragments;
    for (const auto& face : faces) {
        if (face.vertexIndices.size() >= 3) {
            // Tomamos los tres primeros vértices de cada cara para triangularla
            VertexGML A = vertices[face.vertexIndices[0] - 1];
            VertexGML B = vertices[face.vertexIndices[1] - 1];
            VertexGML C = vertices[face.vertexIndices[2] - 1];

            // Triangular la cara utilizando los vértices A, B y C
            std::vector<Fragment> rasterizedTriangle = triangle_F(
                A,
                B,
                C);

            fragments.insert(
                fragments.end(),
                rasterizedTriangle.begin(),
                rasterizedTriangle.end()
            );

        }
    }

    for (Fragment fragment : fragments) {
        if (fragment.position.z < zbuffer[fragment.position.y * pantallaAncho + fragment.position.x]) {
            setCurrentColor(fragment.color);
            point(fragment.position);
            zbuffer[fragment.position.y * pantallaAncho + fragment.position.x] = fragment.position.z;
        }
    }
}

void triangulateAndDrawCube(const std::vector<VertexGML>& vertices, const std::vector<Face>& faces, SDL_Renderer* renderer) {
    std::vector<Fragment> fragments;
    for (const auto& face : faces) {
        if (face.vertexIndices.size() >= 3) {
            // Tomamos los tres primeros vértices de cada cara para triangularla
            VertexGML A = vertices[face.vertexIndices[0] - 1];
            VertexGML B = vertices[face.vertexIndices[1] - 1];
            VertexGML C = vertices[face.vertexIndices[2] - 1];

            // Triangular la cara utilizando los vértices A, B y C
            std::vector<Fragment> rasterizedTriangle = triangle_F(
                A,
                B,
                C);

            fragments.insert(
                fragments.end(),
                rasterizedTriangle.begin(),
                rasterizedTriangle.end()
            );

        }
    }

    for (Fragment fragment : fragments) {
        if (fragment.position.z < zbuffer[fragment.position.y * pantallaAncho + fragment.position.x]) {
            SDL_SetRenderDrawColor(renderer, fragment.color.r, fragment.color.g, fragment.color.b, fragment.color.a);
            SDL_RenderDrawPoint(renderer, fragment.position.x, fragment.position.y);
            zbuffer[fragment.position.y * pantallaAncho + fragment.position.x] = fragment.position.z;
        }
    }
}


void triangulateAndDrawCube(std::vector<Facer> Faces, SDL_Renderer* renderer) {
    std::vector<Fragment> fragments;
    for (const auto& face : Faces) {
        if (face.vertexIndices.size() >= 3) {

            // Triangular la cara utilizando los vértices A, B y C
            std::vector<Fragment> rasterizedTriangle = triangle_F(
                face.vertexIndices[0],
                face.vertexIndices[1],
                face.vertexIndices[2]);

            fragments.insert(
                fragments.end(),
                rasterizedTriangle.begin(),
                rasterizedTriangle.end()
            );

        }
    }

    for (Fragment fragment : fragments) {
        if (fragment.position.z < zbuffer[fragment.position.y * pantallaAncho + fragment.position.x]) {
            SDL_SetRenderDrawColor(renderer, fragment.color.r, fragment.color.g, fragment.color.b, fragment.color.a);
            SDL_RenderDrawPoint(renderer, fragment.position.x, fragment.position.y);
            zbuffer[fragment.position.y * pantallaAncho + fragment.position.x] = fragment.position.z;
        }
    }
}


void triangulateAndDrawCube(const std::vector<glm::vec3>& vertices, const std::vector<Face>& faces, float rotationAngleX, float rotationAngleY) {
    glm::mat4 rotationMatrixX = glm::rotate(glm::mat4(1.0f), glm::radians(rotationAngleX), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rotationMatrixY = glm::rotate(glm::mat4(1.0f), glm::radians(rotationAngleY), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 combinedRotationMatrix = rotationMatrixX * rotationMatrixY;

    for (const auto& face : faces) {
        if (face.vertexIndices.size() >= 3) {
            // Tomamos los tres primeros vértices de cada cara para triangularla
            const glm::vec3& A = vertices[face.vertexIndices[0] - 1];
            const glm::vec3& B = vertices[face.vertexIndices[1] - 1];
            const glm::vec3& C = vertices[face.vertexIndices[2] - 1];

            // Aplicar rotación a los vértices A, B y C
            glm::vec4 rotatedA = combinedRotationMatrix * glm::vec4(A, 1.0f);
            glm::vec4 rotatedB = combinedRotationMatrix * glm::vec4(B, 1.0f);
            glm::vec4 rotatedC = combinedRotationMatrix * glm::vec4(C, 1.0f);

            // Triangular la cara utilizando los vértices rotados
            triangle(glm::vec3(rotatedA), glm::vec3(rotatedB), glm::vec3(rotatedC));
        }
    }
}

