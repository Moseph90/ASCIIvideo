#define WIDTH 1280
#define HEIGHT 720
#define FRAMEW 100
#define FRAMEH 45

#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace cv;

void ASCIIconvert(Mat& frame) {
    for (int i = 0; i < frame.rows; i++) {
        for (int j = 0; j < frame.cols; j++) {
            int greyscale = frame.at<uchar>(i, j);

            char ascii = '.';

            if (greyscale < 16) ascii = '#';
            else if (greyscale < 32) ascii = '$';
            else if (greyscale < 48) ascii = '@';
            else if (greyscale < 64) ascii = '%';
            else if (greyscale < 80) ascii = '&';
            else if (greyscale < 96) ascii = '*';
            else if (greyscale < 128) ascii = '+';
            else if (greyscale < 150) ascii = 'a';
            else if (greyscale < 180) ascii = '0';
            else if (greyscale < 216) ascii = '-';
            else if (greyscale < 255) ascii = '.';

            std::cout << ascii;
        }
        std::cout << std::endl;
    }
    std::cout << "\x1b[H";
}

int main(int argc, char** argv) {
    
    std::string video_path = "Elephant.mp4";
    VideoCapture capture(video_path);

    if (!capture.isOpened())
        std::cout << "Error when reading Parkour.mp4" << std::endl;
    else {
        int fps = capture.get(5);
        std::cout << "Frames per second: " << fps << std::endl;
        int frame_count = capture.get(7);
        std::cout << "Frame count: " << frame_count << std::endl;
    }

    namedWindow("Frame", WINDOW_NORMAL); // Normal window, resizable

    //Resize the window to a specific size (e.g., 640x480)
    resizeWindow("Frame", WIDTH, HEIGHT);

    while(capture.isOpened()) {
        Mat frame;
        Mat greyFrame;
        Mat resizedFrame;
        bool areFrames = capture.read(frame);

        if (areFrames) {
            cvtColor(frame, greyFrame, cv::COLOR_BGR2GRAY);
            resize(greyFrame, resizedFrame, Size(FRAMEW, FRAMEH), INTER_LINEAR);
            imshow("Frame", frame);
            ASCIIconvert(resizedFrame);
        }
        else  
            capture.set(CAP_PROP_POS_FRAMES, 0);

        int key = waitKey(20);

        if (key == 'q') break;

        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
    return 0;
}
