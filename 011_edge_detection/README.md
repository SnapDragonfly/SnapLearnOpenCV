# README



## Directory Structure

**All the code files and folders follow the following structure.**

```
├── CPP
│   ├── CMakeLists.txt
│   ├── edge_detection.cpp
│   └── test.jpg
├── Python
│   ├── edge_detection.py
│   ├── requirements.txt
│   └── test.jpg
└── README.md
```



## Instructions

### Python

To run the code in Python, please go into the `python` folder and execute the Python scripts.

### C++

To run the code in C++, please go into the `cpp` folder, then follow the steps below:

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/edge_detection
```

## Last Run and Tested

Last successful run, Feb 16 2024.