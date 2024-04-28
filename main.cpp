#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    cout << "start\n";
    // Read an image
    Mat src = imread("img/Beauty.jpg");
    if (src.empty()) {
        printf("could not open");
        return -1;
    }
    namedWindow("input", WINDOW_NORMAL); // Create a window with the given title and automatic image size
    // In OpenCV 3, use namedWindow("input", CV_WINDOW_AUTOSIZE)

    resizeWindow("input", src.cols/2, src.rows/2); // Resize the window to match the image size
    imshow("input", src); // Display the image in the "input" window
    waitKey(0); // Prevent the window from closing immediately, wait for user input
    destroyAllWindows(); // Destroy all windows


    
    return 0;
}