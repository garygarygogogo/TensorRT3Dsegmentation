#include <opencv2/opencv.hpp>
#include <time.h>
#include "OnnxTensorRTGlandceilModel.h"



void binaryvnet2dglandceil()
{
	std::string onnx_file_path = "/datav/projects/TensorRTSegmentationDemo/TensorRTC++/src/BinaryVNet2dModel.onnx";
	std::string engine_file_path = "/datav/projects/TensorRTSegmentationDemo/TensorRTC++/src/BinaryVNet2dModel.trt";
	OnnxTensorRTModelGlandceil* binartvnet2d = new OnnxTensorRTModelGlandceil(onnx_file_path, engine_file_path, 1, 1, 512, 512, 1, 1, 512, 512);
	std::vector<std::string> filenams = { "testA_14.bmp" };


	std::string imagefile = "/datav/projects/TensorRTSegmentationDemo/TensorRTC++/src/testA_14.bmp";
	cv::Mat image = cv::imread(imagefile, 0);
	cv::Mat outmask;
	clock_t start, end;
	start = clock();
	binartvnet2d->infer(image, outmask);
	end = clock();
	std::cout << " Inference time with the TensorRT engine£º" << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
	std::string maskfile = "predict.bmp";
	cv::imwrite(maskfile, outmask);
}

int main()
{
	binaryvnet2dglandceil();
	getchar();

}