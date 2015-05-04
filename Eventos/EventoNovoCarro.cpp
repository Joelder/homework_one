/*
 * EventoNovoCarro.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */
#ifndef EVENTONOVOCARRO_CPP
#define EVENTONOVOCARRO_CPP
#include "EventoNovoCarro.h"
using namespace std;

EventoNovoCarro::EventoNovoCarro(int tamanhoCarro, Pista* pistaOrigem,
		Pista* pistaDestino, int timestamp, string name) {
	this->tamanhoCarro = tamanhoCarro;
	this->pistaOrigem = pistaOrigem;
	this->pistaDestino = pistaDestino;
	this->timestamp = timestamp;
	this->name = name;
}

int EventoNovoCarro::getTamanhoCarrro() {
	return this->tamanhoCarro;
}

Pista* EventoNovoCarro::getPistaDestino() {
	return this->pistaDestino;
}

Pista* EventoNovoCarro::getPistaOrigem() {
	return this->pistaOrigem;
}

EventoNovoCarro::~EventoNovoCarro() {
	// TODO Auto-generated destructor stub
}

#endif
