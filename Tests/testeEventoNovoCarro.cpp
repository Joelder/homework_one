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
	Sistema* sistema = new Sistema();
	int antesDosEventosIniciais = sistema->getClock()->getEventos()->size;
	sistema->geraEventosIniciais();
	int depoisDosEventosIniciais = sistema->getClock()->getEventos()->size;

	std::cout << "tamanho antes dos eventos iniciais: "
			<< antesDosEventosIniciais << std::endl;
	std::cout << "tamanho depois dos eventos iniciais: "
			<< depoisDosEventosIniciais << std::endl;
	return 0;

}

#endif
