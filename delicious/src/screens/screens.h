#pragma once

#include <memory>

#include "raylib.h"

namespace screens
{
    struct Screen
    {
        virtual ~Screen() = default;

        virtual void Init() = 0;
        virtual void Dispose() = 0;
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
        virtual void RenderUI() {}

    };

    class ScreenManager
    {
    public:
        ScreenManager();
        ~ScreenManager();

        void Update();
        void Render();
        void SetScreen(Screen* screen);

        inline void Close() { m_closing = true; }
        inline bool Closing() { return m_closing; }

    private:
        Screen* m_current = nullptr;
        bool m_closing = false;

    };

    class GameScreen : public Screen
    {
    public:
        void Init() override;
        void Dispose() override;
        void Update(float dt) override;
        void Render() override;

    private:
        float btn_width, btn_height;
    };

    class MainScreen : public Screen
    {
    public:
        void Init() override;
        void Dispose() override;
        void Update(float dt) override;
        void Render() override {}
        void RenderUI() override;

    private:
        float btn_width, btn_height;
    };
}

extern std::unique_ptr<screens::ScreenManager> screen_manager;