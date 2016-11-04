cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp/include/)

# add_library(shape SHARED IMPORTED)
# set_target_properties(shape PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_shape.a)

# add_library(stitching SHARED IMPORTED)
# set_target_properties(stitching PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_stitching.a)

# add_library(objdetect SHARED IMPORTED)
# set_target_properties(objdetect PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_objdetect.a)

# add_library(superres SHARED IMPORTED)
# set_target_properties(superres PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_superres.a)

# add_library(videostab SHARED IMPORTED)
# set_target_properties(videostab PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_videostab.a)

# add_library(calib3d SHARED IMPORTED)
# set_target_properties(calib3d PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_calib3d.a)

# add_library(features2d SHARED IMPORTED)
# set_target_properties(features2d PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_features2d.a)

# add_library(highgui SHARED IMPORTED)
# set_target_properties(highgui PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_highgui.a)

# add_library(videoio SHARED IMPORTED)
# set_target_properties(videoio PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_videoio.a)

# add_library(imgcodecs SHARED IMPORTED)
# set_target_properties(imgcodecs PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_imgcodecs.a)

# add_library(video SHARED IMPORTED)
# set_target_properties(video PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_video.a)

# add_library(photo SHARED IMPORTED)
# set_target_properties(photo PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_photo.a)

# add_library(ml SHARED IMPORTED)
# set_target_properties(ml PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_ml.a)

# add_library(imgproc SHARED IMPORTED)
# set_target_properties(imgproc PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_imgproc.a)

# add_library(flann SHARED IMPORTED)
# set_target_properties(flann PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_flann.a)

# add_library(core SHARED IMPORTED)
# set_target_properties(core PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_core.a)

# add_library(libjpeg SHARED IMPORTED)
# set_target_properties(libjpeg PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/liblibjpeg.a)

# add_library(libwebp SHARED IMPORTED)
# set_target_properties(libwebp PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/liblibwebp.a)

# add_library(libpng SHARED IMPORTED)
# set_target_properties(libpng PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/liblibpng.a)

# add_library(libtiff SHARED IMPORTED)
# set_target_properties(libtiff PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/liblibtiff.a)

# add_library(libjasper SHARED IMPORTED)
# set_target_properties(libjasper PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/liblibjasper.a)

# add_library(IlmImf SHARED IMPORTED)
# set_target_properties(IlmImf PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libIlmImf.a)

# add_library(tbb SHARED IMPORTED)
# set_target_properties(tbb PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libtbb.a)

# add_library(java3 SHARED IMPORTED)
# set_target_properties(java3 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

add_library(Zxing SHARED IMPORTED)
set_target_properties(Zxing PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libZxing.so)

add_library( NativeManager SHARED src/main/cpp/NativeManager.cpp src/main/cpp/ImageReaderSource.cpp)

find_library( log-lib log )

# target_link_libraries(NativeManager shape stitching objdetect superres videostab calib3d features2d highgui videoio imgcodecs video photo ml imgproc flann core libjpeg libwebp libpng libtiff libjasper IlmImf tbb java3 Zxing ${log-lib} )
target_link_libraries(NativeManager Zxing ${log-lib} )