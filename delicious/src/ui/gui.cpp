#include "gui.h"

namespace gui
{
	void GUI::UpdateChildren(float dt)
	{
		for (auto it = m_Children.begin(); it != m_Children.end();)
		{
			std::unique_ptr<GUI>& child = it->second;
			if (child->m_Removed)
			{
				it = m_Children.erase(it);
				continue;
			}

			child->OnUpdate(dt);
			++it;
		}
	}

	void GUI::RenderChildren()
	{
		for (auto it = m_Children.begin(); it != m_Children.end();)
		{
			std::unique_ptr<GUI>& child = it->second;
			if (child->m_Removed)
			{
				it = m_Children.erase(it);
				continue;
			}

			child->OnRender();
			++it;
		}
	}

	void GUI::AddChild(std::unique_ptr<GUI> child)
	{
		auto id = child->GetID();
		auto& inserted = m_Children.emplace(id, std::move(child)).first->second;

		inserted->OnAdd();
		m_ChildCount++;
	}

	void GUI::RemoveChild(std::string id)
	{
		auto it = m_Children.find(id);
		if (it == m_Children.end()) return;

		it->second->OnRemove();
		m_Children.erase(it);

		m_ChildCount--;
	}
}