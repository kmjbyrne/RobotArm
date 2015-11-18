

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "UpperArm.h"
#include "LowArm.h"
#include "Body.h"
#include "ClawGrips.h"
#include "ComponentConfiguration.h"


bool moveBody(float, float = 0);
bool rotateUpperArm(float);
bool rotateLowerArm(float);
bool rotateFinger(float);

sf::RenderWindow window(Config::videoMode, Config::title);
sf::Font font;
sf::Text help;

UpperArm upperArm;
LowArm lowerArm;
Body body;
ClawGrips claw;

int main(int, char const**)
{
	sf::Clock clock;

	// Timer
	sf::Time time = clock.getElapsedTime();
	std::stringstream ssTime;
	sf::String sTime;
	sf::Text timer;
	timer.setFont(font);
	timer.setColor(sf::Color::Black);

	// Window
	window.setFramerateLimit(Config::framerateLimit);

	// Help text
	help.setFont(font);
	help.setCharacterSize(Config::fontSize);
	help.setColor(sf::Color::Black);
	help.setPosition(Config::msgPosition);

	// Robot Arm
	body.setFillColor(sf::Color::Black);
	moveBody(Config::bodyStartPosition.x, Config::bodyStartPosition.y);
	upperArm.setFillColor(sf::Color::Black);
	lowerArm.setFillColor(sf::Color::Black);
	claw.setFillColor(sf::Color::Black);

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// Escape pressed : exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}


		// Body movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (moveBody(-Config::moveSpeed))
				while (claw.left->O.x - claw.left->getRadius() < 0)
					if (!rotateUpperArm(Config::rotateSpeed))
						break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			if (moveBody(Config::moveSpeed))
				while (claw.right->O.x + claw.right->getRadius() > window.getSize().x
					|| claw.left->O.x + claw.left->getRadius() > window.getSize().x)
					if (!moveBody(-Config::moveSpeed))
						break;

		// Upper arm rotation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (rotateUpperArm(-Config::rotateSpeed))
			{
				while (claw.left->O.x - claw.left->getRadius() < 0)
					if (!rotateLowerArm(Config::rotateSpeed))
						break;
				while (claw.right->O.y + claw.right->getRadius() > Config::bodyStartPosition.y
					|| claw.left->O.x + claw.left->getRadius() > window.getSize().x)
					if (!rotateUpperArm(Config::rotateSpeed))
						break;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (rotateUpperArm(Config::rotateSpeed))
			{
				while (claw.right->O.y + claw.right->getRadius() > Config::bodyStartPosition.y
					|| claw.right->O.x + claw.right->getRadius() > window.getSize().x)
					if (!rotateUpperArm(-Config::rotateSpeed))
						break;
			}
		}

		// Lower arm rotation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (rotateLowerArm(-Config::rotateSpeed))
			{
				while (claw.left->O.x - claw.left->getRadius() < 0)
					rotateUpperArm(Config::rotateSpeed);
				while (claw.right->O.y + claw.right->getRadius() > Config::bodyStartPosition.y
					|| claw.left->O.x + claw.left->getRadius() > window.getSize().x)
					if (!rotateLowerArm(Config::rotateSpeed))
						break;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if (rotateLowerArm(Config::rotateSpeed))
				while (claw.right->O.y + claw.right->getRadius() > Config::bodyStartPosition.y
					|| claw.right->O.x + claw.right->getRadius() > window.getSize().x)
					if (!rotateLowerArm(-Config::rotateSpeed))
						break;

		// Finger rotation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			rotateFinger(Config::rotateSpeed);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			rotateFinger(-Config::rotateSpeed);
			while (claw.left->O.x - claw.left->getRadius() < 0)
				rotateLowerArm(Config::rotateSpeed);
			while (claw.right->O.y + claw.right->getRadius() > Config::bodyStartPosition.y
				|| claw.right->O.x + claw.right->getRadius() > window.getSize().x
				|| claw.left->O.x + claw.left->getRadius() > window.getSize().x)
				if (!rotateFinger(Config::rotateSpeed))
					break;
		}

		// Update position
		upperArm.setPosition(body.O);
		lowerArm.setPosition(upperArm.O);
		claw.setPosition(lowerArm.O);


		// Status
		std::stringstream ss;
		ss.precision(3);
		ss << "Body x=" << body.getPosition().x << " y=" << body.getPosition().y << "\t";
		ss << "Upper x=" << upperArm.getPosition().x << " y=" << upperArm.getPosition().y << " ";
		ss << "rotation=" << upperArm.getRotation() << "\t";
		ss << "Lower x=" << lowerArm.getPosition().x << " y=" << lowerArm.getPosition().y << " ";
		ss << "rotation=" << lowerArm.getRotation() << "\n";
		ss << "Finger x=" << claw.getPosition().x << " y=" << claw.getPosition().y << " ";
		ss << "rotation=" << claw.getRotation() << "\n";
		ss << "Left x=" << claw.left->O.x << " y=" << claw.left->O.y << " ";
		ss << "rotation=" << claw.left->getRotation() << " ";
		ss << "Right x=" << claw.right->O.x << " y=" << claw.right->O.y << " ";
		ss << "rotation=" << claw.right->getRotation();
		help.setString("HELLO");


		// Clear screen
		window.clear(sf::Color::White);
		window.draw(timer);
		window.draw(help);
		window.draw(body);
		window.draw(upperArm);
		window.draw(claw);
		window.draw(lowerArm);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}

bool moveBody(float x, float y)
{
	float m = body.getPosition().x + x;
	if (m >= Config::bodyLimit.x && m <= Config::bodyLimit.y)
	{
		body.move(x, y);
		upperArm.setPosition(body.O);
		lowerArm.setPosition(upperArm.O);
		claw.setPosition(lowerArm.O);
		return true;
	}
	return false;
}

bool rotateUpperArm(float rotate)
{

	float r = upperArm.getRotation() + rotate;
	r = r > Config::halfPI ? r - Config::PI : r;
	if (r >= Config::upperArmLimit.x && r <= Config::upperArmLimit.y)
	{
		upperArm.rotate(rotate);
		lowerArm.rotate(rotate);
		return true;
	}
	return false;
}

bool rotateLowerArm(float rotate)
{
	float ru = upperArm.getRotation();
	float rl = lowerArm.getRotation() + rotate;
	float r = rl - ru;
	if (r > Config::halfPI) {
		r -= Config::PI;
	}
	else if (r < -Config::halfPI)
	{
		r += Config::PI;
	}
	if (r >= Config::lowerArmLimit.x && r <= Config::lowerArmLimit.y)
	{
		lowerArm.rotate(rotate);
		claw.rotate(rotate);
		return true;
	}
	return false;
}

bool rotateFinger(float rotate)
{
	float r = claw.left->getRotation() - claw.right->getRotation();
	r += rotate * 2;
	if (r < 0)
		r += Config::PI;
	if (r >= Config::fingerLimit.x && r <= Config::fingerLimit.y)
	{
		claw.left->rotate(rotate);
		claw.right->rotate(-rotate);
		return true;
	}
	return false;
}
