#include "FileOpenWindow.h"
#include <SFML/Graphics.hpp>

#include <iostream>

FileOpenWindow::FileOpenWindow()
{
	m_window_name = "Open File";
	memset(m_file_name, 0, FILE_NAME_SIZE);
}

void 
FileOpenWindow::update()
{
	if (m_show)
	{
		if (begin(m_window_name))
		{
			ImGui::InputText("Filename", m_file_name, FILE_NAME_SIZE);
			if (ImGui::Button("Open"))
			{
				sf::Texture test_texture;
				test_texture.loadFromFile(m_file_name);
				std::cout << "Loaded: " << m_file_name << std::endl;
			}
		}
		end();
	}
}
