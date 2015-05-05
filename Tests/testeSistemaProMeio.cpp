/*
 * testeSistemaProMeio.cpp
 *
 *  Created on: May 5, 2015
 *      Author: thomas
 */

#ifndef TESTESISTEMAPROMEIO_CPP
#define TESTESISTEMAPROMEIO_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	Sistema* sistema = new Sistema(600);
	Pista* pistaOrigem = sistema->getGerador()->getPistaO1Leste();
	Pista* pistaDestino = sistema->getGerador()->getPistaC1Leste();
	Evento* novoCarro = new Evento(10, 1, 5, pistaOrigem, pistaDestino, NULL);
	sistema->getClock()->adicionaEvento(novoCarro);

	Evento* retira = sistema->retiraEventoClock();
	sistema->consomeEvento(retira);

	Evento* retira2 = sistema->retiraEventoClock();
	sistema->getGerador()->getPistaO1Leste()->setSemaforo();
	sistema->consomeEvento(retira2);

	Evento* retira3 = sistema->retiraEventoClock();
	int valorRetira3 = retira3->getId();
	int tamanhoPista = sistema->getGerador()->getPistaC1Leste()->size;
	int timestamp = retira3->getTimeStamp();
	sistema->getGerador()->getPistaC1Leste()->setSemaforo();
	sistema->consomeEvento(retira3);

	Evento* retira4 = sistema->retiraEventoClock();
	int valorRetira4 = retira4->getId();
	Pista* pista = retira4->getPistaDestino();
	int qualPista = pista->getTamanho();
	int timestamp4 = retira4->getTimeStamp();

	std::cout << "id retira4: " << valorRetira4 << std::endl;
	std::cout << "tamanho Pista: " << qualPista << std::endl;
	std::cout << "timestamp4: " << timestamp4 << std::endl;

	//std::cout << "id retira3: " << valorRetira3 << std::endl;
	//std::cout << "tamanho pista C1Leste: " << tamanhoPista << std::endl;
	//std::cout << "timestamp: " << timestamp << std::endl;

	return 0;

}

#endif
