#include <opencv2/opencv.hpp>
#include "utils.hpp"

int main(int argc, char ** argv) 
{ 
    if (argc != 2) 
    {
        std::cerr << "usage: " << argv[0] << " <filename> \n";
        exit(-1);
    }
    const char * filename = argv[1];
    std::string basename, extension;
    getBasenameAndExtension(filename, basename, extension);

    // load input image
    cv::Mat imgInput = cv::imread(filename);
    if (imgInput.channels()!=3 or imgInput.depth()!=CV_8U)
    {
        std::cerr << "error: only 3-channel 8-bits images are supported\n";
        exit(-1);
    }

    const double COEF = 0.5;

    // operator*=
    timePoint_t tpMul0 = now();
    cv::Mat imgMul = imgInput.clone();
    imgMul *= COEF;
    timePoint_t tpMul1 = now();

    // foreach loop
    // TODO
    timePoint_t tpForEach0 = now();
    
    auto f = [COEF] (cv::Vec3b &color, const int *) {
		color[0] *= COEF;
		color[1] *= COEF;
		color[2] *= COEF;
	};
    cv::Mat imgForeach = imgInput.clone();
    imgForeach.forEach<cv::Vec3b>(f);
    timePoint_t tpForEach1 = now();
    

    // 2D loop
    // TODO
    timePoint_t tpLoop0 = now();
    cv::Mat imgLoop = imgInput.clone();
    for(int i=0;i < imgLoop.rows;i++) {
		for(int j=0;j < imgLoop.cols;j++) {
			imgLoop.at<cv::Vec3b>(i, j) = imgLoop.at<cv::Vec3b>(i, j) * COEF;
		}
	}
	timePoint_t tpLoop1 = now();

    // print computation times
    std::cout << "imgMul: " << duration(tpMul0, tpMul1) << " s\n";
    std::cout << "imgLoop: " << duration(tpLoop0, tpLoop1) << " s\n";
    std::cout << "imgForEach: " << duration(tpForEach0, tpForEach1) << " s\n";
    // TODO

    // write image files
    imwrite(basename + "_imgMul" + extension, imgMul);
    // TODO

    // display images
    cv::imshow("imgInput", imgInput);
    cv::imshow("imgMul", imgMul);
    // TODO

    // wait for "esc"
    while (true)
    {
        int k = cv::waitKey(100) % 0x100;
        if (k == 27)
            break;
    }

    return 0;
}


