#include "Tablero.h"
#include <map>
#include <set>        
#include <cstdlib> // Para rand() y srand()

map <int, int> cambiosL; // Mapa para almacenar los cambios
map <int, int> cambios; // Mapa para almacenar los cambios
set <int> Generados; // Mapa para almacenar los cambios
set<int> CasillasEspeciales;
// Realizamos llamdas para tener un nuevo tablero

//Realizamos todas las funciones para aleatoriedad en las funciones

int Tablero::Escalera(int num, int NumeroCasilla, int EscaleraC) {
	// Verificar si el número ya tiene un cambio guardado
	int resultado=0;
	if (cambios.find(num) != cambios.end()) {
		cout << "Callo en una escalera " << num << ": " << cambios[num] << std::endl;
		return cambios[num];
	}
	int Cantidad = static_cast<int>(floor(NumeroCasilla * 0.15));

	if (EscaleraC <= Cantidad)
	{
		// Generamos un número aleatorio de hasta 6 cifras
		resultado = NumeroAleatorio(num, NumeroCasilla-1);

		cambios[num] = resultado; // Guardamos el resultado en el mapa

		cout << "Creando escalera " << num << " ahora estara en la casilla: " << resultado << endl;
	}
	return resultado;
}

int Tablero::Lombriz(int num, int NumeroCasilla, int EscaleraC) {
	// Verificar si el número ya tiene un cambio guardado
	int resultado = 0;
	if (cambiosL.find(num) != cambiosL.end()) {
		cout << "Callo en una lombriz " << num << ": " << cambiosL[num] << std::endl;
		return cambiosL[num];
	}
	int Cantidad = static_cast<int>(floor(NumeroCasilla * 0.15));

	if (EscaleraC <= Cantidad)
	{
		// Generamos un número aleatorio de hasta 6 cifras
		resultado = NumeroAleatorioL(num, NumeroCasilla - 1);

		cambiosL[num] = resultado; // Guardamos el resultado en el mapa

		cout << "Creando lombriz " << num << " ahora estara en la casilla: " << resultado << endl;
	}
	return resultado;
}
int Tablero::NumeroAleatorioL(int num, int NumeroCasilla)
{
	// Inicializa la semilla para generar números aleatorios
	srand(time(0));
	int resultado = 0;
	do {
		// Genera un número aleatorio entre 1 y NumeroCasilla
		resultado = rand() % NumeroCasilla-num + num;

	} while (resultado >= num-5 || resultado <=0 || (Generados.find(resultado) != Generados.end())); // Repetir si el número generado es igual a num
	Generados.insert(resultado);
	return resultado;
}
int Tablero:: NumeroAleatorio(int num , int NumeroCasilla)
{
	// Inicializa la semilla para generar números aleatorios
	srand(time(0));
	int resultado=0;
	do {
		// Genera un número aleatorio entre 1 y NumeroCasilla
		resultado = rand() % (NumeroCasilla-num) + num;
	} while ((resultado <= num + 5) || (Generados.find(resultado) != Generados.end())); // Repetir si el número generado es igual a num
	Generados.insert(resultado);
	return resultado;
}
//Creamos Lombrices
void Tablero::CrearLombriz(int NumeroCasilla)
{
	srand(time(0));
	int resultado = 0;
	for (int EscaleraC = 1;EscaleraC <= static_cast<int>(floor(NumeroCasilla * 0.15)); EscaleraC++)
	{
		do {
			resultado = rand() % (NumeroCasilla-8) + 7;//REVISION
		} while (CasillasEspeciales.find(resultado) != CasillasEspeciales.end()); // Repetir si el número ya fue generado
		CasillasEspeciales.insert(resultado);
		Lombriz(resultado, NumeroCasilla, EscaleraC);
	}
}

//Creamos las escaleras

