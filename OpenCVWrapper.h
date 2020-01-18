//
// Created by Administrator on 2020-01-18.
//

#ifndef OPENCVENCODER_OPENCVENCODER_H
#define OPENCVENCODER_OPENCVENCODER_H
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class OpenCVWrapper {
private:
    VideoCapture *videoCapture;
    VideoWriter *videoWriter;

    Size *resolution;
    double *fps;
    int *frameCount;
    int framePos;

public:
    OpenCVWrapper();
    ~OpenCVWrapper();

    int getFrameCount();
    int getFramePOS();

    // Input Video
    bool openInputVideo(const String &filename);
    bool getFrameFromInputVideo(Mat &image);
    bool releaseInputVideo();

    // Output Video
    bool initOutVideo(const String &filename);
    bool insertFrameInOutVideo(Mat &image);
    bool releaseOutVideo();
};


#endif //OPENCVENCODER_OPENCVENCODER_H
