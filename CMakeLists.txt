cmake_minimum_required(VERSION 3.22)
project(Fractals)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fractals main.cpp AppController/AppController.cpp AppController/AppController.h AppModel/AppModel.cpp AppModel/AppModel.h AppRender/AppRender.cpp AppRender/AppRender.h AppModel/Koch_Snowflake/Koch_Snowflake.cpp AppModel/Koch_Snowflake/Koch_Snowflake.h AppModel/Complex_num/Complex_num.cpp AppModel/Complex_num/Complex_num.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Fractals sfml-graphics sfml-audio)
