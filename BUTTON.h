#include <SFML/Graphics.hpp>
using namespace sf;

class ButtonClass {
    public:
        ButtonClass() = default;
        RectangleShape Rect;

        ButtonClass(Vector2f _Size, Vector2f _Position, Texture &_Text) {
            Rect.setSize(_Size);
            Rect.setPosition(_Position);
            Rect.setTexture(&_Text);
        }
};
