//
// Created by Семён Чубенко on 15.09.2022.
//

#ifndef FRACTALS_APPCONTROLLER_H
#define FRACTALS_APPCONTROLLER_H

#include "../AppModel/AppModel.h"
#include "../AppRender/AppRender.h"

class AppController {
    AppModel* m_model;
    AppRender* m_render;
public:
    AppController(AppModel* model, AppRender* render);

    void Run();
};


#endif //FRACTALS_APPCONTROLLER_H
