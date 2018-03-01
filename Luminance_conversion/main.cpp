//
//  main.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 10.02.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>
#include <iterator>
#include <cmath>
using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    auto img = imread("/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/imac.jpg");
    imshow("test", img);
    waitKey();
    int r = 0; // максимум красных.
    int g = 0; // максимум зелёных.
    int b = 0; // максимум синих.
    int max = 0; // максимум.
    // Поиск максимумов в каналах.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            b = img.at<Vec3b>(i, j)[0] > b ? img.at<Vec3b>(i, j)[0]: b;
            g = img.at<Vec3b>(i, j)[1] > g ? img.at<Vec3b>(i, j)[1]: g;
            r = img.at<Vec3b>(i, j)[2] > r ? img.at<Vec3b>(i, j)[2]: r;
        }
    }
    int midMax = (r + g + b)/3; // среднее максимумов.
    // Преобразование.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            img.at<Vec3b>(i, j)[0] = img.at<Vec3b>(i, j)[0]/b * midMax;
            max = img.at<Vec3b>(i, j)[0] > max ? img.at<Vec3b>(i, j)[0]: max;
            img.at<Vec3b>(i, j)[1] = img.at<Vec3b>(i, j)[1]/g * midMax;
            max = img.at<Vec3b>(i, j)[1] > max ? img.at<Vec3b>(i, j)[1]: max;
            img.at<Vec3b>(i, j)[2] = img.at<Vec3b>(i, j)[2]/r * midMax;
            max = img.at<Vec3b>(i, j)[2] > max ? img.at<Vec3b>(i, j)[2]: max;
        }
    }
    // масштабирование.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = buf[0]/max * 255;
            img.at<Vec3b>(i, j)[1] = buf[1]/max * 255;
            img.at<Vec3b>(i, j)[2] = buf[2]/max * 255;
        }
    }
    imshow("result", img);
    waitKey();
    destroyAllWindows();
    imwrite("/Users/artemsemenov/Desktop/result.jpg", img);
    img.deallocate();
    return 0;
}
