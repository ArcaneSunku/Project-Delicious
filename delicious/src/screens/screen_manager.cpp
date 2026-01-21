#include "screens.h"

std::unique_ptr<screens::ScreenManager> screen_manager =
std::make_unique<screens::ScreenManager>();

namespace screens
{
    ScreenManager::ScreenManager() = default;

    ScreenManager::~ScreenManager()
    {
        if (m_current)
        {
            m_current->Dispose();
            delete m_current;
        }
    }

    void ScreenManager::Update()
    {
        if (m_current)
            m_current->Update(GetFrameTime());
    }

    void ScreenManager::Render()
    {
        BeginDrawing();
        ClearBackground(BLACK);

#ifdef _DEBUG
        // TODO: Remove on release (make a settings toggle)
        DrawFPS(0, 0);
#endif

        if (m_current)
        {
            m_current->Render();
            m_current->RenderUI();
        }

        EndDrawing();
    }

    void ScreenManager::SetScreen(Screen* screen)
    {
        if (m_current)
        {
            m_current->Dispose();
            delete m_current;
        }

        m_current = screen;
        if (m_current)
            m_current->Init();
    }
}