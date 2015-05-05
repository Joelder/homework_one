/*
 * testeEventoNovoCarro.cpp
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */

#ifndef TESTEEVENTONOVOCARRO_CPP
#define TESTEEVENTONOVOCARRO_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	Sistema* sistema = new Sistema(600);
	int antesDosEventosIniciais = sistema->getClock()->getEventos()->size;
	sistema->geraEventosIniciais();
	int depoisDosEventosIniciais = sistema->getClock()->getEventos()->size;
	Evento* retira = sistema->retiraEventoClock();
	sistema->consomeEvento(retira);
	int depoisDeConsumir = sistema->getClock()->getEventos()->size;
	int espacoRestante =
			sistema->getGerador()->getPistaO1Leste()->getEspacoRestante();

	std::cout << "tamanho antes dos eventos iniciais: "
			<< antesDosEventosIniciais << std::endl;
	std::cout << "tamanho depois dos eventos iniciais: "
			<< depoisDosEventosIniciais << std::endl;
	std::cout << "tamanho depois de ser consumido: " << depoisDeConsumir
			<< std::endl;
	std::cout << "espaco Restante Pista: " << espacoRestante
				<< std::endl;

	return 0;

}

#endif
