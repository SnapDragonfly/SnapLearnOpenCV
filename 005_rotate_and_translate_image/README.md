# README



## Directory Structure

**All the code files and folders follow the following structure.**

```
├── CPP
│   ├── rotate_image
│   │   ├── CMakeLists.txt
│   │   ├── image.jpg
│   │   ├── rotated_im.jpg
│   │   └── rotate_image.cpp
│   └── translate_image
│       ├── CMakeLists.txt
│       ├── image.jpg
│       ├── translated_image.jpg
│       └── translate_image.cpp
├── Python
│   ├── image.jpg
│   ├── image_translation.py
│   ├── requirements.txt
│   ├── rotated_image.jpg
│   ├── rotate_image.py
│   └── translated_image.jpg
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
$ ./build/rotate_image

$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/translate_image
```


## Last Run and Tested

Last successful run, Feb 8 2024.

