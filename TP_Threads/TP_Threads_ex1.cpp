
#include <iostream>
#include <thread>

// fonction qui affiche l'id du thread qui l'execute
void noyauCalcul() 
{
    std::thread::id idThread = std::this_thread::get_id();
    std::cout << "Bonjour, je suis le thread " << idThread << std::endl;
    
}

int main(int , char ** )
{
    // affiche l'id du thread principal
    noyauCalcul();

    // TODO cree deux threads qui affiche leur id
    std::thread thread1(noyauCalcul);  // appel non-bloquant
    std::thread thread2(noyauCalcul);  // appel non-bloquant

    // TODO attend la fin de l'execution des threads
    thread1.join();
    thread2.join();

    return 0;
}

