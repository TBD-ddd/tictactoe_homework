#include "game.hpp"

Game::Game() {
    reset();
}

// 重置棋盘
void Game::reset() {
    for (int i = 0; i < 9; ++i)
        board[i] = ' ';
    currentPlayer = 'X';
}

// 下棋
bool Game::makeMove(int pos) {
    if (pos < 0 || pos > 8 || board[pos] != ' ')
        return false;

    board[pos] = currentPlayer;
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    return true;
}

// 检查胜利
bool Game::checkWin(char p) {
    // 行
    for (int i = 0; i < 9; i += 3)
        if (board[i] == p && board[i+1] == p && board[i+2] == p)
            return true;
    // 列
    for (int i = 0; i < 3; ++i)
        if (board[i] == p && board[i+3] == p && board[i+6] == p)
            return true;
    // 对角线
    if (board[0] == p && board[4] == p && board[8] == p) return true;
    if (board[2] == p && board[4] == p && board[6] == p) return true;

    return false;
}

bool Game::isWin(char player) {
    return checkWin(player);
}

// 平局
bool Game::isTie() {
    for (int i = 0; i < 9; ++i)
        if (board[i] == ' ') return false;
    return true;
}

char Game::getCell(int pos) {
    return board[pos];
}

char Game::getCurrentPlayer() {
    return currentPlayer;
}