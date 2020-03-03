#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include"Animation.h"
enum class AnimationIndex
{
    walkingRight,
    walkingLeft,
    flyingLeft,
    flyingRight,
    MaxCount
};


int main()
{

    sf::Time deltaTime;
    sf::Clock clock;
    Animation animations[int(AnimationIndex::MaxCount)];
    AnimationIndex curAnimation = AnimationIndex::walkingRight;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Little G");
    sf::Texture avatar;
    sf::Sprite avatar1;
    if (!avatar.loadFromFile("avatar1.png"))
        std::cout << "Can't find the image" << std::endl;
    avatar1.setPosition(500.f, 100.f);
    avatar1.setScale(0.5f, 0.5f);
    animations[int(AnimationIndex::walkingLeft)] = Animation(0, 1200, 300, 600);
    animations[int(AnimationIndex::walkingRight)] = Animation(0, 0, 300, 600);
    animations[int(AnimationIndex::flyingLeft)] = Animation(0, 1800, 300, 600);
    animations[int(AnimationIndex::flyingRight)] = Animation(0, 600, 300, 600);
    while (window.isOpen())
    {
        deltaTime = clock.restart();
        sf::Event event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            curAnimation = AnimationIndex::walkingRight;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            curAnimation = AnimationIndex::walkingLeft;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            curAnimation = AnimationIndex::flyingLeft;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            curAnimation = AnimationIndex::flyingRight;
        }
        animations[int(curAnimation)].update(deltaTime);
        animations[int(curAnimation)].applySprite(avatar1);
        window.clear();
        window.draw(avatar1);
        window.display();

    }

    return 0;
}