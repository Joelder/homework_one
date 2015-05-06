/*
 * Fonte.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef PISTA_FONTE_H_
#define PISTA_FONTE_H_
#include "Pista.cpp"
using namespace std;

class Fonte: public Pista {
public:
	Fonte(int proporcao, int tamanho, int velocidade, bool semaforo, string nome);
	virtual ~Fonte();
};

#endif /* PISTA_FONTE_H_ */
