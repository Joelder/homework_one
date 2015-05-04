/*
 * testeChegadaCarro.cpp
 *
 *  Created on: May 4, 2015
 *      Author: thomas
 */

#ifndef TESTECHEGADACARRO_CPP
#define TESTECHEGADACARRO_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	Sistema* sistema = new Sistema();
	int antesDosEventosIniciais = sistema->getClock()->getEventos()->size;
	//sistema->geraEventosIniciais();
	//int depoisDosEventosIniciais = sistema->getClock()->getEventos()->size;

	Pista* destino = sistema->getGerador()->getPistaN1Norte();
	Carro* carro = new Carro(8);
	carro->setDestino(destino);
	destino->adicionarCarroPista(carro);
	int espacoRestanteComCarro = destino->getEspacoRestante();
	Evento* chegada = new Evento(10, 2, 0, NULL, destino, carro);
	sistema->incluiEventoClock(chegada);
	int depoisIncluirClock = sistema->getClock()->getEventos()->size;
	Evento* retira = sistema->getClock()->retiraEvento();
	sistema->consomeEvento(retira);
	int depoisRetirarClock = sistema->getClock()->getEventos()->size;
	int espacoRestante =
			sistema->getGerador()->getPistaN1Norte()->getEspacoRestante();

	//std::cout << "tamanho antes dos eventos iniciais: "
	//	<< antesDosEventosIniciais << std::endl;
	//std::cout << "tamanho depois dos eventos iniciais: "
	//	<< depoisDosEventosIniciais << std::endl;
	std::cout << "tamanho antes do evento chegada: " << depoisIncluirClock
			<< std::endl;
	std::cout << "tamanho depois do evento chegada: " << depoisRetirarClock
			<< std::endl;
	std::cout << "tamanho da pista antes da retirada: " << espacoRestanteComCarro
				<< std::endl;
	std::cout << "tamanho da pista apos retirada: " << espacoRestante
			<< std::endl;
	return 0;

}

#endif
