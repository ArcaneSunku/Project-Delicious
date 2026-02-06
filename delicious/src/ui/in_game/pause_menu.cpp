#include "pause_menu.h"

#ifndef TRANS_GRAY
	#define TRANS_GRAY CLITERAL(Color){ 35, 35, 35, 175 } 
#endif

namespace gui
{
	void PauseMenu::Init()
	{
		m_ButtonSize = { 120.0f, 30.0f };
		m_Paused = m_MainMenu = false;
	}

	void PauseMenu::Dispose()
	{
		m_Paused = m_MainMenu = false;
	}

	void PauseMenu::OnUpdate(float dt)
	{
		m_Paused = !m_Paused;
	}

	void PauseMenu::OnRender()
	{
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), TRANS_GRAY);

		m_Paused = !GuiButton({ (GetScreenWidth() - m_ButtonSize.x) / 2.0f, (GetScreenHeight() - m_ButtonSize.y) / 2.0f, m_ButtonSize.x, m_ButtonSize.y }, "Resume");
		m_MainMenu = GuiButton({ (GetScreenWidth() - m_ButtonSize.x) / 2.0f, (GetScreenHeight() - m_ButtonSize.y) / 2.0f + m_ButtonSize.y + (m_ButtonSize.y / 2.0f), m_ButtonSize.x, m_ButtonSize.y }, "Main Menu");
	}

	void PauseMenu::OnAdd()
	{

	}

	void PauseMenu::OnRemove()
	{

	}

}