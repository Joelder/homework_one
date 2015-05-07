/*
 * testeCompleto.cpp
 *
 *  Created on: May 5, 2015
 *      Author: thomas
 */

#ifndef TESTECOMPLETO_CPP
#define TESTECOMPLETO_CPP

#include <iostream>

#include "../Sistema/Sistema.cpp"

int main(int argc, char** argv) {
	int resposta = 0;
	std::cout << "Digite o tempo de execução: ";
	cin >> resposta;
	Sistema* sistema = new Sistema(resposta);
	sistema->geraEventosIniciais();
	sistema->run();
	return 0;

}

#endif
