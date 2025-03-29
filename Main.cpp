#define WIDTH 1280
#define HEIGHT 720
#define FRAMEW 150
#define FRAMEH 45

#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace cv;

void ASCIIconvert(Mat& frame) {
    for (int i = 0; i < frame.rows; i++) {
        for (int j = 0; j < frame.cols; j++) {
            Vec3b color = frame.at<Vec3b>(i, j); 
            
            int r = color[0];
            int g = color[1];
            int b = color[2];

            std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m#"; 
        }
        std::cout << std::endl; 
    }
    std::cout << "\x1b[H";
}

int main(int argc, char** argv) {
    
    std::string video_path = "Swans.mp4";
    VideoCapture capture(video_path);

    if (!capture.isOpened())
        std::cout << "Error when reading video" << std::endl;
    else {
        int fps = capture.get(5);
        std::cout << "Frames per second: " << fps << std::endl;
        int frame_count = capture.get(7);
        std::cout << "Frame count: " << frame_count << std::endl;
    }

    while(capture.isOpened()) {
        Mat frame;
        Mat resizedColorFrame;
        bool areFrames = capture.read(frame);

        if (areFrames) {
            resize(frame, resizedColorFrame, Size(FRAMEW, FRAMEH), INTER_LINEAR);
            ASCIIconvert(resizedColorFrame);
        }
        else  
            capture.set(CAP_PROP_POS_FRAMES, 0);
        
        //These only work if there's a window present
        int key = waitKey(20);
        if (key == 'q') break;

        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
    return 0;
}
