#include "CUSTOM.h"

void Custom_Screen()
{
    RenderWindow new_game_window(VideoMode(800, 600), "CUSTOM");

    Texture Background;
    Background.loadFromFile("IMAGE/INGAME_BG.jpg");
    Sprite Bg_Sprite;
    Bg_Sprite.setTexture(Background);

    Texture StartGame;
    StartGame.loadFromFile("IMAGE/STARTGAME.png");
    ButtonClass StartGame_Button(Vector2f(200, 60), Vector2f(300, 400), StartGame);

    // Make back Button
    Texture Back_Texture;
    Back_Texture.loadFromFile("IMAGE/BACK_BUTTON.png");
    ButtonClass Back_Button(Vector2f(50, 50), Vector2f(10, 10), Back_Texture);

    int total_custom_button = 12;
    std::vector<int> custom_data(3, 5);
    std::vector<int> lim_custom_data({30, 16, 99});
    std::vector<sf::Text> custom_data_text(3);
// Set up custom button texture
    std::vector<sf::Texture> custom_button_texture;
    custom_button_texture.resize(6);
    for(int i = 0; i < 6; ++i)
    {
        char number = '0' + i;
        std::string image_path = "IMAGE/custom_button";
        image_path += number;
        image_path += ".png";
        custom_button_texture[i].loadFromFile(image_path);
    }

// Set up custom button
    std::vector<ButtonClass> custom_button;
    custom_button.resize(total_custom_button);
    for(int i = 0; i < total_custom_button; ++i)
    {
        int Id = i / 4;
        switch(i % 4)
        {
        case 0:
            custom_button[i] = ButtonClass(sf::Vector2f(120, 50), sf::Vector2f(150, 150 + Id * 60), custom_button_texture[i / 4]);
            break;
        case 1:
            custom_button[i] = ButtonClass(sf::Vector2f(80, 50), sf::Vector2f(320, 150 + Id * 60), custom_button_texture[3]);
            break;
        case 2:
            custom_button[i] = ButtonClass(sf::Vector2f(80, 50), sf::Vector2f(420, 150 + Id * 60), custom_button_texture[5]);
            break;
        case 3:
            custom_button[i] = ButtonClass(sf::Vector2f(80, 50), sf::Vector2f(520, 150 + Id * 60), custom_button_texture[4]);
            break;
        }
    }

// Set up custom font and text
    sf::Font font;
    font.loadFromFile("Game_Font/AppleII.ttf");
    for(int i = 0; i < 3; ++i)
    {
        custom_data_text[i].setFont(font);
        custom_data_text[i].setCharacterSize(20);
        custom_data_text[i].setFillColor(sf::Color::Black);
        custom_data_text[i].setPosition(sf::Vector2f(445, 164 + i * 60));
    }

    while (new_game_window.isOpen())
    {
        sf::Event event;
        while (new_game_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                new_game_window.close();
            }
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    new_game_window.close();
                }
            }
            }
        }

        new_game_window.draw(Bg_Sprite);

        sf::Vector2i mousePosWindow = sf::Mouse::getPosition(new_game_window);
        sf::Vector2f mousePosView = new_game_window.mapPixelToCoords(mousePosWindow);

        for (int i = 1; i < total_custom_button; i = i + 2)
        {
            int val = custom_button[i].Check_Clicked(mousePosView);

            custom_data[2] = min(custom_data[2], custom_data[0] * custom_data[1]);

            if(val == 1) {
                if(i % 4 == 1 && custom_data[i / 4] - 1 > 0) custom_data[i / 4]--;
                else if(i % 4 == 3 && custom_data[i / 4] + 1 <= lim_custom_data[i / 4]) {
                    custom_data[i / 4]++;
                }
            }
            else {
                if(val == 2) custom_button[i].Rect.setFillColor(Color::Green);
                if(val == 0) custom_button[i].Rect.setFillColor(Color::White);
                if(val == 3) {
                    if(i % 4 == 1 && custom_data[i / 4] - 5 > 0) custom_data[i / 4] -= 5;
                    else if(i % 4 == 3 && custom_data[i / 4] + 5 <= lim_custom_data[i / 4]) {
                        custom_data[i / 4] += 5;
                    }
                }
            }
        }

        for(int i = 0; i < 3; ++i)
        {
            std::string str = "";
            unsigned tem = static_cast<unsigned>(custom_data[i]);
            for(int j = 0; j < 2; ++j, tem /= 10)
            {
                str = (char)(tem % 10 + '0') + str;
            }
            custom_data_text[i].setString(str);
        }

        for(int i = 0; i < total_custom_button; ++i)
        {
            new_game_window.draw(custom_button[i].Rect);
        }
        for(int i = 0; i < 3; ++i)
        {
            new_game_window.draw(custom_data_text[i]);
        }

        new_game_window.draw(StartGame_Button.Rect);

        int Start_val = StartGame_Button.is_Clicked(mousePosView);

        if(Start_val == 1) {
            Put_Custom(custom_data[1], custom_data[0], custom_data[2]);
            new_game_window.close();
            NewGame_Screen();
        }
        else {
            if(Start_val == 2) StartGame_Button.Rect.setFillColor(Color::Green);
            else if(Start_val == 0) StartGame_Button.Rect.setFillColor(Color::White);
        }

        // draw Back Button
        new_game_window.draw(Back_Button.Rect);
        int Back_val = Back_Button.is_Clicked(mousePosView);
        if(Back_val == 1) {
            new_game_window.close();
            Startscreen();
        }
        else {
            if(Back_val == 2) Back_Button.Rect.setFillColor(Color::Red);
            if(Back_val == 0) Back_Button.Rect.setFillColor(Color::White);
        }

        new_game_window.display();
    }
}
