//
// Created by Administrator on 2020-01-18.
//

#include "OpenCVWrapper.h"

OpenCVWrapper::OpenCVWrapper() {

}

OpenCVWrapper::~OpenCVWrapper() {
    delete videoCapture;
    delete videoWriter;
    delete resolution;
    delete fps;
    delete frameCount;
}

int OpenCVWrapper::getFrameCount() {
    return *frameCount;
}

int OpenCVWrapper::getFramePOS() {
    return framePos;
}


bool OpenCVWrapper::openInputVideo(const String &filename) {
    try {
        videoCapture = new VideoCapture();
        videoCapture->open(filename);
        if (videoCapture->isOpened()) {
            int width = (int)videoCapture->get(CAP_PROP_FRAME_WIDTH);
            int height = (int)videoCapture->get(CAP_PROP_FRAME_HEIGHT);

            resolution = new Size(width, height);
            fps = new double((double)videoCapture->get(CAP_PROP_FPS));
            frameCount = new int((int)videoCapture->get(CAP_PROP_FRAME_COUNT));

            return true;
        } else {
            cout << "Fail to open input video" << endl;
            return false;
        }
    } catch (Exception e) {
        cout << "Failed to open the input video" << endl;
        return false;
    }
}

bool OpenCVWrapper::getFrameFromInputVideo(Mat &image) {
    try {
        if (videoCapture->read(image)) {
            framePos = (int)videoCapture->get(CAP_PROP_POS_FRAMES) + 1;
            return true;
        } else {
            cout << "Failed to get a frame frome the input video" << endl;
            return false;
        }
    } catch (Exception e) {
        return false;
    }
}

bool OpenCVWrapper::releaseInputVideo() {
    try {
        videoCapture->release();
        return true;
    } catch (Exception e) {
        return false;
    }
}

bool OpenCVWrapper::initOutVideo(const String &filename) {
    try {
        videoWriter = new VideoWriter();
        videoWriter->open(filename, VideoWriter::fourcc('H', '2', '6', '4'), *fps, *resolution, true);

        if (videoWriter->isOpened()) {
            return true;
        } else {
            cout << "Failed to initialize the output video" << endl;
            return false;
        }
        return true;
    } catch (Exception e) {
        cout << "Failed to initialize the output video" << endl;
        return false;
    }
}

bool OpenCVWrapper::insertFrameInOutVideo(Mat &image) {
    try {
        videoWriter->write(image);
        return true;
    } catch (Exception e) {
        return false;
    }
}

bool OpenCVWrapper::releaseOutVideo() {
    try {
        videoWriter->release();
        return true;
    } catch (Exception e) {
        return false;
    }
}

