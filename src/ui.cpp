#include "ui.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

Component createUI(Game& game) {
    std::vector<Component> buttons(9);
    std::string status = "玩家 X 回合";

    auto updateStatus = [&] {
        char player = game.getCurrentPlayer();
        if (game.isWin('X')) status = "❌ X 获胜！";
        else if (game.isWin('O')) status = "⭕ O 获胜！";
        else if (game.isTie()) status = "🤝 平局！";
        else status = std::string("玩家 ") + player + " 回合";
    };

    // 创建 9 个按钮
    for (int i = 0; i < 9; ++i) {
        buttons[i] = Button([&, i] { return std::string(1, game.getCell(i)); },
            [&, i] {
                if (game.isWin('X') || game.isWin('O') || game.isTie())
                    return;
                game.makeMove(i);
                updateStatus();
            }) | size(WIDTH, EQUAL, 8) | size(HEIGHT, EQUAL, 4);
    }

    auto grid = Container::Vertical({
        Container::Horizontal({buttons[0], buttons[1], buttons[2]}),
        Container::Horizontal({buttons[3], buttons[4], buttons[5]}),
        Container::Horizontal({buttons[6], buttons[7], buttons[8]}),
    });

    return Renderer(grid, [&] {
        return vbox({
            text("井字棋游戏") | bold | center | color(Color::Blue),
            separator(),
            grid->Render() | center,
            separator(),
            text(status) | center | bold | color(Color::Red),
            text("按 Q 退出") | center | dim
        }) | border | flex;
    });
}