CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

SET(PROJECT_NAME dseg)

PROJECT(${PROJECT_NAME})

#opencv路径
set(OpenCV_DIR "/datav/lean/opencv-4.2.0")
#tensorrt路径
set(TensorRT_DIR "/datav/lean/TensorRT-8.5.1.7")
#cuda路径
INCLUDE_DIRECTORIES("/datav/lean/cuda-11.2/include")
LINK_DIRECTORIES("/datav/lean/cuda-11.2/lib64")

INCLUDE_DIRECTORIES("/datav/lean/TensorRT-8.5.1.7/include")
LINK_DIRECTORIES("/datav/lean/TensorRT-8.5.1.7/lib")

INCLUDE_DIRECTORIES("/datav/lean/opencv-4.2.0/include/opencv4")
LINK_DIRECTORIES("/datav/lean/opencv-4.2.0/lib")

INCLUDE_DIRECTORIES("/datav/lean/cudnn-linux-x86_64-8.6.0.163_cuda11-archive/include")
LINK_DIRECTORIES("/datav/lean/cudnn-linux-x86_64-8.6.0.163_cuda11-archive/lib")

LINK_DIRECTORIES("/usr/lib/x86_64-linux-gnu")

INCLUDE_DIRECTORIES(./include)

set(CMAKE_CXX_FLAGS -pthread)
set(BOOST_THREAD_LIBRARY boost_thread -pthread)

AUX_SOURCE_DIRECTORY(./src SRC_FILES)
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_FILES})
TARGET_LINK_LIBRARIES(
	${PROJECT_NAME}
	nvinfer
	nvinfer_plugin
	nvparsers
	nvonnxparser
	cudart
	cuda
    cublas
    cudnn
	#opencv的so文件配一下
	opencv_core
    opencv_imgproc
    opencv_videoio
    opencv_imgcodecs
    libpthread.so
    libdl.so.2
)