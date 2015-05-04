/*
 * testeClock.cpp
 *
 *  Created on: May 4, 2015
 *      Author: thomas
 */

#ifndef TESTECLOCK_CPP
#define TESTECLOCK_CPP

#include <iostream>

#include "../Clock/Clock.cpp"
#include "../Clock/Clock.h"
#include "../Estruturas/ListaEnc.hpp"
#include "../Eventos/Evento.cpp"
#include "../Eventos/Evento.h"

int main(int argc, char** argv) {
	Clock* clock = new Clock();
	Evento* evento = new Evento(8);
	Evento* evento2 = new Evento(10);
	Evento* evento3 = new Evento(9);

	clock->adicionaEvento(evento2);
	clock->adicionaEvento(evento);
	clock->adicionaEvento(evento3);

	int posicaoEvento1 = clock->getEventos()->getPosicao(0)->getTimeStamp();
	int posicaoEvento2 = clock->getEventos()->getPosicao(1)->getTimeStamp();
	int posicaoEvento3 = clock->getEventos()->getPosicao(2)->getTimeStamp();

	std::cout << "posicao 1 : " << posicaoEvento1 << std::endl;
	std::cout << "posicao 2 : " << posicaoEvento2 << std::endl;
	std::cout << "posicao 3 : " << posicaoEvento3 << std::endl;
	return 0;

}

#endif
