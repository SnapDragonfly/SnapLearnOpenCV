# README



## Directory Structure

**All the code files and folders follow the following structure.**

```
├── CPP
│   ├── Patching
│   │   ├── CMakeLists.txt
│   │   ├── patched.jpg
│   │   ├── patching.cpp
│   │   └── test_cropped.jpg
│   ├── CMakeLists.txt
│   ├── image_crop.cpp
│   └── test.jpg
├── Python
│   ├── Cropped Image.jpg
│   ├── image_crop.py
│   ├── patching.py
│   ├── requirements.txt
│   └── test.jpg
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
$ ./build/image_crop

$ cd Patching
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/image_patch
```

## Last Run and Tested

Last successful run, Feb 7 2024.