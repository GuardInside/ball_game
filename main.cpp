/* Описание проекта Game
 *
 * Перед игроком располагается несколько пронумерованных шаров, каждый
 * из которых может иметь один из нескольких цветов. Игроку
 * извество количество шаров и цветовая палитра, однако цвета шаров неизвестны.
 * Цель игры: узнать цвета всех шаров
 * */

#include <iostream>

#include "ball_game.h"

int main()
{
    const auto game_info = ball_game::init();

    if (!game_info)
    {
        std::cerr << "Init Ball Game error";
        return -1;
    }

    set_ball_cout(game_info, 3);
    set_color_count(game_info, 10);
    shuffle_ball_colors(game_info);

    std::cout << string_view(game_info) << std::endl;

    exit(game_info);

    return 0;
}
