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

		virtual ~GUI() = default;

		virtual void Init() = 0;
		virtual void Dispose() = 0;

		virtual void OnUpdate(float dt) {}
		virtual void OnRender() = 0;

		virtual void OnAdd() {}
		virtual void OnRemove() {}

		void UpdateChildren(float dt);
		void RenderChildren();

		void AddChild(std::unique_ptr<GUI> child);
		void RemoveChild(std::string id);

		inline const char* GetID() { return m_ID.c_str(); }
		inline std::string GetID() const { return m_ID; }

		inline unsigned int GetChildCount() { return m_ChildCount; }

	protected:
		std::string m_ID;
		bool m_Removed;

		std::map<std::string, std::unique_ptr<GUI>> m_Children;
		unsigned int m_ChildCount;
	};
}