#pragma once
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <array>
#include "color.h"
#include "uniform.h"

struct Face {
    std::vector<int> vertexIndices;

    Face(): vertexIndices(){};
    Face(std::vector<int> temp_vertex): vertexIndices(temp_vertex){};
};



// En vertexGML.h, cambia la definición de la estructura VertexGML
struct VertexGML {
    glm::vec3 position;
    Color color;
    glm::vec3 normal;
    glm::vec3 texture;
};

struct Facer {
    std::vector<VertexGML> vertexIndices;
    Facer(): vertexIndices(){};
    Facer(std::vector<VertexGML> temp_vertex): vertexIndices(temp_vertex){};
};

struct Fragment {
  glm::vec3 position;
  Color color;
};


// Función para imprimir un vértice (puede ser de tamaño 2, 3 o 4)
void printVertex(const glm::vec4& vertex);

// Función para modificar el punto en el framebuffer
inline void point(const glm::vec3& vector);

void line(const glm::vec3& start, const glm::vec3& end);

void triangle(const glm::vec3& A, const glm::vec3& B, const glm::vec3& C);

void triangulateAndDrawCube(const std::vector<VertexGML>& vertices, const std::vector<Face>& faces);

void triangulateAndDrawCube(const std::vector<glm::vec3>& vertices, const std::vector<Face>& faces, float rotationAngleX, float rotationAngleY);
std::vector<Fragment> triangle_F(VertexGML a, VertexGML b, VertexGML c);
VertexGML vertexShader(const VertexGML& vertex, const Uniform& u);
Fragment fragmentShader(Fragment fragment);
void triangulateAndDrawCube(const std::vector<VertexGML>& vertices, const std::vector<Face>& faces, SDL_Renderer* renderer);
void triangulateAndDrawCube(std::vector<Facer> Faces, SDL_Renderer* renderer);


