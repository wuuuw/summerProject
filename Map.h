#pragma once

const int HEIGHT = 5; // высота карты
const int WIDTH = 15; // ширина карты

class Map : public sf::Drawable // класс карты, наследуем от drawable (аналогично player)
{
private:

    std::string path_; // путь до текстур
    sf::Texture texture_; // текстура
    sf::Sprite* sprite_ = new sf::Sprite(); // спрайт

public:

    sf::String tileMap[HEIGHT] = // массив, в котором хранится карта
            {
                    "   G    OOG H G",
                    "  O  O    O  O ",
                    "GO     OH      ",
                    "O  O  O  O O   ",
                    " GOO        G  "
            };
    // G - золото
    // O - шипы
    // H - сердце

    Map(std::string path) // конструктор класса
    {
        this->path_ = path; // инициализируем значением переменную пути

        loadTexture(path_); // загружаем текструы
    }

    // собственно метод загрузки текстур
    void loadTexture(std::string path)
    {
        texture_.loadFromFile(path);
        sprite_->setTexture(texture_);
    }

    // унаследованный метод для удобной отрисовки
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        // в двух циклах прохожимся по каждому элементу карты
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                // определяем его тип
                switch (tileMap[i][j])
                {
                    // в соответствии с типом выбираем нужную текстуру из тайлсета
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

                sprite_->setPosition(j * 64, i * 64); // распологаем текстуру в нужном месте
                target.draw(*sprite_); // отрисовываем
            }
        }
    }
};
