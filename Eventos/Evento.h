/*
 * Evento.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef EVENTOS_EVENTO_H_
#define EVENTOS_EVENTO_H_
#include "../Enum/TipoEvento.cpp"
class Evento {
private:
	enum Eventos evento;
public:
	Evento();
	virtual ~Evento();
};

#endif /* EVENTOS_EVENTO_H_ */
