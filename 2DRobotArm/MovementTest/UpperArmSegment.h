#include "Assembly.h"

class UpperArmSegment : public Assembly
{
private:
	sf::CircleShape* pivot_cog;
	sf::CircleShape* pivot_a;
	sf::CircleShape* pivot_b;
	sf::RectangleShape* arm;
public:
	UpperArmSegment();
	~UpperArmSegment();
};
