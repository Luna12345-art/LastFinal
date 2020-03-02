#pragma once
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include"collider.h"
class Player
{
private:
	sf::RenderWindow window;
	sf::Vector2f Coordinate;
	sf::Vector2f Velocity;
	sf::Vector2f maxVelocity;
	float dampingConstant;
	double gravity;
	sf::Time deltaTime;
	sf::RectangleShape spritePlayer;
	float elasticConstant;
	
public:
	Player();
	void initPlayer();
	void update(sf::Time deltaTime);
	sf::Texture player1;
	sf::Sprite spritePlayer;
	//sf::RectangleShape spritePlayer;
	sf::Vector2f getCoordinate();
	sf::Vector2f getVelocity();
	void handlePlayerCollision(sf::Sprite other);
	void updateCoordinates();
	void updateVelocity();
	Collider* collider;
	//Collider getCollider();
	void draw(sf::RenderWindow* window);
	//void setArena(Arena& arena);
};


