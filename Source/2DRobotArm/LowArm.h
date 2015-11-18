#include "ShapeBridge.h"

class LowArm : public ShapeBridge
{
public:
	explicit LowArm();
	~LowArm();
private:
	sf::CircleShape* c;
	sf::CircleShape* cc;
	sf::CircleShape* c1;
	sf::CircleShape* c2;
	sf::RectangleShape* rect;
};