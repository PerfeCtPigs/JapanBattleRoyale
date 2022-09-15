#include "stdafx.h"
#include "Prefecture.hpp"
#include "NormalState.hpp"

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
}

void NormalState::onExit(Prefecture& prefecture)
{
	
}
