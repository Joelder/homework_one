/*
 * Evento.cpp
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#include "Evento.h"
using namespace std;

Evento::Evento(int timestamp, string name) {
	this->timestamp = timestamp;
	this->name = name;
}

int Evento::getTimeStamp(){
	return this->timestamp;
}

void Evento::setTimeStamp(int timestamp){
	this->timestamp = timestamp;
}

Evento::~Evento() {
	// TODO Auto-generated destructor stub
}

string Evento::getName() {
	return this->name;
}

bool Evento::operator< (const Evento& outro) {
	return this->timestamp < outro.timestamp;
}

bool Evento::operator> (const Evento& outro) {
	return this->timestamp > outro.timestamp;
}

bool Evento::operator== (const Evento& outro) {
	return this->timestamp == outro.timestamp;
}

