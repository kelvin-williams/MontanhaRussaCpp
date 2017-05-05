/*
 * Carro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#include "include/Carro.h"

//int Carro::capacidade = 0;;

Carro::Carro(Parque &p) : parque(p) {
	this->voltas = 1;
	Carro::capacidade = p.getNumPassageiros() / 2;
//	this->nPassageiros = 0;
	this->ticketi = 1;
	this->ticketo = 0;
	this->nexti = 1;
	this->nexto = 0;
	this->pic = 0; //pic = passengers in car
	this->andando = false;
	this->carroaberto = false;
}

Carro::~Carro() {
}

void Carro::esperaEncher() {

	std::cerr<<"\n\nCarro aberto";
	carroaberto = true;
	
	while(pic < capacidade){
		if(pic == parque.getNumPassageiros())
			break;
			
			continue;
			}
	carroaberto = false;

}

void Carro::daUmaVolta() {

	if(parque.getNumPassageiros() != 0){
	std::cerr<<"\n\nCarro Andando";
	andando = true;
	
	sleep(5);
	std::cerr<<"\nTerminou a volta nº "<<voltas;
	}
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
	std::cerr<<"\n\n======================/ Sem mais passageiros, Parque fechado /======================\n\n";
}
