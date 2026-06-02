cmake_minimum_required(VERSION 3.11)
project(tictactoe)

set(CMAKE_CXX_STANDARD 17)

# 自动下载并引入 FTXUI（和 Tetris 项目完全相同）
include(FetchContent)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://gitee.com/mirrors/FTXUI.git
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

# 添加可执行文件
add_executable(tictactoe
  src/main.cpp
  src/game.cpp
  src/ui.cpp)


# 链接 FTXUI
target_link_libraries(tictactoe
    ftxui::component
    ftxui::dom
    ftxui::screen
)