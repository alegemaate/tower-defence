#include "intro.h"

#include <asw/asw.h>
#include <chrono>

#include "../game/components/sprite.h"
#include "../game/components/transform.h"
#include "../game/systems/sprite_renderer.h"

constexpr double INTRO_DURATION_MS = 500;

void IntroState::init()
{
    timer.start();

    // Create into entity
    auto entity = registry.create();

    // Add transform component
    auto display_size = asw::display::getSize();
    registry.emplace<Transform>(entity, Vec2<double>(0, 0), Vec2<double>(display_size.x, display_size.y));
    registry.emplace<Sprite>(entity, "assets/intro.png");
}

void IntroState::update()
{
    if (timer.getElapsedTime<std::chrono::milliseconds>() >= INTRO_DURATION_MS)
    {
        this->setNextState(ProgramState::Game);
    }
}

void IntroState::draw()
{
    asw::draw::clearColor(asw::util::makeColor(255, 0, 0, 255));

    SpriteRendererSystem::update(registry);
}

void IntroState::cleanup()
{
    // Pass
}