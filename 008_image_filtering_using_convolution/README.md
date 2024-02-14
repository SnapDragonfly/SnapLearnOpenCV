# README



## Directory Structure

**All the code files and folders follow the following structure.**

```
├── cpp
│   ├── CMakeLists.txt
│   ├── image_convolution.cpp
│   └── test.jpg
├── python
│   ├── image_convolution.py
│   ├── Image_Convolutions.ipynb
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
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..
./build/convolution
```

## Last Run and Tested

Last successful run, Feb 14 2024.