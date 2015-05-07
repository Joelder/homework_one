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
	Sistema* sistema = new Sistema(1);
	sistema->geraEventosIniciais();
	sistema->run();
	return 0;

}

#endif
