#include "init.h"

#include <asw/asw.h>

void InitState::init()
{
    // Pass
}

void InitState::draw()
{
    // Pass
}

void InitState::cleanup()
{
    // Pass
}

void InitState::update()
{
    this->setNextState(ProgramState::Intro);
}