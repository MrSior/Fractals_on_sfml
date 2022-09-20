//
// Created by Семён Чубенко on 15.09.2022.
//

#include "AppRender.h"
#include "iostream"

AppRender::AppRender(AppModel *model) {
    m_model = model;
    Init();
}

void AppRender::Init() {
    auto screen_size = m_model->Get_screen_size();
    screen_width = screen_size.first;
    screen_height = screen_size.second;
    is_need_render_image = true;

    m_window.create(sf::VideoMode(screen_width, screen_height), "Snowflake" );
    selected_area.setFillColor(sf::Color(126, 166,255, 100));
    selected_area.setOutlineColor(sf::Color::White);
    selected_area.setOutlineThickness(3);
}

void AppRender::Render() {
    m_window.clear(sf::Color(255,255,255));
    if (is_need_render_image) {
        Render_sprite();
        is_need_render_image = false;
    }
    m_window.draw(*this);
    m_window.display();
}

void AppRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(sprite);

    if (is_selecting_area){
        target.draw(selected_area);
    }
}

void AppRender::Set_is_need_render_image(bool value) {
    is_need_render_image = value;
}

void AppRender::Render_sprite() {
    sf::Image image;
    image.create(screen_width, screen_height);
    for (int cord_x = 0; cord_x < screen_width; ++cord_x) {
        for (int cord_y = 0; cord_y < screen_height; ++cord_y) {
            auto rgb_color = m_model->Get_dote_color(cord_x, cord_y);
            image.setPixel(cord_x, cord_y, sf::Color(std::get<0>(rgb_color),
                                                     std::get<1>(rgb_color),
                                                     std::get<2>(rgb_color)));
        }
    }
    texture.loadFromImage(image);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}

void AppRender::Set_is_selecting_area(bool value) {
    is_selecting_area = value;
}

void AppRender::Set_selecting_area_position(sf::Vector2f upper_left_corner) {
    selected_area.setPosition(upper_left_corner.x, upper_left_corner.y);
}

void AppRender::Set_selecting_area_size(sf::Vector2f mouse_position) {
    int width = int(mouse_position.x - selected_area.getPosition().x);
    width = abs(width);
    width = width - width % 16;
    int height = width / 16 * 9;
    if (mouse_position.y < selected_area.getPosition().y && mouse_position.x > selected_area.getPosition().x) {
        height = -height;
    } else if (mouse_position.y > selected_area.getPosition().y && mouse_position.x < selected_area.getPosition().x) {
        width = -width;
    } else if (mouse_position.y < selected_area.getPosition().y && mouse_position.x < selected_area.getPosition().x) {
        width = -width;
        height = -height;
    }
    selected_area.setSize(sf::Vector2f(width, height));
}

bool AppRender::Get_is_selecting_area() const {
    return is_selecting_area;
}

sf::Vector2f AppRender::Get_selected_area_size() {
    return selected_area.getSize();
}

sf::Vector2f AppRender::Get_selected_area_upper_left_corner() {
    return selected_area.getPosition();
}

