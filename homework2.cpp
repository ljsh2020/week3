#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <assert.h>

using namespace cv;
using namespace std;

int main()
{
    FileStorage reader("parameter.txt",FileStorage::READ);
    Mat cMat, dMat;
    reader["C"] >> cMat;
    reader["D"] >> dMat;
    
/*
    FileStorage writer("result.txt",FileStorage::APPEND);

    vector<Point2f> point_pix;
    vector<Point3f> point_obj;

    int square_length = 10;
    int board_w = 9; int board_h = 6;
    int board_n = board_w*board_h;
    Size board_size(9,6);
    for (int i = 0; i < board_w; i++){
        for (int j = 0; j < board_h; j++){
            Point3f p;
            p.x = i*square_length;
            p.y = j*square_length;
            p.z = 0;
            point_obj.push_back(p);
        }
    }
*/
    Mat img = imread(__cxx11::to_string(1)+".jpg");
    imshow("img",img);
/*
    for (int i = 0; i < 41; i++){
        Mat img = imread(__cxx11::to_string(i)+".jpg");
        assert(img.empty());
        bool isFound = findChessboardCorners(img,board_size,point_pix);
        if (isFound){
            Mat gray;
            cvtColor(img,gray,COLOR_BGR2GRAY);
            find4QuadCornerSubpix(gray,point_pix,board_size);

            vector<double> rvec, tvec;
            bool getPnP = solvePnP( point_obj, point_pix, cMat, dMat, rvec, tvec, 0 );
            if (getPnP){
                writer<<"NO."<< i;
                writer<<tvec;
            }
            rvec.clear();
            tvec.clear();
        }
        else {
            cout << "Fail to find all points " << i <<endl;
        }
    }
*/
    return 0;
}