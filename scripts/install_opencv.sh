#!/bin/bash

### Define OpenCV Version to install 
cvVersion="4.9.0"

#git config --global https.proxy http://192.168.1.13:808
#export https_proxy=http://192.168.1.13:808

################################################################################
### Functions
################################################################################

STEP_0 ()
{
	################################################################################
	### STEP 0 Environment
	################################################################################
	set -e # exit on first error
	
	### Save current working directory
	SNAPDRAGONFLY_CURRENT_DIR_PATH=$(pwd)

	SNAPDRAGONFLY_CURRENT_OPENCV=opencv
	SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB=opencv_contrib

	SNAPDRAGONFLY_CURRENT_OPENCV_ZIP=opencv-$cvVersion.zip
	SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB_ZIP=opencv_contrib-$cvVersion.zip
	
	### Echo environment
	sudo lsb_release -a
	echo "OpenCV/Python/C/C++ installation by SnapDragonfly.com"
	echo "Current dir path: $SNAPDRAGONFLY_CURRENT_DIR_PATH"
	echo "Current opencv: $SNAPDRAGONFLY_CURRENT_OPENCV_ZIP"
	echo "Current opencv_contrib: $SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB_ZIP"
	
	if [[ $STEP -gt 0 && $STEP -le 4 ]]
	then
		echo "STEP $STEP ..."
	else
		echo "Install OpenCV ..."
	fi
}

STEP_1 ()
{
	################################################################################
	### STEP 1 System upgrade
	################################################################################
	echo "STEP 1: System upgrade"
	#sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu xenial-security main" -y
	sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu jammy-security main" -y
	sudo apt -y update
	sudo apt -y upgrade
	
	### Install dependencies
	sudo apt -y install unzip locate 
	sudo apt -y install build-essential checkinstall cmake pkg-config yasm
	sudo apt -y install git gfortran
	sudo apt -y install libjpeg8-dev libpng-dev libjpeg-dev libgtk-3-dev 
	sudo apt -y install software-properties-common
	#sudo apt -y install libjasper1
	sudo apt -y install libtiff-dev
	sudo apt -y install libavcodec-dev libavformat-dev libswscale-dev libdc1394-dev
	sudo apt -y install libxine2-dev
	sudo apt -y install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev
	sudo apt -y install libgtk2.0-dev libtbb-dev libtbb2
	sudo apt -y install openexr libopenexr-dev python3-numpy
	
	### qt5-default dependencies
	sudo apt -y install libatlas-base-dev
	sudo apt -y install libfaac-dev libmp3lame-dev libtheora-dev
	sudo apt -y install libvorbis-dev libxvidcore-dev
	sudo apt -y install libopencore-amrnb-dev libopencore-amrwb-dev libavro-dev
	#sudo apt -y install libavresample-dev
	sudo apt -y install x264 libx264-dev v4l-utils
	sudo apt -y install qtcreator qtbase5-dev qt5-qmake cmake
	
	### Optional dependencies
	sudo apt -y install libprotobuf-dev protobuf-compiler
	sudo apt -y install libgoogle-glog-dev libgflags-dev
	sudo apt -y install libgphoto2-dev libeigen3-dev libhdf5-dev doxygen

	### Special dependencies
	sudo apt -y install libv4l-dev
	cd /usr/include/linux
	sudo ln -s -f ../libv4l1-videodev.h videodev.h
	cd "$SNAPDRAGONFLY_CURRENT_DIR_PATH"
}

STEP_2 ()
{
	################################################################################
	### STEP 2 Python Virtual Environment
	################################################################################
	echo "STEP 2: Python Virtual Environment"
	
	cd $SNAPDRAGONFLY_CURRENT_DIR_PATH
	sudo apt -y install python3-dev python3-pip
	sudo apt -y install python3-testresources
	sudo apt -y install python3.10-venv

	### create virtual environment
	python3 -m venv opencv-"$cvVersion"-py3
	echo "# Virtual Environment Wrapper" >> ~/.bashrc
	echo "alias workoncv-$cvVersion=\"source $SNAPDRAGONFLY_CURRENT_DIR_PATH/opencv-$cvVersion-py3/bin/activate\"" >> ~/.bashrc
	
	### enter virtual environment
	source "$SNAPDRAGONFLY_CURRENT_DIR_PATH"/opencv-"$cvVersion"-py3/bin/activate
	
	### install python libraries within this virtual environment
	pip install -r requirements.txt
	
	### quit virtual environment
	deactivate
	
	cat ~/.bashrc | tail -n 2
}

