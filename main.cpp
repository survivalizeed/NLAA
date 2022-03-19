#include "Includes.h"

int main() {

	_window_size_x = 1000;
	_window_size_y = 1000;
	_render_buffer = new unsigned int[_window_size_x * _window_size_y];
	_background_color = Color(255, 255, 255);
	wndCreate("Anti-Aliased-Line", WS_OVERLAPPEDWINDOW);

	bool toggle = true;
	int iterations = 1;
	for (;;) {
		clearPArray();
		if (GetAsyncKeyState('T') & 0x8000) {
			toggle = !toggle;
			Sleep(300);
		}
		if (GetAsyncKeyState('I') & 0x8000) {
			iterations++;
			Sleep(300);
		}
		if (toggle) {
			DrawLine({ 500,500 }, MousePosition(), Color(255, 0, 0));
		}
		else {
			DrawAALine({ 500,500 }, MousePosition(), Color(255, 0, 0), iterations);
		}
		displayPArray();	
	}
}