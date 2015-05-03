/*
 * Carro.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#include "Carro.h"

Carro::Carro(int tamanho) {
	this->tamanho = tamanho;
}

Carro::~Carro() {
	// TODO Auto-generated destructor stub
}

int Carro::getTamanho() {
	return 1 + this->tamanho + 2;
}




