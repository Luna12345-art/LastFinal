#pragma once
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include"Collision.hpp"
#include "Collider.h"
#include "Animation.h"
enum class AnimationIndex
{
	walkingRight,
	walkingLeft,
	flyingLeft,
	flyingRight,
	MaxCount
};
class Player
{
private:
	sf::RenderWindow window;
	sf::Vector2f Coordinate;
	sf::Vector2f Velocity;
	sf::Vector2f maxVelocity;
	sf::Vector2f targetVelocity;
	float dampingConstant;
	double gravity;
	sf::Time deltaTime;
	sf::Texture cool;
	sf::Sprite coolenemy;
	//sf::RectangleShape spritePlayer;
	float elasticConstant;
	Animation animations[int(AnimationIndex::MaxCount)];
	AnimationIndex curAnimation = AnimationIndex::walkingLeft;
public:
	Player();
	void initPlayer();
	void update(sf::Time deltaTime);
	sf::Texture player1;
	sf::Sprite spritePlayer;
	sf::FloatRect intersection;
	sf::RectangleShape body;
	sf::RectangleShape recta;
	sf::FloatRect getIntersection();
	sf::Vector2f getCoordinate();
	sf::Vector2f getVelocity();
	void handlePlayerCollision(sf::RectangleShape other);
	bool checkCollision();
	//void handlePlayerCollision(sf::Sprite other);
	void updateCoordinates();
	void updateVelocity();
	void collisionVelocity();
	void collision();
	Collider* collider;
	Collider getCollider();
	void draw(sf::RenderWindow* window);
	//void setArena(Arena& arena);
};


