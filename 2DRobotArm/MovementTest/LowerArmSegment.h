//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 


#include "Assembly.h"

class LowerArmSegment : public Assembly
{
private:
	sf::CircleShape* pivot_a;
	sf::RectangleShape* arm;
public:
	LowerArmSegment();
	~LowerArmSegment();
};
