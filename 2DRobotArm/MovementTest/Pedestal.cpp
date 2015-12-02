#include "Pedestal.h"


Pedestal::Pedestal() : Assembly(sf::Vector2<float>(110, -50), sf::Vector2<float>(0, 0))
{
	this->base = new sf::RectangleShape(sf::Vector2<float>(200, 40));
	this->base->setFillColor(sf::Color::Black);

	this->riser = new sf::RectangleShape(sf::Vector2<float>(20, 70));
	this->riser->setFillColor(sf::Color::Black);
	this->riser->setOrigin(this->base->getSize().x / -2, this->riser->getSize().y);

	this->pivot = new sf::CircleShape(50);
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("cog.png");
	this->pivot->setTexture(texture);
	this->pivot->setOrigin((this->base->getSize().x / -2) + 40, this->riser->getSize().y + 30);

	this->add(0, base);
	this->add(1, pivot);
	this->add(2, riser);
}

Pedestal::~Pedestal()
{
	delete this->base;
}