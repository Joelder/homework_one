/*
 * Carro.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef CARRO_H_
#define CARRO_H_

#include "../Pista/Pista.h"

class Carro {
private:
	int tamanho;
	Pista<Carro*> *destino;

public:
	Carro(int tamanh, Pista<Carro*> *destino);
	virtual ~Carro();
	int getTamanho();
	Pista<Carro> setDestino(Pista<Carro> novoDestino);
	// implementar gets
	// implementar atributo destino
	// set destino
};

#endif /* CARRO_H_ */
