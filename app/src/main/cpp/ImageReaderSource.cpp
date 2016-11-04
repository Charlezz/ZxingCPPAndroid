//
//  ImageReaderSource.cpp
//  OpenCVTest
//
//  Created by Charles on 10/26/16.
//  Copyright © 2016 Maxst. All rights reserved.
//

#include "ImageReaderSource.hpp"
#include <zxing/common/IllegalArgumentException.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using zxing::Ref;
using zxing::ArrayRef;
using zxing::LuminanceSource;

inline char ImageReaderSource::convertPixel(char const *pixel_) const {
    unsigned char const *pixel = (unsigned char const *) pixel_;
    if (comps == 1 || comps == 2) {
        // Gray or gray+alpha
        return pixel[0];
    }
    if (comps == 3 || comps == 4) {
        // Red, Green, Blue, (Alpha)
        // We assume 16 bit values here
        // 0x200 = 1<<9, half an lsb of the result to force rounding
        return (char) ((306 * (int) pixel[0] + 601 * (int) pixel[1] +
                        117 * (int) pixel[2] + 0x200) >> 10);
    } else {
        throw zxing::IllegalArgumentException("Unexpected image depth");
    }
}

ImageReaderSource::ImageReaderSource(ArrayRef<char> image_, int width, int height, int comps_)
        : LuminanceSource(width, height), image(image_), comps(comps_) {
}

Ref<LuminanceSource> ImageReaderSource::create(char *buffer, int width, int height) {
    int comps = 1;
    zxing::ArrayRef<char> image = zxing::ArrayRef<char>((char *) buffer, width * height*4);
    return Ref<LuminanceSource>(new ImageReaderSource(image, width, height, comps));
}

zxing::ArrayRef<char> ImageReaderSource::getRow(int y, zxing::ArrayRef<char> row) const {
    const char *pixelRow = &image[0] + y * getWidth();
    if (!row) {
        row = zxing::ArrayRef<char>(getWidth());
    }
    for (int x = 0; x < getWidth(); x++) {
        row[x] = convertPixel(pixelRow + (x * 4));
    }
    return row;
}
//243312
/** This is a more efficient implementation. */
zxing::ArrayRef<char> ImageReaderSource::getMatrix() const {

    const char *p = &image[0];
    zxing::ArrayRef<char> matrix(getWidth() * getHeight());
    char *m = &matrix[0];
    int count = 0;
    for (int y = 0; y < getHeight(); y++) {
        for (int x = 0; x < getWidth(); x++) {
            count++;
            *m = convertPixel(p);
            m++;
            p += 4;
        }
    }
    return matrix;
}

