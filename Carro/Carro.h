/*
 * Carro.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef CARRO_H_
#define CARRO_H_

#include "../Pista/Pista.cpp"

class Pista;
class Carro {
private:
	int tamanho;
	bool carroChegou;
	Pista* destino;

public:
	Carro(int tamanho);
	virtual ~Carro();
	int getTamanho();
	void setDestino(Pista* pista);
	Pista* getDestino();
	bool getCarroChegou();
	void setCarroChegou();
};

#endif /* CARRO_H_ */
