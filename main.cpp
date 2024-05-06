#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 创建VideoCapture对象
    cv::VideoCapture cap(1, cv::CAP_DSHOW);
    if (!cap.isOpened()) {
        std::cerr << "VideoCapture not opened" << std::endl;
        return -1;
    }

    // 设置帧率
    cap.set(cv::CAP_PROP_FPS, 30);
    // 设置帧的宽度
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 2560);
    // 设置帧的高度
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
    // 设置编码格式
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

    cv::Mat frame0;
    while (true) {
        // 从摄像头读取下一帧
        if (!cap.read(frame0)) {
            std::cerr << "Failed to grab a frame" << std::endl;
            break;
        }

        // 显示帧
        cv::imshow("FireEyes", frame0);

        // 等待30毫秒，检查是否有按键输入
        if (cv::waitKey(30) >= 0) {
            break;
        }
    }

    // 释放VideoCapture对象
    cap.release();
    // 关闭所有OpenCV窗口
    cv::destroyAllWindows();

    return 0;
}
