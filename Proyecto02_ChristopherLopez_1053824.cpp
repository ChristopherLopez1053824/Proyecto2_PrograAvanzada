// Proyecto02_ChristopherLopez_1053824.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//CHRISTOPHER CONRADO LOPEZ VICENTE
//1053824

#include <iostream>
#include "Tablero.h"

//PROGRAMA PRINCIPAL
int main()
{
		//PEDIMOS QUE INGRESEN LAS CANTIDAS DE CASILLAS Y LO GUARDAMOS EN UNA VARIABLE
	int CantidadCasillas;
	Tablero objTablero = Tablero();
	do {
		cout << "Agregue la cantidad de casillas que desea (Recuerda: mas de 30 y multiplo de 5): \n";
		cin >> CantidadCasillas;

		//VALIDAMOS QUE LAS CASILLAS SEAN MAYORES A 30 Y NUMEROS MULTIPLOS DE 5
		if (CantidadCasillas > 0 && CantidadCasillas >= 30 && CantidadCasillas % 5 == 0) {
			break;
		}
		else {
			cout << "Error: La cantidad debe ser un multiplo de 5 y no mayor a 30.\n";
		}
	} while (true);

		//LLAMAMOS A LAS FUNCIONES PARA CREAR EL TABLERO
	objTablero.CrearFilas(CantidadCasillas);
	objTablero.CrearEscalera(CantidadCasillas);
	objTablero.CrearLombriz(CantidadCasillas);

		//pEDIMOS QUE INGRESEN LA CANTIDAD DE JUGADORES Y LAS GUARDAMOS
	int CantidadJugadores;
	do {
		cout << "Ingrese la cantidad de jugadores (debe ser 2 o mas): ";
		cin >> CantidadJugadores;

		//VALIDAMOS QUE LA CANTIDAD DE JUGADORES SEAN AL MENOS DOS 
		if (CantidadJugadores >= 2) {
			break;
		}
		else {
			cout << "Error: La cantidad de jugadores debe ser exactamente 2 o mas.\n";
		}
	} while (true);

		//LLAMAMOS A LA FUNCION DE AGRAGAR JUGADORES EN LA PRIMERA CASILLA
	objTablero.AgregarJugadores(CantidadJugadores);

		//CREAMOS EL CICLO PARA QUE LOS JUGADORES TIREN POR TURNOS HASTA QUE UNO DE ELLOS GANE
	int CasillaUltima = 0;
	Player* DatosJugador = new Player();
	for (int x = 1; DatosJugador->NumeroCasilla != CantidadCasillas; x++)
	{
		DatosJugador = objTablero.MoverJugador(x, CantidadCasillas);
		if (x == CantidadJugadores)
		{
			x = 0;
		}
	}
	cout << "Felicidades Jugador numero " << DatosJugador->Numero << " " << DatosJugador->Nombre << "a ganado!!\n";

}
