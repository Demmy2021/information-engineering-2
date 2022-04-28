
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>


class CustomRectangleShape : public sf::RectangleShape
{
public:
    CustomRectangleShape(sf::Vector2f size, sf::Vector2f position) : sf::RectangleShape(size)
    {
        setPosition(position);
    }
    void setSpeed(double x, double y, double r)
    {
        speed_x_ = x;
        speed_y_ = y;
        speed_r_ = r;
    }
    void set_bounds(double t, double b, double l, double r)
    {
        top_ = t;
        bottom_ = b;
        left_ = l;
        right_ = r;
    }
    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(key == sf::Keyboard::Up && !(bounds.top <= 0.0))
        {
            move(0, -speed_y_ * elapsed.asSeconds());
        }
        else if(key == sf::Keyboard::Right && !(bounds.left >= right_ - bounds.width))
        {
            move(speed_x_ * elapsed.asSeconds(), 0);
        }
        else if(key == sf::Keyboard::Down && !(bounds.top >= bottom_ - bounds.height))
        {
            move(0, speed_y_ * elapsed.asSeconds());
        }
        else if(key == sf::Keyboard::Left && !(bounds.left <= 0.0))
        {
            move(-speed_x_ * elapsed.asSeconds(), 0);
        }
    }
    bool isClicked(sf::Vector2i &mouse_position)
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(mouse_position.x >= bounds.left && mouse_position.x <= bounds.left + bounds.width
                && mouse_position.y >= bounds.top && mouse_position.y <= bounds.top + bounds.height)
        {
            return true;
        }
        return false;
    }

    void setClick(const float &move_up, const float &move_down, const float &move_left,
                  const float &move_right){
         m_click_ = move_up;
         m_click_ = move_down;
         m_click_ = move_left;
         m_click_ = move_right;
    }
private:
    double speed_x_=0, speed_y_=0, speed_r_=0;
    double top_=0, bottom_=0, left_=0, right_=0;
    float m_click_ = 0;
};
void change_color(sf::RectangleShape &rectangle)
{
    rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}
int main()
{


    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape rectangle(size, position);
    rectangle.setFillColor(sf::Color(150, 100, 50));
    //rectangle.setSpeed(100, 150, 10);
    rectangle.set_bounds(0, window.getSize().y, 0, window.getSize().x);
    rectangle.setClick(0, window.getPosition().x, 0, window.getPosition().y);

    std::srand(std::time(nullptr));

    std::vector<CustomRectangleShape> rectangles;
    std::vector<sf::Vector2f> rectDirection;
    sf::RectangleShape* focus = nullptr;
    bool move = false;


    int focusxvar = 0;
    int focusyvar = 0;

      for(int i=0; i<10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }

    for(auto &rectangle : rectangles)
    {
        rectangle.setFillColor(sf::Color(0, 255, 0));
        rectangle.setSpeed(100, 200, 30);


    }

    sf::Clock clock;
    sf::Time time;
    //sf::Time elapsed = clock.restart();
    std::srand(std::time(nullptr));
    while (window.isOpen())
    {
        sf::Vector2i mousePos;
        time = clock.getElapsedTime();

        for(auto &rectangle : rectangles){

        //sf::Time elapsed = clock.restart();
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
        mousePos = (mousePos == sf::Vector2i(0, 0) ? sf::Mouse::getPosition(window) : mousePos);
        rectangle.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    focus=nullptr;

//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//        {
//            rectangle.moveInDirection(elapsed, sf::Keyboard::Up);
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//        {
//            rectangle.moveInDirection(elapsed, sf::Keyboard::Down);
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        {
//            rectangle.moveInDirection(elapsed, sf::Keyboard::Left);
//        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        {
//            rectangle.moveInDirection(elapsed, sf::Keyboard::Right);
//        }
        }

        if(move)
        {
            {
                      if(focus!=nullptr)
                        {
                                focusxvar = focus->getPosition().x;
                                focusyvar = focus->getPosition().y;

                                focus->move(((rectDirection[0].x - focusxvar)*time.asSeconds()*10),
                                                 (rectDirection[0].y - focusyvar)*time.asSeconds()*10);

                               clock.restart();

                     }
                  }
               }
             //}


        sf::Time elapsed = clock.restart();
         sf::Event event;

        while (window.pollEvent(event))
        {

            for(auto &rectangle : rectangles)
                {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                     if(event.mouseButton.button == sf::Mouse::Left)
                        {
                            //leftclicked = true;
                   mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);

                            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                            std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                            if(rectangle.isClicked(mouse_pos))
                            {
                                change_color(rectangle);

                                 }
                            break;
                    }
                        if(event.type == sf::Event::MouseButtonPressed)
                        {
                            if(event.mouseButton.button == sf::Mouse::Right)
                            {
                                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                                std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                                if(rectangle.isClicked(mouse_pos))
                                   {
                                    //change_color(rectangle);

                                     }         break;

                                    }
                                   }
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        rectangle.moveInDirection(elapsed, sf::Keyboard::Up);
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        rectangle.moveInDirection(elapsed, sf::Keyboard::Down);
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        rectangle.moveInDirection(elapsed, sf::Keyboard::Left);
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        rectangle.moveInDirection(elapsed, sf::Keyboard::Right);
                    }
                    break;
            }
        }
             }

        window.clear(sf::Color::Black);

        //window.draw(rectangle);
        for(auto &rectangle : rectangles)
            {
                window.draw(rectangle);
            }

            window.display();
        }
    return 0;
}
