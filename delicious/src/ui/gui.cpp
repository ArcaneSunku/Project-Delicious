#include "gui.h"

namespace gui
{
	void GUI::UpdateChildren()
	{
		for (auto it = m_Children.begin(); it != m_Children.end();)
		{
			std::unique_ptr<GUI>& child = it->second;
			if (child->m_Removed)
			{
				it = m_Children.erase(it);
				continue;
			}

			child->OnUpdate();
			++it;
		}
	}

	void GUI::RenderChildren()
	{
		for (auto& [id, child] : m_Children)
			child->OnRender();
	}

	void GUI::AddChild(std::unique_ptr<GUI> child)
	{
		m_Children.emplace(child->GetID(), child);

		child->OnAdd();
		m_ChildCount++;
	}

	void GUI::RemoveChild(const char* id)
	{
		std::unique_ptr<GUI>& child = m_Children.at(id);
		m_Children.erase(child->GetID());

		child->OnRemove();
		m_ChildCount--;
	}
}