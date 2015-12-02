#include "Movement.h"


Movement::Movement()
{
}


Movement::~Movement()
{
}

bool Movement::moveAssembly(Assembly body, float x, float y)
{
	float x_margin = body.getPosition().x + x;
	if (x_margin >= Configuration::frameBoundary.x && x_margin <= Configuration::frameBoundary.y)
	{
		body.move(x, y);
		return true;
	}
	return false;
}