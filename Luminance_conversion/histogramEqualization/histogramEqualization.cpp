//
//  histogramEqualization.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 17.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "histogramEqualization.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void histogramEqualization::buildingStackedHistogram() { 
    <#code#>;
}

void histogramEqualization::normalizationHistogram() { 
    <#code#>;
}

void histogramEqualization::plottingHistogram() { 
    <#code#>;
}

void histogramEqualization::showCurrantStat() { 
    imshow("Histogram equalization", image); // вывод изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Histogram equalization"); // уничтожение окна.
}

histogramEqualization::~histogramEqualization() { 
    image.deallocate(); // Освобождение памяти.
}

histogramEqualization::histogramEqualization(std::string filePaah) { 
    image = imread(filePaah); // загрузка изображения.
    conversionToGray();// приведение изображения к полутоновому.
    plottingHistogram(); // построение гистограммы.
    normalizationHistogram(); // нормализация гистограммы.
    buildingStackedHistogram(); // построение гистограммы с накоплением.
    uniformDistributionValues(); // равномерное распределение значений.
    scalingChanges(); // масштабирование.
}

void histogramEqualization::uniformDistributionValues() { 
    <#code#>;
}

