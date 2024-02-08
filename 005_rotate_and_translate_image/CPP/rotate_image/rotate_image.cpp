#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main(int, char**) 
{
    Mat image = imread("image.jpg");
	double angle = 45;

	// get the center coordinates of the image to create the 2D rotation matrix
	Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
	// create the rotation matrix using the image center
	Mat rotation_matix = getRotationMatrix2D(center, angle, 1.0);

	// we will save the resulting image in rotated_image matrix
	Mat rotated_image;
	// apply affine transformation to the original image using the 2D rotaiton matrix
	warpAffine(image, rotated_image, rotation_matix, image.size());
	imshow("Original image", image);
	imshow("Rotated image", rotated_image);
	waitKey(0);
	// save the rotated image to disk
	imwrite("rotated_im.jpg", rotated_image);

	return 0;
}
