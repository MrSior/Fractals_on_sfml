//
// Created by Семён Чубенко on 15.09.2022.
//

#ifndef FRACTALS_APPRENDER_H
#define FRACTALS_APPRENDER_H

#include "SFML/Graphics.hpp"
#include "../AppModel/AppModel.h"

class AppRender : public sf::Drawable, public sf::Transformable{
    AppModel* m_model;
    sf::RenderWindow m_window;

    int screen_width;
    int screen_height;

    bool is_need_render_image;
    bool is_selecting_area;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape selected_area;

    void Render_sprite();
public:
    explicit AppRender(AppModel* model);
    sf::RenderWindow& window() { return m_window; };

    void Init();
    void Render();

    void Set_is_need_render_image(bool value);
    void Set_is_selecting_area(bool value);
    void Set_selecting_area_position(sf::Vector2f upper_left_corner);
    void Set_selecting_area_size(sf::Vector2f mouse_position);


    bool Get_is_selecting_area() const;
    sf::Vector2f Get_selected_area_size();
    sf::Vector2f Get_selected_area_upper_left_corner();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //FRACTALS_APPRENDER_H
