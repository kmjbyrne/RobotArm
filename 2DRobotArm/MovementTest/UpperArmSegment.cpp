#include "UpperArmSegment.h"

UpperArmSegment::UpperArmSegment() : Assembly(sf::Vector2<float>(0, 0), sf::Vector2<float>(230,0))
{
	this->arm = new sf::RectangleShape(sf::Vector2<float>(200, 30));
	this->arm->setOrigin(this->arm->getSize().x + 15, this->arm->getSize().y / 2);
	this->arm->rotate(180);

	this->pivot_a = new sf::CircleShape(30);
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("cog.png");
	this->pivot_a->setTexture(texture);
	this->pivot_a->setOrigin(this->pivot_a->getRadius()-15, this->pivot_a->getRadius());

	this->pivot_b = new sf::CircleShape(30);
	this->pivot_b->setTexture(texture);
	this->pivot_b->setOrigin(this->arm->getSize().x * -1, this->pivot_b->getRadius());

	this->add(0, this->arm);
	this->add(1, this->pivot_a);
	this->add(2, this->pivot_b);
}
UpperArmSegment::~UpperArmSegment()
{
	delete this->arm;
	delete this->pivot_a;
	delete this->pivot_b;
}