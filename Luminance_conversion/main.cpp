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
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            int m = (buf[0] + buf[1] + buf[2])/3;
            img.at<Vec3b>(i, j)[0] = m;
            img.at<Vec3b>(i, j)[1] = m;
            img.at<Vec3b>(i, j)[2] = m;
        }
    }
    imshow("result 1", img);
    waitKey();
    int max = 0;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = static_cast<uchar>(log(static_cast<double>(buf[0]))/log(2));
            max = img.at<Vec3b>(i, j)[0] > max ? img.at<Vec3b>(i, j)[0]: max;
            img.at<Vec3b>(i, j)[1] = static_cast<uchar>(log(static_cast<double>(buf[1]))/log(2));
            max = img.at<Vec3b>(i, j)[1] > max ? img.at<Vec3b>(i, j)[1]: max;
            img.at<Vec3b>(i, j)[2] = static_cast<uchar>(log(static_cast<double>(buf[2]))/log(2));
            max = img.at<Vec3b>(i, j)[2] > max ? img.at<Vec3b>(i, j)[2]: max;
        }
    }
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            auto buf = img.at<Vec3b>(i, j);
            img.at<Vec3b>(i, j)[0] = buf[0]/max * 255;
            img.at<Vec3b>(i, j)[1] = buf[1]/max * 255;
            img.at<Vec3b>(i, j)[2] = buf[2]/max * 255;
        }
    }
    imshow("result 2", img);
    waitKey();
    destroyAllWindows();
    return 0;
}
