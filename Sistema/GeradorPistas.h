/*
 * GeradorPistas.h
 *
 *  Created on: May 3, 2015
 *      Author: thomas
 */

#ifndef SISTEMA_GERADORPISTAS_H_
#define SISTEMA_GERADORPISTAS_H_
class Pista;

class GeradorPistas {
private:
	//Sumidouros
	Pista* pistaO1Oeste;
	Pista* pistaN1Norte;
	Pista* pistaS1Sul;
	Pista* pistaN2Norte;
	Pista* pistaL1Leste;
	Pista* pistaS2Sul;
	//Centrais
	Pista* pistaC1Oeste;
	Pista* pistaC1Leste;
	//Fontes
	Pista* pistaO1Leste;
	Pista* pistaN1Sul;
	Pista* pistaS1Norte;
	Pista* pistaN2Sul;
	Pista* pistaS2Norte;
	Pista* pistaL1Oeste;

public:
	GeradorPistas();
	virtual ~GeradorPistas();
	//Sumidouros
	Pista* getPistaO1Oeste();
	Pista* getPistaN1Norte();
	Pista* getPistaS1Sul();
	Pista* getPistaN2Norte();
	Pista* getPistaL1Leste();
	Pista* getPistaS2Sul();
	//Centrais
	Pista* getPistaC1Oeste();
	Pista* getPistaC1Leste();
	//Fontes
	Pista* getPistaO1Leste();
	Pista* getPistaN1Sul();
	Pista* getPistaS1Norte();
	Pista* getPistaN2Sul();
	Pista* getPistaS2Norte();
	Pista* getPistaL1Oeste();
	void geraPistas();
};

#endif /* SISTEMA_GERADORPISTAS_H_ */
