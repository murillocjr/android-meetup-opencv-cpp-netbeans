/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: netmaster
 *
 * Created on April 22, 2018, 8:44 AM
 */

#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "AreaCalculator.h"

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "Hi"<<endl;
    
    Mat colorFrame;
    AreaCalculator areaCalculator;

    colorFrame = imread("/home/oamakas/projects/cpp_projects/area_by_color/1b3r.jpg", CV_LOAD_IMAGE_ANYCOLOR);
    cout << areaCalculator.processMat(colorFrame);

    return 0;
    
    
}

