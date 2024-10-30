#pragma once
#include "Casillas.h"
#include <iostream>
using namespace std;
class Filas
{
	struct NodoCasillas
	{
		int NumeroCasilla=0;
		Casillas* Casilla;
		NodoCasillas* SiguienteCasilla; 
	};
	NodoCasillas* headerCasilla;
public:
	Player* JugadorDatosMover;
	void CrearCasillas(int ConteoCasillas);
	void AgregarJugadores(int CantidadJugadores);
	bool BusquedaJugadorTablero(int NumeroJugador);
	bool MoverJugador(int Casilla , Player* DatosJugador);
};

