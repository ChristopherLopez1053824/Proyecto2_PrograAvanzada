#include "Casillas.h"

//Se agrgan los jugadores en la casilla 1
void Casillas::AgregarJugador(int CantidadJugadores, int Casilla)
{
	if (header == nullptr)
	{
		header = new NodoPlayer();
		header->Jugador = new Player();
		header->Jugador->AgregarDatosJugador(1, Casilla);
		cout << "Se agrego " << header->Jugador->Nombre << " Numero de jugador " << header->Jugador->Numero << " en la casilla " << header->Jugador->NumeroCasilla<<endl;
		header->AnterirorJugador = new NodoPlayer();

	}
	NodoPlayer* IndiceJugador = header;
	for (int i = 2; i <= CantidadJugadores;i++)
	{
		IndiceJugador->SiguienteJugador = new NodoPlayer();
		IndiceJugador->SiguienteJugador->AnterirorJugador = IndiceJugador;
		IndiceJugador->SiguienteJugador->Jugador = new Player();
		IndiceJugador->SiguienteJugador->Jugador->AgregarDatosJugador(i,Casilla);
		cout << "Se agrego " << IndiceJugador->SiguienteJugador->Jugador->Nombre << " Numero de jugador " << IndiceJugador->SiguienteJugador->Jugador->Numero << " en la casilla " << IndiceJugador->SiguienteJugador->Jugador->NumeroCasilla << endl;
		IndiceJugador = IndiceJugador->SiguienteJugador;
	}
}

//INGRESAMOS AL JUGADOR EN UNA NUEVA CASILLA
void Casillas::addPlayer(Player * JugadorI, int Casilla)
{
	if (header == nullptr)
	{
		header = new NodoPlayer();
		header->Jugador = JugadorI;
		header->Jugador->NumeroCasilla = Casilla;
		cout << "Se agrego " << header->Jugador->Nombre << " Numero de jugador " << header->Jugador->Numero << " en la casilla " << header->Jugador->NumeroCasilla << endl;
		header->AnterirorJugador = new NodoPlayer();
	}
	else {
		NodoPlayer* IndiceJugador = header;
		while (IndiceJugador->SiguienteJugador != nullptr)
		{
			IndiceJugador = IndiceJugador->SiguienteJugador;
		}

		IndiceJugador->SiguienteJugador = new NodoPlayer();
		IndiceJugador->SiguienteJugador-> Jugador = JugadorI;
		IndiceJugador->SiguienteJugador->Jugador->NumeroCasilla = Casilla;
		IndiceJugador->SiguienteJugador->AnterirorJugador = IndiceJugador;
		cout << "Se agrego " << IndiceJugador->SiguienteJugador->Jugador->Nombre << " Numero de jugador " << IndiceJugador->SiguienteJugador->Jugador->Numero << " en la casilla " << IndiceJugador->SiguienteJugador->Jugador->NumeroCasilla << endl;

	}
}

//BUSCAMOS AL JUGADOR LO ELIMINAMOS Y GUARDAMOS SUS DATOS
bool Casillas::BuscarJugador(int NumeroJugador)
{
	if (header == nullptr)
	{
		return 0;
	}
	else {
		NodoPlayer* AuxiliarJugador = header;
		while (AuxiliarJugador->SiguienteJugador != nullptr)
		{
			if (AuxiliarJugador->Jugador->Numero == NumeroJugador)
			{
				DatosJugadoraMover = AuxiliarJugador->Jugador;
				NodoPlayer* DatoEliminar = AuxiliarJugador;
				if (header->Jugador->Numero == NumeroJugador)
				{
					header = header->SiguienteJugador;
					NodoPlayer* DatoEliminar = AuxiliarJugador;
					delete DatoEliminar;
					return 1;
				}
				AuxiliarJugador->AnterirorJugador->SiguienteJugador = AuxiliarJugador->SiguienteJugador;
				delete DatoEliminar;
				return 1;
			}
			AuxiliarJugador = AuxiliarJugador->SiguienteJugador;
		}
		if (AuxiliarJugador->Jugador->Numero == NumeroJugador)
		{
			DatosJugadoraMover = AuxiliarJugador->Jugador;
			NodoPlayer* DatoEliminar = AuxiliarJugador;

			header = nullptr;
			delete DatoEliminar;
			return 1;
		}
	}
}
