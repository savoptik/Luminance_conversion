//
//  luminanceConversion.cpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 16.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "luminanceConversion.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void luminanceConversion::conversionToGray() {
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            auto buf = image.at<Vec3b>(i, j);
            int m = (buf[0] + buf[1] + buf[2])/3;
            image.at<Vec3b>(i, j)[0] = m;
            image.at<Vec3b>(i, j)[1] = m;
            image.at<Vec3b>(i, j)[2] = m;
        }
    }
}

cv::Mat &luminanceConversion::returnMat() {
    return image; // возврат объекта.
}

void luminanceConversion::scalingChanges() { 
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            auto buf = image.at<Vec3b>(i, j);
            image.at<Vec3b>(i, j)[0] = buf[0] * 255 / max;
            image.at<Vec3b>(i, j)[1] = buf[1] * 255 / max;
            image.at<Vec3b>(i, j)[2] = buf[2] * 255 / max;
        }
    }
}
