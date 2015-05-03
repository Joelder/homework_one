/*
 * GeradorPistas.cpp
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */

#include "GeradorPistas.h"

#include <stdlib.h>

#include "../Pista/Sumidouro.h"

GeradorPistas::GeradorPistas() {
	this->pistaO1Oeste = NULL;
	this->pistaN1Norte = NULL;
	this->pistaS1Sul = NULL;
	this->pistaN2Norte = NULL;
	this->pistaL1Leste = NULL;
	this->pistaS2Sul = NULL;
	//Centrais
	this->pistaC1Oeste = NULL;
	this->pistaC1Leste = NULL;
	//Fontes
	this->pistaO1Leste = NULL;
	this->pistaN1Sul = NULL;
	this->pistaS1Norte = NULL;
	this->pistaN2Sul = NULL;
	this->pistaS2Norte = NULL;
	this->pistaL1Oeste = NULL;

}

GeradorPistas::~GeradorPistas() {
	// TODO Auto-generated destructor stub
}

//Sumidouros
Pista* GeradorPistas::gerapistaO1Oeste() {
	if (this->pistaO1Oeste != NULL) {
		this->pistaO1Oeste = new Sumidouro(2000, 80, true);
	}
	return this->pistaO1Oeste;
}

Pista* GeradorPistas::gerapistaN1Norte() {
	if (this->pistaN1Norte != NULL) {
		this->pistaN1Norte = new Sumidouro(500, 60, true);
	}
	return this->pistaN1Norte;
}

Pista* GeradorPistas::gerapistaS1Sul() {
	if (this->pistaS1Sul != NULL) {
		this->pistaS1Sul = new Sumidouro(500, 60, true);
	}
	return this->pistaS1Sul;
}

Pista* GeradorPistas::gerapistaN2Norte() {
	if (this->) {
	this->
}
return this->
}

Pista* GeradorPistas::gerapistaL1Leste() {
if (this->) {
this->
}
return this->
}

Pista* GeradorPistas::gerapistaS2Sul() {
if (this->) {
this->
}
return this->
}

//Centrais
Pista* GeradorPistas::gerapistaC1Oeste() {
if (this->) {
this->
}
return this->
}
Pista* GeradorPistas::gerapistaC1Leste() {
if (this->) {
this->
}
return this->
}
//Fontes
Pista* GeradorPistas::gerapistaO1Leste() {
if (this->) {
this->
}
return this->
}
Pista* GeradorPistas::gerapistaN1Sul() {
if (this->) {
this->
}
return this->
}
Pista* GeradorPistas::gerapistaS1Norte() {
if (this->) {
this->
}
return this->
}
Pista* GeradorPistas::gerapistaN2Sul() {
if (this->) {
this->
}
return this->
}
Pista* GeradorPistas::gerapistaS2Norte() {
if (this->) {
this->
}
return this->
}
Pista* GeradorPistas::gerapistaL1Oeste() {
if (this->) {
this->
}
return this->
}

