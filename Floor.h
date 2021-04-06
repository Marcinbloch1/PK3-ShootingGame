#pragma once

#include <SFML/Graphics.hpp>
#include "Mainclass.h"

using namespace sf;


class Floor : public sf::Drawable, public Mainclass
{
public:
	Floor(int t_X, int t_Y, float t_Width, float t_Height);
	Floor() = delete;
	~Floor() = default;

private:
	void draw(RenderTarget& target, RenderStates state) const override;
};





