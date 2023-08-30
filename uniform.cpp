#include "uniform.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "framebuffer.h"


float a = 3.14f / 3.0f;

glm::mat4 createModelMatrix() {
    glm::mat4 transtation = glm::translate(glm::mat4(1), glm::vec3(0.0f, 0.0f, 0.0f));
    glm::mat4 scale = glm::scale(glm::mat4(a), glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 rotation = glm::rotate(glm::mat4(1), glm::radians(a++), glm::vec3(0.0f, 1.0f, 0.0f));

    return transtation * scale * rotation;
}

glm::mat4 createViewMatrix() {
    return glm::lookAt(
        // donde esta
        glm::vec3(0, 0, 5),
        // hacia adonde mira
        glm::vec3(0, 0, 0),
        // arriba
        glm::vec3(0, 1, 0)
    );
}

glm::mat4 createProjectionMatrix() {
  float fovInDegrees = 45.0f;
  float aspectRatio = static_cast<float>(pantallaAncho) / pantallaAlto;
  float nearClip = 0.1f;
  float farClip = 100.0f;

  return glm::perspective(glm::radians(fovInDegrees), aspectRatio, nearClip, farClip);
}

glm::mat4 createViewportMatrix() {
    glm::mat4 viewport = glm::mat4(1.0f);

    // Scale
    viewport = glm::scale(viewport, glm::vec3(pantallaAncho / 2.0f, pantallaAlto / 2.0f, 0.5f));

    // Translate
    viewport = glm::translate(viewport, glm::vec3(1.0f, 1.0f, 0.5f));

    return viewport;
}


void configureUniform(Uniform* u){
    u->model = createModelMatrix();
    u->view = createViewMatrix();
    u->projection = createProjectionMatrix();
    u->viewport = createViewportMatrix();
}
