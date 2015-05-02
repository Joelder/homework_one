/*
 * EventoMudancaSemaforo.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOMUDANCASEMAFORO_H_
#define EVENTOS_EVENTOMUDANCASEMAFORO_H_
#include "../Eventos/Evento.cpp"

class EventoMudancaSemaforo: private Evento {
public:
	EventoMudancaSemaforo();
	virtual ~EventoMudancaSemaforo();

	// pista
	// get
	// mudar a semaforo da pista
	//Pode gerar evento troca pista


};

#endif /* EVENTOS_EVENTOMUDANCASEMAFORO_H_ */
