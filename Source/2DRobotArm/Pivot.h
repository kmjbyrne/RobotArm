#ifndef __SolarSystem__Pendulum__
#define __SolarSystem__Pendulum__

#include <SFML/Graphics.hpp>


class Pivot
{
private:
	
public:
	// Origin of point O;
	sf::Vector2<float> _O_;
	// _R_ is rotation.
	float _R_;
	// C is the center point. O is the ...(I dont know it in English)
	sf::Vector2<float> C, O;
	Pivot(const sf::Vector2<float>& C, const sf::Vector2<float>& O);
	void transform(const sf::Vector2<float>& vel, float rot);
};

#endif /* defined(__SolarSystem__Pendulum__) */

