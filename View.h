#pragma once
sf::View view; // объект типа вида
sf::View setViewCamera(sf::Vector2f coordinate) // функция для слежения за игроком
{
    sf::Vector2f tempCoordinate = coordinate;

    // делаем границы, чтобы нельзя было выйти за них камере
    if (coordinate.x < 204) tempCoordinate.x = 204;
    if (coordinate.x > 756) tempCoordinate.x = 756;
    tempCoordinate.y = 152;

    view.setCenter(tempCoordinate.x, tempCoordinate.y); // устанавливаем центр
    return view; //возвращаем камеру
}
