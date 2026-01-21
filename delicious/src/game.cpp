#include "game.h"

Game::Game(const char* title, int width, int height) :
	m_title(title), m_width(width), m_height(height)
{
	m_running = false;
}

void Game::Start()
{
	if (m_running) return;

	m_running = true;
	Loop();
}

void Game::Init()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(60);

	InitWindow(m_width, m_height, m_title.c_str());
	SearchAndSetResourceDir("assets");
	SetExitKey(KEY_NULL);

	InitAudioDevice();

	screen_manager->SetScreen(new screens::MainScreen());
}

void Game::Loop()
{
	Init();

	while (m_running)
	{
		if (WindowShouldClose() || screen_manager->Closing())
		{
			m_running = false;
			continue;
		}

		screen_manager->Update();
		screen_manager->Render();
	}

	Dispose();
}

void Game::Dispose()
{
	CloseAudioDevice();
	CloseWindow();
}
