/*
 * EventoMudancaSemaforo.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOMUDANCASEMAFORO_H_
#define EVENTOS_EVENTOMUDANCASEMAFORO_H_
#include "../Eventos/Evento.cpp"

class EventoMudancaSemaforo: public Evento {
private:
	Pista* pista;

public:
	EventoMudancaSemaforo(Pista* pista, int timestamp, string name);

	virtual ~EventoMudancaSemaforo();

	Pista* getPista();
};

#endif /* EVENTOS_EVENTOMUDANCASEMAFORO_H_ */
