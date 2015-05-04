/*
 * Evento.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */
#ifndef EVENTO_CPP
#define EVENTO_CPP
#include "Evento.h"
using namespace std;

Evento::Evento(int timestamp, string name, int tamanhoCarro, Pista* pistaOrigem, Pista* pistaDestino, Carro* carro) {
	this->timestamp = timestamp;
	this->name = name;
	this->tamanhoCarro = tamanhoCarro;
	this->pistaOrigem = pistaOrigem;
	this->pistaDestino = pistaDestino;
	this->carro = carro;
}

int Evento::getTimeStamp(){
	return this->timestamp;
}

void Evento::setTimeStamp(int timestamp){
	this->timestamp = timestamp;
}

Evento::~Evento() {
	// TODO Auto-generated destructor stub
}

string Evento::getName() {
	return this->name;
}

int Evento::getTamanhoCarrro() {
	return this->tamanhoCarro;
}

Pista* Evento::getPistaDestino() {
	return this->pistaDestino;
}

Pista* Evento::getPistaOrigem() {
	return this->pistaOrigem;
}

Carro* Evento::getCarro() {
	return this->carro;
}



#endif
