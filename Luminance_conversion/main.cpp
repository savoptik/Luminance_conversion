//
//  main.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 10.02.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include <string>
#include <conversionOfLog.hpp>
#include "grayWorld.hpp"
#include "histogramEqualization.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // преобразование на основе формулы.
    string filePash = "/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/imac.jpg";
    conversionOfLog col(filePash); // создание объекта.
    col.showCurrantStat(); // вывод результата.
    // преобразование Серый мир.
    string GWFilePash = "/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/Мать_родина.png"; // путь к тестовому изображению.
    grayWorld GW(GWFilePash); // запуск конструктора класса.
    GW.showCurrantStat(); // вывод результата.
    // эквализация гистограммы.
    histogramEqualization HE(GWFilePash); // конструктор загрузит изображение изапустит преобразования.
    HE.showCurrantStat(); // отображение результата.
    return 0;
}
