/*
 * EventoChegadaCarro.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOCHEGADACARRO_H_
#define EVENTOS_EVENTOCHEGADACARRO_H_
#include "../Eventos/Evento.cpp"

class EventoChegadaCarro: private Evento {
public:
	EventoChegadaCarro();
	virtual ~EventoChegadaCarro();

	//Vai tirar o carro da pista
	// Gerar log no sistema
};

#endif /* EVENTOS_EVENTOCHEGADACARRO_H_ */