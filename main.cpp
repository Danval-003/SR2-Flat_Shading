#include <SDL2/SDL.h>
#include <glm/geometric.hpp>
#include <iostream>
#include <glm/glm.hpp>
#include <ostream>
#include <vector>
#include "color.h"
#include "framebuffer.h"
#include "render.h"
#include "vertexGML.h"
#include "objSettings.h"
#include "uniform.h"
#include <random>


using namespace std;

// Dimensiones de la ventana
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;



void init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Software Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Uniform uniform;

std::vector<VertexGML> vertices_out;

    // Definir las caras del cubo
std::vector<Face> faces_out;
std::vector<Face> out_faces;
std::vector<VertexGML> out_vertices;
std::vector<VertexGML> normal_vertices;
std::vector<VertexGML> texture_vertices;
std::vector<Face> normal_faces;
std::vector<Face> textureFaces;

void render(SDL_Renderer* renderer) {
    faces_out.clear();
    vertices_out.clear();
    normal_vertices.clear();
    normal_faces.clear();
    textureFaces.clear();
    texture_vertices.clear();

    if(!loadOBJ("../navecita.obj", out_vertices, out_faces, normal_faces, normal_vertices, textureFaces, texture_vertices)){

        cout<<"No funciono"<<endl;
    }

    triangulateFaces(out_faces, out_vertices, vertices_out, faces_out);
    out_vertices.clear();
    out_faces.clear();
    out_vertices = normal_vertices;
    out_faces = normal_faces;

    normal_vertices.clear();
    normal_faces.clear();
    triangulateFaces(out_faces, out_vertices, normal_vertices, normal_faces);
    out_vertices.clear();
    out_faces.clear();
    out_vertices = texture_vertices;
    out_faces = textureFaces;

    textureFaces.clear();
    texture_vertices.clear();
    triangulateFaces(out_faces, out_vertices, texture_vertices, textureFaces);
    out_vertices.clear();
    out_faces.clear();

    std::vector<Facer> simplyAsemble;

    for (const auto& vertex : vertices_out) {
        //cout<<"Vector Antes "<<vertex.position.x<< endl;
        VertexGML transformedVertex = vertexShader(vertex, uniform);
        //cout<<"Vector "<<transformedVertex.position.x<< endl;
        out_vertices.emplace_back(transformedVertex);
    }

    for (auto& vertex: normal_vertices) {
        vertex.position = glm::normalize(glm::mat3(uniform.model) * vertex.position);
    }

    if( normal_faces.size() == faces_out.size()){
        for (int i = 0; i<normal_faces.size(); i++) {
            Facer simply;

            VertexGML A = {out_vertices[faces_out[i].vertexIndices[0] - 1].position, out_vertices[faces_out[i].vertexIndices[0] - 1].color, normal_vertices[normal_faces[i].vertexIndices[0] - 1].position};
            VertexGML B = {out_vertices[faces_out[i].vertexIndices[1] - 1].position, out_vertices[faces_out[i].vertexIndices[1] - 1].color, normal_vertices[normal_faces[i].vertexIndices[1] - 1].position};
            VertexGML C = {out_vertices[faces_out[i].vertexIndices[2] - 1].position, out_vertices[faces_out[i].vertexIndices[2] - 1].color, normal_vertices[normal_faces[i].vertexIndices[2] - 1].position};

            simply.vertexIndices.push_back(A);
            simply.vertexIndices.push_back(B);
            simply.vertexIndices.push_back(C);
            simplyAsemble.push_back(simply);
        }
    }

    // Dibujar el cubo triangulando las caras
    triangulateAndDrawCube(simplyAsemble, renderer);
    out_vertices.clear();
    faces_out.clear();

    // Render the framebuffer to the screen
    //renderBuffer(renderer);

}





int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Cube", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    bool running = true;
    SDL_Event event;
        // Clear the framebuffer




    while (running) {
        while (SDL_PollEvent(&event)) {
                if( event.type == SDL_QUIT){
                   running = false;
                }
        }
        configureUniform(&uniform);

        clear(renderer);

        // Call our render function
        render(renderer);

        // Present the frame buffer to the screen
        SDL_RenderPresent(renderer);

        // Delay to limit the frame rate
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
