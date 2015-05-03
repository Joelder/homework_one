/*
 * Sumidouro.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef PISTA_SUMIDOURO_H_
#define PISTA_SUMIDOURO_H_
#include "Pista.cpp"

class Sumidouro: public Pista {
public:
	Sumidouro(int tamanho, int velocidade, bool semaforo);
	virtual ~Sumidouro();
};

#endif /* PISTA_SUMIDOURO_H_ */
