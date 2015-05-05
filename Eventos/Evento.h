/*
 * Evento.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef EVENTO_H_
#define EVENTO_H_
#include "../Pista/Fonte.cpp"
#include "../Pista/Sumidouro.cpp"

class Evento {

private:
	int id;
	int tamanhoCarro;
	Pista* pistaOrigem;
	Pista* pistaDestino;
	Carro* carro;

	/*
	 * Evento Novo carro
	 * @params: tamanhoCarro, pistaOrigem, pistaDestino
	 * */

	/*
	 * Evento Chegada carro
	 * @params: pistaDestino, carro
	 * */

	/*
	 * Evento Chegada Semaforo
	 * @params: pistaOrigem, carro
	 * */

	/*
	 * Evento Chegada Final Fila
	 * @params: pistaOrigem, carro
	 * */

	/*
	 * Evento Mudança Semaforo
	 * @params: pistaOrigem
	 * */

public:
	int timestamp;

	Evento(int timestamp, int id, int tamanhoCarro, Pista* pistaOrigem,
			Pista* pistaDestino, Carro* carro);

	int getTimeStamp();

	void setTimeStamp(int timestamp);

	virtual ~Evento();

	int getId();

	int getTamanhoCarrro();

	Pista* getPistaOrigem();

	Pista* getPistaDestino();

	Carro* getCarro();

};

#endif /* EVENTOS_EVENTO_H_ */
