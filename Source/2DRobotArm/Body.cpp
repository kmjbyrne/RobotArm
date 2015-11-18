
#include "Body.h"

	const float space = 2;

	Body::Body() : ShapeBridge(sf::Vector2<float>(0, 0),
	sf::Vector2<float>(20, -140))
{
	this->chassis = new Chassis();
	this->rect1 = new sf::RectangleShape(sf::Vector2<float>(40, 30));
	this->rect1->setOrigin(this->rect1->getSize().x / 2,
		this->rect1->getSize().y + this->chassis->height + Body::space);
	this->rect2 = new sf::RectangleShape(sf::Vector2<float>(40, 30));
	this->rect2->setOrigin(this->rect2->getSize().x / 2,
		this->rect2->getSize().y + this->rect1->getSize().y + this->chassis->height + Body::space * 2);

	this->add(0, this->chassis);
	this->add(1, this->rect1);
}

Body::~Body()
{
	delete this->chassis;
	delete this->rect1;
	delete this->rect2;
}


Body::Chassis::Chassis(float height,
	float heightBelow,
	float widthAbove,
	float widthBelow)
	:height(height), heightBelow(heightBelow), widthAbove(widthAbove), widthBelow(widthBelow)
{
	this->setPointCount(6);
	this->setPoint(0, sf::Vector2<float>(-this->widthBelow / 2, 0));
	this->setPoint(1, sf::Vector2<float>(this->widthBelow / 2, 0));
	this->setPoint(2, sf::Vector2<float>(this->widthBelow / 2, -this->heightBelow));
	this->setPoint(5, sf::Vector2<float>(-this->widthBelow / 2, -this->heightBelow));
	this->setPoint(3, sf::Vector2<float>(this->widthAbove / 2, -this->height));
	this->setPoint(4, sf::Vector2<float>(-this->widthAbove / 2, -this->height));
}
