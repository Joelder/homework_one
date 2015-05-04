/*
 * Sistema.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef SISTEMA_CPP
#define SISTEMA_CPP
#include "Sistema.h"

#include <cstdlib>
#include <ctime>

class EventoChegadaCarro;
class EventoChegadaSemaforo;
class EventoMudancaSemaforo;
class EventoNovoCarro;

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
			geradorAleatorio->gerarTamanhoCarro(), origem, destino, 8, "NovoCarro");
	incluiEventoClock(evento);
}

void Sistema::consomeEventoNovoCarro(EventoNovoCarro* novoCarro) {
	Carro* carro = criaCarro(novoCarro->getTamanhoCarrro());
	carro->setDestino(novoCarro->getPistaDestino());
	novoCarro->getPistaOrigem()->adicionarCarroPista(carro);
}

void Sistema::consomeEventoTrocaPista() {

}

void Sistema::consomeEvento(EventoNovoCarro* ev) {
	consomeEventoNovoCarro(ev);
}

void Sistema::consomeEvento(EventoChegadaCarro* ev) {
	consomeEventoChegadaCarro(ev);
}
void Sistema::consomeEvento(EventoMudancaSemaforo* ev) {
	consomeEventoMudancaSemaforo(ev);
}

void Sistema::consomeEvento(EventoChegadaSemaforo* ev) {
	consomeChegadaSemaforo(ev);
}

void Sistema::consomeEventoMudancaSemaforo(EventoMudancaSemaforo* ev){

}

void Sistema::consomeEventoChegadaCarro(EventoChegadaCarro* ev){

}

void Sistema::consomeChegadaSemaforo(EventoChegadaSemaforo* ev){

}

void Sistema::geraEventoNovoCarro() {

}

void Sistema::geraEventoChegadaSemaforo(){

}

void Sistema::geraEventoChegadaCarro(){

}

void Sistema::geraEventoTrocaPista() {

}

void Sistema::incluiEventoClock(Evento* evento) {
	this->clock->adicionaEvento(evento);
}

Evento* Sistema::retiraEventoClock() {
	return this->clock->retiraEvento();
}

Clock* Sistema::getClock() {
	return this->clock;
}
#endif
