#include "Game.h"


void Game::initWindow()
{
	this->VideoMode.height = 800;
	this->VideoMode.width = 800;
	this->window = new sf::RenderWindow(this->VideoMode, "Game");
	this->window->setFramerateLimit(144);
}

void Player::initPlayer()
{
	
	player1.loadFromFile("Images/image.png");
	spritePlayer.setTexture(player1);
	animations[int(AnimationIndex::walkingLeft)] = Animation(0, 600, 300, 600);
	animations[int(AnimationIndex::walkingRight)] = Animation(0, 0, 300, 600);
	animations[int(AnimationIndex::flyingLeft)] = Animation(600, 0, 300, 600);
	animations[int(AnimationIndex::flyingRight)] = Animation(600, 600, 300, 600);
	//other.setOrigin(spritePlayer.getOrigin);
	
	body.setFillColor(sf::Color::Magenta);
	//other.setSize(spritePlayer.getScale);
	/*spritePlayer.setFillColor(sf::Color::Magenta);
	spritePlayer.setSize(sf::Vector2f(150,200));*/
}

Game::Game()
{

	this->initWindow();
	this->p.initPlayer();
	

}

void Game::running()
{
	sf::Clock clock;


	while (this->window->isOpen())
	{
		sf::Time deltaTime = clock.restart();
		updateEvents();
		update(deltaTime);
		render();
	}
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}
void Game::update(sf::Time deltaTime)
{
	//this->updateEvents();
	p.update(deltaTime);
	p.collision();
	//std::cout<< p.getCoordinate().x<< " " << p.getCoordinate().y<<"\n";
}




void Game::render()
{
	
	this->window->clear();
	
	p.draw(window);
	//this->window->draw(recta);
	//this->window->draw(p.spritePlayer);
	this->window->draw(p.body);

	this->window->display();

}

void Player::collision()
{
	if (Collision::PixelPerfectTest(spritePlayer, coolenemy))
	{

		std::cout << "Collided";
		//collisionVelocity();
	}
	else
	{
		std::cout << "Not Collided";
		//updateVelocity();
	}
}



