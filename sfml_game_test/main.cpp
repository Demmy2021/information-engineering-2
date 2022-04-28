#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow mMainWindow(sf::VideoMode(600,600), "Map", sf::Style::Close);
    mMainWindow.setFramerateLimit(60);
    mMainWindow.setKeyRepeatEnabled(false);
    sf::Image image;
    image.create(50, 50, sf::Color::Red);
    sf::Texture texture;
    texture.loadFromImage(image);

    std::vector<sf::Sprite> EnemyVector;
        std::vector<sf::Vector2f> EnemyDestinations;
        sf::Sprite* focus = nullptr;
        bool move = false;

        int focusxvar = 0;
        int focusyvar = 0;

        sf::Clock clock;
        sf::Time time;

    while (mMainWindow.isOpen())
    {
        sf::Event event;
        bool creating = false;
        bool leftclicked = false;
        sf::Vector2i mousePos;

                time = clock.getElapsedTime();
                clock.restart();

        while (mMainWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                mMainWindow.close();
                break;
            case sf::Event::KeyPressed:
                creating = (event.key.code == sf::Keyboard::A);
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                                {
                    leftclicked = true;
                                        mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
                                        break;
                                }
            }
        }
        if (creating)
        {
            sf::Sprite sprite;
            mousePos = (mousePos == sf::Vector2i(0, 0) ? sf::Mouse::getPosition(mMainWindow) : mousePos);
            sprite.setTexture(texture);
            sprite.setColor(sf::Color::Red);
            sprite.setOrigin(static_cast<float>(sprite.getTextureRect().width) / 2, static_cast<float>(sprite.getTextureRect().height) / 2);
            sprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                        focus=nullptr;
            EnemyVector.push_back(sprite);
                        EnemyDestinations.push_back(sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)));
        }
                if (leftclicked)
                {
                        for (auto& enemy = EnemyVector.rbegin(); enemy != EnemyVector.rend(); ++enemy)
                        {
                                if (enemy->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                                {
                                        if(focus==nullptr)
                                        {
                                        focus = &(*enemy);
                                        EnemyDestinations[0]=sf::Vector2f(static_cast<float>(mousePos.x),static_cast<float>(mousePos.y));
                                        move=false;
                                        break;
                                        }
                                }
                                else
                                {
                                        move=true;
                                        EnemyDestinations[0]=sf::Vector2f(static_cast<float>(mousePos.x),static_cast<float>(mousePos.y));
                                }
                        }
                }
                if(move)
                {
                        {
                                if(focus!=nullptr)
                                {
                                        focusxvar = focus->getPosition().x;
                                        focusyvar = focus->getPosition().y;

                                        focus->move(((EnemyDestinations[0].x - focusxvar)*time.asSeconds()*10),
                                                         (EnemyDestinations[0].y - focusyvar)*time.asSeconds()*10);
                                        clock.restart();

                                        if((EnemyDestinations[0].x == focusxvar && EnemyDestinations[0].y == focusyvar))
                                        {
                                                focus=nullptr;
                                        }
                                }
                        }
                }
        mMainWindow.clear();
        for (auto& enemy = EnemyVector.begin(); enemy != EnemyVector.end(); ++enemy)
        {
            mMainWindow.draw(*enemy);
        }
        mMainWindow.display();
    }
    return 0;
}
