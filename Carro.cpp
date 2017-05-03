/*
 * Carro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#include "include/Carro.h"

int Carro::capacidade = 0;;

Carro::Carro(Parque &p) : parque(p) {
	this->voltas = 0;
	Carro::capacidade = p.getNumPassageiros() / 2;
	this->nPassageiros = 0;
}

Carro::~Carro() {
}

void Carro::esperaEncher() {

	std::cerr<<"\n\nCarro aberto";
	carroaberto = true;
	
	while(pic < 5)continue;
	carroaberto = false;

}

void Carro::daUmaVolta() {

//	carroaberto = false;
	std::cerr<<"\n\nCarro Andando";
	andando = true;
	
	sleep(5);
	std::cerr<<"\nTerminou";
}

void Carro::esperaEsvaziar() {

	andando = false;
	while(pic != 0)continue;
//	carroaberto = true;
//	printf("\n\nCarro aberto");


}

int Carro::getNVoltas() {
	return voltas;
}

Parque &Carro::getParque() {
	return parque;
}

void Carro::run() {
	while (parque.getNumPassageiros() > 0) {
		esperaEncher();

		daUmaVolta();

		esperaEsvaziar();

		voltas++;
	}
}
