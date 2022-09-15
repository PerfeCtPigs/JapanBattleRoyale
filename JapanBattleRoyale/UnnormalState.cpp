#include "stdafx.h"
#include "UnnormalState.hpp"
#include "NormalState.hpp"

void UnnormalState::onEnter(Prefecture& prefecture)
{
	Print << U"Enter Unnormal";
}

void UnnormalState::onUpdate(Prefecture& prefecture)
{

}

void UnnormalState::onExit(Prefecture& prefecture)
{
	Print << U"Exit Unnormal";
}

