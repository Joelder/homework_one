/*
 * EventoMudancaSemaforo.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOMUDANCASEMAFORO_CPP
#define EVENTOMUDANCASEMAFORO_CPP
#include "EventoMudancaSemaforo.h"

EventoMudancaSemaforo::EventoMudancaSemaforo(Pista* pista, int timestamp) {
	this->pista = pista;
	this->timestamp = timestamp;
}

Pista* EventoMudancaSemaforo::getPista(){
	return this->pista;
}

EventoMudancaSemaforo::~EventoMudancaSemaforo() {
	// TODO Auto-generated destructor stub
}

#endif
