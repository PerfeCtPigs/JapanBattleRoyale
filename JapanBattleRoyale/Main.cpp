#include <Siv3D.hpp>
#include "Prefecture.hpp"
#include "PrefectureTokyo.hpp"

void Main()
{
	Rect screenRect = System::EnumerateMonitors()[0].displayRect;

	Window::SetStyle(WindowStyle::Frameless);
	Window::Resize(screenRect.w, screenRect.h);
	Window::Centering();

	Scene::Resize(1920, 1080);
	Scene::SetBackground(Palette::White);
	Scene::SetResizeMode(ResizeMode::Keep);

	PrefectureTokyo tokyo({ 960, 540 });

	while (System::Update())
	{
		ClearPrint();
		tokyo.update();
		tokyo.draw();
	}
}
