# Contour Detection using OpenCV



## Directory Structure

**All the code files and folders follow the following structure.**

```
├── CPP
│   ├── channel_experiments
│   │   ├── CMakeLists.txt
│   │   └── channel_experiments.cpp
│   ├── contour_approximations
│   │   ├── CMakeLists.txt
│   │   └── contour_approx.cpp
│   └── contour_extraction
│       ├── CMakeLists.txt
│       └── contour_extraction.cpp
├── input
│   ├── custom_colors.jpg
│   ├── image_1.jpg
│   └── image_2.jpg
├── python
│   ├── channel_experiments
│   │   └── channel_experiments.py
│   ├── contour_approximations
│   │   └── contour_approx.py
│   └── contour_extraction
│       └── contour_extraction.py
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
$ ./build/channel_experiments
```

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/contour_approximations
```

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/contour_extraction
```



## Last Run and Tested

Last successful run, Feb 17 2024.
