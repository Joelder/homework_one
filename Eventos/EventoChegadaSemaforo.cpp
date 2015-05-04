/*
 * EventoChegadaSemaforo.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOCHEGADASEMAFORO_CPP
#define EVENTOCHEGADASEMAFORO_CPP
#include "EventoChegadaSemaforo.h"
using namespace std;

EventoChegadaSemaforo::EventoChegadaSemaforo(Carro* carro, Pista* pista,
		int timestamp, string name) :
		Evento(timestamp, name) {
	this->carro = carro;
	this->pistaOrigem = pista;
}

Carro* EventoChegadaSemaforo::getCarro() {
	return this->carro;
}

Pista* EventoChegadaSemaforo::getPistaOrigem() {
	return this->pistaOrigem;
}

EventoChegadaSemaforo::~EventoChegadaSemaforo() {
	// TODO Auto-generated destructor stub
}

#endif
