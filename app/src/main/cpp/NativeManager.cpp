#include <jni.h>

#include <zxing/common/Counted.h>
#include <zxing/Binarizer.h>
#include <zxing/MultiFormatReader.h>
#include <zxing/Result.h>
#include <zxing/ReaderException.h>
#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/common/HybridBinarizer.h>
#include <exception>
#include <zxing/Exception.h>
#include <zxing/common/IllegalArgumentException.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/DecodeHints.h>

#include <zxing/qrcode/QRCodeReader.h>
#include <zxing/multi/qrcode/QRCodeMultiReader.h>
#include <zxing/multi/ByQuadrantReader.h>
#include <zxing/multi/MultipleBarcodeReader.h>
#include <zxing/multi/GenericMultipleBarcodeReader.h>
#include "ImageReaderSource.hpp"

#include <android/log.h>
#include <sstream>
#include "math.h"
#include "string"

using namespace std;
using namespace zxing;
using namespace zxing::multi;
using namespace zxing::qrcode;
namespace {
    bool more = false;
    bool test_mode = true;
    bool try_harder = true;
    bool search_multi = false;
    bool use_hybrid = true;
    bool use_global = false;
    bool verbose = true;
}

extern "C" {

static const char *TAG = "NativeManager";
vector<Ref<Result> > decode(Ref<BinaryBitmap> image, DecodeHints hints) {
    Ref<Reader> reader(new MultiFormatReader);
    return vector<Ref<Result> >(1, reader->decode(image, hints));
}

vector<Ref<Result> > decode_multi(Ref<BinaryBitmap> image, DecodeHints hints) {
    MultiFormatReader delegate;
    GenericMultipleBarcodeReader reader(delegate);
    return reader.decodeMultiple(image, hints);
}
string read_image(Ref<LuminanceSource> source, bool hybrid, string expected) {

    vector<Ref<Result> > results;
    string cell_result;
    string finalResult = "";
    int res = -1;

    try {
        Ref<Binarizer> binarizer;
        if (hybrid) {
            binarizer = new HybridBinarizer(source);
        } else {
            binarizer = new GlobalHistogramBinarizer(source);
        }
        DecodeHints hints(DecodeHints::DEFAULT_HINT);
        hints.setTryHarder(try_harder);
        Ref<BinaryBitmap> binary(new BinaryBitmap(binarizer));
        if (search_multi) {
            results = decode_multi(binary, hints);
        } else {
            results = decode(binary, hints);
        }
        res = 0;
    } catch (const ReaderException &e) {
        cell_result = "zxing::ReaderException: " + string(e.what());
        res = -2;
    } catch (const zxing::IllegalArgumentException &e) {
        cell_result = "zxing::IllegalArgumentException: " + string(e.what());
        res = -3;
    } catch (const zxing::Exception &e) {
        cell_result = "zxing::Exception: " + string(e.what());
        res = -4;
    } catch (const std::exception &e) {
        cell_result = "std::exception: " + string(e.what());
        res = -5;
    }


    if (test_mode && results.size() == 1) {
        std::string result = results[0]->getText()->getText();
        if (expected.empty()) {
//            __android_log_write(ANDROID_LOG_ERROR, TAG, result.c_str());
            finalResult = result;
        } else {
            if (expected.compare(result) != 0) {
//                cout << "  Expected: " << expected << endl
//                cout << "  Detected: " << result << endl;
                cell_result = "data did not match";
                res = -6;
//                __android_log_write(ANDROID_LOG_ERROR, TAG, result.c_str());
                finalResult = result;
            }
        }
    }
    if (res != 0 && (verbose || (use_global ^ use_hybrid))) {
//        cout << (hybrid ? "Hybrid" : "Global")
//        << " binarizer failed: " << cell_result << endl;
    } else if (!test_mode) {
        if (verbose) {
            cout << (hybrid ? "Hybrid" : "Global")
            << " binarizer succeeded: " << endl;
        }
        for (size_t i = 0; i < results.size(); i++) {
            if (more) {
                cout << "  Format: "
                << BarcodeFormat::barcodeFormatNames[results[i]->getBarcodeFormat()]
                << endl;
                for (int j = 0; j < results[i]->getResultPoints()->size(); j++) {
                    cout << "  Point[" << j << "]: "
                    << results[i]->getResultPoints()[j]->getX() << " "
                    << results[i]->getResultPoints()[j]->getY() << endl;
                }
            }
            if (verbose) {

                cout << "    ";
            }
//            cout << results[i]->getText()->getText() << endl;
        }
    }

    return finalResult;
}
char *as_char_array(JNIEnv *env, jbyteArray array) {
    int len = env->GetArrayLength(array);
    char *buf = new char[len];
    env->GetByteArrayRegion(array, 0, len, reinterpret_cast<jbyte *>(buf));
    return buf;
}


jstring
Java_com_maxst_www_zxingcpptest_NativeManager_tryToRecognize(JNIEnv *env, jobject obj,
                                                             jint srcWidth, jint srcHeight,
                                                             jbyteArray srcBuffer) {

    char *yArray = as_char_array(env, srcBuffer);
    int bufferCount = 0;

    int halfW = srcWidth / 2;
    int halfH = srcHeight / 2;
    char *cropArray = new char[halfW * halfH * 4];
    for (int i = 0; i < halfH; i++) {
        for (int j = 0; j < halfW; j++) {
            cropArray[bufferCount * 4 + 0] = yArray[(i + halfH / 2) * srcWidth + (j + halfW / 2)];
            cropArray[bufferCount * 4 + 1] = yArray[(i + halfH / 2) * srcWidth + (j + halfW / 2)];
            cropArray[bufferCount * 4 + 2] = yArray[(i + halfH / 2) * srcWidth + (j + halfW / 2)];
            cropArray[bufferCount * 4 + 3] = yArray[(i + halfH / 2) * srcWidth + (j + halfW / 2)];
            bufferCount++;
        }
    }


    stringstream sstm;

    Ref<LuminanceSource> irc = ImageReaderSource::create(cropArray, halfW, halfH);
    string result = read_image(irc, true, "");

    delete cropArray;
    delete yArray;

    return env->NewStringUTF(result.c_str());
}


}