#ifndef __CV_READER_SOURCE_H_
#define __CV_READER_SOURCE_H_

#include <zxing/LuminanceSource.h>


class ImageReaderSource : public zxing::LuminanceSource {
private:
    const zxing::ArrayRef<char> image;
    const int comps;

    char convertPixel(const char *pixel) const;

public:
    static zxing::Ref<LuminanceSource> create(char *buffer, int width, int height);

    ImageReaderSource(zxing::ArrayRef<char> image, int width, int height, int comps);

    zxing::ArrayRef<char> getRow(int y, zxing::ArrayRef<char> row) const;

    zxing::ArrayRef<char> getMatrix() const;
};

#endif /* __CV_READER_SOURCE_H_ */
