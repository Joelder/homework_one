/*
 * EventoMudancaSemaforo.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#include "EventoMudancaSemaforo.h"

EventoMudancaSemaforo::EventoMudancaSemaforo(Pista* pista) {
	this->pista = pista;
}

Pista* EventoMudancaSemaforo::getPista(){
	return this->pista;
}

EventoMudancaSemaforo::~EventoMudancaSemaforo() {
	// TODO Auto-generated destructor stub
}

