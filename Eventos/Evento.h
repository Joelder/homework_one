/*
 * Evento.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef EVENTOS_EVENTO_H_
#define EVENTOS_EVENTO_H_

class Evento {

public:
	int timestamp;
	Evento(int timestamp);

	int getTimeStamp();

	void setTimeStamp(int timestamp);

	virtual ~Evento();

	bool operator< (const Evento& outro);

	bool operator> (const Evento& outro);

	bool operator== (const Evento& outro);
};

#endif /* EVENTOS_EVENTO_H_ */
