#pragma once
#include "IPrefectureState.hpp"

class NormalState : public IPrefectureState {
	void onEnter(Prefecture& prefecture) override;
	void onUpdate(Prefecture& prefecture) override;
	void onExit(Prefecture& prefecture) override;
};
