//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <fstream>
//
//
//int main()
//{
//    const int width = 800;
//    const int height = 600;
//    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
//
//    sf::CircleShape circle(100.f);
//    circle.setFillColor(sf::Color::Red);
//    circle.setPosition(400.f-100, 300.f-100);
//    float circleMoveSpeedx = -0.1f;
//    float circleMoveSpeedy = -0.1f;
//    sf::Font Myfont;
//    if (!Myfont.loadFromFile("font.ttf"))
//    {
//        std::cerr << ":(";
//        exit(-1);
//    }
//
//    sf::Text text;
//    text.setString("asdf");
//    text.setCharacterSize(50);
//    text.setFont(Myfont);
//
//    text.setPosition(300, height - (float)text.getCharacterSize()-30);
//
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        sf::Vector2f previousPosition = circle.getPosition();
//        sf::Vector2f moveVector(circleMoveSpeedx, circleMoveSpeedy);
//        sf::Vector2f newPosition = previousPosition + moveVector;
//
//        circle.setPosition(newPosition);
//        
//
//        if (circle.getPosition().x <= 0 || circle.getPosition().x >= width - 200)
//        {
//            circleMoveSpeedx = -circleMoveSpeedx;
//        }
//        if (circle.getPosition().y <=0 || circle.getPosition().y >= height - 200)
//        {
//            circleMoveSpeedy = -circleMoveSpeedy;
//        }
//        text.setPosition(circle.getPosition().x+100, circle.getPosition().y+100);
//        window.clear();
//        window.draw(circle);
//        window.draw(text);
//        window.display();
//    }
//
//    return 0;
//}