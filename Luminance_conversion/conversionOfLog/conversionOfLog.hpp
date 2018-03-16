//
//  conversionOfLog.hpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 16.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef conversionOfLog_hpp
#define conversionOfLog_hpp

#include <stdio.h>
#include <string>
#include "luminanceConversion.hpp"

class conversionOfLog: luminanceConversion {
public:
    conversionOfLog(std::string filePash); // конструктор загрузит изображение и выполнит преобразование.
    ~conversionOfLog(); // диструктор освободит память.
    virtual void showCurrantStat();
    
private:
    void conversionOfLogFun();
};

#endif /* conversionOfLog_hpp */
