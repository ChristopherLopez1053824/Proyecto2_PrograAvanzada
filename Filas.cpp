#include "Filas.h"
//Creamos 5 casillas
void Filas::CrearCasillas(int ConteoCasillas)
{
	if (headerCasilla == nullptr)
	{
		headerCasilla = new NodoCasillas();
		headerCasilla->Casilla = new Casillas();
		headerCasilla->NumeroCasilla = 1 + ConteoCasillas;
	}
	NodoCasillas* IndiceCasilla=headerCasilla;
	for (int i = 2; i <= 5; i++)
	{
		IndiceCasilla->SiguienteCasilla = new NodoCasillas();
		IndiceCasilla->SiguienteCasilla->Casilla = new Casillas();
		IndiceCasilla->SiguienteCasilla->NumeroCasilla = i + ConteoCasillas;
		IndiceCasilla = IndiceCasilla->SiguienteCasilla;
	}
}

//Se agrgan los jugadores en la casilla 1
void Filas::AgregarJugadores(int CantidadJugadores)
{
	headerCasilla->Casilla->AgregarJugador(CantidadJugadores, headerCasilla->NumeroCasilla);
}

bool Filas::BusquedaJugadorTablero(int NumeroPlayer)
{
	NodoCasillas* AuxiliarCasillas = headerCasilla;
	while (AuxiliarCasillas->SiguienteCasilla != nullptr)
	{
		bool Encontrado = AuxiliarCasillas->Casilla->BuscarJugador(NumeroPlayer);
		if (Encontrado == true)
		{
			JugadorDatosMover = AuxiliarCasillas->Casilla->DatosJugadoraMover;
			AuxiliarCasillas->Casilla->DatosJugadoraMover = nullptr;
			return 1;
		}
		AuxiliarCasillas = AuxiliarCasillas->SiguienteCasilla;
	}
	bool Encontrado = AuxiliarCasillas->Casilla->BuscarJugador(NumeroPlayer);
	if (Encontrado == true)
	{
		JugadorDatosMover = AuxiliarCasillas->Casilla->DatosJugadoraMover;
		AuxiliarCasillas->Casilla->DatosJugadoraMover = nullptr;
		return 1;
	}
	return 0;
}

bool Filas::MoverJugador(int CasillaM, Player* Jugador)
{
	NodoCasillas* AuxiliarCasillas = headerCasilla;
	while (AuxiliarCasillas->SiguienteCasilla != nullptr)
	{
		if (AuxiliarCasillas->NumeroCasilla == CasillaM)
		{
			AuxiliarCasillas->Casilla->addPlayer(Jugador,AuxiliarCasillas->NumeroCasilla);
			return 1;
		}
		AuxiliarCasillas = AuxiliarCasillas->SiguienteCasilla;
	}
	if (AuxiliarCasillas->NumeroCasilla == CasillaM)
	{
		AuxiliarCasillas->Casilla->addPlayer(Jugador, AuxiliarCasillas->NumeroCasilla);
		return 1;
	}
	return 0;
}