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
#include "../Eventos/EventoNovoCarro.h"
#include "../Pista/Pista.cpp"
#include "../Pista/Pista.h"
#include "../util/GeradorAleatorios.h"
#include "GeradorPistas.h"

Sistema::Sistema() {
	criaPistas();
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
EventoNovoCarro* evento = new EventoNovoCarro(geradorAleatorio->gerarTamanhoCarro(),this->gerador->getPistaO1Leste(), );
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

void Sistema::incluiEventoClock();

