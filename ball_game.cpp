#include "ball_game.h"

#include <vector>
#include <ctime>

namespace ball_game
{
    struct game_ball
    {
        int color = 0;
    };

    struct game_info
    {
        int color_count = 0;
        std::vector<game_ball> game_balls;
    };

    void set_ball_cout(game_info *game_info, int ball_count)
    {
        game_info->game_balls.clear();
        game_info->game_balls.resize(ball_count);
    }

    void set_color_count(game_info *game_info, int color_count)
    {
        game_info->color_count = color_count;
    }

    void shuffle_ball_colors(game_info *game_info)
    {
        for (auto & game_ball: game_info->game_balls)
            game_ball.color = rand() % game_info->color_count;
    }

    game_info *init() noexcept
    {
        game_info * this_game_info = new(std::nothrow) game_info;

        if (!this_game_info)
            return nullptr;

        srand(std::time(0));

        return this_game_info;
    }

    std::string string_view(game_info *game_info)
    {
        std::string view;

        for (size_t i = 0, ball_count = game_info->game_balls.size(); i < ball_count; ++i)
            view.append(std::to_string(game_info->game_balls[i].color)).append(" ");

        return view;
    }

    void exit(game_info *game_info)
    {
        delete game_info;
        game_info = nullptr;
    }
}
