#include "Tablero.h"
#include <map>
#include <set>        
#include <cstdlib> // Para rand() y srand()

map <int, int> cambiosL; // MAPA PARA ALMACENAR CAMBIOS DE LAS SERPIENTE
map <int, int> cambios; // MAPA PARA AKMACENAR LOS CAMBIOS DE LAS ESCALERAS
set <int> Generados; // LISTAS QUE GUARDA LOS NUMEROS USADOS PARA DONDE SE MUEVEN 
set <int> CasillasEspeciales; //LISTA QUE GUARDA CUALES ON LAS CASILLAS ESPCIALES

//CREAMOS ESCALERAS Y SEPIENTES

//CREASMO ESCALERA
int Tablero::Escalera(int num, int NumeroCasilla, int EscaleraC) {
	//VERIFICAMOS SI EL NUMERO SELECCIONADO YA TIENE UNA CASILLA ESPECIAL
	int resultado=0;
	if (cambios.find(num) != cambios.end()) {
		cout << "Cayo en una escalera " << num << ": " << cambios[num] << std::endl;
		return cambios[num];
	}
	int Cantidad = static_cast<int>(floor(NumeroCasilla * 0.15));

	if (EscaleraC <= Cantidad)
	{
		//GENERAMOS UN NUMERO ALEATORIO DONDE SE MOVERA LA ESCALERA
		resultado = NumeroAleatorio(num, NumeroCasilla-1);

		cambios[num] = resultado; //GUARAMOS RESULTADOS EN EL MAPA QUE GUARDA LAS ESCALERAS

		cout << "Creando escalera " << num << " ahora estara en la casilla: " << resultado << endl;
	}
	return resultado;
}

//CREAMOS SERPIENTES
int Tablero::Lombriz(int num, int NumeroCasilla, int EscaleraC) {
	//VERIFICAMOS SI EL NUMERO SELECCIONADO YA TIENE UNA CASILLA ESPECIAL
	int resultado = 0;
	if (cambiosL.find(num) != cambiosL.end()) {
		cout << "Cayo en una lombriz " << num << ": " << cambiosL[num] << std::endl;
		return cambiosL[num];
	}
	int Cantidad = static_cast<int>(floor(NumeroCasilla * 0.15));

	if (EscaleraC <= Cantidad)
	{
		//GENERAMOS UN NUMERO ALEATORIO DONDE SE MOVERA LA SERPIENTE

		resultado = NumeroAleatorioL(num, NumeroCasilla - 1);

		cambiosL[num] = resultado; //GUARAMOS RESULTADOS EN EL MAPA QUE GUARDA LAS ESCALERAS

		cout << "Creando lombriz " << num << " ahora estara en la casilla: " << resultado << endl;
	}
	return resultado;
}

//SACAMOS RESULTADOS ALEATORIOS DE LAS SERPIENTES
int Tablero::NumeroAleatorioL(int num, int NumeroCasilla)
{
	srand(time(0));
	int resultado = 0;
	do {
		//GENERAMOS NUMERO ALEATORIOS DESDE LA CASILLA QUE ESTAMOS AL MAXIMO DE CASILLAS
		resultado = rand() % NumeroCasilla-num + num;

	} while (resultado >= num-5 || resultado <=0 || (Generados.find(resultado) != Generados.end())); // REPETIR SI EL NUMERO ES IGUAL A NUM
	Generados.insert(resultado);
	return resultado;
}
int Tablero:: NumeroAleatorio(int num , int NumeroCasilla)
{
	srand(time(0));
	int resultado=0;
	do {
		//GENERAMOS NUMERO ALEATORIOS DESDE LA CASILLA QUE ESTAMOS AL MAXIMO DE CASILLAS
		resultado = rand() % NumeroCasilla-num + num;
	} while ((resultado <= num + 5) || (Generados.find(resultado) != Generados.end())); // RESPETIR SI EL NUMERO ES IGUAL A NUM
	Generados.insert(resultado);
	return resultado;
}

//CREAMOS SERPIENTES
void Tablero::CrearLombriz(int NumeroCasilla)
{
	srand(time(0));
	int resultado = 0;
	for (int EscaleraC = 1;EscaleraC <= static_cast<int>(floor(NumeroCasilla * 0.15)); EscaleraC++)
	{
		do {
			resultado = rand() % (NumeroCasilla-8) + 7;//REVISION
		} while (CasillasEspeciales.find(resultado) != CasillasEspeciales.end()); // REEPTIR SI EL UMERO YA FUE GENERADO
		CasillasEspeciales.insert(resultado);
		Lombriz(resultado, NumeroCasilla, EscaleraC);
	}
}

//CREAR ESCALARES
void Tablero::CrearEscalera(int NumeroCasilla)
{
	srand(time(0));
	int resultado = 0;
	for (int EscaleraC = 1;EscaleraC <= static_cast<int>(floor(NumeroCasilla * 0.15)); EscaleraC++)
	{
		do {
		resultado = rand() % (NumeroCasilla-8) + 1;
		} while (CasillasEspeciales.find(resultado) != CasillasEspeciales.end()); // REPETIR SI EL NUMERO FUE GENERADO
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

//PONEMOS A TODOS LOS JUGADORES EN LA CASILLA 1
void Tablero::AgregarJugadores(int CantidadJugadores)
{
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
	headerFila->Fila->AgregarJugadores(CantidadJugadores);
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";


}


//BUSCAMOS AL JUGADOR Y OBTENEMOS SU DIRECCION DE MEMEORIA DE LA CLASE
Player* Tablero::BuscadorJugador(int NumeroJugador)
{
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

//TIRAR DADO
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
//MOVER JUGADOR EN LAS CASILLAS CORRESPONDIENTES
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