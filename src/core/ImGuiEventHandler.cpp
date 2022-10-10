#include "ImGuiEventHandler.h"
#include "imgui-sfml/imgui-SFML.h"
#include "imgui/imgui.h"
void 
ImGuiEventHandler::handleEvent(sf::Event& event)
{
	ImGui::SFML::ProcessEvent(event);
}
