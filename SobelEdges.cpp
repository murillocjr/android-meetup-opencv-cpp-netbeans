//https://codezone4.wordpress.com/2013/04/02/edge-detection-with-opencv/
#include "SobelEdges.h"

void SobelEdges::processMat(Mat mRgb)
{
    
Mat  src_gray;
    Mat grad;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    GaussianBlur( mRgb, mRgb, Size(3,3), 0, 0, BORDER_DEFAULT );
    cvtColor( mRgb, src_gray, COLOR_BGR2GRAY );
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );
    convertScaleAbs( grad_y, abs_grad_y );
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

    mRgb=grad;
    
    
     namedWindow("edges",1);
     imshow("edges", mRgb);
        //
}

