/*
 * pista.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijoo
 */

#ifndef PISTA_CPP
#define PISTA_CPP
#include "Pista.h"

Pista::Pista(int tamanho, int velocidade, bool semaforo) {
	this->tamanho = tamanho;
	this->espacoRestante = tamanho;
	this->velocidade = velocidade;
	this->semaforo = semaforo;
	this->pistasConectadas = new Lista<Pista*>;
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
	this->semaforo = !this->semaforo;
}

int Pista::getEspacoRestante() {
	return this->espacoRestante;
}

Lista<Pista*>* Pista::getPistasConectadas() {
	return this->pistasConectadas;
}

void Pista::adicionarCarroPista(Carro* carro) {
	FilaEnc<Carro*>::inclui(carro);
	this->espacoRestante -= carro->getTamanho();
}

void Pista::retirarCarroPista() {
	Carro* carro = FilaEnc<Carro*>::retira();
	this->espacoRestante += carro->getTamanho();
}

void Pista::conectarPistas(Pista* pista1, Pista* pista2, Pista* pista3) {
	this->pistasConectadas->adiciona(pista1);
	this->pistasConectadas->adiciona(pista2);
	this->pistasConectadas->adiciona(pista3);
}

bool Pista::transferirCarro(Pista* pista) {
	Carro* auxiliar = FilaEnc::primeiro();
	if (this->semaforo && pista->getEspacoRestante() >= auxiliar->getTamanho()) {
		pista->adicionarCarroPista(auxiliar);
		this->retirarCarroPista();
		return true;
	} else {
		return false;
	}
}
#endif /* PISTA_CPP */
