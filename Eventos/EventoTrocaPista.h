/*
 * EventoTrocaPista.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOTROCAPISTA_H_
#define EVENTOS_EVENTOTROCAPISTA_H_
#include "../Eventos/Evento.cpp"

class EventoTrocaPista: private Evento {
public:
	EventoTrocaPista();
	virtual ~EventoTrocaPista();

	// parametros para mudar a trajetoria do carro caso a pista seja a do meio

};

#endif /* EVENTOS_EVENTOTROCAPISTA_H_ */