#include <iostream>
#include <opencv2/opencv.hpp>
#include "OpenCVWrapper.h"

int main() {
    OpenCVWrapper *openCVWrapper = new OpenCVWrapper();
    openCVWrapper->openInputVideo("input.avi");
    openCVWrapper->initOutVideo("output.mp4");

    /* Variable for input and output video */
    Mat frame;
    int pos;
    int frameCount = openCVWrapper->getFrameCount();

    /* Variable to print */
    int len = 20;
    int barCount;
    float percent;
    float tick = (float)100/len;

    while (openCVWrapper->getFramePOS() <= frameCount) {
        /* Get Position of input video */
        pos = openCVWrapper->getFramePOS();

        /* Print Progress bar */
        cout << "\r" << pos << "/" << frameCount << " [" ;
        percent = (float)pos/frameCount * 100;
        barCount = (int)(percent/tick);
        for (int i = 0; i < len; i++) {
            if (barCount > i) cout << "=";
            else cout << " ";
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "] " << percent << "%" ;

        /* Get a frame from the input video */
        openCVWrapper->getFrameFromInputVideo(frame);

        /* TODO: processing frame */

        /* insert a frame from output video */
        openCVWrapper->insertFrameInOutVideo(frame);
    }
    cout << endl;

    /* Release input and output video*/
    openCVWrapper->releaseInputVideo();
    openCVWrapper->releaseOutVideo();

    return 0;
}