#include "pch.h"
#include "Player.h"

Player::Player(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({this->shapeWidth, this->shapeHeigth});
	shape.setFillColor(Color::Black);
	shape.setOrigin(shapeWidth / 2.f, shapeHeigth / 2.f);
}

void Player::update(float screen_width)
{
	this->shape.move(this->velocity);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		velocity.x = -shapeVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < screen_width)
	{
		velocity.x = shapeVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}

void Player::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->shape, state);
}