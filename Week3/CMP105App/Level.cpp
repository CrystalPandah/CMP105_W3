#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	//Moving circle defined
	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);

	speed.x = 150.0f;
	speed.y = 150.0f;
	
	dir.x = 1;
	dir.y = 1;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	{
		//Update x speed
		speed.x = 70;
	}
	else if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
	{
		//Update x speed
		speed.x = -70;
	}
	else
	{
		//Update x speed
		speed.x = 0;
	}

	if (input->isKeyDown(sf::Keyboard::Up) && !input->isKeyDown(sf::Keyboard::Down))
	{
		//Update y speed
		speed.y = -70;
	}
	else if (!input->isKeyDown(sf::Keyboard::Up) && input->isKeyDown(sf::Keyboard::Down))
	{
		//Update y speed
		speed.y = 70;
	}
	else
	{
		//Update y speed
		speed.y = 0;
	}


	/*if (input->isKeyDown(sf::Keyboard::Add) && !input->isKeyDown(sf::Keyboard::Subtract))
	{
		speed.x = speed.x + 25; 
		speed.y = speed.y + 25; 
	}
	else if (input->isKeyDown(sf::Keyboard::Subtract) && !input->isKeyDown(sf::Keyboard::Add))
	{
		speed.x = speed.x - 25;
		speed.y = speed.y - 25;
	}*/


}

// Update game objects
void Level::update(float dt)
{
	if (circle.getPosition().x + (circle.getRadius()*2) >= (window->getSize().x))
	{
		// Move circle so it is not past the edge
		circle.setPosition(window->getSize().x-(circle.getRadius()*2), circle.getPosition().y);
		
		// Reverse speed
		dir.x = -1;
	}
	else if (circle.getPosition().x <= 0)
	{
		// Move circle so it is not past the edge
		circle.setPosition(0, circle.getPosition().y);
		
		// change direction 
		dir.x = 1;
	}

	if (circle.getPosition().y + (circle.getRadius() * 2) >= (window->getSize().y))
	{
		// Move circle so it is not past the edge
		circle.setPosition(circle.getPosition().x, window->getSize().y - (circle.getRadius() * 2));

		// change direction
		dir.y = -1;
	}
	else if (circle.getPosition().y <= 0)
	{
		// Move circle so it is not past the edge
		circle.setPosition(circle.getPosition().x, 0);

		// change direction
		dir.y = 1;
	}	

	/*if (speed.x > 500)
	{
		speed.x = 500;
	}
	else if (speed.x < 75)
	{
		speed.x = 75;
	}

	if (speed.y > 500)
	{
		speed.y = 500;
	}
	else if (speed.y < 75)
	{
		speed.y = 75;
	}*/

	//Update/move circle
	circle.move(speed.x*dt*dir.x, speed.y*dt*dir.y);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}