#pragma once

#include <SFML/Graphics.hpp>
#include "Mainclass.h"

using namespace sf;
using namespace std;



class Player : public sf::Drawable, public Mainclass
{
public:
	Player(float t_X, float t_Y);
	Player() = delete;
	~Player() = default;

	void update(float screen_width);

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	const float shapeWidth{ 100.0f };
	const float shapeHeigth{ 90.0f };
	const float shapeVelocity{ 10.0f };
	Vector2f velocity{ shapeVelocity, 0.f };
};

