/*
 * Sistema.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef SISTEMA_SISTEMA_H_
#define SISTEMA_SISTEMA_H_
#include "../Carro/Carro.cpp"
#include "../Clock/Clock.cpp"
#include "../Estruturas/Lista.hpp"
#include "../Pista/Pista.cpp"
#include "../util/GeradorAleatorios.cpp"
#include "../Eventos/EventoNovoCarro.cpp"
#include "GeradorPistas.cpp"
#include "../Eventos/EventoChegadaCarro.cpp"
#include "../Eventos/EventoChegadaSemaforo.cpp"
#include "../Eventos/EventoMudancaSemaforo.cpp"
#include "../Eventos/EventoNovoCarro.cpp"
#include "../Eventos/EventoTrocaPista.cpp"

class Sistema {
protected:
	GeradorPistas* gerador;
	Clock* clock;
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
	 * Classifica e roteia o Evento que chegou no sistema
	 * */
	void consomeEvento(EventoNovoCarro* ev);
	void consomeEvento(EventoChegadaCarro* ev);
	void consomeEvento(EventoMudancaSemaforo* ev);
	void consomeEvento(EventoChegadaSemaforo* ev);

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
	void consomeEventoMudancaSemaforo(EventoMudancaSemaforo* ev);

	/*
	 * Evento tira o carro da pista sumidouro, gera log no sistema
	 * */
	void consomeEventoChegadaCarro(EventoChegadaCarro* ev);

	/*
	 * Evento que faz as verificações para gerar o evento troca de pista ou gerar um novo Chegada Semaforo
	 * */
	void consomeChegadaSemaforo(EventoChegadaSemaforo* ev);

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
	void incluiEventoClock(Evento* evento);

	void retiraEventoClock();

	Clock* getClock();
};

#endif /* SISTEMA_SISTEMA_H_ */
