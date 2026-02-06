#pragma once

#include "ui/gui.h"

namespace gui
{
	class PauseMenu : public GUI
	{
	public:
		PauseMenu() : GUI("ui_pause_menu") {}
		virtual ~PauseMenu() override = default;

		virtual void Init() override;
		virtual void Dispose() override;

		virtual void OnUpdate(float dt) override;
		virtual void OnRender() override;

		virtual void OnAdd() override;
		virtual void OnRemove() override;

		inline bool IsPaused() { return m_Paused; }
		inline bool ReturnToMain() { return m_MainMenu; }

	private:
		Vector2 m_ButtonSize;
		bool m_Paused, m_MainMenu;

	};
}