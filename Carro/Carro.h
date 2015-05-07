/*
 * Carro.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijoo
 */

#ifndef CARRO_H_
#define CARRO_H_

#include "../Pista/Pista.cpp"

class Pista;
/*
 * Carro, meio de transporte utilizado para trafegar pela pista
 */
class Carro {
private:
	int tamanho; //!< O tamanho do carro (em metros)
	bool carroChegou; //!< boolean que indica se um carro chegou ao semaforo
	Pista* destino; //!< Pista destino do carro

public:
	/*
	 * Constrói um carro
	 */
	Carro(int tamanho);
	/*
	 * Destroi um carro
	 */
	virtual ~Carro();
	/*
	 * Retorna o tamanho do carro
	 */
	int getTamanho();
	/*
	 * Seta o destino do carro
	 * @param pista Pista que o carro ira se destinar
	 */
	void setDestino(Pista* pista);
	/*
	 * Retorna o destino do carro
	 */
	Pista* getDestino();
	/*
		 * Retorna o boolean se o carro chegou no semaforo
		*/
	bool getCarroChegou();
	/*
		 * Seta se o carro chegou no semaforo
		*/
	void setCarroChegou();
};

#endif /* CARRO_H_ */
