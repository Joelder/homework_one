/*
 * testeGerarCarros.cpp
 *
 *  Created on: May 5, 2015
 *      Author: thomas
 */

#ifndef TESTEGERARCARROS_CPP
#define TESTEGERARCARROS_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	Sistema* sistema = new Sistema(600);
	sistema->geraEventosIniciais();
	int tamanhoClock = sistema->getClock()->getEventos()->size;
	for (int i = 0; i < tamanhoClock; i++) {
		int id =	sistema->getClock()->getEventos()->getPosicao(i)->getId();
		int timestamp =	sistema->getClock()->getEventos()->getPosicao(i)->getTimeStamp();
		std::cout << "id e timestamp: " << id << " ";
		std::cout << timestamp << std::endl;
	}
	return 0;

}

#endif
