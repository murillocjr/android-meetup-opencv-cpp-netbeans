/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContourEvaluator.h
 * Author: netmaster
 *
 * Created on April 28, 2018, 9:37 PM
 */

#ifndef CONTOUREVALUATOR_H
#define CONTOUREVALUATOR_H

#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


class ContourEvaluator {
public:
    String processMat(Mat frame);

};

#endif /* CONTOUREVALUATOR_H */

