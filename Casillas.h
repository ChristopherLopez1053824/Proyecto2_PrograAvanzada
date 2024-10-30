#pragma once
#include "Player.h"
#include <iostream>
using namespace std;
class Casillas
{
	struct NodoPlayer
	{
		Player* Jugador;
		NodoPlayer* SiguienteJugador;
		NodoPlayer* AnterirorJugador;
	};
	NodoPlayer* header;
public:
	Player* DatosJugadoraMover;
	void AgregarJugador(int CantidadJugadores, int Casilla);
	bool BuscarJugador(int NumeroJugador);
	void addPlayer(Player* Jugador, int casilla);
};

