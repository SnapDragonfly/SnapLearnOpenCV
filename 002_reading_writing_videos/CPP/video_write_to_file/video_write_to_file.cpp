// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main()
{
    // initialize a video capture object
	VideoCapture vid_capture("Resources/Cars.mp4");

    // Acquire frame width and height with the help of get() method
    // You can replace 3 and 4 with CAP_PROP_FRAME_WIDTH and CAP_PROP_FRAME_HEIGHT
    // They are just enumerations
	int frame_width = static_cast<int>(vid_capture.get(3));
	int frame_height = static_cast<int>(vid_capture.get(4));

    //define frame_size to be used in VideoWriter() argument
	Size frame_size(frame_width, frame_height);
	int fps = 20;

    // Initialize video writer object
	VideoWriter output("Resources/output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, frame_size);
	
    while (vid_capture.isOpened())
    {
        // Initialize frame matrix to store frames
        Mat frame;

        // Initialize a boolean to check if the frames are present or not
        bool isSuccess = vid_capture.read(frame);

        // If frames are not there, close it
        if (isSuccess == false)
        {
            cout << "Video camera is disconnected" << endl;
            break;
        }
        // If frames are present
        if(isSuccess == true)
        {
            //display frames
            output.write(frame);
            // display frames
            imshow("Frame", frame);

            // wait for 20 ms between successive frames and break the loop if key q is pressed
            int key = waitKey(20);
            if (key == 'q')
            {
                cout << "Key q is pressed by the user. Stopping the video" << endl;
                break;
            }
        }
    }
   destroyAllWindows();
   vid_capture.release();
   output.release();
   return 0;
}