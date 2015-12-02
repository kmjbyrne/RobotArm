//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 

#ifndef ASSEMBLY_COMPONENT_CLASS
#define ASSEMBLY_COMPONENT_CLASS

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#pragma once

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
#include <map>

class Assembly : public sf::Drawable, public sf::Transformable
{
private:
	std::map<int, sf::Shape*> shapes;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Assembly(const sf::Vector2<float>&focus = sf::Vector2<float>(0, 0), const sf::Vector2<float>&origin = sf::Vector2<float>(0, 0));
	void add(int index, sf::Shape*);
	void setFillColor(const sf::Color& color);
	void setPosition(float x, float y);
	void setPosition(const sf::Vector2<float>& position);
	void rotate(float angle);
	void move(float offsetX, float offsetY);
	void move(const sf::Vector2f& offset);
	void transform(const sf::Vector2<float>& vel, float rot);

	//Relative Object rotation and Macro rotation
	float rotation, _rotation;
	//_origin is the KEY point focus of the objects
	sf::Vector2<float> _origin;
	sf::Vector2<float> origin, focus;
};

#endif ASSEMBLY_COMPONENT_CLASS