#pragma once
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include"Player.h"
#include "Collision.hpp"
#include"Animation.h"


class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;
	sf::FloatRect intersection;
	void initWindow();
	
public:

	Game();
	//void initPlayer();
	void updateEvents();
	void update(sf::Time deltaTime);
	void running();
	void render();
	//void collision();
	Player p;
};

