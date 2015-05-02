/*
 * pista.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#include "Pista.h"
#include "../Estruturas/Lista.hpp"

Pista::Pista(int tamanho, int velocidade) {
	this->tamanho = tamanho;
	this->velocidade = velocidade;
	this->semaforo = false;
	this->pistaCheia = false;
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
	switch(this->semaforo);
}

bool Pista::getPistaCheia() {
	return this->pistaCheia;
}

void Pista::setPistaCheia() {
	switch(this->pistaCheia);
}

Lista<Pista*>* Pista::getPistasConectadas() {
	return this->pistasConectadas;
}

void Pista::adicionarCarroPista(Carro* carro) {
	FilaEnc<Carro*>::adiciona(carro);
}

void Pista::retirarCarroPista() {
	FilaEnc<Carro*>::retira();
}

void Pista::conectarPistas(Pista* pista1, Pista* pista2, Pista* pista3) {
	this->pistasConectadas->adiciona(pista1);
	this->pistasConectadas->adiciona(pista2);
	this->pistasConectadas->adiciona(pista3);
}

bool Pista::transferirCarro() {
}

