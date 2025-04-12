#include <asw/asw.h>

#include "./states/game.h"
#include "./states/init.h"
#include "./states/intro.h"
#include "state.h"

// Main function
auto main() -> int
{
    asw::core::init(1280, 960);

    auto app = asw::scene::SceneManager<States>();
    app.registerScene<InitState>(States::Init, app);
    app.registerScene<IntroState>(States::Intro, app);
    app.registerScene<GameState>(States::Game, app);
    app.setNextScene(States::Init);

    app.start();

    return 0;
}
