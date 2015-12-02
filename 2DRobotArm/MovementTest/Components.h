//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 

#include "SFML/Graphics.hpp" 
#include "LeverPoint.h"

class Components : public LeverPoint
{
public:
	Components(sf::Vector2<float>center = sf::Vector2<float>(0, 0), sf::Vector2<float>origin = sf::Vector2<float>(0, 0));
};

