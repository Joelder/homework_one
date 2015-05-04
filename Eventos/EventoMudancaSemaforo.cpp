/*
 * EventoMudancaSemaforo.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOMUDANCASEMAFORO_CPP
#define EVENTOMUDANCASEMAFORO_CPP
#include "EventoMudancaSemaforo.h"
using namespace std;

EventoMudancaSemaforo::EventoMudancaSemaforo(Pista* pista, int timestamp,
		string name) :
		Evento(timestamp, name) {
	this->pista = pista;
}

Pista* EventoMudancaSemaforo::getPista() {
	return this->pista;
}

EventoMudancaSemaforo::~EventoMudancaSemaforo() {
	// TODO Auto-generated destructor stub
}

#endif
