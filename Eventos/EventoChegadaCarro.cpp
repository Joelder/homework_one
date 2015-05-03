/*
 * EventoChegadaCarro.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#include "EventoChegadaCarro.h"

EventoChegadaCarro::EventoChegadaCarro(Carro* carro, Pista* pista) {
	this->carro = carro;
	this->pista = pista;
}


Carro* EventoChegadaCarro::getCarro() {
	return this->carro;
}

Pista* EventoChegadaCarro::getPista(){
	return this->pista;
}


EventoChegadaCarro::~EventoChegadaCarro() {
	// TODO Auto-generated destructor stub
}

