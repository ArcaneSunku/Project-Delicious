#pragma once

#include "gui.h"

namespace gui
{

	class MainMenu : public GUI
	{
	public:
		MainMenu() : GUI("ui_main_menu") {}
		virtual ~MainMenu() override = default;

		virtual void Init() override;
		virtual void Dispose() override;

		virtual void OnUpdate(float dt) override;
		virtual void OnRender() override;

		virtual void OnAdd() override;
		virtual void OnRemove() override;

		inline bool PressedPlay() { return m_Play; }
		inline bool PressedExit() { return m_Exit; }

	private:
		Vector2 m_TitlePos;
		int m_TitleSize, m_TitleWidth;

		float m_PlayButtonY;
		Vector2 m_ButtonSize;

		const char* m_Title;
		bool m_Play, m_Exit;
	};

}