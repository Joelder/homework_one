/*
 * Clock.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijoo
 */

#include "../Estruturas/ListaEnc.hpp"

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

class Clock: private ListaEnc<Evento> {

//private:
	//ListaEnc<Evento>* eventos;

public:
	Clock();
	virtual ~Clock();

	//implementar como uma lista encadeada de eventos ordenada pelo timestamp do evento
	//adicionar na lista evento
	//retirar o evento da lista
	// gerador de numeros aleatorios

	void adicionaEvento(const Evento& ev) {
		this->adicionaEmOrdem(ev);
	}

	Evento retiraEvento() {
		this->retiraDoInicio();
	}

};

#endif /* CLOCK_CLOCK_H_ */
