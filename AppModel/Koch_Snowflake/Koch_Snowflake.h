//
// Created by Семён Чубенко on 15.09.2022.
//

#ifndef FRACTALS_KOCH_SNOWFLAKE_H
#define FRACTALS_KOCH_SNOWFLAKE_H

#include "SFML/Graphics.hpp"
#include "cmath"

class Koch_Snowflake {
    sf::VertexArray vertexes;
    sf::Color color;
public:
    Koch_Snowflake();
    void Create_next_generation();
    void Return_prev_generation();

    sf::VertexArray Get_points_array() {return vertexes;};
};


#endif //FRACTALS_KOCH_SNOWFLAKE_H
