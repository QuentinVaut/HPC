#include <iostream>
#include <mpi.h>

int main(int argc, char ** argv)
{
    MPI_Init(&argc, &argv);

    int worldRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
    std::cout << "Hello, I am process #" << worldRank << std::endl; 

    MPI_Finalize();
    return 0;
}

