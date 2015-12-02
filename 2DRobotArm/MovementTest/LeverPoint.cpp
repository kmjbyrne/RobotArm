#include "LeverPoint.h"

LeverPoint::LeverPoint(sf::Vector2<float>centre, sf::Vector2<float>origin)
{
	this->centre = centre;
	this->origin = origin;
	this->rotation = 0;
	this->transform(sf::Vector2<float>(0, 0), 0);
}

void LeverPoint::transform(const sf::Vector2<float> &vel, float rot)
{
	sf::Transform T;
	sf::Transform R;
	sf::Transform M;

	this->centre += vel;
	T.translate(this->centre);
	this->rotation += rot;
	R.rotate(this->rotation);

	M = T * R;
	this->origin = M.transformPoint(this->origin);
}