/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AreaCalculator.cpp
 * Author: netmaster
 * 
 * Created on April 22, 2018, 5:18 PM
 */

#include "AreaCalculator.h"



String AreaCalculator::processMat(Mat frame)
{
    
    ostringstream os;
    os << frame.cols;
    
    return os.str();;
}