//
//  grayWorld.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 17.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "grayWorld.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void grayWorld::showCurrantStat() { 
    imshow("Gray world", image); // вывод изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Gray world"); // уничтожение окна.
}

grayWorld::~grayWorld() { 
    image.deallocate(); // освобождение памяти.
}

grayWorld::grayWorld(std::string filePash) { 
    image = imread(filePash); // загрузка изображения.
    conversiontoGrayWorld(); // преобразование к серому миру.
}

void grayWorld::conversiontoGrayWorld() { 
    int r = 0; // максимум красных.
    int g = 0; // максимум зелёных.
    int b = 0; // максимум синих.
    int max = 0; // максимум.
    int colp = img.rows * img.cols;
    // Поиск максимумов в каналах.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            b += img.at<Vec3b>(i, j)[0];
            g += img.at<Vec3b>(i, j)[1];
            r += img.at<Vec3b>(i, j)[2];
        }
    }
    b = b /colp;
    g = g / colp;
    r = r / colp;
    int midMax = (r + g + b)/3; // среднее максимумов.
    // Преобразование.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = buf[0] * midMax / b; // преобразование канала.
            max = img.at<Vec3b>(i, j)[0] > max ? img.at<Vec3b>(i, j)[0]: max; // поиск максимума.
            img.at<Vec3b>(i, j)[1] = buf[1] * midMax / g;
            max = img.at<Vec3b>(i, j)[1] > max ? img.at<Vec3b>(i, j)[1]: max;
            img.at<Vec3b>(i, j)[2] = buf[2] * midMax / r;
            max = img.at<Vec3b>(i, j)[2] > max ? img.at<Vec3b>(i, j)[2]: max;
        }
    }
}

