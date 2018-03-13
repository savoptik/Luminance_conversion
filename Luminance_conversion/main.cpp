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
    auto img = imread("/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/апельсин.png"); // загрузка изображения.
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
    cout << "test 1" << endl;
    vector<Mat> vec; // вектор для разделения изображения.
    split(img, vec); // разделения изображения на 3 матрицы.
    Mat bHist; // матрица для гистограммы синего цвета.
    int histSyse = 256; // количество столбиков гистограммы.
    float range[] = {0, 256}; // высота столбиков.
    const float *ranges[] = {range}; // высота столбиков ДЛЯ ОДНОЙ ГИСТОГРАММЫ
    calcHist(&vec[0], 1, 0, Mat(), bHist, 1, &histSyse, ranges); // построение гистограммы.
    cout << "test 2" << endl;
    // нормализация гистограммы.
    for (int i = 0; i < bHist.rows; i++) {
        bHist.at<float>(i) = bHist.at<float>(i) / (img.rows * img.cols);
    }
    cout << "test 3" << endl;
    // построение гистограммы с накоплением.
    for (int i = 1; i < bHist.rows; i++) {
        bHist.at<float>(i) = bHist.at<float>(i-1) + bHist.at<float>(i);
    }
    cout << "test 4" << endl;
    // равномерное распределение значений.
    int max = 0;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            img.at<Vec3b>(i, j)[0] = round(bHist.at<float>(img.at<Vec3b>(i, j)[0]) * 255);
            max = img.at<Vec3b>(i, j)[0] > max? img.at<Vec3b>(i, j)[0]: max; // поиск максимума для мосштабирования.
            img.at<Vec3b>(i, j)[1] = round(bHist.at<float>(img.at<Vec3b>(i, j)[1]) * 255);
            max = img.at<Vec3b>(i, j)[1] > max? img.at<Vec3b>(i, j)[1]: max;
            img.at<Vec3b>(i, j)[2] = round(bHist.at<float>(img.at<Vec3b>(i, j)[2]) * 255);
            max = img.at<Vec3b>(i, j)[2] > max? img.at<Vec3b>(i, j)[2]: max;
        }
    }
    cout << "test 5" << endl;
    imshow("the result without scaling", img);
    waitKey();
    cout << "test 6" << endl;
    // масштабирование.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = buf[0] * 255  / max;
            img.at<Vec3b>(i, j)[1] = buf[1] * 255 / max;
            img.at<Vec3b>(i, j)[2] = buf[2] * 255 / max;
        }
    }
    cout << "test 7" << endl;
    imshow("result", img); // вывод преобразованного изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyAllWindows(); // уничтожение всех окон.
    imwrite("/Users/artemsemenov/Desktop/result.jpg", img); // запись на диск.
    img.deallocate(); // освобождение памяти.
    return 0;
}
