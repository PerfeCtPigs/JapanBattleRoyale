#pragma once
#include <map>
#include "NormalState.hpp"

enum AttackType {
	NORMAL_ATTACK,
	SPECIAL_ATTACK,
	EXTRA_ATTACK
};

class Prefecture {
public:
	Prefecture(Vec2 pos);

	void update();

	const void draw();

	void changeState(IPrefectureState* state);

	void checkAlive();

	void damage(int damage);

	void setPos(Vec2 pos);
	Vec2 getPos();

	void setHealth(int health);
	int getHealth();

	void setSpeed(double speed);
	double getSpeed();

	void setPower(int power);
	int setPower();

	void setRegen(int regen);
	int setRegen();

	int getID();

	void move(Vec2 motion);

	bool isDead();

	void setTexture(Texture texture);
	Texture getTexture();

	void setCollision(Array<Vec2> collision);
	Array<Vec2> getCollision();

	void setAttack(AttackType type, IPrefectureState* state);
	void attack(AttackType type);
private:
	int id;

	Vec2 center;
	Vec2 motion = { 0, 0 };

	bool deadFlag = false;

	int health = 10;
	double movementSpeed = 1000.0;
	int attackPower = 10;
	int regenerationRate = 10;

	Texture texture;
	Array<Vec2> collisionVertices;

	Stopwatch stateTimer;

	IPrefectureState* state = new NormalState;

	std::map<AttackType, IPrefectureState*> attacks;

	IPrefectureState* normalAttackState = nullptr;
	IPrefectureState* soecialAttackState = nullptr;
	IPrefectureState* extraAttackState = nullptr;
};
