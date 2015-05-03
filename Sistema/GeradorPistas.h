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
		Pista* gerapistaO1Oeste();
		Pista* gerapistaN1Norte();
		Pista* gerapistaS1Sul();
		Pista* gerapistaN2Norte();
		Pista* gerapistaL1Leste();
		Pista* gerapistaS2Sul();
		//Centrais
		Pista* gerapistaC1Oeste();
		Pista* gerapistaC1Leste();
		//Fontes
		Pista* gerapistaO1Leste();
		Pista* gerapistaN1Sul();
		Pista* gerapistaS1Norte();
		Pista* gerapistaN2Sul();
		Pista* gerapistaS2Norte();
		Pista* gerapistaL1Oeste();

public:
	GeradorPistas();
	virtual ~GeradorPistas();
	void geraPistas();
};

#endif /* SISTEMA_GERADORPISTAS_H_ */
