#pragma once
class Prefecture;

class IPrefectureState {
public:
	virtual void onEnter(Prefecture& prefecture) = 0;
	virtual void onUpdate(Prefecture& prefecture) = 0;
	virtual void onExit(Prefecture& prefecture) = 0;
	virtual void onDraw(Prefecture& prefecture) = 0;
};
