/*
 * Clock.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#include "Clock.h"

#include "../Eventos/Evento.h"

Clock::Clock() {
	this->eventos = new ListaEnc<Evento*>;
}

void Clock::adicionaEvento(Evento* ev) {
	this->adicionaEmOrdem(ev);
}

Evento* Clock::retiraEvento() {
	return this->retiraDoInicio();
}

Clock::~Clock() {
	// TODO Auto-generated destructor stub
}

