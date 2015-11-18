#include "ClawGrips.h"
#include <cmath>


ClawGrips::ClawGrips() : ShapeBridge(sf::Vector2<float>(0, 0),
	sf::Vector2<float>(0, -20))
{
	this->left = new ClawGrips::Arch(sf::Vector2<float>(0, 0),
		sf::Vector2<float>(0, -50));
	this->left->setRadius(50);
	this->left->setOrigin(this->left->getRadius(), 0);
	this->left->Transformable::rotate(180);
	this->right = new ClawGrips::Arch(sf::Vector2<float>(0, 0),
		sf::Vector2<float>(0, -50));
	this->right->setRadius(50);
	this->right->setOrigin(this->right->getRadius(), this->right->getRadius() * 2);
	this->add(0, this->left);
	this->add(1, this->right);
}
ClawGrips::~ClawGrips()
{
	delete this->left;
	delete this->right;
}


void ClawGrips::setPosition(float x, float y)
{
	this->setPosition(sf::Vector2<float>(x, y));
}

void ClawGrips::setPosition(const sf::Vector2<float> &position)
{
	this->move(position - this->getPosition());
}

void ClawGrips::rotate(float angle)
{
	this->sf::Transformable::rotate(angle);
	this->left->rotate(angle);
	this->right->rotate(angle);
	this->transform(sf::Vector2<float>(0, 0), angle);
}

void ClawGrips::move(float offsetX, float offsetY)
{
	this->move(sf::Vector2<float>(offsetX, offsetY));
}

void ClawGrips::move(const sf::Vector2f &offset)
{
	this->Transformable::move(offset);
	this->left->move(offset);
	this->right->move(offset);
	this->transform(offset, 0);
}


ClawGrips::Arch::Arch(const sf::Vector2<float>& C, const sf::Vector2<float>& O)
	: Pivot(C, O)
{}

sf::Vector2f ClawGrips::Arch::getPoint(unsigned int index)
{
	if (index > this->getPointCount() / 2) {
		return this->getPoint(index - this->getPointCount() / 2);
	}
	return this->CircleShape::getPoint(index);
}

void ClawGrips::Arch::setPosition(float x, float y)
{
	this->setPosition(sf::Vector2<float>(x, y));
}

void ClawGrips::Arch::setPosition(const sf::Vector2<float> &position)
{
	this->move(position - this->getPosition());
}

void ClawGrips::Arch::rotate(float angle)
{
	this->sf::Transformable::rotate(angle);
	this->transform(sf::Vector2<float>(0, 0), angle);
}

void ClawGrips::Arch::move(float offsetX, float offsetY)
{
	this->move(sf::Vector2<float>(offsetX, offsetY));
}

void ClawGrips::Arch::move(const sf::Vector2f &offset)
{
	this->Transformable::move(offset);
	this->transform(offset, 0);
}