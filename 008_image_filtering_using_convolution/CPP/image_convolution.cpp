// Import dependancies
#include <opencv2/opencv.hpp>
#include <iostream>

// Using namespaces to nullify use of c::function(); syntax and std::function(); syntax
using namespace std;
using namespace cv;

int main()
{
    // Read Image
    Mat image = imread("test.jpg");

    // Print Error message if image is null
    if (image.empty()) 
        {
            cout << "Could not read image" << endl;
        }
    
    // Apply identity filter using kernel
    Mat kernel1 = (Mat_<double>(3,3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);
    Mat identity; 
    filter2D(image, identity, -1 , kernel1, Point(-1, -1), 0, 4);
    imshow("Original", image);
    imshow("Identity", identity);
    waitKey();
    imwrite("identity.jpg", identity);
    destroyAllWindows();

    // Blurred using kernel
    // Initialize matrix with all ones
    Mat kernel2 = Mat::ones(5,5, CV_64F);
    // Normalize the elements
    kernel2 = kernel2 / 25;
    Mat img;
    filter2D(image, img, -1 , kernel2, Point(-1, -1), 0, 4);
    imshow("Original", image);
    imshow("Kernel blur", img);
    imwrite("blur_kernel.jpg", img);
    waitKey();
    destroyAllWindows();

    // Blurred using OpenCV C++ blur() function
    Mat img_blur;
    blur(image, img_blur, Size(5,5));
    imshow("Original", image);
    imshow("Blurred", img_blur); 
    imwrite("blur.jpg", img_blur);
    waitKey();
    destroyAllWindows();
    
    // Performing Gaussian Blur
    Mat gaussian_blur;
    GaussianBlur(image, gaussian_blur, Size(5,5), 0);
    imshow("Original", image);
    imshow("Gaussian Blurred", gaussian_blur);
    imwrite("gaussian_blur.jpg", gaussian_blur);
    waitKey();
    destroyAllWindows();

    // Apply Median Blur
    Mat median_blurred;
    medianBlur(image, median_blurred, (5,5));
    imshow("Original", image);
    imshow("Median Blurred", median_blurred);
    imwrite("median_blur.jpg", median_blurred);
    waitKey();
    destroyAllWindows();

    // Apply Sharpening using kernel
    Mat sharp_img;
    Mat kernel3 = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1 ,0);
    filter2D(image, sharp_img, -1 , kernel3, Point(-1, -1), 0, BORDER_DEFAULT);
    imshow("Original", image);
    imshow("Sharpenned", sharp_img);
    imwrite("sharp_image.jpg", sharp_img);
    waitKey();
    destroyAllWindows();

    // Apply bilateral filtering
    Mat bilateral_filter;
    bilateralFilter(image, bilateral_filter, 9, 75, 75);
    imshow("Original", image);
    imshow("Bilateral filtering", bilateral_filter);
    imwrite("bilateral_filtering.jpg", bilateral_filter);
    waitKey(0);
    destroyAllWindows();
    return 0;
}