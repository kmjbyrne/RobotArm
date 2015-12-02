/*

Author:				Keith Byrne
Student ID:			C00170460
Date Completed:		N/A
Submission Date:	07/12/2015
Program:			2D Interactive Robot Arm
References:			SFML API, Ken Power, Noel O'Hara
					http://www.tutorialspoint.com/cplusplus/
					http://www.cplusplus.com/reference/clibrary/
					http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php
*/

#include "SFML/Graphics.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include "Pedestal.h"
#include "LowerArmSegment.h"
#include "UpperArmSegment.h"
#include "Claw.h"

bool moveAssembly(float, float = 0);
bool rotateLowerArmSegment(float rotate, int code);
bool rotateUpperArmSegment(float rotate, int code);
bool clawControl(float rotate, int code);


//Create Assembly components
Pedestal frame;
LowerArmSegment lowerArmSegment;
UpperArmSegment upperArmSegment;
Claw claw;

//Global configuration declaration
//Warning: Changing these can screw up the mechanics
//Please make conscience changes (and fallbacks) to these

const sf::String title = "Graphics Assessment 1 C00170460";
const sf::VideoMode resolution(800, 600, 32);
const int framerateLimit = 100;
const sf::Vector2<float> infoPosition(20, 540);
const sf::Vector2<float> frameStartPosition(100, 500);
const float movementRate = 1;
const float rotationRate = 1;
const sf::Vector2<float> frameBoundary(100, 600);
const sf::Vector2<float> upperArmLimit(-40, -60);
const sf::Vector2<float> low_margin(-91, 20); //Lower segment boundary

int main()
{
	// Create the main window 
	sf::RenderWindow window(resolution, title);

	std::string controls = "Controls: ";
	controls.append("\nMovement: << + >> Arrow Keys Left/Right");
	controls.append("\nLower Arm Right: A + S Up/Down");
	controls.append("\nUpper Arm Right: Z + X Up/Down");
	controls.append("\nClaw Mechanism: Q + E Open/Close");

	sf::Font _font;
	_font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	sf::Text text;
	text.setFont(_font);
	text.setString(controls);
	text.setColor(sf::Color::Black);
	text.setPosition(20, 40);
	text.setCharacterSize(20);

	window.setFramerateLimit(framerateLimit);

	//Position entire Assembly object (contains all child units)
	moveAssembly(frameStartPosition.x, frameStartPosition.y);
	//lowerArmSegment.setFillColor(sf::Color::Black);
	upperArmSegment.setFillColor(sf::Color::Black);
	
	//Set the claw to 45 degree setup
	claw.controlClaw(45);
	
	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		#pragma region Listeners to handle complete frame movement
		// Listeners to handle complete frame movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (moveAssembly(-movementRate))
			{
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (moveAssembly(movementRate))
			{

			}
		}
		#pragma endregion

		//Listeners for lower arm commands
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			rotateLowerArmSegment(-rotationRate, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			rotateLowerArmSegment(rotationRate, 1);

		//Listeners for upper arm commands
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			rotateUpperArmSegment(-rotationRate, 0);

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			rotateUpperArmSegment(rotationRate, 1);

		//Listeners for claw commands
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			clawControl(rotationRate, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			clawControl(-rotationRate, 1);


		lowerArmSegment.setPosition(frame.focus);
		upperArmSegment.setPosition(lowerArmSegment.origin);
		claw.setPosition(upperArmSegment.origin);

		//prepare frame
		window.clear(sf::Color::White);

		window.draw(frame);
		window.draw(lowerArmSegment);
		window.draw(upperArmSegment);
		window.draw(claw);
		window.draw(text);

		// Finally, display rendered frame on screen 
		window.display();

	} //loop back for next frame

	return EXIT_SUCCESS;
}

bool moveAssembly(float x, float y)
{
	float margin = frame.getPosition().x + x;
	if (margin >= frameBoundary.x && margin <= frameBoundary.y)
	{
		frame.move(x,y);
		lowerArmSegment.setPosition(frame.focus);
		upperArmSegment.setPosition(frame.origin);
		return true;
	}
	return false;
}
bool rotateLowerArmSegment(float rotate, int code)
{
	float rotate_margin = lowerArmSegment._rotation;

	switch (code)
	{
	case 0:
		if (rotate_margin > low_margin.x){
			claw.rotate(rotate);
			upperArmSegment.rotate(rotate);
			lowerArmSegment.rotate(rotate);
			return true;
		}
		break;
	case 1:
		if (rotate_margin < low_margin.y){
			claw.rotate(rotate);
			upperArmSegment.rotate(rotate);
			lowerArmSegment.rotate(rotate);
			return true;
		}
		break;
	}
	return false;
}
bool rotateUpperArmSegment(float rotate, int code)
{
	float rotate_margin = upperArmSegment._rotation;
	switch (code)
	{
	case 0:
		if (rotate_margin > -143)
		{
			claw.rotate(rotate);
			upperArmSegment.rotate(rotate);
			return true;
		}
		break;
	case 1:
		if (rotate_margin < 153)
		{
			claw.rotate(rotate);
			upperArmSegment.rotate(rotate);
			return true;
		}
		break;
	}
	return false;
}
bool clawControl(float rotate, int code)
{
	float rotate_margin = claw.left_a->getRotation() - claw.right_a->getRotation();
	switch (code)
	{
	case 0:
		if (rotate_margin < -55){
			claw.controlClaw(rotate);
			return true;
		}
		return false;
		break;
	case 1:

		if (rotate_margin > -175){
			claw.controlClaw(rotate);
			return true;
		}
		return false;
		break;
	}
	
	return false;
}

