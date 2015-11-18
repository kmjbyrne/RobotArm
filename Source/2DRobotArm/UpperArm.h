

#include "ShapeBridge.h"

class UpperArm : public ShapeBridge
{
public:
	explicit UpperArm();
	~UpperArm();
private:
	sf::CircleShape* c1;
	sf::CircleShape* c2;
	sf::RectangleShape* rect;
};