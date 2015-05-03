/*
 * EventoTrocaPista.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOTROCAPISTA_H_
#define EVENTOS_EVENTOTROCAPISTA_H_

class EventoTrocaPista {
private:
	Carro* carro;

public:
	EventoTrocaPista(Carro* carro);

	virtual ~EventoTrocaPista();

	Carro* getCarro();

};

#endif /* EVENTOS_EVENTOTROCAPISTA_H_ */
