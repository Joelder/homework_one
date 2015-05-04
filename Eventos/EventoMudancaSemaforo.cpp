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

EventoMudancaSemaforo::EventoMudancaSemaforo(Pista* pista, int timestamp, string name) {
	this->pista = pista;
	this->timestamp = timestamp;
	this->name = name;
}

Pista* EventoMudancaSemaforo::getPista(){
	return this->pista;
}

EventoMudancaSemaforo::~EventoMudancaSemaforo() {
	// TODO Auto-generated destructor stub
}

#endif
