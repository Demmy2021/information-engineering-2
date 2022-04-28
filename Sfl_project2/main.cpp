
#include<iostream>
#include<vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class  CustomRectangleShape : public sf::RectangleShape{
   public:
        CustomRectangleShape(const sf::Vector2f &size , const sf::Vector2f &position)
            :sf::RectangleShape(size)
        {
        setPosition(position);
        }

        void setSpeed(int x_s, int y_s, int ro_s){

            m_speed_x = x_s;
            m_speed_y = y_s;
            m_speed_ro = ro_s;
        }


        void setBounds(int top, int down, int right, int left){

            bounds_up = top;
            bounds_down = down;
            bounds_left = left;
            bounds_right = right;

        }
        void animate(const sf::Time &elapsed){
        float dt = elapsed.asSeconds();
        move(m_speed_x * dt, m_speed_y * dt);
        rotate(m_speed_ro*dt);
        bounce();
        }

//        void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key){

//        }

private:
        int m_speed_x = 0;
        int m_speed_y = 0;
        int m_speed_ro = 0;

        int bounds_up = 0;
        int bounds_down = 0;
        int bounds_left = 0;
        int bounds_right = 0;

        void bounce(){
               sf::FloatRect rectangle_bounds = getGlobalBounds();

               if(rectangle_bounds.top <= bounds_up){
                   m_speed_y = abs(m_speed_y);
               }

               if(rectangle_bounds.top + rectangle_bounds.height >= bounds_down){
                   m_speed_y = abs(m_speed_y) * -1;
                   setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
               }

               if(rectangle_bounds.left <= bounds_left  ){
                  m_speed_x  = abs(m_speed_x );
                  setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
               }

               if(rectangle_bounds.left + rectangle_bounds.width >= bounds_right){
                   m_speed_x = abs(m_speed_x) * -1;
                   setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
               }
           }

 };

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape rectangle(size, position);
    rectangle.setFillColor(sf::Color(100, 50, 250));
    rectangle.setSpeed(100, 50, 10);


    // create some shapes
    sf::CircleShape circle(50.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    //sf::RectangleShape rectangle(sf::Vector2f(150.0, 80.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::ConvexShape convex;
        // resize it to 5 points
    convex.setPointCount(5);
        // define the points
    convex.setPoint(0, sf::Vector2f(0.0, 0.0));
    convex.setPoint(1, sf::Vector2f(0.0, 50.0));
    convex.setPoint(2, sf::Vector2f(120.0, 90.0));
    convex.setPoint(3, sf::Vector2f(30.0, 100.0));
    convex.setPoint(4, sf::Vector2f(0.0, 50.0));
    convex.setPosition(400.0, 80.0);
    convex.setFillColor(sf::Color::Blue);

    // run the program as long as the window is open

    sf::Clock clock;
    //sf::Transformable::move;

    int rectangle_velocity_x = 200;
    int rectangle_velocity_y = 400;
    int rectangle_angular_velocity = 30;

    int circle_velocity_x = 200;
    int circle_velocity_y = 400;
    int circle_angular_velocity = 30;

    int triangle_velocity_x = 200;
    int triangle_velocity_y = 400;
    int triangle_angular_velocity = 30;

    int convex_velocity_x = 200;
    int convex_velocity_y = 400;
    int convex_angular_velocity = 30;

      bool flag_y_1 = false;
      bool flag_x_1 = false;
      bool flag_y_2 = false;
      bool flag_x_2 = false;
      bool flag_y_3 = false;
      bool flag_x_3 = false;
      bool flag_y_4 = false;
      bool flag_x_4 = false;



    while (window.isOpen()) {

        sf::Time elapsed = clock.restart();
        std::cout <<"duration: " << elapsed.asSeconds()/10e6 <<std::endl;
        float dt = elapsed.asSeconds();
        rectangle.move(rectangle_velocity_x * dt, rectangle_velocity_y * dt);
        rectangle.rotate(rectangle_angular_velocity*dt);


        //sf::FloatRect rectangle_bounds = rectangle2.getGlobalBounds();
        rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);

        circle.move(circle_velocity_x * dt, circle_velocity_y * dt);
        circle.rotate(circle_angular_velocity*dt);

        triangle.move(triangle_velocity_x * dt, triangle_velocity_y * dt);
        triangle.rotate(triangle_angular_velocity*dt);

        convex.move(convex_velocity_x * dt, convex_velocity_y * dt);
        convex.rotate(convex_angular_velocity*dt);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
                std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
                std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;

        sf::FloatRect circle_bounds = circle.getGlobalBounds();
                std::cout << circle_bounds.top << " " << circle_bounds.left << " " ;
                std::cout << circle_bounds.width << " " << circle_bounds.height << std::endl;

        sf::FloatRect triangle_bounds = triangle.getGlobalBounds();
                std::cout << triangle_bounds.top << " " << triangle_bounds.left << " " ;
                std::cout << triangle_bounds.width << " " << triangle_bounds.height << std::endl;

        sf::FloatRect convex_bounds = convex.getGlobalBounds();
                std::cout << convex_bounds.top << " " << convex_bounds.left << " " ;
                std::cout << convex_bounds.width << " " << convex_bounds.height << std::endl;

                if(rectangle_bounds.top<=0 || rectangle_bounds.top+rectangle_bounds.height>=window.getSize().y)
                    {
                        if(flag_y_1 != true)
                        {
                            rectangle_velocity_y *= -1;
                            rectangle.setFillColor(sf::Color(rand() % 256,
                                                             rand() % 256,
                                                             rand() % 256));
                        }
                        flag_y_1 = true;
                    }
                    else
                        flag_y_1 = false;

                    if(rectangle_bounds.left<=0 || rectangle_bounds.left+rectangle_bounds.width>=window.getSize().x)
                    {
                        if(flag_x_1!=true)
                        {
                            rectangle_velocity_x *= -1;
                            rectangle.setFillColor(sf::Color(rand() % 256,
                                                             rand() % 256,
                                                             rand() % 256));
                        }
                        flag_x_1 = true;
                    }
                    else
                        flag_x_1 = false;


                    if(circle_bounds.top<=0 || circle_bounds.top+circle_bounds.height>=window.getSize().y)
                        {
                            if(flag_y_2 != true)
                            {
                                circle_velocity_y *= -1;
                                circle.setFillColor(sf::Color(rand() % 256,
                                                                 rand() % 256,
                                                                 rand() % 256));
                            }
                            flag_y_2 = true;
                        }
                        else
                            flag_y_2 = false;

                        if(circle_bounds.left<=0 || circle_bounds.left+circle_bounds.width>=window.getSize().x)
                        {
                            if(flag_x_2!=true)
                            {
                                circle_velocity_x *= -1;
                                circle.setFillColor(sf::Color(rand() % 256,
                                                                 rand() % 256,
                                                                 rand() % 256));
                            }
                            flag_x_2 = true;
                        }
                        else
                            flag_x_2 = false;

                        if(triangle_bounds.top<=0 || triangle_bounds.top+triangle_bounds.height>=window.getSize().y)
                            {
                                if(flag_y_3 != true)
                                {
                                    triangle_velocity_y *= -1;
                                    triangle.setFillColor(sf::Color(rand() % 256,
                                                                     rand() % 256,
                                                                     rand() % 256));
                                }
                                flag_y_3 = true;
                            }
                            else
                                flag_y_3 = false;

                            if(triangle_bounds.left<=0 || triangle_bounds.left+triangle_bounds.width>=window.getSize().x)
                            {
                                if(flag_x_3!=true)
                                {
                                    triangle_velocity_x *= -1;
                                    triangle.setFillColor(sf::Color(rand() % 256,
                                                                     rand() % 256,
                                                                     rand() % 256));
                                }
                                flag_x_3 = true;
                            }
                            else
                                flag_x_3 = false;

                            if(convex_bounds.top<=0 || convex_bounds.top+convex_bounds.height>=window.getSize().y)
                                {
                                    if(flag_y_4 != true)
                                    {
                                        convex_velocity_y *= -1;
                                        convex.setFillColor(sf::Color(rand() % 256,
                                                                         rand() % 256,
                                                                         rand() % 256));
                                    }
                                    flag_y_4 = true;
                                }
                                else
                                    flag_y_4 = false;

                                if(convex_bounds.left<=0 || convex_bounds.left+convex_bounds.width>=window.getSize().x)
                                {
                                    if(flag_x_4!=true)
                                    {
                                        convex_velocity_x *= -1;
                                        convex.setFillColor(sf::Color(rand() % 256,
                                                                         rand() % 256,
                                                                         rand() % 256));
                                    }
                                    flag_x_4 = true;
                                }
                                else
                                    flag_x_4 = false;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

//        if(event.type == sf::Event::KeyReleased)
//                    {
//                        if(event.key.code == sf::Keyboard::Space)
//                        {
//                            rectangle.animate(elapsed);

//                            std::cout << "Hold up Button" << std::endl;
//                        }
//                    }
//       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//                {
//                    rectangle.animate(elapsed);
//                }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
                rectangle.animate(elapsed);
            std::cout << "Holding up button" << std::endl;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Middle))
        {
            std::cout << "Holding middle mouse button" << std::endl;
        }
                if(event.type == sf::Event::KeyReleased)
                    {
                        if(event.key.code == sf::Keyboard::Space)
                            rectangle.animate(elapsed);
                          std::cout << "Space released" << std::endl;
                    }

                    if(event.type == sf::Event::MouseButtonPressed)
                    {
                        if(event.mouseButton.button == sf::Mouse::Left)
                        {
                            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                            std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                        }
                    }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        //window.draw(rectangle2);
        window.draw(convex);

        // end the current frame
        window.display();
    }

    return 0;
}
