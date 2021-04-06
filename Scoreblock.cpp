#include "pch.h"
#include "Scoreblock.h"


Scoreblock::Scoreblock(int t_X, int t_Y, float t_Width, float t_Height)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_Width, t_Height });
	shape.setFillColor(Color::Green);
	shape.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

void Scoreblock::update()
{
	this->shape.move(this->velocity);

	velocity.y = shapeVelocity;
}

Vector2f Scoreblock::getSize()
{
	return shape.getSize();
}

void Scoreblock::change_speed(float vel_for_scoreblock)
{
	this->shapeVelocity=vel_for_scoreblock;
}


void Scoreblock::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->shape, state);
}