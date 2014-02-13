#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void circleMidpoint(Mat &img, int x0, int y0, int radius, int val);

int main(int argc, char *argv[])
{
    Mat M(20, 20, CV_8UC1, Scalar(0));

    circleMidpoint(M, 10, 10, 8, 255);

    cout << "M = " << endl << M << endl;
    namedWindow("win");
    imshow("win", M);
    waitKey(0);
}

void circleMidpoint(Mat &img, int x0, int y0, int radius, int val)
{
    int x = radius, y = 0;
    int radiusError = 1-x;

    while(x > y)
    {
        img.at<unsigned char>(y+ y0,x + x0) = val;
        img.at<unsigned char>(x+ y0,y + x0) = val;
        img.at<unsigned char>(-y+ y0,x + x0) = val;
        img.at<unsigned char>(-x+ y0,y + x0) = val;
        img.at<unsigned char>(-y+ y0,-x + x0) = val;
        img.at<unsigned char>(-x+ y0,-y + x0) = val;
        img.at<unsigned char>(y+ y0,-x + x0) = val;
        img.at<unsigned char>(x+ y0,-y + x0) = val;
        y++;
        if(radiusError < 0){
            radiusError += 2 * y + 1;
        }else{
            x--;
            radiusError += 2 * ( y - x + 1);
        }
    }
}
