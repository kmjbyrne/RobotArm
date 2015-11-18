#include "ShapeBridge.h"


void ShapeBridge::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (auto i = this->shapes.begin(); i != this->shapes.end(); i++)
	{
		target.draw(*(i->second), states);
	}
}

ShapeBridge::ShapeBridge(const sf::Vector2<float>& C,
	const sf::Vector2<float>& O)
	:
	Pivot(C, O)
{
}

void ShapeBridge::add(int index, sf::Shape* shape)
{
	this->shapes[index] = shape;
}

void ShapeBridge::setFillColor(const sf::Color &color)
{
	for (auto i = this->shapes.begin(); i != this->shapes.end(); i++)
	{
		i->second->setFillColor(color);
	}
}

void ShapeBridge::setPosition(float x, float y)
{
	this->setPosition(sf::Vector2<float>(x, y));
}

void ShapeBridge::setPosition(const sf::Vector2<float> &position)
{
	this->move(position - this->getPosition());
}

void ShapeBridge::rotate(float angle)
{
	this->sf::Transformable::rotate(angle);
	for (auto i = this->shapes.begin(); i != this->shapes.end(); i++)
	{
		i->second->rotate(angle);
	}
	this->transform(sf::Vector2<float>(0, 0), angle);
}

void ShapeBridge::move(float offsetX, float offsetY)
{
	this->move(sf::Vector2<float>(offsetX, offsetY));
}

void ShapeBridge::move(const sf::Vector2f &offset)
{
	this->Transformable::move(offset);
	for (auto i = this->shapes.begin(); i != this->shapes.end(); i++)
	{
		i->second->move(offset);
	}
	this->transform(offset, 0);
}