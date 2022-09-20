//
// Created by Семён Чубенко on 15.09.2022.
//

#include "Koch_Snowflake.h"

Koch_Snowflake::Koch_Snowflake() {
    vertexes = sf::VertexArray(sf::LineStrip);
    vertexes.append(sf::Vector2f(250, 325));
    vertexes.append(sf::Vector2f(750, 325));
    vertexes.append(sf::Vector2f(500, float(325.0 + 250 * sqrt(3))));
    vertexes.append(sf::Vector2f(250, 325));

    color = sf::Color::White;
    for (int ind = 0; ind < vertexes.getVertexCount(); ++ind) {
        vertexes[ind].color = color;
    }
}

void Koch_Snowflake::Create_next_generation() {
    sf::VertexArray new_vertexes(sf::LineStrip);
    for (int i = 0; i < vertexes.getVertexCount() - 1; ++i) {
        new_vertexes.append(vertexes[i]);
        sf::Vector2f edge(vertexes[i + 1].position - vertexes[i].position);
        sf::Vector2f normal(edge.y, -edge.x);
        normal.x /= 2 * sqrtf(3);
        normal.y /= 2 * sqrtf(3);
        sf::Vector2f edge_center(float((vertexes[i].position.x + vertexes[i + 1].position.x) / 2.0),
                                 float((vertexes[i].position.y + vertexes[i + 1].position.y) / 2.0));
        sf::Vector2f first_dote(vertexes[i].position + sf::Vector2f(edge.x / 3.f, edge.y / 3.f));
        sf::Vector2f third_dote(vertexes[i].position + sf::Vector2f(edge.x * 2 / 3.f, edge.y * 2 / 3.f));
        sf::Vector2f second_dote = edge_center + normal;

        new_vertexes.append(first_dote);
        new_vertexes.append(second_dote);
        new_vertexes.append(third_dote);
    }
    new_vertexes.append(vertexes[vertexes.getVertexCount() - 1]);

    for (int ind = 0; ind < new_vertexes.getVertexCount(); ++ind) {
        new_vertexes[ind].color = color;
    }
    vertexes = new_vertexes;
}

void Koch_Snowflake::Return_prev_generation() {
    sf::VertexArray new_vertexes(sf::LineStrip);
    for (int ind = 0; ind < vertexes.getVertexCount(); ind += 4) {
        new_vertexes.append(vertexes[ind]);
    }
    vertexes = new_vertexes;
}
