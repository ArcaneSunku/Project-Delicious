#include "screens.h"

#include <ostream>

#include "raygui.h"

#ifndef TRANS_GRAY
	#define TRANS_GRAY CLITERAL(Color){ 35, 35, 35, 175 } 
#endif

namespace screens
{

	Texture wabbit; // Very temporary - REMOVE WHEN DONE

	bool paused, return_main_menu;

	void GameScreen::Init()
	{
		wabbit = LoadTexture("textures/wabbit_alpha.png");


		btn_width = 120.0f;
		btn_height = 30.0f;

		paused = return_main_menu = false;
	}

	void GameScreen::Dispose()
	{
		UnloadTexture(wabbit);
	}

	void GameScreen::Update(float dt)
	{
		if (IsKeyPressed(KEY_ESCAPE))
			paused = !paused;

		if(return_main_menu)
			screen_manager->SetScreen(new MainScreen());
	}

	void GameScreen::Render()
	{
		DrawRectangle((GetScreenWidth() - wabbit.width) / 2, (GetScreenHeight() - wabbit.height) / 2, wabbit.width, wabbit.height, GOLD);

		if (paused)
		{
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), TRANS_GRAY);

			paused = !GuiButton({ (GetScreenWidth() - btn_width) / 2.0f, (GetScreenHeight() - btn_width) / 2.0f, btn_width, btn_height }, "Resume");
			return_main_menu = GuiButton({ (GetScreenWidth() - btn_width) / 2.0f, (GetScreenHeight() - btn_width) / 2.0f + btn_height + (btn_height / 2.0f), btn_width, btn_height }, "Main Menu");
		}
	}

}