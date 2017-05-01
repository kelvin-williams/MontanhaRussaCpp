/*
 * Passageiro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#include "include/Passageiro.h"
#include <random>

#define MAX_NUM_VOLTAS 100

Passageiro::Passageiro(Carro &c) : carro(c) {
}

Passageiro::~Passageiro() {
}

void Passageiro::entraNoCarro() {
	

	Sincronizador Sync;
	filai = Sync.FetchAndAdd(&ticketi, 1); //entry protocol
	printf("\nPassageiro %d entrou na fila", id);

	while(carroaberto == false || pic >= 5)continue;

	while(filai != nexti){
	continue;}

	pic = pic+1;
	printf("\nPassageiro %d entrou no carro", id); 

	nexti = nexti+1; //exit protocol

}

void Passageiro::esperaVoltaAcabar() {

	while(andando == true) continue;

}

void Passageiro::saiDoCarro() {

    Sincronizador Sync;
	filao = Sync.FetchAndAdd(&ticketo, 1); //entry protocol

	while(filao != nexto){
	continue;}

	pic = pic-1;
	printf("\nPassageiro %d saiu no carro", id);

	nexto = nexto+1; //exit protocol

}

void Passageiro::passeiaPeloParque() {

	printf("\nPassageiro %d está passeando", id);
	float r = 10 * (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	sleep(r);

}

bool Passageiro::parqueFechado() {
	if (carro.getNVoltas() <= MAX_NUM_VOLTAS)
		return false;

	return true;
}

void Passageiro::run() {
	while (!parqueFechado()) {
		entraNoCarro(); // protocolo de entrada

		esperaVoltaAcabar();

		saiDoCarro(); // protocolo de saida

		passeiaPeloParque(); // secao nao critica
	}

	// decrementa o numero de passageiros no parque
}

