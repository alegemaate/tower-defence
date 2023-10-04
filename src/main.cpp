#include <asw/asw.h>

#include <chrono>
#include <memory>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

// For state engine
#include "state.h"

using namespace std::chrono_literals;
using namespace std::chrono;
constexpr nanoseconds timestep(16ms);

// Loop (emscripten compatibility)
#ifdef __EMSCRIPTEN__
void loop()
{
    update();
    draw();
}
#endif

// Main function
auto main() -> int
{
    // Setup basic functionality
    asw::core::init(1280, 960);

    // State engine
    auto state_engine = std::make_unique<StateEngine>();

    // Set the current state ID
    state_engine->setNextState(ProgramState::Init);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(loop, 0, 1);
#else

    // Fix timestep
    nanoseconds lag(0ns);
    auto time_start = high_resolution_clock::now();

    while (!asw::input::isKeyDown(asw::input::Key::ESCAPE) && !asw::core::exit)
    {
        auto delta_time = high_resolution_clock::now() - time_start;
        time_start = high_resolution_clock::now();
        lag += duration_cast<nanoseconds>(delta_time);

        while (lag >= timestep)
        {
            lag -= timestep;
            state_engine->update();
        }

        state_engine->draw();
    }
#endif

    return 0;
}
