#include "collider.h"





Collider::Collider()
{
}

bool Collider::checkCollision(sf:sprite& other)
{
	//this->other = other;
	return body.getGlobalBounds().intersects(other.getGlobalBounds(), intersection);

}

Collider::Collider(sf::Sprite spritePlayer)
{

}

sf::FloatRect Collider::getGlobalBounds()
{
	return this->body.getGlobalBounds();
}

sf::FloatRect Collider::getIntersection()
{
	return intersection;
}
