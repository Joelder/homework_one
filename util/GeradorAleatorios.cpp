/*
 * GeradorAleatorios.cpp
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */

#ifndef GERADORALEATORIOS_CPP
#define GERADORALEATORIOS_CPP
#include "GeradorAleatorios.h"
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

GeradorAleatorios::GeradorAleatorios() {
	// TODO Auto-generated constructor stub

}

GeradorAleatorios::~GeradorAleatorios() {
	// TODO Auto-generated destructor stub
}

int GeradorAleatorios::gerarTamanhoCarro() {
	return 2 + (rand() % 9);
}

int GeradorAleatorios::gerarProbabilidade() {
	return 1 + (rand() % 10);
}

#endif