void Tablero::CrearEscalera(int NumeroCasilla)
{
	srand(time(0));
	int resultado = 0;
	for (int EscaleraC = 1;EscaleraC <= static_cast<int>(floor(NumeroCasilla * 0.15)); EscaleraC++)
	{
		do {
		resultado = rand() % (NumeroCasilla-8) + 1;
		} while (CasillasEspeciales.find(resultado) != CasillasEspeciales.end()); // Repetir si el número ya fue generado
		CasillasEspeciales.insert(resultado);
		Escalera(resultado, NumeroCasilla, EscaleraC);
	}
}
void Tablero::CrearFilas(int NumeroCasillas)
{

	if (headerFila == nullptr)
	{
		headerFila = new NodoFilas();
		headerFila ->Fila = new Filas();
		headerFila ->Fila->CrearCasillas(0);
	}
	NodoFilas* IndiceFilas = headerFila;
	int ConteoCasillas = 5;
	for (int i = 1; i <= NumeroCasillas / 5;i++)
	{
		IndiceFilas->SiguienteFila = new NodoFilas();
		IndiceFilas->SiguienteFila->Fila = new Filas();
		IndiceFilas->SiguienteFila->Fila->CrearCasillas(ConteoCasillas);
		IndiceFilas = IndiceFilas->SiguienteFila;
		ConteoCasillas = ConteoCasillas + 5;
	}
	cout << "Tablero con: " << NumeroCasillas << " casillas fue creado exitosamente\n";
}
//Aqui ponemos al jugador en la casilla 1
void Tablero::AgregarJugadores(int CantidadJugadores)
{
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
	headerFila->Fila->AgregarJugadores(CantidadJugadores);
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";


}

Player* Tablero::BuscadorJugador(int NumeroJugador)
{

	//Arreglar no llega al ultimo
	NodoFilas* AuxiliarFila = headerFila;
	while (AuxiliarFila->SiguienteFila!=nullptr)
	{
		bool Encontrada = AuxiliarFila->Fila->BusquedaJugadorTablero(NumeroJugador);
		if (Encontrada == true)
		{
			Player* Datos = AuxiliarFila->Fila->JugadorDatosMover;
			AuxiliarFila->Fila->JugadorDatosMover = nullptr;
			return Datos;
		}
		AuxiliarFila = AuxiliarFila->SiguienteFila;
	}
	bool Encontrada = AuxiliarFila->Fila->BusquedaJugadorTablero(NumeroJugador);
	if (Encontrada == true)
	{
		Player* Datos = AuxiliarFila->Fila->JugadorDatosMover;
		AuxiliarFila->Fila->JugadorDatosMover = nullptr;
		return Datos;
	}

}
//tirar dado
int Tablero::TirarDado() {
	srand(time(0));
	int resultado = rand() % 6 + 1;
	bool Dado;
	cout << "Precione 1 para tirar el dado\n";
	cin >> Dado;
	cout << "Tirando el dado... 🎲\n";
	cout << "Has sacado un " << resultado << "!\n";
	return resultado;
}
//Mover Jugador
Player* Tablero::MoverJugador(int NumeroJugador,int NumeroCasilla)
{
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
	Player* DatosJugador = BuscadorJugador(NumeroJugador);
	cout << "Turno de " << DatosJugador->Nombre << endl;
	int Moviemiento = TirarDado();
	int Mov = DatosJugador->NumeroCasilla + Moviemiento;
	int AuxMovE = Escalera(Mov, NumeroCasilla, NumeroCasilla);
	int AuxMovL = Lombriz(Mov, NumeroCasilla, NumeroCasilla);
	if (AuxMovE != 0)
	{
		Mov = AuxMovE;
	}
	if (AuxMovL != 0)
	{
		Mov = AuxMovL;
	}
	if (Mov <= NumeroCasilla)
	{
		NodoFilas* AuxiliarFila = headerFila;
		while (AuxiliarFila->SiguienteFila != nullptr)
		{
			bool Encontrada = AuxiliarFila->Fila->MoverJugador(Mov, DatosJugador);
			if (Encontrada == true)
			{
				break;
			}
			AuxiliarFila = AuxiliarFila->SiguienteFila;
		}
	}
	else {
		NodoFilas* AuxiliarFila = headerFila;
		while (AuxiliarFila->SiguienteFila != nullptr)
		{
			bool Encontrada = AuxiliarFila->Fila->MoverJugador(DatosJugador->NumeroCasilla, DatosJugador);
			if (Encontrada == true)
			{
				break;
			}
			AuxiliarFila = AuxiliarFila->SiguienteFila;
		}
		cout << "uy Se paso del tablero, sigue en las posicion " << DatosJugador->NumeroCasilla << " Suerte para la proxima\n";
	}
	return DatosJugador;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";

}