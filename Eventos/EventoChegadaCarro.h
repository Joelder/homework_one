/*
 * EventoChegadaCarro.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOCHEGADACARRO_H_
#define EVENTOS_EVENTOCHEGADACARRO_H_
#include "../Eventos/Evento.cpp"
using namespace std;
class EventoChegadaCarro: public Evento {

private:
	Carro* carro;
	Pista* pista;

public:
	EventoChegadaCarro(Carro* carro, Pista* pista, int timestamp, string name);

	virtual ~EventoChegadaCarro();

	Carro* getCarro();

	Pista* getPista();
};

#endif /* EVENTOS_EVENTOCHEGADACARRO_H_ */
