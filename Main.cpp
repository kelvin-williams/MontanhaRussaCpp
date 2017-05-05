#define NUM_THREADS 20
#define MAX_NUM_VOLTAS 10

int npass = NUM_THREADS;

#include <iostream>
#include <unistd.h>
#include "Parque.cpp"
#include "Passageiro.cpp"
#include "Carro.cpp"
#include "Sincronizador.cpp"
#include "Thread.cpp"


using namespace std;


int main() {

	Parque p(npass);

    Carro c(p);
    
    Passageiro *passageiros[npass];

	for(int i = 0; i<npass; i++ ){

		passageiros[i] = new Passageiro(c);
		passageiros[i]->id = i+1;

	}

	c.start();
	for(int k = 0; k<npass; k++){

		passageiros[k]->start();
	}

	c.join();

	return 0;
}
