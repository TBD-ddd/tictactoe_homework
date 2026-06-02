#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

class Game {
public:
    Game();
    bool makeMove(int pos);    // 下棋
    bool isWin(char player);  // 判断胜利
    bool isTie();             // 判断平局
    char getCell(int pos);    // 获取格子内容
    char getCurrentPlayer();  // 当前玩家
    void reset();             // 重置游戏

private:
    char board[9];
    char currentPlayer;
    bool checkWin(char p);
};

#endif