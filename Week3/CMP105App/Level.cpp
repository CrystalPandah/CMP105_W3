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

	speed = 150.0f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	window->getSize().x;
	window->getSize().y;

	circle.getRadius();
	circle.getRadius() * 2;

	if (circle.getPosition().x + (circle.getRadius()*2) >= (window->getSize().x))
	{
		// Move circle so it is not past the edge
		circle.setPosition(window->getSize().x-(circle.getRadius()*2), circle.getPosition().y);
		
		// Reverse speed
		speed *= -1;
	}
	else if (circle.getPosition().x <= 0)
	{
		// Move circle so it is not past the edge
		circle.setPosition(0, circle.getPosition().y);
		
		// Reverse the speed
		speed *= -1;
	}

	
	

	//Update/move circle
	circle.move(speed*dt, 0);
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