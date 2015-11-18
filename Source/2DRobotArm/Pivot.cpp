#include "Pivot.h"


Pivot::Pivot(const sf::Vector2<float>& C, const sf::Vector2<float>& O)
{
	this->C = C;
	this->_O_ = O;
	this->_R_ = 0;
	this->transform(sf::Vector2<float>(0, 0), 0);
}

void Pivot::transform(const sf::Vector2<float> &vel, float rot)
{
	sf::Transform T;
	sf::Transform R;
	sf::Transform M;

	this->C += vel;
	T.translate(this->C);
	this->_R_ += rot;
	R.rotate(this->_R_);

	M = T * R;
	this->O = M.transformPoint(this->_O_);
}