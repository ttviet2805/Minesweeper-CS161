#include "MOUSE.h"
/*
bool isPress = false;
while(Mouse::isButtonPressed(Mouse::Left)) isPress = true;

if(isPress == true)
{
    StartButton.Rect.setFillColor(Color::Red);
    Vector2i localPosition = Mouse::getPosition(start_window);
    //std::cout << localPosition.x << ' ' << localPosition.y << '\n';
}
*/

Vector2f Click_StartScreen(RenderWindow window) {
    bool isPress = false;

    while(Mouse::isButtonPressed(Mouse::Left)) isPress = true;

    Vector2i Position = Mouse::getPosition(window);

    return Vector2f(Position.x, Position.y);
}
