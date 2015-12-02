#include "LowerArmSegment.h"

LowerArmSegment::LowerArmSegment() : Assembly(sf::Vector2<float>(0, 0), sf::Vector2<float>(190, 0))
{
	this->pivot_a = new sf::CircleShape(20);
	this->pivot_a->setOrigin(this->pivot_a->getRadius(), this->pivot_a->getRadius());
	this->pivot_a->setOutlineColor(sf::Color::Yellow);
	this->pivot_a->setFillColor(sf::Color::Black);
	this->pivot_a->setOutlineThickness(2);

	this->arm = new sf::RectangleShape(sf::Vector2<float>(200, 30));
	this->arm->setOrigin(this->arm->getSize().x, this->arm->getSize().y / 2);
	this->arm->rotate(180);

	sf::Texture *decal = new sf::Texture();
	if (decal->loadFromFile("finger.jpg") == false)
	{
		this->arm->setFillColor(sf::Color::Black);
	}
	else
	{
		this->arm->setTexture(decal);
	}


	this->add(0, this->arm);
	this->add(1, this->pivot_a);
}
LowerArmSegment::~LowerArmSegment()
{
	delete this->arm;
	delete this->pivot_a;
}