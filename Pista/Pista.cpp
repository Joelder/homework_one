/*
 * pista.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijoo
 */

#ifndef PISTA_CPP
#define PISTA_CPP
#include <stdlib.h>
#include "Pista.h"
#include "../util/GeradorAleatorios.cpp"

Pista::Pista(int proporcao, int tamanho, int velocidade, bool semaforo) {
	this->proporcao = proporcao;
	this->tamanho = tamanho;
	this->espacoRestante = tamanho;
	this->velocidade = velocidade;
	this->semaforo = semaforo;
	this->pistasConectadas = new Lista<Pista*>;
}

Pista::~Pista() {
	// TODO Auto-generated destructor stub
}

int Pista::getProporcao() {
	return this->proporcao;
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
	Carro* auxiliar = FilaEnc<Carro*>::primeiro();
	if (this->semaforo
			&& pista->getEspacoRestante() >= auxiliar->getTamanho()) {
		pista->adicionarCarroPista(auxiliar);
		this->retirarCarroPista();
		return true;
	} else {
		return false;
	}
}

int Pista::getPistaConectadaProporcao() {
	GeradorAleatorios* gerador = new GeradorAleatorios();
	srand(time(NULL));
	if (this->getProporcao()) {
		int a = gerador->gerarProbabilidade();
		if (a <= 4) {
			return 0;
		} else if (a <= 7) {
			return 1;
		} else {
			return 2;
		}
	} else {
		int b = gerador->gerarProbabilidade();
		if (b <= 8) {
			return 0;
		} else if (b == 9) {
			return 1;
		} else {
			return 2;
		}
	}

}

#endif /* PISTA_CPP */
