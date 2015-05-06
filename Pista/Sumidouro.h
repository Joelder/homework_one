/*
 * Sumidouro.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef PISTA_SUMIDOURO_H_
#define PISTA_SUMIDOURO_H_
#include "Pista.cpp"
using namespace std;

class Sumidouro: public Pista {
public:
	Sumidouro(int proporcao, int tamanho, int velocidade, bool semaforo, string nome);
	virtual ~Sumidouro();
};

#endif /* PISTA_SUMIDOURO_H_ */
