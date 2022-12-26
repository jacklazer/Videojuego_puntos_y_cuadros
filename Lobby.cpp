/**
Archivo: Lobby.cpp
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

#include "Lobby.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

Lobby::Lobby()
{
	identificador_de_pantalla_del_lobby = GetStdHandle(STD_OUTPUT_HANDLE);

	posicion_x_y_del_lobby.X = 10;
	posicion_x_y_del_lobby.Y = 5;
	SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
	printf("PUNTOS Y CUADROS: EL JUEGO");

	posicion_x_y_del_lobby.X = 20;
	posicion_x_y_del_lobby.Y = 10;
	SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
	printf("Presione cualquier tecla para continuar...");

	bool continuar = false;
	char cualquier_tecla;
	while (continuar == false)
	{
		if (_kbhit())
		{
			cualquier_tecla = _getch();
			if (cualquier_tecla)
			{
				continuar = true;
			}
		}

		Sleep(10);
	}
}

Lobby::~Lobby()
{
}

void Lobby::preguntar_las_dimenciones_del_tablero()
{
	posicion_x_y_del_lobby.X = 0;

	posicion_x_y_del_lobby.Y = 3;
	SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
	printf("Ancho del tablero: "); cin >> ancho_del_tablero;

	posicion_x_y_del_lobby.Y = 5;
	SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
	printf("Alto del tablero: "); cin >> alto_del_tablero;
}

void Lobby::preguntar_por_jugadores()
{
	posicion_x_y_del_lobby.X = 0;
	posicion_x_y_del_lobby.Y = 3;
	SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
	printf("Numero de jugadores: "); cin >> numero_de_jugadores;

	if (numero_de_jugadores > 10)
		numero_de_jugadores = 10;

	if (numero_de_jugadores < 0)
		numero_de_jugadores = 0;

	string nombre_de_jugador;
	for (int jugador = 0; jugador < numero_de_jugadores; jugador++)
	{
		posicion_x_y_del_lobby.Y = 6 + (jugador*2);
		SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
		cout << "Nombre del jugador " << jugador+1 << ": "; cin >> nombre_de_jugador;

		nombres_de_jugadores.push_back(nombre_de_jugador);
	}
}

void Lobby::preguntar_por_bots()
{
	posicion_x_y_del_lobby.X = 0;
	posicion_x_y_del_lobby.Y = 3;
	SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
	printf("Numero de bots: "); cin >> numero_de_bots;

	if (numero_de_bots > 10)
		numero_de_bots = 10;

	if (numero_de_bots < 0)
		numero_de_bots = 0;

	posicion_x_y_del_lobby.X = 0;
	posicion_x_y_del_lobby.Y = 6;
	SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
	printf("Dificultades: 1 = tonto; 2 = no tan tonto ");

	string dificultad_del_bot;
	string nombre_del_bot_bot;
	for (int bot = 0; bot < numero_de_bots; bot++)
	{
		posicion_x_y_del_lobby.Y = 9 + (bot * 2);
		SetConsoleCursorPosition(identificador_de_pantalla_del_lobby, posicion_x_y_del_lobby);
		cout << "Dificultad del bot " << bot + 1 << ": "; cin >> dificultad_del_bot;

		nombre_del_bot_bot = "Bot " + to_string(bot+1);
		nombres_de_bots.push_back(nombre_del_bot_bot);

		if (dificultad_del_bot == "1" or dificultad_del_bot == "tonto")
			dificultad_de_bots.push_back("1");
		else
			dificultad_de_bots.push_back("2");
	}
}

int Lobby::devolver_dimencion_x()
{
	return ancho_del_tablero;
}

int Lobby::devolver_dimencion_y()
{
	return alto_del_tablero;
}

int Lobby::devolver_numero_de_jugadores()
{
	return numero_de_jugadores;
}

string Lobby::devolver_jugador(int numero_de_jugador)
{
	return nombres_de_jugadores[numero_de_jugador];
}

int Lobby::devolver_numero_de_bots()
{
	return numero_de_bots;
}

string Lobby::devolver_bot(int numero_de_bot)
{
	return nombres_de_bots[numero_de_bot];
}

string Lobby::devolver_dificultad_del_bot(int numero_de_bot)
{
	return dificultad_de_bots[numero_de_bot];
}
