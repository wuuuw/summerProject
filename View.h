#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>

/// объект типа вида
sf::View view;

/**
     * функция для слежения за игроком
     * \param coordinate координаты
     */
sf::View setViewCamera(sf::Vector2f coordinate)
{
    sf::Vector2f tempCoordinate = coordinate;

    /** делаем границы, чтобы нельзя было выйти за них камере */
    if (coordinate.x < 204) tempCoordinate.x = 204;
    if (coordinate.x > 756) tempCoordinate.x = 756;
    tempCoordinate.y = 152;

    view.setCenter(tempCoordinate.x, tempCoordinate.y); /** устанавливаем центр */
    return view; /** возвращаем камеру */
}
#endif
