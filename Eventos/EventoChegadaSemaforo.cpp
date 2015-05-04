/*
 * EventoChegadaSemaforo.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOCHEGADASEMAFORO_CPP
#define EVENTOCHEGADASEMAFORO_CPP
#include "EventoChegadaSemaforo.h"

EventoChegadaSemaforo::EventoChegadaSemaforo(Carro* carro, Pista* pista, int timestamp) {
	this->carro = carro;
	this->pistaOrigem = pista;
	this->timestamp = timestamp;
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

#endif
