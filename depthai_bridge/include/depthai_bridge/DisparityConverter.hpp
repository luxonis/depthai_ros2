#pragma once

#include <sstream>
#include <iostream>
#include <unordered_map>

#include "stereo_msgs/DisparityImage.h"

#include "depthai/depthai.hpp"
#include <opencv2/opencv.hpp>

namespace dai::rosBridge {
using TimePoint = std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration>;

class DisparityConverter{

    public:
    // DisparityConverter() = default;
    DisparityConverter(const std::string frameName, float focalLength, float baseline = 7.5, float minDepth = 80, float maxDepth = 1100);
    
    void toRosMsg(std::shared_ptr<dai::ImgFrame> inData, stereo_msgs::DisparityImage& outImageMsg);
    stereo_msgs::DisparityImagePtr toRosMsgPtr(std::shared_ptr<dai::ImgFrame> inData);

    // void toDaiMsg(const stereo_msgs::DisparityImage& inMsg, dai::ImgFrame& outData);

    private:
        const std::string _frameName = "";
        const float _focalLength = 882.2, _baseline = 7.5, _minDepth = 80, _maxDepth;

};

}   // namespace dai::rosBridge