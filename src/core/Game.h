#pragma once

#include "imgui/imgui.h"

#include <Window.h>

#include <queue>
class Game
{
public:
   Game();
   void init();
   void run();
   void shutdown();

   void handleEvents();
   void update();
   void render();

private:
   Window* m_test_window;
};