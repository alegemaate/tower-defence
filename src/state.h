/**
 * @file state.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief  Compartmentalize program into states which can handle only their own logic, drawing and transitions
 * @version 0.1
 * @date 2016-12-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <memory>

// Class
class State;

// Game states
enum class ProgramState
{
    Null,
    Init,
    Intro,
    Game,
    Exit,
};

/*****************
 * STATE ENGINE
 *****************/
class StateEngine
{
  public:
    // Init
    StateEngine() = default;

    // Update
    void update();

    // Draw
    void draw();

    // Set next state
    void setNextState(ProgramState state);

    // Get state id
    auto getStateId() const -> ProgramState;

  private:
    // Change state
    void changeState();

    // Next state
    ProgramState nextState{ProgramState::Null};

    // State id
    ProgramState currentState{ProgramState::Null};

    // Stores states
    std::unique_ptr<State> state{nullptr};
};

/*********
 * STATE
 *********/
class State
{
  public:
    // Constructor
    explicit State(StateEngine &engine) : engine(engine){};

    virtual ~State() = default;

    // Init the state
    virtual void init() = 0;

    // Draw to screen
    virtual void draw() = 0;

    // Cleanup
    virtual void cleanup() = 0;

    // Update logic
    virtual void update() = 0;

    // Change state
    void setNextState(ProgramState state);

  private:
    StateEngine &engine;
};
