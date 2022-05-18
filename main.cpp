/* Описание проекта Game
 *
 * Перед игроком располагается несколько пронумерованных шаров, каждый
 * из которых может иметь один из нескольких цветов. Игроку
 * извество количество шаров и цветовая палитра, однако цвета шаров неизвестны.
 * Цель игры: узнать цвета всех шаров
 * */

#include <iostream>

#include "ball_game.h"

std::vector<int> request_user_input_ball_colors(int ball_count)
{
    std::vector<int> ball_colors;

    while (ball_colors.size() < ball_count)
    {
        auto color = 0;

        std::cin >> color;

        if (!std::cin.good())
        {
            std::cin.clear();
            return {};
        }

        ball_colors.push_back(color);
    }

    return ball_colors;
}

bool request_user_input_repeat_game()
{
    std::string input;

    auto is_correct_input = false;

    while (std::getline(std::cin, input))
    {
         if (input.size() == 1 && (input[0] == 'y' || input[0] == 'n'))
             break;
    }

    return input[0] == 'y';
}

int main()
{
    const auto color_count = 2;
    const auto ball_count = 3;

    const auto game_info = ball_game::init();

    if (!game_info)
    {
        std::cerr << "Init Ball Game error";
        return -1;
    }

    set_ball_cout(game_info, ball_count);
    set_color_count(game_info, color_count);

    while(true)
    {
        shuffle_ball_colors(game_info);

        std::cout << string_view(game_info) << std::endl;

        while(true)
        {
            std::cout << "Enter ball colors: ";

            std::vector<int> ball_colors = request_user_input_ball_colors(ball_count);

            if (ball_colors.empty())
            {
                std::cout << "Game is interrupted" << std::endl;
                break;
            }

            if (!is_correct_step(game_info, ball_colors))
            {
                std::cout << "Incorrect input, try again" << std::endl;
                continue;
            }

            const auto status = step(game_info, ball_colors);

            const auto guessed_colors = status.first;
            const auto guessed_balls = status.second;

            if (guessed_balls == ball_count)
            {
                std::cout << "Congratulation! You guess all ball colors" << std::endl;
                break;
            }

            std::cout << "Guessed " << guessed_colors << " colors and " << guessed_balls << " ball colors" << std::endl;
        }

        std::cout << "Do you want to try again? (y or n): ";

        if (!request_user_input_repeat_game())
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
    }

    exit(game_info);

    std::cout << "Press any key..." << std::endl;
    std::cin.getline(nullptr, 0);

    return 0;
}
