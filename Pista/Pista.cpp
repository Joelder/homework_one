/*
 * pista.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#include "Pista.h"

Pista::Pista() {
	// TODO Auto-generated constructor stub

}

Pista::~Pista() {
	// TODO Auto-generated destructor stub
}

int Pista::getTamanho() {
	return this->tamanho;
}

int Pista::getVelocidade() {
	return this->velocidade;
}

bool Pista::getSemaforo() {
	return this->semaforo;
}

void Pista::setSemaforo() {
	!this->semaforo;
}

bool Pista::getPistaCheia() {
	return this->pistaCheia;
}

void Pista::setPistaCheia() {
	!this->pistaCheia;
}

Lista<Pista*> Pista::getPistasConectadas() {
	return this->pistasConectadas;
}
