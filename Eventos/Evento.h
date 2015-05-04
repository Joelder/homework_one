/*
 * Evento.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef EVENTO_H_
#define EVENTO_H_
using namespace std;


class Evento {

private:
	string name;

public:
	int timestamp;

	Evento(int timestamp, string name);

	int getTimeStamp();

	void setTimeStamp(int timestamp);

	virtual ~Evento();

	string getName();

	bool operator< (const Evento& outro);

	bool operator> (const Evento& outro);

	bool operator== (const Evento& outro);
};

#endif /* EVENTOS_EVENTO_H_ */
