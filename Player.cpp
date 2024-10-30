#include "Player.h"

void Player::AgregarDatosJugador(int i, int casilla)
{
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Agregue la infromacion del jugador #" << i << endl;
	cout << "Ingrese su Nombre\n";
	cin >> Nombre;
	Numero = i;
	NumeroCasilla = casilla;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";


}