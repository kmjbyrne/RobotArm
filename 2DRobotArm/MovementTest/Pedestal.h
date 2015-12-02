//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 


#include "Assembly.h"


class Pedestal : public Assembly
{
	private:
		sf::CircleShape* pivot;
		sf::RectangleShape* base;
		sf::RectangleShape* riser;
	public:
		explicit Pedestal();
		~Pedestal();
};

