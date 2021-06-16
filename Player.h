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

    // направление, ускорение и скорость
    int dir_;
    sf::Vector2f acceleration_;
    float speed_;

    // здоровье персонажа и количетсво собранного золота
    float health_;
    int gold_;

    //шрифт и текст для вывода информации
    sf::Font font_;
    sf::Text* text_ = new sf::Text();

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

        // загружаем шрифт
        font_.loadFromFile("C:/Users/ilins/CLionProjects/Game/font.ttf");

        // задаем настройки для текста
        text_->setFont(font_);
        text_->setCharacterSize(40);
    }

    // унаследованный метод для удобный отрисовки нескольких обьектов
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(sprite_); // отрисовываем спрайт персонажа

        // устанавливаем позицию и содержимое текста
        text_->setPosition(view.getCenter().x-200, view.getCenter().y-150);
        text_->setString("Health: " + std::to_string(int(health_)));

        target.draw(*text_); // отрисовываем текст
    }

    // метод для проверки взаимодействия персонажа с картой
    void interectionWithMap(sf::String map[])
    {
        // условиями ограничиваем карту, чтобы персонаж не мог выйти за ее пределы
        if (position_.x > 920) position_.x = 920;
        if (position_.x < 0) position_.x = 0;
        if (position_.y > 250) position_.y = 250;
        if (position_.y < 4) position_.y = 4;

        // проверяем на коллизию (столковения) с обьектами на карте
        for (int i = position_.y / 64; i < (position_.y + size_.y) / 64; i++)
        {
            for (int j = position_.x / 64; j < (position_.x + size_.x) / 64; j++)
            {
                switch (map[i][j])
                {
                    case 'G': // если это золото
                        map[i][j] = ' '; // убираем золото с карты, чтобы его больше не подбирать
                        gold_++; // увеливаем счетчик
                        break;
                    case 'H': // если это сердце
                        map[i][j] = ' '; // убираем его
                        health_ += 20; // добавляем к здоровью
                        if (health_ > 100) health_ = 100; // проверяем, чтобы здоровье не переполнилось
                        break;
                    case 'O': // если это шипы
                        health_ -= 0.01; // уменьшаем здоровье
                        break;
                }
            }
        }
    }
    // метод для обновления персонажа
    void update(float time, sf::String map[])
    {
        this->interectionWithMap(map); // обращаемся к предыдущему методу

        // проверяем направление и в зависимости от него меняем ускорение, а в последующем изменяем положение
        // стоит упомянуть, что тут отличительная система от декартовой системы координат, y положительный идет вниз
        switch (dir_)
        {
            case 0: // направление вправо
                acceleration_.x = speed_; // ускорение по оси x равное скорости
                acceleration_.y = 0; // ускорение равно нулю (ведь движется строго вправо)
                break;
            case 1: // направление влево
                acceleration_.x = -speed_; // ускорение будет равно отрицательной скорости
                acceleration_.y = 0; // по оси у нет смещений
                break;
            case 2: // направление вниз, аналогично
                acceleration_.x = 0;
                acceleration_.y = speed_;
                break;
            case 3: // направление вверх, аналогично
                acceleration_.x = 0;
                acceleration_.y = -speed_;
                break;
        }

        // изменяем положение игрока в соотвествии с усорением по осям и времени
        position_.x += acceleration_.x * time;
        position_.y += acceleration_.y * time;

        // обнуялем скорость, чтобы персонаж не двигался после отжатия кнопки
        speed_ = 0;

        // устанавливем новую позицию для него
        sprite_.setPosition(position_.x, position_.y);
    }

    // метод для смены кадров, то есть реализация анимации движения
    void changeFrameAnimation(int frame)
    {
        // в зависимости от направления движения
        switch (dir_)
        {
            case 0: // если вправо, то
                sprite_.setTextureRect(sf::IntRect(32 * int(frame), 96, 32, 48)); // смещаем кадр анимации в тайлсете аналогично вправо для отобрадения анимации
                break;
                // для полного понимания лучше открыть в папке images сам тайлсет и посмотреть, как там находятся кадры
            case 1: // аналогично, но другой кадр
                sprite_.setTextureRect(sf::IntRect(32 * int(frame), 48, 32, 48));
                break;
            case 2:
                sprite_.setTextureRect(sf::IntRect(32 * int(frame), 0, 32, 48));
                break;
            case 3:
                sprite_.setTextureRect(sf::IntRect(32 * int(frame), 144, 32, 48));
                break;
        }
    }

    // устанавливаем направление в зависимости от нажатой клавиши
    void setDirection(int dir)
    {
        dir_ = dir;
    }

    // устанавливаем скорость
    void setSpeed(float speed)
    {
        speed_ = speed;
    }

    // для получения позиции, чтобы ее потом передать камере
    sf::Vector2f getPosition()
    {
        return position_;
    }

    // чтобы узнать, завершена игра или нет
    bool gameIsOver()
    {
        if (health_ <= 0 || gold_ == 6) return true; // если здоровье меньше нуля или собрано все золото, то да
        return false; // иначе нет
    }
};
