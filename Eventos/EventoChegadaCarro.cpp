/*
 * EventoChegadaCarro.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */
#ifndef EVENTOCHEGADACARRO_CPP
#define EVENTOCHEGADACARRO_CPP
#include "EventoChegadaCarro.h"
using namespace std;
EventoChegadaCarro::EventoChegadaCarro(Carro* carro, Pista* pista, int timestamp, string name) : Evento(timestamp, name) {
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

#endif
