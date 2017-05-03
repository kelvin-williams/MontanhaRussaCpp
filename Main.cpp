#include "include/definitions.h"

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

	Parque p(10);

    Carro c(p);
    
    Passageiro *passageiros[10];

	for(int i = 0; i<10; i++ ){

		passageiros[i] = new Passageiro(c);
		passageiros[i]->id = i;

	}

	c.start();
	for(int k = 0; k<10; k++){

		passageiros[k]->start();
	}

	c.join();

	return 0;
}
