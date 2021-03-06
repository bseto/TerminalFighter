#pragma once
#include <SDL2/SDL.h>

#include "GameState/I_GameState.h"

#include "Keyboard/KeyboardListener.h"
#include "Keyboard/Keyboard.h"
#include "Events/Events.h"
#include "Delay/Delay.h"

#include "MissileLauncher/MissileLauncher.h"
#include "Settings/I_Settings.h"

class Delay;
struct SDL_Renderer;

class TestState : public I_GameState, public KeyboardListener, public EventsListener {
public:
    TestState(SDL_Renderer& renderer, const I_Settings& settings);
    gamestates::GameStateName run();
    gamestates::GameStateName name() const;

    /* listeners */
    void handle_key_press(const std::string& keypress);
    void notify_events(const SDL_Event& e);

private:
    void display_debug_frames_(Delay* delayer);
    bool exit_;

    SDL_Renderer& renderer_;
    const I_Settings& settings_;
};
