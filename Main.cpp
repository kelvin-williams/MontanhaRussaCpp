//#include "include/definitions.h"

int npass = 10;

#include <iostream>
#include <unistd.h>
#include "Parque.cpp"
#include "Passageiro.cpp"
#include "Carro.cpp"
#include "Sincronizador.cpp"
#include "Thread.cpp"

#define NUM_THREADS 10



using namespace std;


int main() {

	Parque p(npass);

    Carro c(p);
    
    Passageiro *passageiros[npass];

	for(int i = 0; i<npass; i++ ){

		passageiros[i] = new Passageiro(c);
		passageiros[i]->id = i;

	}

	c.start();
	for(int k = 0; k<npass; k++){

		passageiros[k]->start();
	}

	c.join();

	return 0;
}
