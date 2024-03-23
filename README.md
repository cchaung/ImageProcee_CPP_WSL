# ImageProcee_CPP_WSL
This is a practice to use the openCV with C/C++in WSL2 platform.

## Setting OpenCV and print the image
ref: [Using OpenCV C++ on Windows Subsystem for Linux (WSL)](https://jingmengzhiyue.top/2024/03/16/OpenCV-WSL/)

### 1. Update and Install Dependencies
Launch your Linux distribution and use the following commands to update your package manager and install the required dependencies for compiling OpenCV:
```bash=
sudo apt-get install build-essential libgtk2.0-dev libgtk-3-dev libavcodec-dev libavformat-dev libjpeg-dev libswscale-dev libtiff5-dev
```

### 2. Download OpenCV and OpenCV Contrib Source Code
Download the OpenCV and OpenCV Contrib source code from the OpenCV GitHub repository:
```bash
mkdir ~/opencv_build && cd ~/opencv_build
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```

Ensure both repositories are on the same version:
```bash
cd ~/opencv_build/opencv
git checkout 4.x
cd ../opencv_contrib
git checkout 4.x
```

### 3. Compile and Install OpenCV:
```bash
cd ~/opencv_build/opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D INSTALL_C_EXAMPLES=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D OPENCV_GENERATE_PKGCONFIG=ON \
-D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
-D BUILD_EXAMPLES=ON ..
make -j$(nproc)
sudo make install
```

### 4. Configure Environment Variables : 
To ensure the compiler can find the OpenCV libraries, you need to update the LD_LIBRARY_PATHenvironment variable. Add the following line to `your~/.bashrc` or `~/.profilefile`:


### 5. 將opencv2的資料夾連結到include資料夾下
```bash
sudo ln -s /usr/include/opencv4/opencv2 /usr/include
```


### 6. 編寫Makefile
需要將以下文件添加到連結庫中:
* -lopencv_core 
* -lopencv_highgui 
* -lopencv_imgproc 
* -lopencv_imgcodecs 

> **Warning!!** 在一般網路上的寫法不包含 "-lopencv_imgcodecs"，但在編譯後會出現
'undefined reference to cv::imread(std::__cxx11::basic_string… 对‘cv::imread(std::__cxx11::basic_string<char, std::char_traits, std::allocator > const&, int)'的錯誤
(ref: [编译连接imread报错undefined reference to cv::imread(std::__cxx11::basic_string](https://www.jianshu.com/p/2e79ef1b0471))

```makefile
main: main.cpp
	g++ main.cpp -o main -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs


clean:
	rm -rf main
```

### 7. 執行main
```bash
./main
```
