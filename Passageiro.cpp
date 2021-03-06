/*
 * Passageiro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#include "include/Passageiro.h"
#include <random>

Passageiro::Passageiro(Carro &c) : carro(c) {
}

Passageiro::~Passageiro() {
}

void Passageiro::entraNoCarro() {
	

	Sincronizador Sync;
	filai = Sync.FetchAndAdd(&(carro.ticketi), 1); //entry protocol
//	printf("\nPassageiro %d entrou na fila com ticket %d", id, filai);

	while(filai != carro.nexti){
	continue;}

	while(carro.carroaberto == false || carro.pic >= carro.capacidade)continue;

	std::cerr<<"\nPassageiro "<<id<<" entrou no carro com ticket "<<filai<<",    pic = "<<carro.pic+1;
	carro.pic = carro.pic+1;
	

	carro.nexti = carro.nexti+1; //exit protocol

}

void Passageiro::esperaVoltaAcabar() {

	
	while(carro.andando == false) continue;
	while(carro.andando == true) continue;

}

void Passageiro::saiDoCarro() {

    Sincronizador Sync;
	filao = Sync.FetchAndAdd(&(carro.ticketo), 1); //entry protocol

	while(filao != carro.nexto){
	continue;}

	std::cerr<<"\nPassageiro "<<id<<" saiu do carro,       pic = "<<carro.pic-1;
	carro.pic = carro.pic-1;
	
	voltas++;

	carro.nexto = carro.nexto+1; //exit protocol

}

void Passageiro::passeiaPeloParque() {

	
	float r = 10 * (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	std::cerr<<"\nPassageiro "<<id<<" vai passear por "<<(int)r<<" segundo(s)";
	sleep(r);

}

bool Passageiro::parqueFechado() {
	if (carro.nexti <= MAX_NUM_VOLTAS * carro.capacidade)
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

	std::cerr<<"\n\nPassageiro "<<id<<" saiu do parque"<<", Número de voltas = "<<voltas<<std::endl;
	npass--;// decrementa o numero de passageiros no parque
}

