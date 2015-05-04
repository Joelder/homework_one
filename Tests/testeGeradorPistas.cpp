/*
 * testeGeradorPistas.cpp
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */
#ifndef TESTEGERADORPISTAS_CPP
#define TESTEGERADORPISTAS_CPP

#include <iostream>

#include "../Estruturas/Lista.hpp"
#include "../Pista/Pista.cpp"
#include "../Pista/Pista.h"
#include "../Sistema/GeradorPistas.cpp"
#include "../Sistema/GeradorPistas.h"

int main(int argc, char** argv) {
	GeradorPistas* gerador = new GeradorPistas();
	int tamanhoO1Leste = gerador->getPistaO1Leste()->getTamanho();
	int tamanhoO1Oeste = gerador->getPistaO1Oeste()->getTamanho();
	int tamanhoN1Norte = gerador->getPistaN1Norte()->getTamanho();
	int tamanhoS1Norte = gerador->getPistaS1Norte()->getTamanho();
	Lista<Pista*>* pistasConectadas =
			gerador->getPistaO1Leste()->getPistasConectadas();
	bool contemPistaS1Sul = pistasConectadas->contem(gerador->getPistaS1Sul());
	bool contemPistaC1Leste = pistasConectadas->contem(
			gerador->getPistaC1Leste());
	bool contemPistaN1Norte = pistasConectadas->contem(
			gerador->getPistaN1Norte());
	bool contemPistaL1Oeste = pistasConectadas->contem(
			gerador->getPistaL1Oeste());

	std::cout << "tamanho pista O1Leste: " << tamanhoO1Leste << std::endl;
	std::cout << "tamanho pista O1Oeste: " << tamanhoO1Oeste << std::endl;
	std::cout << "tamanho pista N1Norte: " << tamanhoN1Norte << std::endl;
	std::cout << "tamanho pista S1Norte: " << tamanhoS1Norte << std::endl;
	std::cout << "contem a pista S1Sul: " << contemPistaS1Sul << std::endl;
	std::cout << "contem a pista C1Leste: " << contemPistaC1Leste << std::endl;
	std::cout << "contem a pista N1Norte: " << contemPistaN1Norte << std::endl;
	std::cout << "contem a pista L1Oeste: " << contemPistaL1Oeste << std::endl;
	return 0;
}

#endif
