/*
 * pista.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef PISTA_H_
#define PISTA_H_
#include "../Estruturas/FilaEnc.hpp"
#include "../Estruturas/Lista.hpp"
#include "../Carro/Carro.cpp"
using namespace std;

class Pista: public FilaEnc<Carro*> {

protected:
	/*
	 * Proporcação indica se a pista é de proporção "0" 80/10/10 ou "1" 40/30/30
	 * */
	int proporcao;
	int tamanho;
	int espacoRestante;
	int velocidade;
	bool semaforo;
	Lista<Pista*>* pistasConectadas;
	string nome;


public:
	Pista(int proporcao, int tamanho, int velocidade, bool semaforo, string nome);
	virtual ~Pista();

	int getProporcao();

	int getTamanho();

	int getVelocidade();

	bool getSemaforo();

	void setSemaforo();

	Lista<Pista*>* getPistasConectadas();

	void adicionarCarroPista(Carro* carro);

	void retirarCarroPista();

	void conectarPistas(Pista* pista1, Pista* pista2, Pista* pista3);

	bool transferirCarro(Pista* pista);

	int getEspacoRestante();

	int getPistaConectadaProporcao();

	string getNome();

};

#endif /* PISTA_H_ */
