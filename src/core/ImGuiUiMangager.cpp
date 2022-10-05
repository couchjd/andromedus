#include "ImGuiUiManager.h"

ImGuiUIManager::ImGuiUIManager(sf::RenderWindow* window)
{
	ImGui::SFML::Init(*window);
	m_render_window = window;
}

ImGuiUIManager::~ImGuiUIManager()
{
}

void 
ImGuiUIManager::processEvent(const sf::Event& event)
{
	ImGui::SFML::ProcessEvent(event);
}

void 
ImGuiUIManager::update(sf::Time dt)
{
	ImGui::SFML::Update(*m_render_window, dt);
	updateWindows();
}

void ImGuiUIManager::render()
{
	ImGui::SFML::Render(*m_render_window);
}

void ImGuiUIManager::shutdown()
{
	ImGui::SFML::Shutdown();
}

void ImGuiUIManager::updateWindows()
{
	for (auto i = 0; i < m_windows.size(); i++)
	{
		m_windows[i]->update();
	}
}

void 
ImGuiUIManager::deleteWindows()
{
	for (auto& window : m_windows)
	{
		delete(window);
	}
}

void 
ImGuiUIManager::addWindow(GuiBaseWindow* new_window)
{
	m_windows.push_back(new_window);
}

ImGuiEventHandler* 
ImGuiUIManager::getEventHandler()
{
	return &m_event_handler;
}
