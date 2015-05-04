/*
 * Clock.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */
#ifndef CLOCK_CPP
#define CLOCK_CPP
#include "Clock.h"

#include "../Eventos/Evento.h"

Clock::Clock() {
	this->eventos = new ListaEnc<Evento*>;
}

void Clock::adicionaEvento(Evento* ev) {
	int tamanhoLista = this->eventos->size;
	int count = 0;
	while(count < tamanhoLista && this->eventos->getPosicao(count)->getTimeStamp() < ev->getTimeStamp()){
		count++;
	}
	this->eventos->adicionaNaPosicao(ev,count);
}

Evento* Clock::retiraEvento() {
	return this->eventos->retiraDoInicio();
}

ListaEnc<Evento*>* Clock::getEventos() {
	return this->eventos;
}

Clock::~Clock() {
	// TODO Auto-generated destructor stub
}
#endif
