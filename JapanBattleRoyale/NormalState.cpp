#include "stdafx.h"
#include "Prefecture.hpp"
#include "NormalState.hpp"
#include "IDUtils.hpp"

void NormalState::onEnter(Prefecture& prefecture)
{
	
}

void NormalState::onUpdate(Prefecture& prefecture)
{
	Vec2 direction = {
		(KeyRight.pressed() - KeyLeft.pressed()),
		(KeyDown.pressed() - KeyUp.pressed())
	};
	direction.setLength(prefecture.getSpeed() * Scene::DeltaTime());
	prefecture.move(direction);
	if (!direction.isZero()) prefecture.setDirection(direction);
}

void NormalState::onExit(Prefecture& prefecture)
{
	
}

void NormalState::onDraw(Prefecture& prefecture)
{
	prefecture.getTexture().rotated(Math::ToRadians(prefecture.getRotation())).drawAt(prefecture.getPos());
}

