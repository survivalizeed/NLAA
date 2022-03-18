
#pragma once

#include "../Includes.h"

inline void clearPArray() {
	std::fill(_render_buffer, _render_buffer + static_cast<unsigned long>(_window_size_x * _window_size_y), _background_color);
}

inline void displayPArray() {
	BITMAPINFO bi = { 0 };
	bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bi.bmiHeader.biWidth = _window_size_x;
	bi.bmiHeader.biHeight = _window_size_y;
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 32;
	bi.bmiHeader.biCompression = BI_RGB;
	SetDIBitsToDevice(dc, 0, 0, _window_size_x, _window_size_y, 0, 0, 0, _window_size_x, _render_buffer, &bi, 0);
}