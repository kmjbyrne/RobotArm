//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 

#include "Assembly.h"

class Claw : public Assembly
{
private:
	sf::CircleShape* pivot;
	sf::RectangleShape* left_b;
	sf::RectangleShape* right_b;

public:
	sf::RectangleShape* left_a;
	sf::RectangleShape* right_a;
	bool controlClaw(float rotate);
	Claw();
	~Claw();
};
