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
#include <cmath>
#include <vector>
using namespace cv;

void histogramEqualization::buildingStackedHistogram() { 
    for (int i = 1; i < bHist.rows; i++) {
        bHist.at<float>(i) = bHist.at<float>(i-1) + bHist.at<float>(i);
    }
}

void histogramEqualization::normalizationHistogram() { 
    for (int i = 0; i < bHist.rows; i++) {
        bHist.at<float>(i) = bHist.at<float>(i) / (image.rows * image.cols);
    }
}

void histogramEqualization::plottingHistogram() { 
    std::vector<Mat> vec; // вектор для разделения изображения.
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
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            image.at<Vec3b>(i, j)[0] = round(bHist.at<float>(image.at<Vec3b>(i, j)[0]) * 255);
            max = image.at<Vec3b>(i, j)[0] > max? image.at<Vec3b>(i, j)[0]: max; // поиск максимума для мосштабирования.
            image.at<Vec3b>(i, j)[1] = round(bHist.at<float>(image.at<Vec3b>(i, j)[1]) * 255);
            max = image.at<Vec3b>(i, j)[1] > max? image.at<Vec3b>(i, j)[1]: max;
            image.at<Vec3b>(i, j)[2] = round(bHist.at<float>(image.at<Vec3b>(i, j)[2]) * 255);
            max = image.at<Vec3b>(i, j)[2] > max? image.at<Vec3b>(i, j)[2]: max;
        }
    }
}
