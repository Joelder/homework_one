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

	//Sumidouros
		Pista* geraPistaO1Oeste();
		Pista* geraPistaN1Norte();
		Pista* geraPistaS1Sul();
		Pista* geraPistaN2Norte();
		Pista* geraPistaL1Leste();
		Pista* geraPistaS2Sul();
		//Centrais
		Pista* geraPistaC1Oeste();
		Pista* geraPistaC1Leste();
		//Fontes
		Pista* geraPistaO1Leste();
		Pista* geraPistaN1Sul();
		Pista* geraPistaS1Norte();
		Pista* geraPistaN2Sul();
		Pista* geraPistaS2Norte();
		Pista* geraPistaL1Oeste();

public:
	GeradorPistas();
	virtual ~GeradorPistas();
	void geraPistas();
};

#endif /* SISTEMA_GERADORPISTAS_H_ */
