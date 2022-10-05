#pragma once

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

class GuiBaseWindow
{
public:
	GuiBaseWindow();
	~GuiBaseWindow();

	virtual void update() = 0;
	void setWindowName(const std::string& window_name);
	bool getShowWindow();
	void setShowWindow(bool show_window);

protected:
	virtual bool begin(std::string name);
	void end();
	bool m_show;
	std::string m_window_name;

private:
	
};
