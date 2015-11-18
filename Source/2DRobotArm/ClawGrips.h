#include "ShapeBridge.h"

class ClawGrips : public ShapeBridge
{	
public:
	class Arch;
	explicit ClawGrips();
	~ClawGrips();
	void setPosition(float x, float y);
	void setPosition(const sf::Vector2<float>& position);
	void rotate(float angle);
	void move(float offsetX, float offsetY);
	void move(const sf::Vector2f& offset);

	Arch* left;
	Arch* right;
};

class ClawGrips::Arch : public sf::CircleShape, public Pivot
{
public:
	explicit Arch(const sf::Vector2<float>& C, const sf::Vector2<float>& O);
	virtual sf::Vector2f getPoint(unsigned int index) ;
	void setPosition(float x, float y);
	void setPosition(const sf::Vector2<float>& position);
	void rotate(float angle);
	void move(float offsetX, float offsetY);
	void move(const sf::Vector2f& offset);
};