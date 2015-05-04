/*
 * EventoNovoCarro.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTONOVOCARRO_H_
#define EVENTOS_EVENTONOVOCARRO_H_
#include "../Eventos/Evento.cpp"
#include "../Pista/Pista.cpp"

class EventoNovoCarro: public Evento {
private:
	int tamanhoCarro;
	Pista* pistaOrigem;
	Pista* pistaDestino;

public:
	EventoNovoCarro(int tamanhoCarro, Pista* pistaOrigem, Pista* pistaDestino,
			int timestamp, string name);

	virtual ~EventoNovoCarro();

	int getTamanhoCarrro();

	Pista* getPistaOrigem();

	Pista* getPistaDestino();
};

#endif /* EVENTOS_EVENTONOVOCARRO_H_ */
