/*
 * EventoChegadaSemaforo.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOCHEGADASEMAFORO_H_
#define EVENTOS_EVENTOCHEGADASEMAFORO_H_
#include "../Eventos/Evento.cpp"

class EventoChegadaSemaforo: public Evento {
private:
	Carro* carro;
	Pista* pistaOrigem;

public:

	EventoChegadaSemaforo(Carro* carro, Pista* pista, int timestamp);

	virtual ~EventoChegadaSemaforo();

	Carro* getCarro();

	Pista* getPistaOrigem();

};

#endif /* EVENTOS_EVENTOCHEGADASEMAFORO_H_ */
