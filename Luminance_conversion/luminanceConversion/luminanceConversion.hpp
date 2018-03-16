//
//  luminanceConversion.hpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 16.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef luminanceConversion_hpp
#define luminanceConversion_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class luminanceConversion { // родительский класс для всех преобразований.
public:
    cv::Mat& returnMat(); // на всякий случай функция возврата ссылки на матрицу.
    virtual void showCurrantStat() {} // метод в каждом дочернем классе будет выводить текущее состояние картинки.
    
protected:
    cv::Mat image; // изображение.
    int max; // максимум для масштабирования.
    void conversionToGray(); // преобразование к полутоновому.
    void scalingChanges(); // масштабирование изменений.
};

#endif /* luminanceConversion_hpp */
