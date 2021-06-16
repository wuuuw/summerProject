#include <SFML/Graphics.hpp>
#include "View.h" // работа с камерой
#include "Player.h" // класс игрока
#include "Map.h" // класс карты

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    // создаем окно размером 800 на 600, под названием "Game"

    Player player({ 32, 44 }, { 200, 120 }, "C:/Users/ilins/CLionProjects/Game/hero.png");
    // создаем главного героя с размером 32 на 44 на координатах 200, 120 с текстурой из файла "hero.png"

    Map map("C:/Users/ilins/CLionProjects/Game/map.png"); // создаем карту с тестурой из "map.png"

    //В этом блоке создается текстура и спрайт, где находится картинка gameOver для показа завершения игры
    sf::Texture texture;
    texture.loadFromFile("C:/Users/ilins/CLionProjects/Project/gameOver.png");
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

            if(!player.gameIsOver()) // пока игра не завершена
            {
                window.clear(); // очищаем экран
                window.setView(view); // обновляем положение камеры
                window.draw(map); // отрисовываем карту
                window.draw(player); // отрисовываем игрока
                window.display(); // оторбражаем изменения на экране
            }

            else // иначе, если игра завершилась
            {
                window.clear(); // очищаем экран
                view.setCenter(200, 150); //установка камеры в начальное положение
                window.setView(view);
                window.draw(gameOver); // выводим картинку о завершении игры
                window.display(); // отображаем изминения
            }

        }

    return 0;
}
