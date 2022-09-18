#include "PrefectureTokyo.hpp"
#include "stdafx.h"

PrefectureTokyo::PrefectureTokyo(Vec2 pos) : Prefecture(pos) {
	this->setHealth(10);
	this->setPower(1000);
	this->setRegen(100);
	this->setTexture(Texture(U"Assets/Prefectures/tokyo.png"));
	this->setPolygon(Polygon{
		{24 - 150, 1 - 75},
		{111 - 150, 28 - 75},
		{136 - 150, 48 - 75},
		{185 - 150, 38 - 75},
		{187 - 150, 51 - 75},
		{208 - 150, 47 - 75},
		{214 - 150, 39 - 75},
		{248 - 150, 43 - 75},
		{248 - 150, 31 - 75},
		{287 - 150, 39 - 75},
		{300 - 150, 72 - 75},
		{290 - 150, 92 - 75},
		{263 - 150, 139 - 75},
		{235 - 150, 134 - 75},
		{183 - 150, 97 - 75},
		{163 - 150, 147 - 75},
		{136 - 150, 116 - 75},
		{97 - 150, 113 - 75},
		{74 - 150, 94 - 75},
		{25 - 150, 66 - 75},
		{12 - 150, 50 - 75},
		{9 - 150, 26 - 75},
		{1 - 150, 21 - 75},
		{1 - 150, 8 - 75},
	}.moveBy(pos));
}
