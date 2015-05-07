#ifndef SISTEMA_SISTEMA_H_
#define SISTEMA_SISTEMA_H_
#include "../Clock/Clock.cpp"
#include "GeradorPistas.cpp"
#include "../Eventos/EventoTrocaPista.cpp"
/*
 * Sistema, classe responsavel pela criação do programa
 * */
class Sistema {

public:
	GeradorPistas* gerador;
	Clock* clock;
	int tempo;
	int entradaCarros;
	int saidaCarros;
	/*
	 * Construtor do sistema
	 * @param tempo O tempo que o programa irá rodar
	 */
	Sistema(int tempo);
	/*
	 * Destrutor do sistema
	 * */
	virtual ~Sistema();

	/*
	 * todas as pistas são geradas
	 * */
	void criaPistas();
	/*
	 * executa o sistema
	 */
	void run();

	/*
	 * Método que cria o carro
	 * */
	Carro* criaCarro(int tamanho);

	/*
	 * Gera os eventos iniciais
	 * */
	void geraEventosIniciais();
	/*
	 * Classifica e roteia o Evento que chegou no sistema
	 * */
	void consomeEvento(Evento* ev);

	/*
	 * Evento Cria Novo carro, coloca na pista, gera novo evento Chegada Semaforo
	 * */
	void consomeEventoNovoCarro(Evento* novoCarro);

	/*
	 * Evento Troca um carro de uma pista para outra
	 * */
	void consomeEventoTrocaPista(EventoTrocaPista* ev, Pista* pistaOrigem,
			int time);

	/*
	 * Evento troca o semaforo de uma pista, pode gerar evento troca de pista
	 * */
	void consomeEventoMudancaSemaforo(Evento* ev);

	/*
	 * Evento tira o carro da pista sumidouro, gera log no sistema
	 * */
	void consomeEventoChegadaCarro(Evento* ev);

	/*
	 * Evento que faz as verificações para gerar o evento troca de pista ou gerar um novo Chegada Semaforo
	 * */
	void consomeChegadaSemaforo(Evento* ev);

	/*
	 * Evento que faz as verificações para gerar o evento troca de pista ou gerar um novo Chegada Semaforo
	 * */
	void consomeChegadaFinalFila(Evento* ev);

	/*
	 * Gera o evento chegada semaforo
	 * */
	void geraEventoChegadaSemaforo(Carro* carro, Pista* pista, int time);

	/*
	 * Gera o evento chegada semaforo
	 * */
	void geraEventoDeslocamentoChegadaSemaforo(Carro* carro, Pista* pista,
			int time);

	/*
	 * Gera o evento chegada semaforo
	 * */
	void geraEventoChegadaFila(Carro* carro, Pista* pistaOrigem, int time);

	/*
	 * Gera o evento chegada carro
	 * */
	void geraEventoChegadaCarro(Pista* pista, int timestamp);

	/*
	 * Gera o evento troca pista
	 * */
	void geraEventoTrocaPista(Carro* carro, Pista* pistaOrigem, int timestamp);

	/*
	 * Gera o evento troca semaforo
	 * */
	void geraEventoTrocaSemaforo(Pista* pista, int timestamp);

	/*
	 * Gera o evento Novo carro
	 * */
	void geraEventoNovoCarro(int tamanhoCarro, Pista* pistaOrigem,
			Pista* pistaDestino, int timestamp);

	/*
	 * Gera Semaforos
	 * */
	void geraSemaforos(int time);

	/*
	 * Gera Semaforos
	 * */
	void geraNovosCarros(int time);

	/*
	 * Inclui no clock o evento recém gerado
	 * */
	void incluiEventoClock(Evento* evento);
	/*
	 * retira evento do clock
	 * */
	Evento* retiraEventoClock();
	/*
	 * retorna o clock
	 * */
	Clock* getClock();
	/*
	 * retorna o gerador
	 * */
	GeradorPistas* getGerador();
};

#endif /* SISTEMA_SISTEMA_H_ */
