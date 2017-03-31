
#include <cmath>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

#include <omp.h>

// output data as a grayscale PNM image
void writePnm(std::ostream &os, int width, int height, 
        const std::vector<unsigned char> & data) 
{
    os << "P2" << std::endl;
    os << width << ' ' << height << std::endl;
    os << "255" << std::endl;
    for (unsigned char pixel : data) os << (unsigned)pixel << ' ';
}

int main(int argc, char ** argv)
{
    // check command line arguments
    if (argc!=4 and argc!=3)
    {
        std::cout << "usage; " << argv[0] 
            << " <width> <height> [PNM filename] \n";
        return -1;
    }

    // reserve image data
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    std::vector<unsigned char> data(width*height);
    auto ind = [&data,width](int xx, int yy)->unsigned char& 
    { return data[yy*width+xx]; };

    // start chrono 
    double startTime = omp_get_wtime();

    // compute image data
    // TODO
   
    omp_set_num_threads(3);
    
		std::cout << omp_get_num_threads() << std::endl;
		#pragma omp parallel for 
		for (int x=0; x<width; x++)
		{
			for (int y=0; y<height; y++)
			{
				// diagonal gradient
				// TODO remove that
				//double t = (x+y) / sqrt(width*width + height*height);
				//t = (x+y)/10000;
				//double f = 2.0;
				

				// put the color of the thread
				// TODO
				double c = omp_get_thread_num() * (255/(omp_get_num_threads()-1));
				ind(x,y) = c;
			}
		}

    // stop chrono
    double endTime = omp_get_wtime();
    std::cout << argv[1] << ' ' << argv[2] << ' ' << endTime - startTime 
        << std::endl;

    // write image in a file
    if (argc==4)
    {
        std::ofstream ofs(argv[3]);
        writePnm(ofs, width, height, data);
    }

    return 0;
}

