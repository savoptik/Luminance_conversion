//
//  main.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 10.02.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include <string>

#include "grayWorld.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // преобразование Серый мир.
    string GWFilePash = "/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/Мать_родина.png"; // путь к тестовому изображению.
    grayWorld GW(GWFilePash); // запуск конструктора класса.
    GW.showCurrantStat(); // вывод результата.
    return 0;
}
