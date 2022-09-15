#include "PrefectureTokyo.hpp"
#include "stdafx.h"

PrefectureTokyo::PrefectureTokyo(Vec2 pos) : Prefecture(pos) {
	this->setHealth(10);
	this->setPower(1000);
	this->setRegen(100);
	this->setTexture(Texture(U"Assets/Prefectures/tokyo.png"));
}
