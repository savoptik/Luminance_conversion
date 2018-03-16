//
//  conversionOfLog.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 16.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "conversionOfLog.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <cmath>
using namespace cv;

conversionOfLog::conversionOfLog(std::string filePash) { 
    image = imread(filePash); // загрузка изображения.
    conversionToGray(); // перевод изображения к полутоновому.
    max = 0;
    conversionOfLogFun(); // преобразование по формуле.
    scalingChanges(); // мосштабирование.
}

void conversionOfLog::showCurrantStat() {
    imshow("Conversion of log", image); // отображение изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Conversion of log"); // уничтожение окна.
}

conversionOfLog::~conversionOfLog() { 
    image.deallocate(); // освобождение памяти.
}

void conversionOfLog::conversionOfLogFun() { 
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            auto buf = image.at<Vec3b>(i, j);
            image.at<Vec3b>(i, j)[0] = static_cast<uchar>(log(static_cast<double>(buf[0]))/log(2));
            max = image.at<Vec3b>(i, j)[0] > max? image.at<Vec3b>(i, j)[0]: max;
            image.at<Vec3b>(i, j)[1] = static_cast<uchar>(log(static_cast<double>(buf[1]))/log(2));
            max = image.at<Vec3b>(i, j)[1] > max? image.at<Vec3b>(i, j)[1]: max;
            image.at<Vec3b>(i, j)[2] = static_cast<uchar>(log(static_cast<double>(buf[2]))/log(2));
            max = image.at<Vec3b>(i, j)[2] > max? image.at<Vec3b>(i, j)[2]: max;
        }
    }
}

