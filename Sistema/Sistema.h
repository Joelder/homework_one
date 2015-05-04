/*
 * Sistema.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef SISTEMA_SISTEMA_H_
#define SISTEMA_SISTEMA_H_
#include "../Eventos/EventoNovoCarro.cpp"
#include "GeradorPistas.cpp"

class Sistema {
protected:
	GeradorPistas* gerador;
public:
	Sistema();

	virtual ~Sistema();

	/*
	 * Big Bang e no inicio fez se as pistas
	 * */
	void criaPistas();

	/*
	 * Método que cria o carro
	 * */
	Carro* criaCarro(int tamanho);

	/*
	 * Big Bang e no inicio fez se os eventos
	 * */
	void geraEventosIniciais();

	/*
	 * Evento Cria Novo carro, coloca na pista, gera novo evento Chegada Semaforo
	 * */
	void consomeEventoNovoCarro(EventoNovoCarro* novoCarro);

	/*
	 * Evento Troca um carro de uma pista para outra
	 * */
	void consomeEventoTrocaPista();

	/*
	 * Evento troca o semaforo de uma pista, pode gerar evento troca de pista
	 * */
	void consomeEventoMudancaSemaforo();

	/*
	 * Evento tira o carro da pista sumidouro, gera log no sistema
	 * */
	void consomeEventoChegadaCarro();

	/*
	 * Evento que faz as verificações para gerar o evento troca de pista ou gerar um novo Chegada Semaforo
	 * */
	void consomeChegadaSemaforo();

	/*
	 * Gera o evento novo carro
	 * */
	void geraEventoNovoCarro();

	/*
	 * Gera o evento chegada semaforo
	 * */
	void geraEventoChegadaSemaforo();

	/*
	 * Gera o evento chegada carro
	 * */
	void geraEventoChegadaCarro();

	/*
	 * Gera o evento troca pista
	 * */
	void geraEventoTrocaPista();

	/*
	 * Inclui no clock o evento recém gerado
	 * */
	void incluiEventoClock();

};

#endif /* SISTEMA_SISTEMA_H_ */
