#include "state.h"

#include <asw/asw.h>

#include <iostream>

#include "./states/game.h"
#include "./states/init.h"
#include "./states/intro.h"

/**
 * STATE ENGINE
 */

// Draw
void StateEngine::draw()
{
    if (state)
    {
        // Clear screen
        SDL_RenderClear(asw::display::renderer);

        state->draw();

        // Update screen
        SDL_RenderPresent(asw::display::renderer);
    }
}

// Update
void StateEngine::update()
{
    // Update core
    asw::core::update();

    if (state)
    {
        state->update();
    }

    changeState();

    // Handle exit
    if (getStateId() == ProgramState::Exit)
    {
        asw::core::exit = true;
    }
}

// Set next state
void StateEngine::setNextState(const ProgramState newState)
{
    nextState = newState;
}

// Get state id
auto StateEngine::getStateId() const -> ProgramState
{
    return currentState;
}

// Change game screen
void StateEngine::changeState()
{
    // If the state needs to be changed
    if (nextState == ProgramState::Null)
    {
        return;
    }

    // Delete the current state
    if (state)
    {
        state->cleanup();
        state = nullptr;
    }

    // Change the state
    if (nextState == ProgramState::Init)
    {
        state = std::make_unique<InitState>(*this);
        std::cout << "Switched state to init." << std::endl;
    }
    else if (nextState == ProgramState::Intro)
    {
        state = std::make_unique<IntroState>(*this);
        std::cout << "Switched state to intro." << std::endl;
    }
    else if (nextState == ProgramState::Game)
    {
        state = std::make_unique<GameState>(*this);
        std::cout << "Switched state to game." << std::endl;
    }
    else if (nextState == ProgramState::Exit)
    {
        std::cout << "Switched state to exit." << std::endl;
    }
    else
    {
        std::cout << "State not found." << std::endl;
    }

    state->init();

    // Change the current state ID
    currentState = nextState;

    // NULL the next state ID
    nextState = ProgramState::Null;
}

/**
 * STATE
 */

// Change state
void State::setNextState(const ProgramState state)
{
    this->engine.setNextState(state);
}
