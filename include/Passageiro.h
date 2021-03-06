/*
 * Passageiro.h
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#ifndef PASSAGEIRO_H_
#define PASSAGEIRO_H_

#include "Thread.h"
#include "Carro.h"
#include "Sincronizador.h"
//#include "definitions.h"

class Passageiro: public Thread {
public:
	Passageiro(Carro &c);
	virtual ~Passageiro();
	void entraNoCarro();
	void esperaVoltaAcabar();
	void saiDoCarro();
	void passeiaPeloParque();
	bool parqueFechado();
	int id;
	int filai;
	int filao;
	int voltas;

	void run();
private:
	Carro &carro;
};

#endif /* PASSAGEIRO_H_ */
