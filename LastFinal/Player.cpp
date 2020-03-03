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
	collider = (new Collider(body));
}

void Player::update(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;
	//animations[int(curAnimation)].update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Velocity.y = -100;
		curAnimation = AnimationIndex::flyingLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Velocity.x = -100;
		curAnimation = AnimationIndex::walkingLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Velocity.x = +100;
		curAnimation = AnimationIndex::walkingRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Velocity.y = +100;
		curAnimation = AnimationIndex::flyingRight;
	}
	void handlePlayerCollision(sf::RectangleShape recta);
	body.setPosition(Coordinate);
    updateCoordinates();
	updateVelocity();
	
	
	
   
	//std::cout << getCoordinate().x << "," << getCoordinate().y << std::endl;
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
void Player::collisionVelocity()
{
	Velocity = -Velocity*elasticConstant;
	Coordinate.x -= 10;
	Coordinate.y -= 10;
}

void Player::draw(sf::RenderWindow* window)
{
	spritePlayer.setScale(0.5, 0.5);
	//spritePlayer.setPosition(50, 50);
	spritePlayer.setPosition(getCoordinate().x, getCoordinate().y);
	std::cout << getCoordinate().x << " ," << getCoordinate().y << std::endl;
	//cool.loadFromFile("Images/arena.png");
	//coolenemy.setTexture(cool);
	//coolenemy.setPosition(300, 300);
	animations[int(curAnimation)].applySprite(spritePlayer);
	body.setOrigin(spritePlayer.getOrigin());
	//body.setPosition(Coordinate);
	body.setSize(sf::Vector2f(200, 300));
	
	recta.setSize(sf::Vector2f(200, 200));
	recta.setFillColor(sf::Color::Magenta);
	recta.setPosition(400, 400);
	//window->draw(spritePlayer);
	//window->draw(coolenemy);
	window->draw(recta);
	//spritePlayer.setFillColor(sf::Color(100, 250, 50));
	//window->draw(spritePlayer);
}


void Player::updateCoordinates()
{
	Coordinate.x += Velocity.x * deltaTime.asSeconds();
	Coordinate.y += Velocity.y * deltaTime.asSeconds();
}

sf::FloatRect Player::getIntersection()
{
	return intersection;
}

sf::Vector2f Player::getCoordinate()
{

	return sf::Vector2f(Coordinate);
}
Collider Player::getCollider()
{
	return Collider(body);
}

sf::Vector2f Player::getVelocity()
{
	return sf::Vector2f(Velocity);
}
bool Player::checkCollision()
{
	//this->other = other;
	return body.getGlobalBounds().intersects(recta.getGlobalBounds(), intersection);

}

void Player::handlePlayerCollision(sf::RectangleShape other)
{

	if (collider->checkCollision((other))) {
		if (collider->intersection.height < collider->intersection.width) {
			if (body.getGlobalBounds().top < other.getGlobalBounds().top) {
				Coordinate.y -= collider->intersection.height;
				if (abs(Velocity.y) < 1) { Velocity.y = 0; }
				Velocity.y = -elasticConstant * Velocity.y;
				targetVelocity.y = 0;
			}
			else {
				Coordinate.y += collider->intersection.height;
				if (abs(Velocity.y) < 1) { Velocity.y = 0; }
				Velocity.y = -elasticConstant * Velocity.y;
				targetVelocity.y = Velocity.y;
			}
		}
	}
	if (collider->intersection.height > collider->intersection.width) { //horizontal collission

		if (body.getGlobalBounds().left < other.getGlobalBounds().left) {
			Coordinate.x -= collider->intersection.width;
			Velocity.x = -elasticConstant * Velocity.x;
			targetVelocity.x = Velocity.x;

		}
	}
}