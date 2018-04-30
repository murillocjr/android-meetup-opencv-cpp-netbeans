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
#include "SobelEdges.h"


/*
 * 
 */
int main(int argc, char** argv) {

    SobelEdges sobelEdges;
    
    
    VideoCapture cap;
    
    cap.open(1);

    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480); 

    
    for(;;)
    {
        Mat frame;
        if(!cap.isOpened()) continue;
        cap.read(frame); // get a new frame from camera
        if (frame.empty()) continue;
        
        sobelEdges.processMat(frame);
        
       if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
    
    
}

