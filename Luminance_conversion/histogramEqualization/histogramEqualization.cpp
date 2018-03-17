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
    for (int i = 0; i < bHist.rows; i++) {
        bHist.at<float>(i) = bHist.at<float>(i) / (img.rows * img.cols);
    }
}

void histogramEqualization::plottingHistogram() { 
    vector<Mat> vec; // вектор для разделения изображения.
    split(image, vec); // разделения изображения на 3 матрицы.
    int histSyse = 256; // количество столбиков гистограммы.
    float range[] = {0, 256}; // высота столбиков.
    const float *ranges[] = {range}; // высота столбиков ДЛЯ ОДНОЙ ГИСТОГРАММЫ
    calcHist(&vec[0], 1, 0, Mat(), bHist, 1, &histSyse, ranges); // построение гистограммы.
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

