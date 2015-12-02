#include "SFML/Graphics.hpp" 

class LeverPoint
{
public:
	float rotation;
	//Centre and origin points
	sf::Vector2<float> centre, origin;
	void transform(const sf::Vector2<float>& vel, float rot);
	LeverPoint(sf::Vector2<float>centre, sf::Vector2<float>origin);
};