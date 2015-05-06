/*
 * Sumidouro.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef SUMIDOURO_CPP
#define SUMIDOURO_CPP
#include "Sumidouro.h"
using namespace std;

Sumidouro::Sumidouro(int proporcao, int tamanho, int velocidade, bool semaforo, string nome) :
		Pista(0, tamanho, velocidade, true, nome) {
}

Sumidouro::~Sumidouro() {
	// TODO Auto-generated destructor stub
}

#endif
