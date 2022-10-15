#include "FileOpenWindow.h"

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
				std::cout << "Open Button Pressed\n";
			}
		}
		end();
	}
}
