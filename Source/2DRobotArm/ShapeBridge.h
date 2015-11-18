
#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include "Pivot.h"

class ShapeBridge : public sf::Drawable, public sf::Transformable, public Pivot
{
	private:
		std::map<int, sf::Shape*> shapes;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		explicit ShapeBridge(const sf::Vector2<float>& C = sf::Vector2<float>(0, 0),
			const sf::Vector2<float>& O = sf::Vector2<float>(0, 0));
		void add(int index, sf::Shape*);
		void setFillColor(const sf::Color& color);
		void setPosition(float x, float y);
		void setPosition(const sf::Vector2<float>& position);
		void rotate(float angle);
		void move(float offsetX, float offsetY);
		void move(const sf::Vector2f& offset);
};


