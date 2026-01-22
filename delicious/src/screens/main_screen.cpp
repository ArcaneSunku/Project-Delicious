#include "screens.h"

#include "../ui/main_menu.h"

namespace screens
{

	void MainScreen::Init()
	{
		GuiLoadStyle("ui/dark/style_dark.txt.rgs");

		m_MainMenu = std::make_unique<gui::MainMenu>();
		m_MainMenu->Init();
	}

	void MainScreen::Dispose()
	{
		m_MainMenu->Dispose();
	}

	void MainScreen::Update(float dt)
	{
		m_MainMenu->OnUpdate(dt);

		if (((gui::MainMenu*)m_MainMenu.get())->PressedExit())
			screen_manager->Close();

		if (((gui::MainMenu*)m_MainMenu.get())->PressedPlay())
			screen_manager->SetScreen(new GameScreen());
	}

	void MainScreen::RenderUI()
	{
		m_MainMenu->OnRender();
	}

}