#pragma once
#include <SFML/Graphics.hpp>
#include "Mainclass.h"

using namespace sf;

class Scoreblock : public sf::Drawable, public Mainclass
{
public:
	Scoreblock(int t_X, int t_Y, float t_Width, float t_Height);
	Scoreblock() = delete;
	~Scoreblock() = default;

	void update();
	Vector2f getSize();
	void change_speed(float vel_for_scoreblock);

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	float shapeVelocity=5.0f;
	Vector2f velocity{ 0.f, shapeVelocity };
};

