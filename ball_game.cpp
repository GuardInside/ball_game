#include "ball_game.h"

#include <cstdlib>
#include <ctime>

namespace
{
    std::vector<bool> make_palete(const std::vector<int> & ball_colors, int color_count)
    {
        std::vector<bool> palete(color_count, false);

        for (const auto ball_color: ball_colors)
            palete[ball_color] = true;

        return palete;
    };
}

namespace ball_game
{
    struct game_info
    {
        int color_count = 0;
        std::vector<int> ball_colors;
    };

    void set_ball_cout(game_info *game_info, int ball_count)
    {
        game_info->ball_colors.clear();
        game_info->ball_colors.resize(ball_count);
    }

    void set_color_count(game_info *game_info, int color_count)
    {
        game_info->color_count = color_count;
    }

    void shuffle_ball_colors(game_info *game_info)
    {
        for (auto & ball_color: game_info->ball_colors)
            ball_color = rand() % game_info->color_count;
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

        for (size_t i = 0, ball_count = game_info->ball_colors.size(); i < ball_count; ++i)
            view.append(std::to_string(game_info->ball_colors[i])).append(" ");

        return view;
    }

    void exit(game_info *game_info)
    {
        delete game_info;
        game_info = nullptr;
    }

    bool is_correct_step(game_info *game_info, const std::vector<int> &ball_colors)
    {
        if (ball_colors.size() != game_info->ball_colors.size())
            return false;

#if 0
        for (const auto ball_color: ball_colors)
            if (ball_color < 0 || ball_color >= game_info->color_count)
                return false;
#endif

        return true;
    }

    std::pair<int, int> step(game_info *game_info, const std::vector<int> &ball_colors)
    {
        std::pair<int, int> status = {0, 0};

        for (size_t i = 0, ball_colors_count = ball_colors.size(); i < ball_colors_count; ++i)
        {
            if (game_info->ball_colors[i] == ball_colors[i])
                ++status.second;
        }

        const auto color_count = game_info->color_count;
        const auto game_palete = make_palete(game_info->ball_colors, color_count);
        const auto palete = make_palete(ball_colors, color_count);

        for (size_t i = 0; i < color_count; ++i)
        {
            if (game_palete[i] == palete[i])
                ++status.first;
        }

        return status;
    }

}
