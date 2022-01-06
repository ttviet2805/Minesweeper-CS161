#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

// Here is the class for the Button
class ButtonClass {
    public:
        ButtonClass() = default;
        RectangleShape Rect;

        // here is the constructor of buttonclass
        ButtonClass(Vector2f _Size, Vector2f _Position, Texture &_Text) {
            Rect.setSize(_Size);
            Rect.setPosition(_Position);
            Rect.setTexture(&_Text);
        }

    int is_Clicked(Vector2f Position) {
        int isPress = 0;

        if(Rect.getGlobalBounds().contains(Position)) {
            while(Mouse::isButtonPressed(Mouse::Left)) isPress = 1;

            if(isPress) return 1;

            return 2;
        }

        return 0;
    }

    int Check_Clicked(Vector2f Position) {
        int isPress = 0;

        if(Rect.getGlobalBounds().contains(Position)) {
            while(Mouse::isButtonPressed(Mouse::Left)) isPress = 1;

            if(isPress) return 1;

            while(Mouse::isButtonPressed(Mouse::Right)) isPress = 3;

            if(isPress == 3) return 3;

            return 2;
        }

        return 0;
    }
};
