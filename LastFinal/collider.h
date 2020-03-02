#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
class Collider
{
private:
	
public:
	Collider();
	
	bool checkCollision(sf::RectangleShape& other);
	Collider(sf::RectangleShape& body);
	sf::FloatRect getGlobalBounds();
	sf::FloatRect intersection;
	sf::FloatRect getIntersection();
	bool isIntersected;
	sf::RectangleShape body;
};

