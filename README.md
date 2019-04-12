# at1
Data Analyst Library

# libs
## opencv on ubuntu14
sudo apt-get install build-essential
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
sudo apt-get install libxvidcore-dev libx264-dev
sudo apt-get install libv4l-dev
cd /opt/
sudo git clone https://github.com/opencv/opencv.git
sudo git clone https://github.com/opencv/opencv_contrib.git
cd opencv
sudo mkdir release
cd release
sudo cmake -D CMAKE_INSTALL_PREFIX=/usr/local -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules -D WITH_LIBV4L=ON -D WITH_V4L=OFF -D BUILD_EXAMPLES=ON /opt/opencv/
sudo make
sudo make install
pkg-config --modversion opencv # check version installed
