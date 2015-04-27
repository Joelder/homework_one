/*
 * pista.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef PISTA_H_
#define PISTA_H_
#include "../Estruturas/FilaEnc.hpp"

class Pista: private FilaEnc {

private:
	int tamanho;
	int velocidade;
	bool semaforo;
	Lista<Pista>* pistas;


public:
	Pista();
	virtual ~Pista();
};

#endif /* PISTA_H_ */
