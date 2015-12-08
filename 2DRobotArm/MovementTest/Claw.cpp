#include "Claw.h"
#include <cmath>


Claw::Claw() : Assembly(sf::Vector2<float>(0, 0), sf::Vector2<float>(0, 0))
{
	sf::Texture *decal = new sf::Texture();
	decal->loadFromFile("finger.jpg");

		
	this->pivot = new sf::CircleShape(15);
	this->pivot->setOrigin(this->pivot->getRadius(), this->pivot->getRadius());
	this->pivot->setFillColor(sf::Color::Black);

	this->left_a = new sf::RectangleShape(sf::Vector2<float>(10, -110));
	this->right_a = new sf::RectangleShape(sf::Vector2<float>(10, -100));

	this->left_b = new sf::RectangleShape(sf::Vector2<float>(-50, -10));
	this->right_b = new sf::RectangleShape(sf::Vector2<float>(60, 10));
	

	this->left_a->setOrigin(this->left_a->getSize().x - 5, this->left_a->getSize().y);
	this->right_a->setOrigin(this->right_a->getSize().x - 5, this->right_a->getSize().y);

	this->left_b->setOrigin(this->left_a->getSize().x - 5, this->left_a->getSize().y);
	this->right_b->setOrigin(this->right_a->getSize().x - 5, this->right_a->getSize().y);

	this->left_a->rotate(180);
	this->left_b->rotate(180);

	//Texture mapping
	this->left_a->setTexture(decal);
	this->left_b->setTexture(decal);
	this->right_a->setTexture(decal);
	this->right_b->setTexture(decal);

	this->add(0, this->left_a);
	this->add(1, this->right_a);
	this->add(2, this->left_b);
	this->add(3, this->right_b);
	this->add(4, this->pivot);
}
Claw::~Claw()
{
	delete this->left_a;
	delete this->left_b;
	delete this->right_a;
	delete this->right_b;
	delete this->pivot;
}

bool Claw::controlClaw(float rotate)
{
	this->sf::Transformable::rotate(rotate);

	this->left_a->rotate(rotate);
	this->right_a->rotate(-rotate);

	this->left_b->rotate(rotate);
	this->right_b->rotate(-rotate);

	this->transform(sf::Vector2<float>(0, 0), rotate);

	return false;
}