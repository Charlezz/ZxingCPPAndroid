cmake_minimum_required(VERSION 3.4.1)

include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/)

add_library( Zxing SHARED
src/main/cpp/zxing/BarcodeFormat.cpp
src/main/cpp/zxing/Binarizer.cpp
src/main/cpp/zxing/BinaryBitmap.cpp
src/main/cpp/zxing/ChecksumException.cpp
src/main/cpp/zxing/DecodeHints.cpp
src/main/cpp/zxing/Exception.cpp
src/main/cpp/zxing/FormatException.cpp
src/main/cpp/zxing/InvertedLuminanceSource.cpp
src/main/cpp/zxing/LuminanceSource.cpp
src/main/cpp/zxing/MultiFormatReader.cpp
src/main/cpp/zxing/Reader.cpp
src/main/cpp/zxing/Result.cpp
src/main/cpp/zxing/ResultIO.cpp
src/main/cpp/zxing/ResultPoint.cpp
src/main/cpp/zxing/ResultPointCallback.cpp

src/main/cpp/zxing/aztec/AztecDetectorResult.cpp
src/main/cpp/zxing/aztec/AztecReader.cpp
src/main/cpp/zxing/aztec/decoder/Decoder.cpp
src/main/cpp/zxing/aztec/detector/Detector.cpp

src/main/cpp/zxing/common/BitArray.cpp
src/main/cpp/zxing/common/BitArrayIO.cpp
src/main/cpp/zxing/common/BitMatrix.cpp
src/main/cpp/zxing/common/BitSource.cpp
src/main/cpp/zxing/common/CharacterSetECI.cpp
src/main/cpp/zxing/common/DecoderResult.cpp
src/main/cpp/zxing/common/DetectorResult.cpp
src/main/cpp/zxing/common/GlobalHistogramBinarizer.cpp
src/main/cpp/zxing/common/GreyscaleLuminanceSource.cpp
src/main/cpp/zxing/common/GreyscaleRotatedLuminanceSource.cpp
src/main/cpp/zxing/common/GridSampler.cpp
src/main/cpp/zxing/common/HybridBinarizer.cpp
src/main/cpp/zxing/common/IllegalArgumentException.cpp
src/main/cpp/zxing/common/PerspectiveTransform.cpp
src/main/cpp/zxing/common/Str.cpp
src/main/cpp/zxing/common/StringUtils.cpp
src/main/cpp/zxing/common/detector/MonochromeRectangleDetector.cpp
src/main/cpp/zxing/common/detector/WhiteRectangleDetector.cpp
src/main/cpp/zxing/common/reedsolomon/GenericGF.cpp
src/main/cpp/zxing/common/reedsolomon/GenericGFPoly.cpp
src/main/cpp/zxing/common/reedsolomon/ReedSolomonDecoder.cpp
src/main/cpp/zxing/common/reedsolomon/ReedSolomonException.cpp

src/main/cpp/zxing/datamatrix/DataMatrixReader.cpp
src/main/cpp/zxing/datamatrix/Version.cpp
src/main/cpp/zxing/datamatrix/decoder/BitMatrixParser.cpp
src/main/cpp/zxing/datamatrix/decoder/DataBlock.cpp
src/main/cpp/zxing/datamatrix/decoder/DecodedBitStreamParser.cpp
src/main/cpp/zxing/datamatrix/decoder/Decoder.cpp
src/main/cpp/zxing/datamatrix/detector/CornerPoint.cpp
src/main/cpp/zxing/datamatrix/detector/Detector.cpp
src/main/cpp/zxing/datamatrix/detector/DetectorException.cpp

src/main/cpp/zxing/multi/ByQuadrantReader.cpp
src/main/cpp/zxing/multi/GenericMultipleBarcodeReader.cpp
src/main/cpp/zxing/multi/MultipleBarcodeReader.cpp

src/main/cpp/zxing/multi/qrcode/QRCodeMultiReader.cpp
src/main/cpp/zxing/multi/qrcode/detector/MultiDetector.cpp
src/main/cpp/zxing/multi/qrcode/detector/MultiFinderPatternFinder.cpp

src/main/cpp/zxing/oned/CodaBarReader.cpp
src/main/cpp/zxing/oned/Code39Reader.cpp
src/main/cpp/zxing/oned/Code93Reader.cpp
src/main/cpp/zxing/oned/Code128Reader.cpp
src/main/cpp/zxing/oned/EAN8Reader.cpp
src/main/cpp/zxing/oned/EAN13Reader.cpp
src/main/cpp/zxing/oned/ITFReader.cpp
src/main/cpp/zxing/oned/MultiFormatOneDReader.cpp
src/main/cpp/zxing/oned/MultiFormatUPCEANReader.cpp
src/main/cpp/zxing/oned/OneDReader.cpp
src/main/cpp/zxing/oned/OneDResultPoint.cpp
src/main/cpp/zxing/oned/UPCAReader.cpp
src/main/cpp/zxing/oned/UPCEANReader.cpp
src/main/cpp/zxing/oned/UPCEReader.cpp

src/main/cpp/zxing/pdf417/PDF417Reader.cpp
src/main/cpp/zxing/pdf417/decoder/BitMatrixParser.cpp
src/main/cpp/zxing/pdf417/decoder/DecodedBitStreamParser.cpp
src/main/cpp/zxing/pdf417/decoder/Decoder.cpp
src/main/cpp/zxing/pdf417/decoder/ec/ErrorCorrection.cpp
src/main/cpp/zxing/pdf417/decoder/ec/ModulusGF.cpp
src/main/cpp/zxing/pdf417/decoder/ec/ModulusPoly.cpp
src/main/cpp/zxing/pdf417/detector/Detector.cpp
src/main/cpp/zxing/pdf417/detector/LinesSampler.cpp

src/main/cpp/zxing/qrcode/ErrorCorrectionLevel.cpp
src/main/cpp/zxing/qrcode/FormatInformation.cpp
src/main/cpp/zxing/qrcode/QRCodeReader.cpp
src/main/cpp/zxing/qrcode/Version.cpp
src/main/cpp/zxing/qrcode/decoder/BitMatrixParser.cpp
src/main/cpp/zxing/qrcode/decoder/DataBlock.cpp
src/main/cpp/zxing/qrcode/decoder/DataMask.cpp
src/main/cpp/zxing/qrcode/decoder/DecodedBitStreamParser.cpp
src/main/cpp/zxing/qrcode/decoder/Decoder.cpp
src/main/cpp/zxing/qrcode/decoder/Mode.cpp
src/main/cpp/zxing/qrcode/detector/AlignmentPattern.cpp
src/main/cpp/zxing/qrcode/detector/AlignmentPatternFinder.cpp
src/main/cpp/zxing/qrcode/detector/Detector.cpp
src/main/cpp/zxing/qrcode/detector/FinderPattern.cpp
src/main/cpp/zxing/qrcode/detector/FinderPatternFinder.cpp
src/main/cpp/zxing/qrcode/detector/AlignmentPattern.cpp
src/main/cpp/zxing/qrcode/detector/FinderPatternInfo.cpp


src/main/cpp/bigint/BigInteger.cc
src/main/cpp/bigint/BigIntegerAlgorithms.cc
src/main/cpp/bigint/BigIntegerUtils.cc
src/main/cpp/bigint/BigUnsigned.cc
src/main/cpp/bigint/BigUnsignedInABase.cc





)

find_library( log-lib log )

target_link_libraries( Zxing ${log-lib} )