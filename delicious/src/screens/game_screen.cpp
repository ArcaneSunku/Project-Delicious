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

		m_Camera = { 0 };
		m_Camera.target = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		m_Camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		m_Camera.rotation = 0.0f;
		m_Camera.zoom = 1.0f;
	}

	void GameScreen::Dispose()
	{
		UnloadTexture(wabbit);
		m_PauseMenu->Dispose();
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
		BeginMode2D(m_Camera);
		DrawRectangle((GetScreenWidth() - wabbit.width) / 2, (GetScreenHeight() - wabbit.height) / 2, wabbit.width, wabbit.height, GOLD);
		EndMode2D();

		if(((gui::PauseMenu*)m_PauseMenu.get())->IsPaused())
			m_PauseMenu->OnRender();
	}

}