STEP_3 ()
{
	################################################################################
	### STEP 3 OpenCV Installation
	################################################################################
	echo "STEP 3: OpenCV Installation"
	cd "$SNAPDRAGONFLY_CURRENT_DIR_PATH"

	if ! test -f $SNAPDRAGONFLY_CURRENT_OPENCV_ZIP; then
		# https://github.com/opencv/opencv.git
		wget https://github.com/opencv/opencv/archive/refs/tags/$cvVersion.zip
		mv $cvVersion.zip $SNAPDRAGONFLY_CURRENT_OPENCV_ZIP
		#unzip $SNAPDRAGONFLY_CURRENT_OPENCV_ZIP
		#mv opencv-$cvVersion opencv
	fi
	
	if ! test -f $SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB_ZIP; then
		# https://github.com/opencv/opencv_contrib.git
		wget https://github.com/opencv/opencv_contrib/archive/refs/tags/$cvVersion.zip
		mv $cvVersion.zip $SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB_ZIP
		#unzip $SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB_ZIP
		#mv opencv_contrib-$cvVersion opencv_contrib
	fi

	if ! test -d $SNAPDRAGONFLY_CURRENT_OPENCV; then
		unzip $SNAPDRAGONFLY_CURRENT_OPENCV_ZIP
		mv opencv-$cvVersion opencv
		mkdir -p opencv/build
	fi
	
	if ! test -d $SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB; then
		unzip $SNAPDRAGONFLY_CURRENT_OPENCV_CONTRIB_ZIP
		mv opencv_contrib-$cvVersion opencv_contrib
		mkdir -p opencv_contrib/build
	fi

	if ! test -d $SNAPDRAGONFLY_CURRENT_DIR_PATH/installation; then
		### Create directory for installation
		mkdir installation
		mkdir installation/opencv-"$cvVersion"
	fi
	
	### configure opencv
	cd opencv
	cd build
	
	if ! test -f $SNAPDRAGONFLY_CURRENT_OPENCV/build/Makefile; then
		echo "STEP 3.1: Configure OpenCV ..."
		cmake -D CMAKE_BUILD_TYPE=RELEASE \
			-D WITH_TBB=ON \
			-D BUILD_TBB=OFF \
			-D WITH_V4L=ON \
			-D WITH_QT=ON \
			-D WITH_OPENGL=ON \
			-D OPENCV_GENERATE_PKGCONFIG=ON \
			-D INSTALL_PYTHON_EXAMPLES=ON \
			-D INSTALL_C_EXAMPLES=ON \
			-D CMAKE_INSTALL_PREFIX=$SNAPDRAGONFLY_CURRENT_DIR_PATH/installation/opencv-"$cvVersion" \
			-D OPENCV_PYTHON3_INSTALL_PATH=$SNAPDRAGONFLY_CURRENT_DIR_PATH/opencv-$cvVersion-py3/lib/python3.10/site-packages \
			-D OPENCV_ENABLE_NONFREE=ON \
			-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
			-D PYTHON_EXECUTABLE=../../opencv-$cvVersion-py3/bin/python3 \
			-D BUILD_EXAMPLES=ON ..
	else
		echo "STEP 3.1: Skip Configure OpenCV!!!"
	fi	
	
	#cmake -D CMAKE_BUILD_TYPE=RELEASE \
	#            -D CMAKE_INSTALL_PREFIX=$SNAPDRAGONFLY_CURRENT_DIR_PATH/installation/opencv-"$cvVersion" \
	#            -D INSTALL_C_EXAMPLES=ON \
	#            -D INSTALL_PYTHON_EXAMPLES=ON \
	#            -D WITH_TBB=ON \
	#            -D BUILD_TBB=OFF \
	#            -D WITH_V4L=ON \
	#            -D OPENCV_PYTHON3_INSTALL_PATH=$SNAPDRAGONFLY_CURRENT_DIR_PATH/opencv-$cvVersion-py3/lib/python3.6/site-packages \
	#        -D WITH_QT=ON \
	#        -D WITH_OPENGL=ON \
	#        -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
	#        -D BUILD_EXAMPLES=ON ..
	
	#cmake -D CMAKE_BUILD_TYPE=RELEASE \
	#	-D CMAKE_INSTALL_PREFIX=$SNAPDRAGONFLY_CURRENT_DIR_PATH/installation/opencv-"$cvVersion" \
	#	-D INSTALL_PYTHON_EXAMPLES=ON \
	#	-D INSTALL_C_EXAMPLES=OFF \
	#	-D OPENCV_PYTHON3_INSTALL_PATH=$SNAPDRAGONFLY_CURRENT_DIR_PATH/opencv-$cvVersion-py3/lib/python3.6/site-packages \
	#	-D OPENCV_ENABLE_NONFREE=ON \
	#	-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
	#	-D PYTHON_EXECUTABLE=../../opencv-$cvVersion-py3/bin/python3 \
	#	-D BUILD_EXAMPLES=ON ..
	
	### build opencv
	echo "STEP 3.2: Build OpenCV ..."
	make -j$(nproc)
	
	### install opencv
	echo "STEP 3.2: Install OpenCV ..."
	make install
	
	cd "$SNAPDRAGONFLY_CURRENT_DIR_PATH"
	cp $SNAPDRAGONFLY_CURRENT_OPENCV/build/lib/python3/cv2.cpython-310-x86_64-linux-gnu.so $OPENCV_PYTHON3_INSTALL_PATH/cv2/cv2.so
}

STEP_4 ()
{
	### Check opencv
	pkg-config --modversion opencv4
	python3 -c "import cv2; print(cv2.__version__)"
}

STEP=$1
STEP_0

read -p "Press Enter to continue"

case $1 in
	1) { STEP_1 ; } ;;
	2) { STEP_2 ; } ;;
	3) { STEP_3 ; } ;;
	4) { STEP_4 ; } ;;
    *) { STEP_1 ; STEP_2 ; STEP_3 ; STEP_4 ; } ;;
esac

