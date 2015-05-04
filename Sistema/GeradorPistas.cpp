/*
 * GeradorPistas.cpp
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */

#include "GeradorPistas.h"

#include <stdlib.h>

#include "../Pista/Fonte.cpp"
#include "../Pista/Sumidouro.cpp"

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
	this->geraPistas();

}

GeradorPistas::~GeradorPistas() {
	// TODO Auto-generated destructor stub
}

//Sumidouros
Pista* GeradorPistas::getPistaO1Oeste() {
	if (this->pistaO1Oeste == NULL) {
		this->pistaO1Oeste = new Sumidouro(2000, 80, true);
	}
	return this->pistaO1Oeste;
}

Pista* GeradorPistas::getPistaN1Norte() {
	if (this->pistaN1Norte == NULL) {
		this->pistaN1Norte = new Sumidouro(500, 60, true);
	}
	return this->pistaN1Norte;
}

Pista* GeradorPistas::getPistaS1Sul() {
	if (this->pistaS1Sul == NULL) {
		this->pistaS1Sul = new Sumidouro(500, 60, true);
	}
	return this->pistaS1Sul;
}

Pista* GeradorPistas::getPistaN2Norte() {
	if (this->pistaN2Norte == NULL) {
		this->pistaN2Norte = new Sumidouro(500, 40, true);
	}
	return this->pistaN2Norte;
}

Pista* GeradorPistas::getPistaL1Leste() {
	if (this->pistaL1Leste == NULL) {
		this->pistaL1Leste = new Sumidouro(400, 30, true);
	}
	return this->pistaL1Leste;
}

Pista* GeradorPistas::getPistaS2Sul() {
	if (this->pistaS2Sul == NULL) {
		this->pistaS2Sul = new Sumidouro(500, 40, true);
	}
	return this->pistaS2Sul;
}

//Centrais
Pista* GeradorPistas::getPistaC1Oeste() {
	if (this->pistaC1Oeste == NULL) {
		this->pistaC1Oeste = new Pista(300, 60, false);
		this->pistaC1Oeste->conectarPistas(this->getPistaN1Norte(),
				this->getPistaO1Oeste(), this->getPistaS1Sul());
	}
	return this->pistaC1Oeste;
}

Pista* GeradorPistas::getPistaC1Leste() {
	if (this->pistaC1Leste == NULL) {
		this->pistaC1Leste = new Pista(300, 60, false);
		this->pistaC1Leste->conectarPistas(this->getPistaN2Norte(),
				this->getPistaL1Leste(), this->getPistaS2Sul());
	}
	return this->pistaC1Leste;
}

//Fontes
Pista* GeradorPistas::getPistaO1Leste() {
	if (this->pistaO1Leste == NULL) {
		this->pistaO1Leste = new Fonte(2000, 80, false);
		this->pistaO1Leste->conectarPistas(this->getPistaN1Norte(),
				this->getPistaC1Leste(), this->getPistaS1Sul());
	}
	return this->pistaO1Leste;
}

Pista* GeradorPistas::getPistaN1Sul() {
	if (this->pistaN1Sul == NULL) {
		this->pistaN1Sul = new Fonte(500, 60, false);
		this->pistaN1Sul->conectarPistas(this->getPistaO1Oeste(),
				this->getPistaS1Sul(), this->getPistaC1Leste());
	}
	return this->pistaN1Sul;
}

Pista* GeradorPistas::getPistaS1Norte() {
	if (this->pistaS1Norte == NULL) {
		this->pistaS1Norte = new Fonte(500, 60, false);
		this->pistaS1Norte->conectarPistas(this->getPistaO1Oeste(),
				this->getPistaN1Norte(), this->getPistaC1Leste());
	}
	return this->pistaS1Norte;
}

Pista* GeradorPistas::getPistaN2Sul() {
	if (this->pistaN2Sul == NULL) {
		this->pistaN2Sul = new Fonte(500, 40, false);
		this->pistaN2Sul->conectarPistas(this->getPistaC1Oeste(),
				this->getPistaS2Sul(), this->getPistaL1Leste());
	}
	return this->pistaN2Sul;
}

Pista* GeradorPistas::getPistaS2Norte() {
	if (this->pistaS2Norte == NULL) {
		this->pistaS2Norte = new Fonte(500, 40, false);
		this->pistaS2Norte->conectarPistas(this->getPistaC1Oeste(),
				this->getPistaN2Norte(), this->getPistaL1Leste());
	}
	return this->pistaS2Norte;
}

Pista* GeradorPistas::getPistaL1Oeste() {
	if (this->pistaL1Oeste == NULL) {
		this->pistaL1Oeste = new Fonte(400, 30, false);
		this->pistaL1Oeste->conectarPistas(this->getPistaN2Norte(),
				this->getPistaC1Oeste(), this->getPistaS2Sul());
	}
	return this->pistaL1Oeste;
}

void GeradorPistas::geraPistas() {
	// Pistas sumidouras
	this->getPistaO1Oeste();
	this->getPistaL1Leste();
	this->getPistaS1Sul();
	this->getPistaS2Sul();
	this->getPistaN1Norte();
	this->getPistaN2Norte();
	// Pistas normais
	this->getPistaC1Oeste();
	this->getPistaC1Leste();
	// Pistas fontes
	this->getPistaO1Leste();
	this->getPistaL1Oeste();
	this->getPistaN1Sul();
	this->getPistaN2Sul();
	this->getPistaS1Norte();
	this->getPistaS2Norte();
}

