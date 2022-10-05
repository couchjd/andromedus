#pragma once

#include "GuiBaseWindow.h"

#define FILE_NAME_SIZE 256

class FileOpenWindow : public GuiBaseWindow
{
public:
	FileOpenWindow();
	void update() override;
private:
	char m_file_name[FILE_NAME_SIZE];
};