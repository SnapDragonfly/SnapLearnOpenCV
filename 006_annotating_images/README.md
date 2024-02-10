# README



## Directory Structure

**All the code files and folders follow the following structure.**

```
├── CPP
│   ├── CMakeLists.txt
│   ├── image_annotation.cpp
│   └── sample.jpg
├── Python
│   ├── image_annotation.py
│   ├── requirements.txt
│   └── sample.jpg
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
$ ./build/image_annotation
```

## Last Run and Tested

Last successful run, Feb 10 2024.