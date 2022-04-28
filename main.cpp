#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CustomRectangleShape : public sf::RectangleShape {
public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position) : sf::RectangleShape(size)
    {
        setPosition(position);
    }

    void setSpeed(const int& x_speed, const int& y_speed, const int & ro_speed) {
        x_speed_ = x_speed;
        y_speed_ = y_speed;
        ro_speed_ = ro_speed;
    }

    void setBounds(const float& left, const float& right ,const float& top,const float& down ){
        l_bound_  = left ;
        r_bound_  = right  ;
        u_bound_  = top  ;
        d_bound_  = down  ;
    }

      void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
        {
            float dt = elapsed.asSeconds();
            if(key == sf::Keyboard::Up)
            {
                y_speed_ = -1*abs(y_speed_);
                            bounce();
                move(0, y_speed_ * dt);
            }
            else if(key == sf::Keyboard::Down)
            {
                y_speed_ = abs(y_speed_);
                            bounce();
                move(0, y_speed_ * dt);
            }
            else if(key == sf::Keyboard::Left)
            {
                x_speed_ = -1*abs(x_speed_);
                            bounce();
                move(x_speed_ * dt, 0);
            }
            else if(key == sf::Keyboard::Right)
            {
                x_speed_ = abs(x_speed_);
                           bounce();
                move(x_speed_ * dt, 0);
            }
        }
        bool isClicked(sf::Vector2i &mouse_position)
        {
            sf::FloatRect rectangle_bounds = getGlobalBounds();
            if(mouse_position.x >= rectangle_bounds.left &&
               mouse_position.x <= rectangle_bounds.left + rectangle_bounds.width
               && mouse_position.y >= rectangle_bounds.top &&
               mouse_position.y <= rectangle_bounds.top + rectangle_bounds.height)
            {
                return true;
            }
            return false;
        }

        bool isColorActive(){return active_;}
           void makeActive(){
               setFillColor(sf::Color(255,0,0));
               active_ = true;
           }
           void dactivateColor(){
               setFillColor(sf::Color(0,255,0));
               active_ = false;
           }

 private:
    int x_speed_ = 0 ;
    int y_speed_ = 0 ;
    int ro_speed_ = 0 ;
    float l_bound_ = 0;
    float r_bound_ = 0;
    float u_bound_ = 0;
    float d_bound_ = 0;
    float active_ = 0;

    void bounce(){
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(rectangle_bounds.top <= u_bound_){
            y_speed_ = abs(y_speed_);
        }

        if(rectangle_bounds.top + rectangle_bounds.height >= d_bound_){
            y_speed_ = abs(y_speed_) * -1;

        }

        if(rectangle_bounds.left <= l_bound_ ){
           x_speed_ = abs(x_speed_);

        }

        if(rectangle_bounds.left + rectangle_bounds.width >= r_bound_){
            x_speed_ = abs(x_speed_) * -1;

        }
    }

};

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape rectangle(size, position);
    rectangle.setFillColor(sf::Color(150, 100, 50));
    rectangle.setSpeed(100, 150, 10);

    std::srand(std::time(nullptr));

    std::vector<CustomRectangleShape> rectangles;

    for(int i=0; i<10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }

    for(auto &rectangle : rectangles)
    {
        rectangle.setFillColor(sf::Color(0, 255, 0));
        rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rectangle.setSpeed(100, 200, 10);

    }

    // run the program as long as the window is open
    srand(time(NULL));
     sf::Clock clock;
    while (window.isOpen()) {

        sf::Time elapsed = clock.restart();

     // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                       window.close();
                 }
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                  if(event.type == sf::Event::MouseButtonPressed)
                        {
                      if(event.mouseButton.button == sf::Mouse::Left)
                                std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                                 for(auto &rectangle : rectangles){
                                            rectangle.dactivateColor();
                                           if(rectangle.isClicked(mouse_pos))
                                           rectangle.makeActive();
                                               }
                                      }
                                 sf::Keyboard::Key pressed;
                                   if(event.type == sf::Event::KeyPressed)
                                            {
                                            pressed = event.key.code;
                                            for(auto &rectangle : rectangles)
                                                {
                                             if(rectangle.isColorActive())
                                                rectangle.moveInDirection(elapsed,pressed);
                                                }

                                            }

         window.clear(sf::Color::Black);
         for(auto &rectangle : rectangles)
            {
                window.draw(rectangle);
            }

            window.display();
        }

    return 0;
}
