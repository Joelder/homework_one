/*
 * Sistema.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#include "Sistema.h"

#include <cstdlib>
#include <ctime>

#include "../Carro/Carro.cpp"
#include "../Carro/Carro.h"
#include "../Estruturas/Lista.hpp"
#include "../Eventos/EventoNovoCarro.h"
#include "../Pista/Pista.cpp"
#include "../Pista/Pista.h"
#include "../util/GeradorAleatorios.cpp"
#include "../util/GeradorAleatorios.h"
#include "GeradorPistas.h"
#include "../Clock/Clock.cpp"

Sistema::Sistema() {
	criaPistas();
	this->clock = new Clock();
}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

void Sistema::criaPistas() {
	this->gerador = new GeradorPistas();
}

Carro* Sistema::criaCarro(int tamanho) {
	Carro* carro = new Carro(tamanho);
	return carro;
}

void Sistema::geraEventosIniciais() {
	GeradorAleatorios* geradorAleatorio = new GeradorAleatorios();
	srand(time(NULL));
	Pista* origem = this->gerador->getPistaO1Leste();
	int proporcao = origem->getPistaConectadaProporcao();
	Pista* destino = origem->getPistasConectadas()->getPosicao(proporcao);
	EventoNovoCarro* evento = new EventoNovoCarro(
			geradorAleatorio->gerarTamanhoCarro(), origem, destino, 8);
}

void Sistema::consomeEventoNovoCarro(EventoNovoCarro* novoCarro) {
	Carro* carro = criaCarro(novoCarro->getTamanhoCarrro());
	carro->setDestino(novoCarro->getPistaDestino());
	novoCarro->getPistaOrigem()->adicionarCarroPista(carro);
}

void Sistema::consomeEventoTrocaPista() {

}

void Sistema::consomeEventoMudancaSemaforo();

void Sistema::consomeEventoChegadaCarro();

void Sistema::consomeChegadaSemaforo();

void Sistema::geraEventoNovoCarro();

void Sistema::geraEventoChegadaSemaforo();

void Sistema::geraEventoChegadaCarro();

void Sistema::geraEventoTrocaPista();

void Sistema::incluiEventoClock(Evento* evento) {
	this->clock->adicionaEvento(evento);
}

void Sistema::retiraEventoClock() {
	this->clock->retiraEvento();
}
