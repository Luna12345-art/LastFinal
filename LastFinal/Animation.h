
#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
    static constexpr int nFrames = 2;
    static constexpr float holdTime = .25;
    sf::Texture texture;
    sf::IntRect frames[nFrames];
    int iFrame = 0;
    int time = 0.0;
public:
    Animation();
    Animation(int xPos, int yPos, int width, int height);
    void update(sf::Time dt);
    void applySprite(sf::Sprite& sp)const;
    void nxtUpdate();
};
