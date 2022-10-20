#pragma once

#include <string>
#include <iostream>

#ifdef _DEBUG
#  define DEBUG(x) std::cout << x << "\n";
#else
#  define DEBUG(x)
#endif

const std::string SPRITES_FOLDER_PATH = "../../assets/sprites";
const std::string RESOURCES_FOLDER_PATH = "../../resources";

#include <string>

const std::string sf_event_types[] =
{
   "Closed",
   "Resized",
   "LostFocus",
   "GainedFocus",
   "TextEntered",
   "KeyPressed",
   "KeyReleased",
   "MouseWheelMoved",
   "MouseWheelScrolled",
   "MouseButtonPressed",
   "MouseButtonReleased",
   "MouseMoved",
   "MouseEntered",
   "MouseLeft",
   "JoystickButtonPressed",
   "JoystickButtonReleased",
   "JoystickMoved",
   "JoystickConnected",
   "JoystickDisconnected",
   "TouchBegan",
   "TouchMoved",
   "TouchEnded",
   "SensorChanged"
};

