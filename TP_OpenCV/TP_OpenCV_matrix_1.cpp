#include <opencv2/opencv.hpp>
#include "utils.hpp"

int main()
{

    cv::Mat M = (cv::Mat_<float>(3, 3) << 1, 0, 0, 0, 1, 0, 0, 0, 1);
    cv::Mat U = (cv::Mat_<float>(3, 1) << 1, 2, 3);
    cv::Mat V = (cv::Mat_<float>(3, 1) << 1, 1, 1);//Nb Line, Nb colonne
    cv::Mat V3 = M * V; 
    
    std::cout << "---- M ----\n" << V3 << std::endl;

    // TODO

	return 0;
}

