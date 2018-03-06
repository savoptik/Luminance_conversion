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
#include <cmath>
#include <vector>
using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    auto img = imread("/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/imac.jpg"); // загрузка изображения.
    imshow("test", img); // вывод загруженного изображения для контроля.
    waitKey(); // ожидание нажатия клавиши.
    // перевод изображения к полутоновому.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            int m = (buf[0] + buf[1] + buf[2])/3;
            img.at<Vec3b>(i, j)[0] = m;
            img.at<Vec3b>(i, j)[1] = m;
            img.at<Vec3b>(i, j)[2] = m;
        }
    }
    imshow("semitone", img);
    waitKey();
    // построение гистограммы.
    vector<Mat> vec;
    split(vec, img);
    Mat bHist;
    int histSyse = 256;
    float range[] = {0, 255};
    const float *ranges[] = {range};
    calcHist(&vec[0], 1, 0, Mat(), bHist, 1, &histSyse, ranges);
    // масштабирование.
/*    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = buf[0] * 255  / max;
            img.at<Vec3b>(i, j)[1] = buf[1] * 255 / max;
            img.at<Vec3b>(i, j)[2] = buf[2] * 255  / max;
        }
    } */
    imshow("result", img); // вывод преобразованного изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyAllWindows(); // уничтожение всех окон.
    imwrite("/Users/artemsemenov/Desktop/result.jpg", img); // запись на диск.
    img.deallocate(); // освобождение памяти.
    return 0;
}
