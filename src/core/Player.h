#pragma once

#include "Character.h"

class Player : public Character
{
public:
   Player();

   void update(const sf::Event& event) override;

   sf::Shader& getShader();

private:
   sf::Shader m_shader;
};