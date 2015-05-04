/*
 * testeEventoNovoCarro.cpp
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */

#ifndef TESTEEVENTONOVOCARRO_CPP
#define TESTEEVENTONOVOCARRO_CPP

#include <iostream>

#include "../Estruturas/ListaEnc.hpp"
#include "../Eventos/Evento.cpp"

int main(int argc, char** argv) {
	Evento* evento = new Evento(8);
	Evento* evento2 = new Evento(10);
	Evento* evento3 = new Evento(10);
	bool resposta = evento2 < evento3;

	ListaEnc<Evento*>* eventos = new ListaEnc<Evento*>;
	eventos->adicionaEmOrdem(evento2);
	eventos->adicionaEmOrdem(evento);
	eventos->adicionaEmOrdem(evento3);
	int posicaoEvento1 = eventos->posicao(evento);
	int posicaoEvento2 = eventos->posicao(evento2);
	int posicaoEvento3 = eventos->posicao(evento3);
	std::cout << "é maior? : " << resposta << std::endl;
	std::cout << "posicao 1 : " << posicaoEvento1 << std::endl;
	std::cout << "posicao 2 : " << posicaoEvento2 << std::endl;
	std::cout << "posicao 3 : " << posicaoEvento3 << std::endl;
	return 0;
}

#endif
