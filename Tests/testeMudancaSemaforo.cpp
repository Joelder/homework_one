/*
 * testeMudancaClock.cpp
 *
 *  Created on: May 4, 2015
 *      Author: thomas
 */

#ifndef TESTEMUDANCASEMAFORO_CPP
#define TESTEMUDANCASEMAFORO_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	Sistema* sistema = new Sistema();
	Pista* pista = sistema->getGerador()->getPistaO1Leste();
	bool semaforoAntes = sistema->getGerador()->getPistaO1Leste()->getSemaforo();
	Evento* evento = new Evento(10, 4, 0, pista, NULL, NULL);
	sistema->incluiEventoClock(evento);
	int depoisIncluirClock = sistema->getClock()->getEventos()->size;
	Evento* retira = sistema->getClock()->retiraEvento();
	sistema->consomeEvento(retira);
	int depoisRetirarClock = sistema->getClock()->getEventos()->size;
	bool semaforoDepois = sistema->getGerador()->getPistaO1Leste()->getSemaforo();

	std::cout << "tamanho depois de incluir: " << depoisIncluirClock
				<< std::endl;
	std::cout << "tamanho depois de retirar do clock: " << depoisRetirarClock
					<< std::endl;
	std::cout << "semaforo na criacao: " << semaforoAntes
					<< std::endl;
	std::cout << "semaforo depois: " << semaforoDepois
					<< std::endl;
	return 0;

}

#endif
