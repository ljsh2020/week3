#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d.hpp>

using namespace cv;
using namespace std;

vector<Point2f> points_src(4);
vector<Point2f> points_dst(4);
int points_num = 0;

Mat src = imread("car.jpg");
Mat dst = src.clone();

void getPoints(int event, int x, int y, int flags, void *usrdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        if (points_num < 4)
        {
            points_src[points_num].x = x;
            points_src[points_num].y = y;
            circle(src, points_src[points_num], 1, {0, 0, 255}, 3);
            imshow("src",src);
        points_num++;
        cout << points_num << endl;
        if (points_num == 4)
        {
            Mat warpMat = getPerspectiveTransform(points_src, points_dst);
            warpPerspective(dst,dst, warpMat, Size(200,100));
            imshow("dst",dst);
        }
        }
    }
}

int main()
{
    points_dst[0].x = 0;
points_dst[0].y = 0;
points_dst[1].x = 200;
points_dst[1].y = 0;
points_dst[2].x = 200;
points_dst[2].y = 100;
points_dst[3].x = 0;
points_dst[3].y = 100;


namedWindow("src");    
setMouseCallback("src", getPoints, 0);
    imshow("src",src); waitKey(0);
    destroyAllWindows();
    return 0;
}