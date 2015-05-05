/*
 * testeSistema.cpp
 *
 *  Created on: May 4, 2015
 *      Author: thomas
 */

#ifndef TESTESISTEMA_CPP
#define TESTESISTEMA_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	Sistema* sistema = new Sistema(600);
	Pista* pistaOrigem = sistema->getGerador()->getPistaO1Leste();
	Pista* pistaDestino = sistema->getGerador()->getPistaS1Sul();
	//int tamanhoPista = sistema->getGerador()->getPistaO1Leste()->size;
	Evento* novoCarro = new Evento(10, 1, 5, pistaOrigem, pistaDestino, NULL);
	sistema->getClock()->adicionaEvento(novoCarro);

	Evento* retira = sistema->retiraEventoClock();
	sistema->consomeEvento(retira);
	Evento* retira2 = sistema->retiraEventoClock();

	//int valorTimestamp = retira2->getTimeStamp();
	//int valorRetira = retira2->getId();
	//int depoisDeConsumir = sistema->getClock()->getEventos()->size;
	//int tamanho = sistema->getGerador()->getPistaO1Leste()->size;

	sistema->getGerador()->getPistaO1Leste()->setSemaforo();

	sistema->consomeEvento(retira2);
	int depoisDeConsumir2 = sistema->getClock()->getEventos()->size;
	int novoTamanhoLeste = sistema->getGerador()->getPistaO1Leste()->size;
	int tamanhoSul = sistema->getGerador()->getPistaS1Sul()->size;
	Evento* retira3 = sistema->retiraEventoClock();
	int valorId3 = retira3->getId();
	int timestamp = retira3->getTimeStamp();
	sistema->consomeEvento(retira3);
	int novoTamanhoSul = sistema->getGerador()->getPistaS1Sul()->size;


	//std::cout << "tamanho depois de consumir: " << depoisDeConsumir
	//	<< std::endl;
	//std::cout << "tamanho pistaO1Leste: " << tamanho << std::endl;
	//std::cout << "id do retira: " << valorRetira << std::endl;
	//std::cout << "tamanho Pista Leste antes do carro: " << tamanhoPista
	//	<< std::endl;
	//std::cout << "timestamp " << valorTimestamp << std::endl;
	std::cout << "tamanho clock depois do retira2: " << depoisDeConsumir2
			<< std::endl;
	std::cout << "tamanho pista Leste: " << novoTamanhoLeste << std::endl;
	std::cout << "tamanho pista Sul: " << tamanhoSul << std::endl;
	std::cout << "Id retira3: " << valorId3 << std::endl;
	std::cout << "timestamp retira3: " << timestamp << std::endl;
	std::cout << "Novo tamanho pista Sul: " << novoTamanhoSul << std::endl;
	return 0;

}

#endif
