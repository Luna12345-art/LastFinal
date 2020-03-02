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
	
	player1.loadFromFile("Images/player.png");
	spritePlayer.setTexture(player1);
	
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

	//std::cout<< p.getCoordinate().x<< " " << p.getCoordinate().y<<"\n";
}




void Game::render()
{
	
	this->window->clear();
	//sf::RectangleShape coolenemy;
	cool.loadFromFile("Images/enemy.png",sf::IntRect(250,250,580,580));
	coolenemy.setTexture(cool);
	//Enemy1.setScale(0.05, 0.05);
	//std::cout << p.getCoordinate().x << " ," << p.getCoordinate().y << std::endl;
	coolenemy.setPosition(sf::Vector2f(150, 150));
	coolenemy.setScale(0.5f, 0.5f);
	this->window->draw(coolenemy);
	p.draw(window);
	this->window->display();

}


