/*
 * EventoTrocaPista.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#include "EventoTrocaPista.h"

EventoTrocaPista::EventoTrocaPista(Carro* carro) {
	this->carro = carro;
}


Carro* EventoTrocaPista::getCarro(){
	return this->carro;
}

EventoTrocaPista::~EventoTrocaPista() {
	// TODO Auto-generated destructor stub
}

