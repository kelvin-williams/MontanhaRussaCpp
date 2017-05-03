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
//	printf("\nPassageiro %d entrou na fila com ticket %d", id, filai);

	while(carroaberto == false || pic >= 5 || andando == true)continue;

	while(filai != nexti){
	continue;}

	std::cerr<<"\nPassageiro "<<id<<" entrou no carro com ticket "<<filai<<",    pic = "<<pic+1;
	pic = pic+1;
	

	nexti = nexti+1; //exit protocol

}

void Passageiro::esperaVoltaAcabar() {

	
	while(andando == false) continue;
	while(andando == true) continue;

}

void Passageiro::saiDoCarro() {

    Sincronizador Sync;
	filao = Sync.FetchAndAdd(&ticketo, 1); //entry protocol

	while(filao != nexto){
	continue;}

	pic = pic-1;
	std::cerr<<"\nPassageiro "<<id<<" saiu do carro,       pic = "<<pic;
	voltas++;

	nexto = nexto+1; //exit protocol

}

void Passageiro::passeiaPeloParque() {

	
	float r = 10 * (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	std::cerr<<"\nPassageiro "<<id<<" vai passear por "<<(int)r<<" segundos";
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

