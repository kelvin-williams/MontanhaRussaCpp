/*
 * Carro.h
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#ifndef CARRO_H_
#define CARRO_H_

#include "Thread.h"
#include "Parque.h"
//#include "definitions.h"

class Carro: public Thread {
public:
	Carro(Parque &p);
	virtual ~Carro();
	void esperaEncher();
	void daUmaVolta();
	void esperaEsvaziar();
	int getNVoltas();
	Parque &getParque();
	int ticketi;
    int ticketo;
    int nexti;
    int nexto;

    int pic; //pic = passengers in car
    bool andando;
    bool carroaberto;

	void run();
private:
	static int capacidade;
	int voltas;
//	int nPassageiros;
	Parque &parque;
};

#endif /* CARRO_H_ */
