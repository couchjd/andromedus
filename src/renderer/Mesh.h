#pragma once

#include "Shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <vector>

#define MAX_BONE_INFLUENCE 4

struct Vertex
{
   glm::vec3 position;
   glm::vec3 normal;
   glm::vec2 tex_coords;
   glm::vec3 tangent;
   glm::vec3 bitangent;

   int m_bone_ids[MAX_BONE_INFLUENCE];
   float m_weights[MAX_BONE_INFLUENCE];
};

struct Texture
{
   unsigned int id;
   std::string type;
   std::string path;
};

class Mesh
{
public:
   std::vector<Vertex> m_vertices;
   std::vector<unsigned int> m_indices;
   std::vector<Texture> m_textures;
   unsigned int VAO;

   Mesh(
      std::vector<Vertex> vertices,
      std::vector<unsigned int> indices,
      std::vector<Texture> textures);

   void Draw(Shader& shader);

private:
   void setupMesh();

   unsigned int VBO;
   unsigned int EBO;
};
