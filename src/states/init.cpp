#include "init.h"

#include <asw/asw.h>

void InitState::update(float dt)
{
    Scene::update(dt);

    sceneManager.setNextScene(States::Intro);
}