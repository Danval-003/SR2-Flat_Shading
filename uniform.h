#pragma once
#include <glm/glm.hpp>

extern float a;

struct Uniform {
  glm::mat4 model;
  glm::mat4 view;
  glm::mat4 projection;
  glm::mat4 viewport;
};

glm::mat4 createModelMatrix();

glm::mat4 createViewMatrix();

glm::mat4 createProjectionMatrix();

glm::mat4 createViewportMatrix();

void configureUniform(Uniform* u);
