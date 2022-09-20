//
// Created by Семён Чубенко on 15.09.2022.
//

#ifndef FRACTALS_APPMODEL_H
#define FRACTALS_APPMODEL_H

#include "SFML/Graphics.hpp"
#include "Complex_num/Complex_num.h"
#include "vector"

class AppModel {
    Complex_num c_const;
    int n_iter;

    std::pair<double, double> x_boarders;
    std::pair<double, double> y_boarders;

    int screen_width;
    int screen_height;

    std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> previous_boarders;
public:
    AppModel();
    void init();

    void Set_plane_boarders(std::pair<int, int> upper_left_corner, int screen_width, int screen_height);
    void Set_previous_plane_boarders();

    std::tuple<int, int, int> Get_dote_color(double x_pixel, double y_pixel);
    std::pair<int, int> Get_screen_size();
};


#endif //FRACTALS_APPMODEL_H
