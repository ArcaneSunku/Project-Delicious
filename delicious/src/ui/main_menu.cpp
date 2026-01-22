#include "main_menu.h"

namespace gui
{
	void MainMenu::Init()
	{
		m_Title = "Delicious Adventure";
		m_TitleSize = (int)(64.0f * 1.5f);
		m_TitleWidth = MeasureText(m_Title, m_TitleSize);

		m_ButtonSize = { 120.0f, 30.0f };
		m_PlayButtonY = GetScreenHeight() / 2.5f + m_TitleSize + (m_ButtonSize.y * 1.5f);
		m_Play = m_Exit = false;
	}

	void MainMenu::Dispose() 
	{
		m_Play = m_Exit = false;
	}

	void MainMenu::OnUpdate(float dt) 
	{
		// TODO: Add any GUI animations here
	}

	void MainMenu::OnRender()
	{
		m_Play = GuiButton({ (GetScreenWidth() - m_ButtonSize.x) / 2.0f, m_PlayButtonY, m_ButtonSize.x, m_ButtonSize.y }, "Play");
		m_Exit = GuiButton({ (GetScreenWidth() - m_ButtonSize.x) / 2.0f, m_PlayButtonY + m_ButtonSize.y + (m_ButtonSize.y / 2.0f), m_ButtonSize.x, m_ButtonSize.y }, "Exit");
		
		DrawText(m_Title, (int)((GetScreenWidth() - m_TitleWidth) / 2.0f), (int)(GetScreenHeight() / 2.5f), m_TitleSize, WHITE);
	}

	void MainMenu::OnAdd()   
	{
		
	}

	void MainMenu::OnRemove()
	{
		
	}
}