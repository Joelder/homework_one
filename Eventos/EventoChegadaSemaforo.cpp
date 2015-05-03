/*
 * EventoChegadaSemaforo.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#include "EventoChegadaSemaforo.h"

EventoChegadaSemaforo::EventoChegadaSemaforo(Carro* carro, Pista* pista) {
	this->carro = carro;
	this->pistaOrigem = pista;
}


Carro* EventoChegadaSemaforo::getCarro() {
	return this->carro;
}

Pista* EventoChegadaSemaforo::getPistaOrigem(){
	return this->pistaOrigem;
}

EventoChegadaSemaforo::~EventoChegadaSemaforo() {
	// TODO Auto-generated destructor stub
}

