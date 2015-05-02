/*
 * Carro.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#include "Carro.h"
#include "../Pista/Pista.h"

Carro::Carro(int tamanh, Pista<Carro> *destino) {
	this->tamanho = tamanh;
	this->destino = destino;
}

Carro::~Carro() {
	// TODO Auto-generated destructor stub
}

int Carro::getTamanho() {
	return 1 + this->tamanho + 2;
}

Carro::setDestino(Pista<Carro> novoDestino){
	this->destino = novoDestino;
}
