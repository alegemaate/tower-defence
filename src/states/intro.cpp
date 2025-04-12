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
    registry.emplace<Transform>(entity, asw::Vec2<float>(0, 0), asw::Vec2<float>(display_size.x, display_size.y));
    registry.emplace<Sprite>(entity, "assets/intro.png");
}

void IntroState::update(float dt)
{
    Scene::update(dt);

    if (timer.getElapsedTime<std::chrono::milliseconds>() >= INTRO_DURATION_MS)
    {
        sceneManager.setNextScene(States::Game);
    }
}

void IntroState::draw()
{
    asw::draw::clearColor(asw::util::makeColor(255, 0, 0, 255));

    SpriteRendererSystem::update(registry);
}
