#include <SFML/Graphics.hpp>
#include "View.h" /** работа с камерой */
#include "Player.h" /** класс игрока */
#include "Map.h" /** класс карты */

int main()
{   /** создаем окно размером 800 на 600, под названием "Game" */
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    /** уменьшем нашу камеру, чтобы тем самым увеличить персонажа */
    view.reset(sf::FloatRect(0, 0, 400, 300));

    /** создаем главного героя с размером 32 на 44 на координатах 200, 120 с текстурой из файла "hero.png" */
    Player player({ 32, 44 }, { 200, 120 }, "files/hero.png");

    /** создаем карту с тестурой из "map.png" */
    Map map("files/map.png");

    /** В этом блоке мы создаем текстуру и спрайт, где находится картинка gameOver для показа завершении игры */
    sf::Texture texture;
    texture.loadFromFile("files/gameOver.png");
    sf::Sprite gameOver;
    gameOver.setTexture(texture);

    /// счетчик кадров для реализации анимации персонажа
    float CurrentFrame = 0;
    /// часы, которые будут отсчитывать время
    sf::Clock clock;

    /** главный цикл программы, пока открыто наше окно с игрой */
    while (window.isOpen())
    {   /// получаем прошеднее время и переводим его в микросекунды
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart(); /** перезапускаем часы для нового отсчета */
        time = time / 800; /** делим для того, чтобы задать "скорость игры", можно его изменять */

        sf::Event event{}; /** cоздаем событие, для отслеживания действий с окном */
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close(); /** закрываем окно, если пользователь нажал на крестик */
        }

            if(!player.gameIsOver()) /** пока игра не завершена */
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) /** если была зажата клавиша влево */
                {
                    player.setDirection(1); /** устанавливаем направление 1 (что и есть влево) */
                    player.setSpeed(0.1); /** устанавливаем скорость движения, можно изменять */
                    if (CurrentFrame > 3) CurrentFrame -= 3; /** всего у нас 4 кадра анимации (включая нулевой), поэтому мы должны следить, чтобы счетчик не был больше трех */
                    player.changeFrameAnimation(CurrentFrame); /** изменяем кадр анимации */
                    CurrentFrame += 0.008 * time; /** изменяем счетчик кадров анимации */
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) /** аналогично и здесь, но меняется направление */
                {
                    player.setDirection(0);
                    player.setSpeed(0.1);
                    if (CurrentFrame > 3) CurrentFrame -= 3;
                    player.changeFrameAnimation(CurrentFrame);
                    CurrentFrame += 0.008 * time;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    player.setDirection(2);
                    player.setSpeed(0.1);
                    if (CurrentFrame > 3) CurrentFrame -= 3;
                    player.changeFrameAnimation(CurrentFrame);
                    CurrentFrame += 0.008 * time;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    player.setDirection(3);
                    player.setSpeed(0.1);
                    if (CurrentFrame > 3) CurrentFrame -= 3;
                    player.changeFrameAnimation(CurrentFrame);
                    CurrentFrame += 0.008 * time;
                }

                setViewCamera(player.getPosition()); /** передаем камере координаты игрока, чтобы она перемещалась за ним */

                player.update(time, map.tileMap); /** обновляем состояние игрока (проверяем на столкновения и движение) */

                window.clear(); /** очищаем экран */
                window.setView(view); /** обновляем положение камеры */
                window.draw(map); /** отрисовываем карту */
                window.draw(player); /** отрисовываем игрока */
                window.display(); /** оторбражаем изменения на экране */
            }

            else /** иначе, если игра завершилась */
            {
                window.clear(); /** очищаем экран */
                view.setCenter(200, 150); /** установка камеры в начальное положение */
                window.setView(view);
                window.draw(gameOver); /** выводим картинку о завершении игры */
                window.display(); /** отображаем изминения */
            }
        }
    return 0;
}
