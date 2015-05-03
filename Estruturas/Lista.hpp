// Copyright [2015] <Joelder>
/// Implementação de uma Lista
/**
 * Criado por Joelder Maragno Arcaro
 * 28/03/2015
 */

#ifndef LISTA_HPP
#define LISTA_HPP

template <typename T>

/** Implementação da Lista  */

class Lista {
 private:
  static const int indexInicial = -1;
  static const int maximoLista = 1000;
  int tamanhoLista, valorTopo;
  int *enderecoTopo;
  T *lista;

/** Construtor padrão  */
 public:
  Lista() {
    this->tamanhoLista = maximoLista;
    this->valorTopo = indexInicial;
    this->lista = new T[maximoLista];
}

/** Construtor passando como parametro o tamanho do vetor  */
  explicit Lista<T>(int tam) {
    this->tamanhoLista = tam;
    this->valorTopo = indexInicial;
    this->lista = new T[tam];
}

/** Metodo que adiciona um dado ao vetor  */
  void adiciona(T dado) {
    if (listaCheia()) {
      throw "Erro lista cheia";
    } else {
       this->valorTopo = valorTopo + 1;
       this->lista[valorTopo] = dado;
      }
}

/** Metodo que adiciona um elemento no inicio  */
  void adicionaNoInicio(T dado) {
    if (listaCheia()) {
      throw "Erro lista cheia";
    } else {
      this-> valorTopo = valorTopo + 1;
      int countLoop = valorTopo;
      while (countLoop > 0) {
	lista[countLoop] = lista[countLoop-1];
	countLoop--;
      }
      lista[0] = dado;
    }
}

/** Método que adiciona um elemento em uma determinada posição especifica  */
  void adicionaNaPosicao(T dado, int destino) {
    if (listaCheia()) {
      throw "Erro lista cheia";
    } else {
      if (destino > valorTopo+1 || destino < 0) {
	throw "Erro de posição";
      }
      this->valorTopo = valorTopo + 1;
      int countLoop = valorTopo;
      while (countLoop > destino) {
	lista[countLoop] = lista[countLoop - 1];
	countLoop--;
      }
      lista[destino] = dado;
    }
}

/** Método que adiciona obdecendo ordem crescente  */
  void adicionaEmOrdem(T dado) {
    if (listaCheia()) {
      throw "Erro lista cheia";
    } else {
      int position = 0;
      while (position <= valorTopo && dado > lista[position]) {
	    position++;
	    }
      adicionaNaPosicao(dado, position);
      }
}

/** Retira um elemento da lista  */
	T retira() {
	  if (listaVazia()) {
	    throw "Erro lista vazia";
	  } else {
	    this->valorTopo = valorTopo - 1;
	    return (lista[valorTopo + 1]);
	  }
}


/** Retira do inicio da lista  */
  T retiraDoInicio() {
    if (listaVazia()) {
      throw "Erro lista vazia";
    } else {
      this->valorTopo = valorTopo - 1;
      T valor = lista[0];
      int countLoop = 0;
      while (countLoop <= valorTopo) {
	lista[countLoop] = lista[countLoop + 1];
	countLoop++;
      }
      return valor;
    }
}

/** Retira de uma determinada posição  */
  T retiraDaPosicao(int posicao) {
    if (posicao > valorTopo || posicao < 0) {
      throw "Erro posição";
    } else {
      if (listaVazia()) {
	    throw "Erro lista vazia";
      }
	this->valorTopo = valorTopo - 1;
	T valor = lista[posicao];
	int countLoop = posicao;
	while (countLoop <= valorTopo) {
	  lista[countLoop] = lista[countLoop + 1];
	  countLoop++;
	}
	return valor;
    }
}

/** Retira um elemento específico  */
    T retiraEspecifico(T dado) {
      if (listaVazia()) {
	throw "Erro lista vazia";
      } else {
	int position = posicao(dado);
	if (position < 0) {
	  throw "Erro posicao";
	} else {return retiraDaPosicao(position);}
      }
}

/** Resolve a posição passando um elemnto como parametro  */
    int posicao(T dado) {
	  int position= 0;
	  while (position <= valorTopo && !igual(dado, lista[position])) {
	    position++;
	  }
	  if (position > valorTopo) {
	    throw "Erro posicao";
	  } else {return position;}
}

/** Verifica se tem um determinado elemento na lista  */
  bool contem(T dado) {
    if (listaVazia()) {
      throw "Erro lista vazia";
    }
    int position = 0;
    while (position <= valorTopo && dado != lista[position]) {
      position++;
    }
    if (position > valorTopo) {
      return false;
    } else { return true;}
}

/** Metodos que comparam dois elementos  */

  bool igual(T dado1, T dado2) {
    return (dado1 == dado2);
}

  bool maior(T dado1, T dado2) {
    return (dado1 > dado2);
}

  bool menor(T dado1, T dado2) {
    return (dado1 < dado2);
}

/** Verifica se a lista está cheia  */
	bool listaCheia() {
	  return(valorTopo == tamanhoLista-1);
	}

/** Verifica se a lista está vazia  */
       bool listaVazia() {
	 return(valorTopo == indexInicial);
       }

/** Destrutor da lista  */
	void destroiLista() {
	  this->valorTopo = indexInicial;
	}
};
#endif
