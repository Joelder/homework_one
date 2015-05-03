/*
 * GeradorPistas.cpp
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */

#include "GeradorPistas.h"

#include <stdlib.h>

#include "../Pista/Fonte.h"
#include "../Pista/Pista.cpp"
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
Pista* GeradorPistas::geraPistaO1Oeste() {
	if (this->pistaO1Oeste != NULL) {
		this->pistaO1Oeste = new Sumidouro(2000, 80, true);
	}
	return this->pistaO1Oeste;
}

Pista* GeradorPistas::geraPistaN1Norte() {
	if (this->pistaN1Norte != NULL) {
		this->pistaN1Norte = new Sumidouro(500, 60, true);
	}
	return this->pistaN1Norte;
}

Pista* GeradorPistas::geraPistaS1Sul() {
	if (this->pistaS1Sul != NULL) {
		this->pistaS1Sul = new Sumidouro(500, 60, true);
	}
	return this->pistaS1Sul;
}

Pista* GeradorPistas::geraPistaN2Norte() {
	if (this->pistaN2Norte != NULL) {
		this->pistaN2Norte = new Sumidouro(500, 40, true);
	}
	return this->pistaN2Norte;
}

Pista* GeradorPistas::geraPistaL1Leste() {
	if (this->pistaL1Leste != NULL) {
		this->pistaL1Leste = new Sumidouro(400, 30, true);
	}
	return this->pistaL1Leste;
}

Pista* GeradorPistas::geraPistaS2Sul() {
	if (this->pistaS2Sul != NULL) {
		this->pistaS2Sul = new Sumidouro(500, 40, true);
	}
	return this->pistaS2Sul;
}

//Centrais
Pista* GeradorPistas::geraPistaC1Oeste() {
	if (this->pistaC1Oeste != NULL) {
		this->pistaC1Oeste = new Pista(300, 60, false);
		this->pistaC1Oeste->conectarPistas(this->geraPistaN1Norte(),
				this->geraPistaO1Oeste(), this->geraPistaS1Sul());
	}
	return this->pistaC1Oeste;
}

Pista* GeradorPistas::geraPistaC1Leste() {
	if (this->pistaC1Leste != NULL) {
		this->pistaC1Leste = new Pista(300, 60, false);
		this->pistaC1Leste->conectarPistas(this->geraPistaN2Norte(),
				this->geraPistaL1Leste(), this->geraPistaS2Sul());
	}
	return this->pistaC1Leste;
}

//Fontes
Pista* GeradorPistas::geraPistaO1Leste() {
	if (this->pistaO1Leste != NULL) {
		this->pistaO1Leste = new Fonte(2000, 80, false);
		this->pistaO1Leste->conectarPistas(this->geraPistaN1Norte(),
				this->geraPistaC1Leste(), this->geraPistaS1Sul());
	}
	return this->pistaO1Leste;
}

Pista* GeradorPistas::geraPistaN1Sul() {
	if (this->pistaN1Sul != NULL) {
		this->pistaN1Sul = new Fonte(500, 60, false);
		this->pistaN1Sul->conectarPistas(this->geraPistaO1Oeste(),
				this->geraPistaS1Sul(), this->geraPistaC1Leste());
	}
	return this->pistaN1Sul;
}

Pista* GeradorPistas::geraPistaS1Norte() {
	if (this->pistaS1Norte != NULL) {
		this->pistaS1Norte = new Fonte(500, 60, false);
		this->pistaS1Norte->conectarPistas(this->geraPistaO1Oeste(),
				this->geraPistaN1Norte(), this->geraPistaC1Leste());
	}
	return this->pistaS1Norte;
}

Pista* GeradorPistas::geraPistaN2Sul() {
	if (this->pistaN2Sul != NULL) {
		this->pistaN2Sul = new Fonte(500, 40, false);
		this->pistaN2Sul->conectarPistas(this->geraPistaC1Oeste(),
				this->geraPistaS2Sul(), this->geraPistaL1Leste());
	}
	return this->pistaN2Sul;
}

Pista* GeradorPistas::geraPistaS2Norte() {
	if (this->pistaS2Norte != NULL) {
		this->pistaS2Norte = new Fonte(500, 40, false);
		this->pistaS2Norte->conectarPistas(this->geraPistaC1Oeste(),
				this->geraPistaN2Norte(), this->geraPistaL1Leste());
	}
	return this->pistaS2Norte;
}

Pista* GeradorPistas::geraPistaL1Oeste() {
	if (this->pistaL1Oeste != NULL) {
		this->pistaL1Oeste = new Fonte(400, 30, false);
		this->pistaL1Oeste->conectarPistas(this->geraPistaN2Norte(),
				this->geraPistaC1Oeste(), this->geraPistaS2Sul());
	}
	return this->pistaL1Oeste;
}

void GeradorPistas::geraPistas() {
	// Pistas sumidouras
	this->geraPistaO1Oeste();
	this->geraPistaL1Leste();
	this->geraPistaS1Sul();
	this->geraPistaS2Sul();
	this->geraPistaN1Norte();
	this->geraPistaN2Norte();
	// Pistas normais
	this->geraPistaC1Oeste();
	this->geraPistaC1Leste();
	// Pistas fontes
	this->geraPistaO1Leste();
	this->geraPistaL1Oeste();
	this->geraPistaN1Sul();
	this->geraPistaN2Sul();
	this->geraPistaS1Norte();
	this->geraPistaS2Norte();
}

