#pragma once

#include <raygui.h>

#include <string>
#include <memory>
#include <map>

namespace gui
{
	class GUI
	{
	public:
		GUI() : m_Removed(false), m_ChildCount(0) { m_ID = "ui_test"; }
		GUI(const char* id) : m_ID(id), m_Removed(false), m_ChildCount(0) {}

		virtual ~GUI() { Dispose(); }

		virtual void Init() = 0;
		virtual void Dispose() = 0;

		virtual void OnUpdate() {}
		virtual void OnRender() = 0;

		virtual void OnAdd() {}
		virtual void OnRemove() {}

		void UpdateChildren();
		void RenderChildren();

		void AddChild(std::unique_ptr<GUI> child);
		void RemoveChild(const char* id);

		inline const char* GetID() { return m_ID; }
		inline std::string GetID() const { return static_cast<std::string>(m_ID); }

		inline unsigned int GetChildCount() { return m_ChildCount; }

	protected:
		const char* m_ID;
		bool m_Removed;

		std::map<const char*, std::unique_ptr<GUI>> m_Children;
		unsigned int m_ChildCount;
	};
}