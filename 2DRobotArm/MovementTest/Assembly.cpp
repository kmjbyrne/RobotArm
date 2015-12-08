#include "Assembly.h"

Assembly::Assembly(const sf::Vector2<float>&focus, const sf::Vector2<float>&origin)
{
	this->focus = focus;
	this->_origin = origin;
	this->_rotation = 0;
	this->transform(sf::Vector2<float>(0, 0), 0);
}

void Assembly::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (auto i = this->constructs.begin(); i != this->constructs.end(); i++)
	{
		target.draw(*(i->second), states);
	}
}

void Assembly::add(int index, sf::Shape* shape)
{
	this->constructs[index] = shape;
}

void Assembly::setFillColor(const sf::Color &color)
{
	for (auto i = this->constructs.begin(); i != this->constructs.end(); i++)
	{
		i->second->setFillColor(color);
	}
}

void Assembly::setPosition(float x, float y)
{
	this->setPosition(sf::Vector2<float>(x, y));
}

void Assembly::setPosition(const sf::Vector2<float> &position)
{
	this->move(position - this->getPosition());
}

void Assembly::rotate(float angle)
{
	this->sf::Transformable::rotate(angle);
	for (auto i = this->constructs.begin(); i != this->constructs.end(); i++)
	{
		i->second->rotate(angle);
	}
	this->transform(sf::Vector2<float>(0, 0), angle);
}

void Assembly::move(float offsetX, float offsetY)
{
	this->move(sf::Vector2<float>(offsetX, offsetY));
}

void Assembly::move(const sf::Vector2f &offset)
{
	this->Transformable::move(offset);
	for (auto i = this->constructs.begin(); i != this->constructs.end(); i++)
	{
		i->second->move(offset);
	}
	this->transform(offset, 0);
}

void Assembly::transform(const sf::Vector2<float> &vel, float rot)
{
	sf::Transform translation;
	sf::Transform rotation;
	sf::Transform M;

	this->focus += vel;
	translation.translate(this->focus);
	this->_rotation += rot;
	rotation.rotate(this->_rotation);

	M = translation * rotation;
	this->origin = M.transformPoint(this->_origin);
}