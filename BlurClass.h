//
// Created by Vladislav on 7/28/17.
//

#ifndef IMAGEBLUR_BLURCLASS_H
#define IMAGEBLUR_BLURCLASS_H


#include <ml.h>
#include <highgui.h>
#include <MacTypes.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


class Blur {

    public:
        char* ImageName;
        cv::Mat originImage;
        cv::Mat resizedImage;
        explicit Blur(const std::string &ImageName) {
            const char *ImageNameInChar = ImageName.c_str();
            this->ImageName = const_cast<char *>(ImageNameInChar);
        };
        bool loadImage() {
            this->originImage = cv::imread(this->ImageName);
            return this->originImage.data != nullptr;
        }
        bool resizeImage(int value) {
            int newImageHeight = (this->originImage.size().height / value);
            int newImageWidth = (this->originImage.size().width / value);
            cv::Size newImageSize(newImageWidth, newImageHeight);
            cv::resize(this->originImage, this->resizedImage, newImageSize);
            return true;
        }
        cv::Mat blurImage() {
            for(int i = 0; i < 5; i++) {
                cv::blur(this->resizedImage, this->resizedImage, cv::Size(25,25));
            }
            this->oldImageSize();
            return this->resizedImage;
        }
        bool writeImageToFile(const std::string &filePath, const cv::Mat &image) {
            cv::imwrite(filePath, image);
            return true;
        }

    private:
        void oldImageSize() {
            cv::resize(this->resizedImage, this->resizedImage, cv::Size(this->originImage.size().width, this->originImage.size().height));
        }
};


#endif //IMAGEBLUR_BLURCLASS_H
