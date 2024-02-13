
# README



## Directory Structure

**All the code files and folders follow the following structure.**

```
.
├── CPP
│   ├── CMakeLists.txt
│   ├── interactive_color_detect.cpp
│   ├── interactive_color_segment.cpp
│   ├── images
│   └── pieces
├── Python
│   ├── data_analysis.py
│   ├── interactive_color_detect.py
│   ├── interactive_color_segment.py
│   ├── images
│   └── pieces
└── README.md

```

## Instructions

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
$ ./build/interactive_color_detect
$ ./build/interactive_color_segment
```

## Last Run and Tested

Last successful run, Feb 13 2024.
