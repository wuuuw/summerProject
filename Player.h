#pragma once
class Player : public sf::Drawable // класс нашего персонажа, наследуем от Drawable для удобной отрисовки в дальнейшем
{
private: // публичные поля

    // обьекты для хранения спрайта (картинки)
    sf::Texture texture_;
    sf::Sprite sprite_;

    // переменные размера и позиции
    sf::Vector2f size_;
    sf::Vector2f position_;

    // здоровье персонажа и количетсво собранного золота
    float health_;
    int gold_;

public: // приватные поля

    Player(sf::Vector2f size, sf::Vector2f position, std::string path) // конструктор, принимает размер, положение персонажа и путь до файла с картинкой
    {
        // инициализируем приватные поля полученными данными
        this->size_ = size;
        this->position_ = position;

        // загружаем текстуры + шрифт
        loadTexture(path);

        // устанавливаем начальные значения здоровья и количества золота
        health_ = 100;
        gold_ = 0;

        // обрезаем тайлсет по размеру персонажа и устанавливаем в нужную позицию
        sprite_.setTextureRect(sf::IntRect(0, 0, size_.x, size_.y));
        sprite_.setPosition(position_);
    }

    // метод для загрузки текстур
    void loadTexture(std::string path)
    {
        // загружаем и устанавливаем спрайт
        texture_.loadFromFile(path);
        sprite_.setTexture(texture_);
    }

    // унаследованный метод для удобный отрисовки нескольких обьектов
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(sprite_); // отрисовываем спрайт персонажа
    }

    // метод для проверки взаимодействия персонажа с картой
    void interectionWithMap(sf::String map[])
    {
        // условиями ограничиваем карту, чтобы персонаж не мог выйти за ее пределы
        if (position_.x > 920) position_.x = 920;
        if (position_.x < 0) position_.x = 0;
        if (position_.y > 250) position_.y = 250;
        if (position_.y < 4) position_.y = 4;
    }

    // чтобы узнать, завершена игра или нет
    bool gameIsOver()
    {
        if (health_ <= 0 || gold_ == 6) return true; // если здоровье меньше нуля или собрано все золото, то да
        return false; // иначе нет
    }
};
