//
//  grayWorld.hpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 17.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef grayWorld_hpp
#define grayWorld_hpp

#include <stdio.h>
#include <string>
#include "luminanceConversion.hpp"

class grayWorld: luminanceConversion {
public:
    grayWorld(std::string filePash); // конструктор загрузит изображение и запустит преобразование.
    ~grayWorld(); // деструктор освободит память.
    virtual void showCurrantStat(); // вывод изменённого изображения.
private:
    void conversiontoGrayWorld(); // преобразование к серому миру.
};

#endif /* grayWorld_hpp */
