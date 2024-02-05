# README

## Directory Structure

**All the code files and folders follow the following structure.**

```
│   README.md
│
├───CPP
│   ├───video_read_from_file
│   │   │   CMakeLists.txt
│   │   │   video_read_from_file.cpp
│   │   │
│   │   └───Resources
│   │           Cars.mp4
│   │
│   ├───video_read_from_image_sequence
│   │   │   CMakeLists.txt
│   │   │   video_read_from_image_sequence.cpp
│   │   │
│   │   └───Resources
│   │       └───Image_Sequence
│   │
│   ├───video_read_from_webcam
│   │       CMakeLists.txt
│   │       video_read_from_webcam.cpp
│   │
│   ├───video_write_from_webcam
│   │       CMakeLists.txt
│   │       video_write_from_webcam.cpp
│   │
│   └───video_write_to_file
│       │   CMakeLists.txt
│       │   video_write_to_file.cpp
│       │
│       └───Resources
│               Cars.mp4
│
└───Python
    │   video_read_from_file.py
    │   video_read_from_image_sequence.py
    │   video_read_from_webcam.py
    │   video_write_from_webcam.py
    │   video_write_to_file.py
    │   requirements.txt
    │
    └───Resources
        │   Cars.mp4
        │
        └───Image_sequence
                
```



## Instructions

### Python

To run the code in Python, please go into the `Python` folder and execute the Python scripts in each of the respective sub-folders.

### C++

To run the code in C++, please go into the `CPP` folder, then go into each of the respective sub-folders and follow the steps below:

```
$ cd video_read_from_file
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/video_read_from_file
```

```
$ cd video_read_from_image_sequence
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/video_read_is
```

```
$ cd video_read_from_webcam
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/video_read_from_webcam
```

```
$ cd video_write_from_webcam
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/video_write_from_webcam
```

```
$ cd video_write_to_file
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cd ..
$ ./build/video_write_to_file
```

## Last Run and Tested

Last successful run, Feb 5 2024.