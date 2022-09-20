//
// Created by Семён Чубенко on 15.09.2022.
//

#include "AppModel.h"

AppModel::AppModel() {
    init();
}

void AppModel::init() {
    screen_height = 1080;
    screen_width = 1920;

    x_boarders.first = -(double)screen_width / 2;
    x_boarders.second = (double)screen_width / 2;
    y_boarders.first = -(double)screen_height / 2;
    y_boarders.second = (double)screen_height / 2;

    n_iter = 100;
//    c_const.a = -0.2;
//    c_const.b = 0.75;
    c_const.a = 1.25;
    c_const.b = 0;
}

std::tuple<int, int, int> AppModel::Get_dote_color(double x_pixel, double y_pixel) {
    double plane_width;
    if (x_boarders.first * x_boarders.second > 0){
        plane_width = x_boarders.second - x_boarders.first;
    } else {
        plane_width = abs(x_boarders.second) + abs(x_boarders.first);
    }

    double plane_height;
    if (y_boarders.first * y_boarders.second > 0){
        plane_height = y_boarders.second - y_boarders.first;
    } else {
        plane_height = abs(y_boarders.second) + abs(y_boarders.first);
    }

    double zoom_k = screen_width / plane_width;
    x_pixel /= zoom_k;
    y_pixel /= zoom_k;

    Complex_num complex_num(x_boarders.first + x_pixel, y_boarders.second - y_pixel);
    complex_num.a /= float(screen_width) / 4;
    complex_num.b /= float(screen_width) / 4;

    int r = 0, g = 0, b = 0;
    int cnt = 0;
    for (; cnt < n_iter; ++cnt) {
        complex_num = complex_num * complex_num + c_const;
        if (complex_num.abs() > 2){
            break;
        }
    }
    if (cnt < n_iter - 1) {
//        r = (cnt % 2) * 32 + 128;
//        g = (cnt % 4) * 64;
//        b = (cnt % 2) * 16 + 128;
        r = (cnt % 5) * 7;
        g = (cnt % 9) * 19 + 73;
        b = (cnt % 5) * 14 + 73;
    }

    return {r, g, b};
}

void AppModel::Set_plane_boarders(std::pair<int, int> upper_left_corner, int width, int height) {
    previous_boarders.emplace_back(x_boarders, y_boarders);

    double plane_width;
    if (x_boarders.first * x_boarders.second > 0){
        plane_width = x_boarders.second - x_boarders.first;
    } else {
        plane_width = abs(x_boarders.second) + abs(x_boarders.first);
    }
    double zoom_k = screen_width / plane_width;

    std::pair<double, double> dote(x_boarders.first + upper_left_corner.first / zoom_k, y_boarders.second - upper_left_corner.second / zoom_k);

    x_boarders.first = dote.first;
    x_boarders.second = dote.first + width / zoom_k;
    y_boarders.first = dote.second - height / zoom_k;
    y_boarders.second = dote.second;
}

std::pair<int, int> AppModel::Get_screen_size() {
    return {screen_width, screen_height};
}

void AppModel::Set_previous_plane_boarders() {
    if (previous_boarders.empty()) return;
    auto boarders = previous_boarders.back();
    previous_boarders.pop_back();
    x_boarders = boarders.first;
    y_boarders = boarders.second;
}
