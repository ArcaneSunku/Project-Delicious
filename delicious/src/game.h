#pragma once

#include <string>

#include "screens/screens.h"
#include "resource_dir.h"

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game() {}

	void Start();

private:
	void Init();
	void Loop();
	void Dispose();

private:
	std::string m_title;
	int m_width, m_height;
	bool m_running;
};

