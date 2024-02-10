// Import dependancies
#include <opencv2/opencv.hpp>
#include <iostream>

// Using namespaces to nullify use of c::function(); syntax and std::function(); syntax
using namespace std;
using namespace cv;

int main()
{
    // Read Images
    Mat img = imread("sample.jpg");
    // Display Image
    imshow("Original Image", img);
    waitKey();

    // Print Error message if image is null
    if (img.empty())
        {
            cout << "Could not read image" << endl;
        }
    
    // Draw line on image
    Mat imageLine = img.clone();
    // Draw the image from point  A to B
    Point pointA(200,80);
    Point pointB(450,80);
    line(imageLine, pointA,  pointB, Scalar(255, 255, 0), 3, 8, 0);
    imshow("Lined Image", imageLine);
    waitKey();

    // Draw Circle on image
    Mat imageCircle = img.clone();
    int radius = 100;
    Point circle_center(415,190);
    circle(imageCircle, circle_center, radius, Scalar(0, 0, 255), 3, 8, 0);
    imshow("Circle on Image", imageCircle);
    waitKey();

    // Draw Filled Circle
    Mat Filled_circle_image = img.clone();
    circle(Filled_circle_image, circle_center, radius, Scalar(255, 0, 0), -1, 8, 0);
    imshow("Circle on Image", Filled_circle_image);
    waitKey();

    // Draw Rectangle
    Mat imageRectangle = img.clone();
    Point start_point(300,115);
    Point end_point(475,225);
    rectangle(imageRectangle, start_point, end_point, Scalar(0,0,255), 3, 8, 0);
    imshow("Rectangle on Image", imageRectangle);
    waitKey();

    // Draw Ellipse
    Mat imageEllipse = img.clone();
    // Horizontal
    Point ellipse_center(415,190);
    Point axis1(100, 50);
    Point axis2(125, 50);
    ellipse(imageEllipse, ellipse_center, axis1, 0, 0, 360, Scalar(255, 0, 0), 3, 8, 0);
    // Vertical
    ellipse(imageEllipse, ellipse_center, axis2, 90, 0, 360, Scalar(0, 0, 255), 3, 8, 0);
    imshow("Ellipses on Image", imageEllipse);
    waitKey();


    Mat halfEllipse = img.clone();
    // Half Ellipse
    ellipse(halfEllipse, ellipse_center, axis1, 0, 180, 360, Scalar(255, 0, 0), 3, 8, 0);
    // Filled ellipse
    ellipse(halfEllipse, ellipse_center, axis1, 0, 0, 180, Scalar(0, 0, 255), -2, 8, 0);
    imshow("halfEllipse", halfEllipse);
    waitKey();


    // Put Text on Image
    Mat imageText = img.clone();
    // org: Where you want to put the text
    Point org(50,350);
    putText(imageText, "I am a Happy dog!", org, FONT_HERSHEY_COMPLEX, 1.5, Scalar(0,255,0), 3, 8, false);
    imshow("Text on Image", imageText);
    waitKey(0);

    
    destroyAllWindows();
    return 0;
}
