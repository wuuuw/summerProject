#include <SFML/Graphics.hpp>
//#include "View.h" // работа с камерой

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    // создаем окно размером 800 на 600, под названием "Game"

    //В этом блоке создается текстура и спрайт, где находится картинка gameOver для показа завершения игры
    sf::Texture texture;
    texture.loadFromFile("C:/Users/ilins/CLionProjects/Game/gameOver.png");
    sf::Sprite gameOver;
    gameOver.setTexture(texture);
    //

    sf::Clock clock; // часы, которые будут отсчитывать время

    while (window.isOpen()) // главный цикл программы, пока открыто наше окно с игрой
    {
        float time = clock.getElapsedTime().asMicroseconds(); // получаем прошеднее время и переводим его в микросекунды
        clock.restart(); // перезапускаем часы для нового отсчета

        sf::Event event; //создаем событие, для отслеживания действий с окном
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close(); // закрываем окно, если пользователь нажал на крестик
        }

        window.clear(); // очищаем экран
        view.setCenter(200, 150); //установка камеры в начальное положение
        window.setView(view);
        window.draw(gameOver); // выводим картинку о завершении игры
        window.display(); // отображаем изминения
    }

    return 0;
}
