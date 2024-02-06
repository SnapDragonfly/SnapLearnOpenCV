// Include Libraries
// We are not using matplotlib here instead we will make use of opencv HiGUI

#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("image.jpg");
	// Get height and width
	cout << "Original Height and Width :" << image.rows << "x" << image.cols << endl;
	waitKey();
	imshow("Original Image", image);
	waitKey();

			// ..........METHOD 1.......... 

	// let's downscale the image using new  width and height
	int down_width = 300;
	int down_height = 200;
	Mat resized_down;
	//resize down
	resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
	// let's upscale the image using new  width and height
	int up_width = 600;
	int up_height = 400;
	Mat resized_up;
	//resize up
	resize(image, resized_up, Size(up_width, up_height), INTER_LINEAR);
	// Display Images and press any key to continue
	imshow("Resized Down by defining height and width", resized_down);
	waitKey();
	imshow("Resized Up image by defining height and width", resized_up);
	waitKey();

			// ..........METHOD 2.......... 

	// Scaling Down the image 1.2 times by specifying both scaling factors
	double scale_up_x = 1.2;
	double scale_up_y = 1.2;
	// Scaling Down the image 0.6 times specifying a single scale factor.
	double scale_down = 0.5;
	Mat scaled_f_up, scaled_f_down;
	//resize 
	resize(image,scaled_f_down, Size(), scale_down, scale_down, INTER_LINEAR);
	resize(image, scaled_f_up, Size(), scale_up_x, scale_up_y, INTER_LINEAR);
	// display images and Press any key to continue
	imshow("Resized Down by defining scaling factor", scaled_f_down);
	waitKey();
	imshow("Resized Up by defining scaling factor", scaled_f_up);
	waitKey();

			  // ..........METHOD 3.......... 
		  // resizing with different interpolation 

	Mat res_inter_linear, res_inter_nearest, res_inter_area;
	resize(image, res_inter_linear, Size(), scale_down, scale_down, INTER_LINEAR);
	resize(image, res_inter_nearest, Size(), scale_down, scale_down, INTER_NEAREST);
	resize(image, res_inter_area, Size(), scale_down, scale_down, INTER_AREA);

	
	// Let's save the rest of the images resized with different interpolation
	// Concatenate images in vertical axis for comparison
	// a , b and c are to store matrices for concatenation
	// We are joining inter area twice just for the convenience of concatenation
	
	Mat a,b,c;
	vconcat(res_inter_linear, res_inter_nearest, a);
	vconcat(res_inter_area, res_inter_area, b);
	vconcat(a, b, c);
	// Display the image and press any key to continue
	imshow("Inter Linear :: Inter Nearest :: Inter Area :: Inter Area", c);


	//Let's save the images
	imwrite("resized_up_image.jpg", resized_up);
	imwrite("resized_down_image.jpg", resized_down);
	imwrite("scaled_down.jpg", scaled_f_down);
	imwrite("scaled_up.jpg", scaled_f_up);
	imwrite("Comparison_Image.jpg", c);
	
	// 0 means loop the window infinitely 
	waitKey(0);
	destroyAllWindows();
	return 0;
}
