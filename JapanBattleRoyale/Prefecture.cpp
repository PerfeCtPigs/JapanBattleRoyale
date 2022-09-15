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

void Prefecture::setCollision(Array<Vec2> collision)
{
	this->collisionVertices = collision;
}

Array<Vec2> Prefecture::getCollision()
{
	return this->collisionVertices;
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
	this->center.moveBy(this->motion);
	this->center.clamp({ 0, 0, 1920, 1080 });
	this->motion.set(0, 0);
}

const void Prefecture::draw()
{
	this->texture.drawAt(this->center);
	return;
}
