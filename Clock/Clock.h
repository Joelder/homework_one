/*
 * Clock.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijoo
 */
#ifndef CLOCK_H_
#define CLOCK_H_

#include "../Estruturas/ListaEnc.hpp"
#include "../Eventos/Evento.cpp"

class Clock: public ListaEnc<Evento*> {

private:
	ListaEnc<Evento*>* eventos;

public:

	Clock();

	virtual ~Clock();

	void adicionaEvento(Evento* ev);

	Evento* retiraEvento();

	ListaEnc<Evento*>* getEventos();
};

#endif /* CLOCK_CLOCK_H_ */
