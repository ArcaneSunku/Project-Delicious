#include "screens.h"

#include "raygui.h"

namespace screens
{

	const char* title_text = "Delicious Adventure";
	constexpr int title_size = (int)(64.0f * 1.5f);
	int text_width;

	float play_y;
	bool play_game, exit_game;

	void MainScreen::Init()
	{
		GuiLoadStyle("ui/dark/style_dark.txt.rgs");
		text_width = MeasureText(title_text, title_size);

		btn_width = 120.0f;
		btn_height = 30.0f;
		play_y = GetScreenHeight() / 2.5f + title_size + (btn_height * 1.5f);
		play_game = exit_game = false;
	}

	void MainScreen::Dispose()
	{
		play_game = exit_game = false;
	}

	void MainScreen::Update(float dt)
	{
		if (exit_game)
			screen_manager->Close();

		if (play_game)
			screen_manager->SetScreen(new GameScreen());
	}

	void MainScreen::RenderUI()
	{
		play_game = GuiButton({ (GetScreenWidth() - btn_width) / 2.0f, play_y, btn_width, btn_height }, "Play");
		exit_game = GuiButton({ (GetScreenWidth() - btn_width) / 2.0f, play_y + btn_height + (btn_height / 2.0f), btn_width, btn_height }, "Exit");

		DrawText(title_text, (int) ((GetScreenWidth() - text_width) / 2.0f), (int)(GetScreenHeight() / 2.5f), title_size, WHITE);
	}

}