#include "screens.h"

#include "ui/in_game/pause_menu.h"

namespace screens
{

	Texture wabbit; // Very temporary - REMOVE WHEN DONE

	void GameScreen::Init()
	{
		wabbit = LoadTexture("textures/wabbit_alpha.png");


		m_PauseMenu = std::make_unique<gui::PauseMenu>();
		m_PauseMenu->Init();
	}

	void GameScreen::Dispose()
	{
		UnloadTexture(wabbit);
	}

	void GameScreen::Update(float dt)
	{
		if (IsKeyPressed(KEY_ESCAPE))
			m_PauseMenu->OnUpdate(dt);

		if(((gui::PauseMenu*)m_PauseMenu.get())->ReturnToMain())
			screen_manager->SetScreen(new MainScreen());
	}

	void GameScreen::Render()
	{
		DrawRectangle((GetScreenWidth() - wabbit.width) / 2, (GetScreenHeight() - wabbit.height) / 2, wabbit.width, wabbit.height, GOLD);

		if(((gui::PauseMenu*)m_PauseMenu.get())->IsPaused())
			m_PauseMenu->OnRender();
	}

}