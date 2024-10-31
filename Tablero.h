#pragma once
#include "Filas.h"
#include <iostream>
using namespace std;
class Tablero
{
	struct NodoFilas
	{
		Filas* Fila;
		NodoFilas* SiguienteFila;
	};
	NodoFilas* headerFila;

public:
	void CrearFilas(int NumeroCasillas);
	void AgregarJugadores(int CantidadJugadores);
	Player* BuscadorJugador(int NumeroJugador);
	Player* MoverJugador(int NumeroJugador, int NumeroCasilla);
	int Escalera(int num, int NumeroCasilla, int EscleraC);
	int NumeroAleatorio(int NumeroCasilla, int num);
	int TirarDado();
	void CrearEscalera(int NumeroCasilla);
	void CrearLombriz(int NumeroCasilla);
	int Lombriz(int num, int NumeroCasilla, int EscleraC);
	int NumeroAleatorioL(int NumeroCasilla, int num);
};

