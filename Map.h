#include <SFML/Graphics.hpp>
#include <utility>

#pragma once

/// высота карты
const int HEIGHT = 5;
/// ширина карты
const int WIDTH = 15;

/**
* класс карты,
* наследуем от drawable
* (аналогично player)
*/
class Map : public sf::Drawable
{
private:
    /// путь до текстур
    std::string path_;
    /// текстура
    sf::Texture texture_;
    /// спрайт
    sf::Sprite* sprite_ = new sf::Sprite();

public:
    /** массив, в котором хранится карта, где
     * G - золото, O - шипы, H - сердце
     */
    sf::String tileMap[HEIGHT] =
            {
                    "   G    OOG H G",
                    "  O  O    O  O ",
                    "GO     OH      ",
                    "O  O  O  O O   ",
                    " GOO        G  "
            };

    /**
     * конструктор класса
     * \param path путь до файла
     */
    explicit Map(std::string path)
    {
        this->path_ = std::move(path); /** инициализируем значением переменную пути */

        loadTexture(path_); /** загружаем текструы */
    }

    /**
     * собственно метод загрузки текстур
     * \param path путь до файла
     */
    void loadTexture(const std::string& path)
    {
        texture_.loadFromFile(path);
        sprite_->setTexture(texture_);
    }

    /**
     * унаследованный метод для удобной отрисовки
     * \param target текстура
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        /** в двух циклах проходимся по каждому элементу карты */
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                /** определяем его тип */
                switch (tileMap[i][j])
                {
                    /** в соответствии с типом выбираем нужную текстуру из тайлсета */
                    case ' ':
                        sprite_->setTextureRect(sf::IntRect(0, 0, 64, 64));
                        break;
                    case 'O':
                        sprite_->setTextureRect(sf::IntRect(65, 0, 128, 64));
                        break;
                    case 'G':
                        sprite_->setTextureRect(sf::IntRect(127, 0, 192, 64));
                        break;
                    case 'H':
                        sprite_->setTextureRect(sf::IntRect(193, 0, 256, 64));
                        break;
                }

                sprite_->setPosition(j * 64, i * 64); /** распологаем текстуру в нужном месте */
                target.draw(*sprite_); /** отрисовываем */
            }
        }
    }
};
