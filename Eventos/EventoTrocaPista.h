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
	// parametros para mudar a trajetoria do carro caso a pista seja a do meio

};

#endif /* EVENTOS_EVENTOTROCAPISTA_H_ */
