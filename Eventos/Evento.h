/*
 * Evento.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef EVENTO_H_
#define EVENTO_H_
using namespace std;

class Evento {

private:
	string name;
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
	 * Evento Mudança Semaforo
	 * @params: pistaOrigem
	 * */

public:
	int timestamp;

	Evento(int timestamp, string name, int tamanhoCarro, Pista* pistaOrigem,
			Pista* pistaDestino, Carro* carro);

	int getTimeStamp();

	void setTimeStamp(int timestamp);

	virtual ~Evento();

	string getName();

	int getTamanhoCarrro();

	Pista* getPistaOrigem();

	Pista* getPistaDestino();

	Carro* getCarro();

};

#endif /* EVENTOS_EVENTO_H_ */
