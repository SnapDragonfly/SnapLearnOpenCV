# README

## Directory Structure

**All the code files and folders follow the following structure.**

```
├── CPP
│   ├── Mouse
│   │   ├── CMakeLists.txt
│   │   └── mouse.cpp
│   └── Trackbar
│       ├── CMakeLists.txt
│       └── trackbar.cpp
├── Input
│   └── sample.jpg
├── Python
│   ├── mouse.py
│   ├── requirements.txt
│   └── trackbar.py
└── README.md
```



## Instructions

### Python

To run the code in Python, please go into the `python` folder and execute the Python scripts.

### C++

Example, To run the code in C++, please go into the `cpp/mouse` folder, then follow the steps below:
```
$ cd Mouse
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/mouse
```


```
$ cd Trackbar
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/trackbar
```

## Last Run and Tested

Last successful run, Feb 17 2024.