#include "Player.h"

Player::Player()
{
	Coordinate.x = 50;
	Coordinate.y = 50;
	Velocity.x = 0;
	Velocity.y = 0;
	maxVelocity.x = 10;
	maxVelocity.y = 10;
	dampingConstant = 50;
	gravity = 9.8;
	//spritePlayer.setSize(sf::Vector2f(28.f, 50.f));
	collider = (new Collider(spritePlayer));
}

void Player::update(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Velocity.y = -100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Velocity.x = -100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Velocity.x = +100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Velocity.y = +100;
	}
    updateCoordinates();
    updateVelocity();
	std::cout << getCoordinate().x << "," << getCoordinate().y << std::endl;
}

void Player::updateVelocity()
{

	if (abs(Velocity.x) < 0.5)
	{
		Velocity.x = 0;
	}
	else
	{
		Velocity.x -= dampingConstant * deltaTime.asSeconds() * (Velocity.x / abs(Velocity.x));
	}
	if (abs(Velocity.y) < 0.5)
	{
		Velocity.y = 0;
	}
	else
	{
		Velocity.y -= gravity * 50 * deltaTime.asSeconds() * (Velocity.y / abs(Velocity.y));
	}
}

void Player::draw(sf::RenderWindow* window)
{
	spritePlayer.setScale(0.5, 0.5);
	spritePlayer.setPosition(getCoordinate().x, getCoordinate().y);

	std::cout << getCoordinate().x << " ," << getCoordinate().y << std::endl;
	//window->draw(spritePlayer);
	//spritePlayer.setFillColor(sf::Color(100, 250, 50));
	window->draw(spritePlayer);
}


void Player::updateCoordinates()
{
	Coordinate.x += Velocity.x * deltaTime.asSeconds();
	Coordinate.y += Velocity.y * deltaTime.asSeconds();
}

sf::Vector2f Player::getCoordinate()
{
	return sf::Vector2f(Coordinate);
}
/*Collider Player::getCollider()
{
	return Collider(spritePlayer);
}*/

sf::Vector2f Player::getVelocity()
{
	return sf::Vector2f(Velocity);
}
void Player::handlePlayerCollision(sf::Sprite other)
{
	if (collider->checkCollision((other))) {
		if (collider->intersection.height < collider->intersection.width) {
			if (spritePlayer.getGlobalBounds().top < other.getGlobalBounds().top) {
				Coordinate.y -= collider->intersection.height;
				if (abs(Velocity.y) < 1) { Velocity.y = 0; }
					Velocity.y = -elasticConstant * Velocity.y;
				//targetVelocity.y = 0;
			}
			else {
				Coordinate.y += collider->intersection.height;
				if (abs(Velocity.y) < 1) { Velocity.y = 0; }
				Velocity.y = -elasticConstant * Velocity.y;
				//targetVelocity.y = currentVelocity.y;
			}
		}

		if (collider->intersection.height > collider->intersection.width) { //horizontal collission

			if (spritePlayer.getGlobalBounds().left < other.getGlobalBounds().left) {
				Coordinate.x -= collider->intersection.width;
				Velocity.x = -elasticConstant * Velocity.x;
				Velocity.x = Velocity.x;
			}
			else {
				Coordinate.x += collider->intersection.width;
				Velocity.x = -elasticConstant * Velocity.x;
				Velocity.x = Velocity.x;
			}
		}
		spritePlayer.setPosition(Coordinate);


	}
}




