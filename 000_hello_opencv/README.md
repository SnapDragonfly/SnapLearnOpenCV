# README



## Directory Structure

**All the code files and folders follow the following structure.**

```
|-- CPP
|   |-- CMakeLists.txt
|   |-- hello_opencv.cpp
|   `-- test.jpg
|-- Python
|   |-- hello_opencv.py
|   |-- requirements.txt
|   `-- test.jpg
`-- README.md
```



## Instructions

```
find / -name "OpenCVConfig.cmake"
export OpenCV_DIR=/path/found/above
```

or 
```
SET(OpenCV_DIR <OpenCV_Home_Dir>/installation/OpenCV-master/lib/cmake/opencv4)
```

e.g.

```
$ find /home/daniel/ -name "OpenCVConfig.cmake"
/home/daniel/OpenCV/installation/opencv-4.9.0/lib/cmake/opencv4/
/home/daniel/OpenCV/opencv/build/OpenCVConfig.cmake
/home/daniel/OpenCV/opencv/build/unix-install/OpenCVConfig.cmake


export OpenCV_DIR=/home/daniel/OpenCV/installation/opencv-4.9.0/lib/cmake/opencv4/
```

or 
```
SET(OpenCV_DIR /home/daniel/OpenCV/installation/opencv-4.9.0/lib/cmake/opencv4/)
```

### Python

To run the code in Python, please go into the `Python` folder and execute the Python scripts in each of the respective sub-folders.

### C++

To run the code in C++, please go into the `CPP` folder, then go into each of the respective sub-folders and follow the steps below:

```
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..
./build/hello_opencv
```



# AI Courses by OpenCV

Want to become an expert in AI? [AI Courses by OpenCV](https://opencv.org/courses/) is a great place to start.

[![img](https://camo.githubusercontent.com/18c5719ef10afe9607af3e87e990068c942ae4cba8bd4d72d21950d6213ea97e/68747470733a2f2f7777772e6c6561726e6f70656e63762e636f6d2f77702d636f6e74656e742f75706c6f6164732f323032302f30342f41492d436f75727365732d42792d4f70656e43562d4769746875622e706e67)](https://opencv.org/courses/)

## Last Run and Tested

Last successful run, Feb 5 2024.

