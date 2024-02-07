// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>  

// Namespace nullifies the use of cv::function();
using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("test_cropped.jpg");
    Mat image_copy = img.clone();
    cout << img.size << endl;
    
    int imgheight = img.rows;
    int imgwidth = img.cols;

    int M = 76;
    int N = 104;

    int x1 = 0;
    int y1 = 0;
    for (int y = 0; y<imgheight; y=y+M)
    {
        for (int x = 0; x<imgwidth; x=x+N)
        {
            if ((imgheight - y) < M || (imgwidth - x) < N)
            {
                break;
            }
            y1 = y + M;
            x1 = x + N;
            string a = to_string(x);
            string b = to_string(y);

            if (x1 >= imgwidth && y1 >= imgheight)
            {
                x = imgwidth - 1;
                y = imgheight - 1;
                x1 = imgwidth - 1;
                y1 = imgheight - 1;

                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, imgheight), Range(x, imgwidth));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);    
            }
            else if (y1 >= imgheight)
            {
                y = imgheight - 1;
                y1 = imgheight - 1;

                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, imgheight), Range(x, x+N));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);    
            }
            else if (x1 >= imgwidth)
            {
                x = imgwidth - 1;   
                x1 = imgwidth - 1;

                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, y+M), Range(x, imgwidth));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);    
            }
            else
            {
                // crop the patches of size MxN
                Mat tiles = image_copy(Range(y, y+M), Range(x, x+N));
                //save each patches into file directory
                imwrite("saved_patches/tile" + a + '_' + b + ".jpg", tiles);  
                rectangle(img, Point(x,y), Point(x1,y1), Scalar(0,255,0), 1);    
            }
        }
    }
    imshow("Patched Image", img);
    imwrite("patched.jpg",img);
    waitKey();
    destroyAllWindows();

    return 0;
}