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
            img.at<Vec3b>(i, j)[0] = buf[0]<1 ? 0: static_cast<uchar>(log(2)/log(static_cast<double>(buf[0])));
            img.at<Vec3b>(i, j)[1] = buf[1]<1 ? 0: static_cast<uchar>(log(2)/log(static_cast<double>(buf[1])));
            img.at<Vec3b>(i, j)[2] = buf[2]<1 ? 0: static_cast<uchar>(log(2)/log(static_cast<double>(buf[2])));
        }
    }
    imshow("result", img);
    waitKey();
    destroyAllWindows();
    return 0;
}
