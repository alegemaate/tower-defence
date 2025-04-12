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

// Game states
enum class States
{
    Init,
    Intro,
    Game,
};