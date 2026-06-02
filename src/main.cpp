#include "game.hpp"
#include "ui.hpp"
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

int main() {
    Game game;
    auto screen = ScreenInteractive::Fullscreen();
    auto ui = createUI(game);

    screen.Loop(ui | CatchEvent([&](Event event) {
        if (event == Event::Character('q')) {
            screen.ExitLoop();
            return true;
        }
        return false;
    }));

    return 0;
}