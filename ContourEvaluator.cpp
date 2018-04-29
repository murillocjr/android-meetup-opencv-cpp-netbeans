#include "ContourEvaluator.h"

String ContourEvaluator::processMat(Mat frame)
{
    
    int factor = 30;
    resize(frame,frame,cvSize((frame.cols)/factor,(frame.rows)/factor));
    
    cvtColor( frame, frame, CV_BGR2HSV );
    blur( frame, frame, Size(3,3) );
    
    imshow("frame", frame);
    waitKey();
    
    Mat1b mask;
    inRange(frame, Scalar(5, 0, 0), Scalar(40, 255, 255), mask);

    imshow("Mask", mask);
    waitKey();
    
    
    Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  RNG rng(12345);

  int thresh = 200;
  /// Detect edges using canny
  Canny( frame, canny_output, thresh, thresh*2, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
     }

  /// Show in a window
  namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );
    
        waitKey();

    
    
    

    ostringstream os;
    /*
    os<<round(proportion);
    os<<",";
    os<<proportion;
    os<<",";
    os<<red;
    os<<",";
    os<<blue;
    os<<",";
*/
    return os.str();
}

