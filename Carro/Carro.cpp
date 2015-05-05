/*
 * Carro.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#include "Carro.h"

#include <stdio.h>

Carro::Carro(int tamanho) {
	this->tamanho = tamanho;
	this->destino = NULL;
	this->carroChegou = false;
}

Carro::~Carro() {
	// TODO Auto-generated destructor stub
}

int Carro::getTamanho() {
	return 1 + this->tamanho + 2;
}

void Carro::setDestino(Pista* pista) {
	this->destino = pista;
}

Pista* Carro::getDestino() {
	return this->destino;
}

bool Carro::getCarroChegou(){
	return this->carroChegou;
}

void Carro::setCarroChegou(){
	this->carroChegou = !this->carroChegou;
}

