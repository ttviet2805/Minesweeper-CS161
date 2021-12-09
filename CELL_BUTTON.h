#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace sf;

class Cell_Class {
public:
    Cell_Class() = default;

    RectangleShape Rect;

    Cell_Class(Vector2f _Size, Vector2f _Position, Texture &_Text) {
        Rect.setSize(_Size);
        Rect.setPosition(_Position);
        Rect.setTexture(&_Text);
    }

    int is_Clicked(Vector2f Position) {
        int isPress = 0;

        if(Rect.getGlobalBounds().contains(Position)) {
            while(Mouse::isButtonPressed(Mouse::Left)) isPress = 1;

            if(isPress) return 1;

            while(Mouse::isButtonPressed(Mouse::Right)) isPress = 2;

            if(isPress) return 2;
        }

        return false;
    }
};
