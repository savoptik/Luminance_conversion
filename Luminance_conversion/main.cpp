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
using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    auto img = imread("/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/апельсин.png"); // загрузка изображения.
    imshow("test", img); // отображение загруженного изображения для контроля.
    waitKey(); // ожидание нажатия клавиши.
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
    // масштабирование.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = buf[0] * 255 / max;
            img.at<Vec3b>(i, j)[1] = buf[1] * 255 / max;
            img.at<Vec3b>(i, j)[2] = buf[2] * 255 / max;
        }
    }
    imshow("result", img); // вывод результата.
    waitKey(); // ожидание нажатия клавиши.
    destroyAllWindows(); // уничтожение всех окон.
    imwrite("/Users/artemsemenov/Desktop/result.png", img); // запись результата на диск.
    img.deallocate(); // освобождение памяти.
    return 0;
}
