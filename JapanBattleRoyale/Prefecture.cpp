#include "stdafx.h"
#include "IDUtils.hpp"
#include "Prefecture.hpp"

Prefecture::Prefecture(Vec2 pos)
{
	this->id = generateID();
	this->center = pos;
}

void Prefecture::changeState(IPrefectureState* newState)
{
	if (!newState) return;
	if (this->state) this->state->onExit(*this);
	this->state = newState;
	this->state->onEnter(*this);
	this->stateTimer.restart();
}

void Prefecture::checkAlive()
{
	if (health <= 0)
	{
		this->deadFlag = true;
	}
}

void Prefecture::damage(int damage)
{
	if (damage > 0) this->health -= damage;
	checkAlive();
}

void Prefecture::setPos(Vec2 pos)
{
	this->center = pos;
}

Vec2 Prefecture::getPos()
{
	return this->center;
}

void Prefecture::setRotation(int rotation)
{
	this->rotation = rotation;
}

int Prefecture::getRotation()
{
	return this->rotation;
}

void Prefecture::setDirection(Vec2 direction)
{
	direction.normalize();
	double x = direction.x;
	double y = direction.y;

	if (y < 0.0)
	{
		int result = 450 - (Math::ToDegrees(Math::Acos(direction.x)));
		this->rotation = result >= 360 ? result - 360 : result;
	}
	else
	{
		this->rotation = Math::ToDegrees(Math::Acos(direction.x)) + 90;
	}
}

Vec2 Prefecture::getDirection()
{
	return Vec2(Math::Cos(Math::ToRadians(this->rotation - 90)), Math::Sin(Math::ToRadians(this->rotation - 90)));
}

void Prefecture::setHealth(int health)
{
	this->health = health;
	checkAlive();
}

int Prefecture::getHealth()
{
	return this->health;
}

void Prefecture::setSpeed(double speed)
{
	this->movementSpeed = speed;
}

double Prefecture::getSpeed()
{
	return this->movementSpeed;
}

void Prefecture::setPower(int power)
{
	this->attackPower = power;
}

int Prefecture::setPower()
{
	return this->attackPower;
}

void Prefecture::setRegen(int regen)
{
	this->regenerationRate = regen;
}

int Prefecture::setRegen()
{
	return this->regenerationRate;
}

int Prefecture::getID()
{
	return this->id;
}

void Prefecture::move(Vec2 motion)
{
	this->motion.moveBy(motion);
}

bool Prefecture::isDead()
{
	return this->deadFlag;
}

void Prefecture::setTexture(Texture texture)
{
	this->texture = texture;
}

Texture Prefecture::getTexture()
{
	return this->texture;
}

void Prefecture::setPolygon(Polygon polygon)
{
	this->polygon = polygon;
}

Polygon Prefecture::getPolygon()
{
	return this->polygon;
}

void Prefecture::setAttack(AttackType type, IPrefectureState* state)
{
	this->attacks[type] = state;
}

void Prefecture::attack(AttackType type)
{
	if (this->attacks.find(type) == std::end(this->attacks)) {
		return;
	}
	changeState(this->attacks.at(type));
}

void Prefecture::update()
{
	if(this->state) this->state->onUpdate(*this);
	Vec2 to = this->center.movedBy(this->motion);
	to.clamp({ 0, 0, 1920, 1080 });
	Vec2 fixedMotion = to - this->center;
	this->center.moveBy(fixedMotion);
	this->polygon.moveBy(fixedMotion);
	this->motion.set(0, 0);
}

const void Prefecture::draw()
{
	this->state->onDraw(*this);
	return;
}
