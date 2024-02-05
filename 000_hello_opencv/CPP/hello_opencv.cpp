// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace nullifies the use of cv::function();
using namespace std;
using namespace cv;

int main()
{
	// Read image
	Mat img_color, img_grayscale, img_unchanged;
	img_color = imread("hello_opencv.jpg",1);
	img_grayscale = imread("hello_opencv.jpg",0);
	img_unchanged = imread("hello_opencv.jpg",-1);

	// Print image type and shape
	cout << "Color Image type : " << img_color.type() << endl;
	cout << "Color Image shape : " << img_color.size() << endl;


	//display image
	imshow("color image",img_color);
	imshow("grayscale image",img_grayscale);
	imshow("unchanged image",img_unchanged);

	//Write the image in the same directory
	//We are saving the same image here without making any changes
	//Just to understand how image saving is carried out

	imwrite("grayscale_hello_opencv.jpg",img_grayscale);
	cout << "Hello OpenCV!" << endl;

	// 0 means loop infinitely
	// Press any key to close it

	waitKey(0);
	return 0;
}
