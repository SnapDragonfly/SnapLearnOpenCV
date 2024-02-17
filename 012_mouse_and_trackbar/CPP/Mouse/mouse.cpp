// Import packages
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

//Using namespace to nullify use of cv::function(); syntax
using namespace cv;
using namespace std;

// Points to store the center of the circle and a point on the circumference
Point top_left_corner, bottom_right_corner;
// image image
Mat image;

// function which will be called on mouse input
void drawRectangle(int action, int x, int y, int flags, void *userdata)
{
  // Mark the center when left mouse button is pressed
  if( action == EVENT_LBUTTONDOWN )
  {
    top_left_corner = Point(x,y);
  }
  // When left mouse button is released
  else if( action == EVENT_LBUTTONUP)
  {
    bottom_right_corner = Point(x,y);
    // Draw rectangle
    rectangle(image, top_left_corner, bottom_right_corner, Scalar(0,255,0), 2, 8 );
    // Display image
    imshow("Window", image);
  }
  
}

// Main function
int main()
{
  image = imread("../../Input/sample.jpg");
  // Make a temp image, which will be used to clear the image
  Mat temp = image.clone();
  // Create a named window
  namedWindow("Window");
  // highgui function called when mouse events occur
  setMouseCallback("Window", drawRectangle);

  int k=0;
  // loop until q character is pressed
  while(k!=113)
  {
    imshow("Window", image );
    k= waitKey(0);
    // If c is pressed, clear the window, usin the dummy image
    if(k == 99)
    {
    	temp.copyTo(image);
    }
  }
  destroyAllWindows();
  return 0;
}