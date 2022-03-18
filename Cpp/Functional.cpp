#include "../Headers/Functional.h"

void Set(Vec2 pos, Color color)
{
    if (pos.x < 0 || pos.x > static_cast<int>(_window_size_x) - 1 || pos.y < 0 || pos.y > static_cast<int>(_window_size_y) - 1)
        return;
    _render_buffer[pos.x + _window_size_x * pos.y] = color;
}

Color Get(Vec2 pos)
{
    if (pos.x < 0 || pos.x > static_cast<int>(_window_size_x) - 1 || pos.y < 0 || pos.y > static_cast<int>(_window_size_y) - 1)
        return Color(0,0,0);
    return _render_buffer[pos.x + _window_size_x * pos.y];
}

Vec2 MousePosition() {
    POINT point;
    GetCursorPos(&point);
    ScreenToClient(_window_hwnd, &point);
    point.y = _window_size_y - point.y;
    return { point.x, point.y };
}