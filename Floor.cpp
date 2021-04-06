#include "pch.h"
#include "Floor.h"

Floor::Floor(int t_X, int t_Y, float t_Width, float t_Height)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_Width, t_Height });
	shape.setFillColor(Color::Red);
	shape.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

void Floor::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->shape, state);
}