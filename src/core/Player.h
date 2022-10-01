#pragma once

#include "Character.h"

class Player : public Character
{
public:
   void update(const sf::Event& event) override;

private:

};