//
// Created by kafkalainen on 2/11/23.
//

#include <boilerplate.h>

int main()
{
    sf::RenderWindow    m_applicationWindow;

    sf::Vector2u windowSize = sf::Vector2u(800, 600);
    m_applicationWindow.create( sf::VideoMode(windowSize), "rt");

    while (m_applicationWindow.isOpen())
    {
        sf::Event event{};
        while (m_applicationWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_applicationWindow.close();
            }
        }

        m_applicationWindow.clear();
        m_applicationWindow.display();
    }

    std::cout << "Initialized" << std::endl;
    return (0);
}