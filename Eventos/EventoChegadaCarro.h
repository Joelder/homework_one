/*
 * EventoChegadaCarro.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOCHEGADACARRO_H_
#define EVENTOS_EVENTOCHEGADACARRO_H_
#include "../Eventos/Evento.cpp"

class EventoChegadaCarro: public Evento {

private:
	Carro* carro;
	Pista* pista;

public:
	EventoChegadaCarro(Carro* carro, Pista* pista);

	virtual ~EventoChegadaCarro();

	Carro* getCarro();

	Pista* getPista();

	//Vai tirar o carro da pista
	// Gerar log no sistema
};

#endif /* EVENTOS_EVENTOCHEGADACARRO_H_ */
