//
// Created by Семён Чубенко on 15.09.2022.
//

#include "AppController.h"

AppController::AppController(AppModel *model, AppRender *render) {
    m_model = model;
    m_render = render;
}

void AppController::Run() {
    sf::Event event;

    while (m_render->window().isOpen()) {
        while (m_render->window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) m_render->window().close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (!m_render->Get_is_selecting_area()) {
                        m_render->Set_is_selecting_area(true);
                        m_render->Set_selecting_area_position(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    m_model->Set_previous_plane_boarders();
                    m_render->Set_is_need_render_image(true);
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    m_render->Set_is_selecting_area(false);

                    auto upper_left_corner = m_render->Get_selected_area_upper_left_corner();
                    auto selected_area_size = m_render->Get_selected_area_size();
                    if (selected_area_size.x < 0 && selected_area_size.y < 0) {
                        upper_left_corner.x += selected_area_size.x;
                        upper_left_corner.y += selected_area_size.y;
                        selected_area_size.x = abs(selected_area_size.x);
                        selected_area_size.y = abs(selected_area_size.y);
                    } else if (selected_area_size.x > 0 && selected_area_size.y < 0) {
                        upper_left_corner.y += selected_area_size.y;
                        selected_area_size.y = abs(selected_area_size.y);
                    } else if (selected_area_size.x < 0 && selected_area_size.y > 0){
                        upper_left_corner.x += selected_area_size.x;
                        selected_area_size.x = abs(selected_area_size.x);
                    }
                    m_model->Set_plane_boarders({upper_left_corner.x, upper_left_corner.y},
                                                int(selected_area_size.x), int(selected_area_size.y));
                    m_render->Set_is_need_render_image(true);
                }
            }
        }

        if (m_render->Get_is_selecting_area()) {
            auto mouse_position = sf::Mouse::getPosition(m_render->window());
            m_render->Set_selecting_area_size(sf::Vector2f(mouse_position));
        }
        m_render->Render();
    }
}
