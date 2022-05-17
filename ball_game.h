#pragma once

#include <string>

namespace ball_game
{
    struct game_info;

    //! Инициализация игры
    //!
    //! @return false Если инициализация не удалась, например,
    //! потому что не хватило памяти для аллокации ресурсов
    game_info * init() noexcept;

    //! Установить количество шаров
    //!
    //! Меняет цвет всех шаров на цвет по умолчанию
    void set_ball_cout(game_info *game_info, int ball_count);

    //! Установить количество цветов
    //!
    //! Каждый шар может иметь цвета на отрезке [0, color_count - 1]
    void set_color_count(game_info *game_info, int color_count);

    //! Перемешать шары
    void shuffle_ball_colors(game_info *game_info);

    //! Строковое представление игры
    //!
    //! Возвращает строку вида "0 1 5", где каждому числу
    //! соответствует цвет, а позиция числа соответствует
    //! позиции шара в наборе
    //!
    //! @note Используется для отладки
    std::string string_view(game_info * game_info);

    //! Закрыть игру
    void exit(game_info * game_info);
}
