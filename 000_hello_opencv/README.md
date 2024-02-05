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
$ find / -name "OpenCVConfig.cmake"
$ export OpenCV_DIR=/path/found/above
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


$ export OpenCV_DIR=/home/daniel/OpenCV/installation/opencv-4.9.0/lib/cmake/opencv4/
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
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/hello_opencv
```

## Last Run and Tested

Last successful run, Feb 5 2024.

