//
//  main.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 10.02.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include <string>
#include <conversionOfLog.hpp>
#include "grayWorld.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // преобразование на основе формулы.
    string filePash = "/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/imac.jpg";
    conversionOfLog col(filePash); // создание объекта.
    col.showCurrantStat(); // вывод результата.
    // преобразование Серый мир.
    string GWFilePash = "/Users/artemsemenov/Documents/projects/xcode/Luminance_conversion/Luminance_conversion/Мать_родина.png"; // путь к тестовому изображению.
    grayWorld GW(GWFilePash); // запуск конструктора класса.
    GW.showCurrantStat(); // вывод результата.

    // построение гистограммы.

    // нормализация гистограммы.
    // построение гистограммы с накоплением.
    for (int i = 1; i < bHist.rows; i++) {
        bHist.at<float>(i) = bHist.at<float>(i-1) + bHist.at<float>(i);
    }
    // равномерное распределение значений.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            img.at<Vec3b>(i, j)[0] = round(bHist.at<float>(img.at<Vec3b>(i, j)[0] * 256));
            max = img.at<Vec3b>(i, j)[0] > max? img.at<Vec3b>(i, j)[0]: max; // поиск максимума для мосштабирования.
            img.at<Vec3b>(i, j)[1] = round(bHist.at<float>(img.at<Vec3b>(i, j)[1] * 256));
            max = img.at<Vec3b>(i, j)[1] > max? img.at<Vec3b>(i, j)[1]: max;
            img.at<Vec3b>(i, j)[2] = round(bHist.at<float>(img.at<Vec3b>(i, j)[2] * 256));
            max = img.at<Vec3b>(i, j)[2] > max? img.at<Vec3b>(i, j)[2]: max;
        }
    }
    // масштабирование.
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = buf[0] * 255  / max;
            img.at<Vec3b>(i, j)[1] = buf[1] * 255 / max;
            img.at<Vec3b>(i, j)[2] = buf[2] * 255  / max;
        }
    }
    imshow("result", img); // вывод преобразованного изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyAllWindows(); // уничтожение всех окон.
    imwrite("/Users/artemsemenov/Desktop/result.jpg", img); // запись на диск.
    img.deallocate(); // освобождение памяти.
    return 0;
}
