/*
 * Image blur on c++
 * Author Vladislav Len <heavenly.beta@gmail.com>
 */

#include <iostream>
#include <opencv2/core/core.hpp>
#include "BlurClass.h"

using namespace cv;
using namespace std;


int main(int argc, char* argv[]) {

    const std::string originName = argv[1];
    const std::string blurredName = argv[2];
    const int blurValue = atoi(argv[3]);
    Blur BlurObject = Blur(originName);
    if(BlurObject.loadImage()) {
        BlurObject.resizeImage(blurValue);
        cv::Mat blurredImage = BlurObject.blurImage();
        BlurObject.writeImageToFile(blurredName, blurredImage);
        std::cout << "true" << std::end;
    }else {
        std::cout << "false" << std::end;
    }

    return 0;
}