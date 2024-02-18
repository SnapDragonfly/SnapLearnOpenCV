# Simple Background Estimation in Videos Using Opencv-C-Python

## Directory Structure

**All the code files and folders follow the following structure.**

```
.
├── CPP
│   ├── CMakeLists.txt
│   └── remove_video_bg.cpp
├── input
│   ├── 4k_road_traffic_for_object_detection.mp4
│   └── video.mp4
├── Python
│   ├── remove_video_bg.py
│   └── remove_video_bg_save.py
└── README.md
```



## Instructions

### Python

To run the code in Python, please go into the `python` folder and execute the Python scripts in each of the respective sub-folders.

### C++

To run the code in C++, please go into the `cpp` folder, then go into each of the respective sub-folders and follow the steps below:

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/remove_video_bg
```


## Last Run and Tested

Last successful run, Feb 18 2024.