
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

// calcule le Nieme terme de la suite de "Fibonacci modulo 42"
// precondition : N >= 0
int FibonacciMod42(int N)
{
    int f_curr = 0;
    int f_prec = 1;
    for (int i=1; i<=N; i++)
    {
        int tmp = f_curr;
        f_curr = (f_curr + f_prec) % 42;
        f_prec = tmp;
    }
    return f_curr;
}

void calculer(std::vector<int> & data,int i0,int nbThread, int i1) {
	for (int i=i0; i<i1; i+=nbThread) {
		data[i] = FibonacciMod42(i);	
	}	
}

int main(int argc, char ** argv)
{
    // verifie les arguments de la ligne de commande
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " <nbData>" << std::endl;
        return -1;
    }

    // cree le tableau de donnees a calculer
    int nbData = std::stoi(argv[1]);
    std::vector<int> data(nbData); 

    // calcule le tableau de donnees 
	// TODO
	/*for (int i=1; i<=nbData; i++)
    {
		//std::cout << "FIBO : " << FibonacciMod42(i) << std::endl;
		data[i] = FibonacciMod42(i);
	}*/
	
	std::thread th1(calculer,std::ref(data),0,2,nbData);
	std::thread th2(calculer,std::ref(data),1,2,nbData);
	
	th1.join();
	th2.join();
	
	
    // ecrit les donnees calculees dans un fichier
    std::ofstream ofs("output.txt");
    for (int x : data)
    {
        ofs << x << ' ';
    }

    return 0;
}

