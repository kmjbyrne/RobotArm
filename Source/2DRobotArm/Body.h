//
//  RobotBody.h
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "ShapeBridge.h"


class Body : public ShapeBridge
{
public:
	float space;
	sf::Vector2<float> center;
	explicit Body();
	~Body();

	class Chassis;
	class ControlRoom;
	Chassis* chassis;
	sf::RectangleShape* rect1;
	sf::RectangleShape* rect2;
};

class Body::Chassis : public sf::ConvexShape
{
public:
	float height;
	float heightBelow;
	float widthAbove;
	float widthBelow;
	explicit Chassis(float height = 20,
		float heightBelow = 15,
		float widthAbove = 40,
		float widthBelow = 130);
};
