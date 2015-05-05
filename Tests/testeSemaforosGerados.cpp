/*
 * testeSemaforosGerados.cpp
 *
 *  Created on: May 5, 2015
 *      Author: thomas
 */

#ifndef TESTESEMAFOROSGERADOS_CPP
#define TESTESEMAFOROSGERADOS_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	Sistema* sistema = new Sistema(600);
	sistema->geraEventosIniciais();
	int tamanhoClock = sistema->getClock()->getEventos()->size;
	for (int i = 0; i < tamanhoClock; i++) {
		int timestamp = sistema->getClock()->getEventos()->getPosicao(i)->getTimeStamp();
		std::cout << "timestamp: " << timestamp << std::endl;
	}
	//std::cout << "tamanho clock: " << tamanhoClock << std::endl;
	return 0;

}

#endif
