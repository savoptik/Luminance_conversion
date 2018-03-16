//
//  main.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 10.02.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include <string>
#include "conversionOfLog.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    string filePash = "/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/imac.jpg";
    conversionOfLog col(filePash); // создание объекта.
    col.showCurrantStat(); // вывод результата.
    return 0;
}
