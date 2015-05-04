/*
 * Clock.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijoo
 */

#include "../Estruturas/ListaEnc.hpp"
#include "../Eventos/Evento.cpp"

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

class Clock: public ListaEnc<Evento*> {

private:
	ListaEnc<Evento*>* eventos;

public:

	Clock();

	virtual ~Clock();

	void adicionaEvento(Evento* ev);

	Evento* retiraEvento();

	ListaEnc<Evento*>* getEvento();
};

#endif /* CLOCK_CLOCK_H_ */
