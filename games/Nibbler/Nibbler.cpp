/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main_snake
*/

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

int size = 20;
int begin_snake = 3;
int dir = 0;
int num = 3;

struct snake {
    int x;
    int y;
}s[100];

struct fruit {
    int x;
    int y;
}f;

void Action()
{
    for (int i = 1; i < num; i++)
    {
        s[i].x = s[i-1].x;
        s[i].y = s[i-1].y;
    }
    if (dir == 3)
        s[0].x += 1;
    if (dir == 2)
        s[0].x -= 1;
    if (dir == 1)
        s[0].y -= 1;
    if (dir == 0)
        s[0].y += 1;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Snake");
    window.setFramerateLimit(5);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    sf::RectangleShape box(sf::Vector2f(20, 20));
    box.setFillColor(sf::Color::Red);

    sf::RectangleShape apple(sf::Vector2f(20, 20));
    apple.setFillColor(sf::Color::Green);
    
    sf::Clock timer;

    f.x = rand() % size;
    f.y = rand() % size;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }
        if (timer.getElapsedTime().asMicroseconds() > 800)
        {
            Action();
            timer.restart();
        }
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Up) {
                dir = 1;
            }
            if (event.key.code == sf::Keyboard::Down) {
                dir = 0;
            }
            if (event.key.code == sf::Keyboard::Right) {
                dir = 3;
            }
            if (event.key.code == sf::Keyboard::Left) {
                dir = 2;
            }
        }
        window.clear();

        for (int i = 0; i < num; i++) {
            box.setPosition(s[i].x * size, s[i].y * size);
            window.draw(box);
        }
        window.draw(apple);
        window.display();
    }
    window.close();
    return 0;
}

