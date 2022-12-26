/**
Archivo: TablaDePuntuacion.cpp
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

#include "TablaDePuntuacion.h"
#include <stdio.h>

using namespace std;

TablaDePuntuacion::TablaDePuntuacion(Lobby un_lobby)
{
	int el_maximo = max(un_lobby.devolver_numero_de_bots(), un_lobby.devolver_numero_de_jugadores());
	for (int participante = 0; participante < el_maximo; participante++)
	{
		if (un_lobby.devolver_numero_de_jugadores() - 1 >= participante)
		{
			lista_de_participantes.push_back(un_lobby.devolver_jugador(participante));
			dificultad_de_los_participantes_bots.push_back("0");
			puntuacion_de_los_participantes.push_back(0);
		}
		if (un_lobby.devolver_numero_de_bots() - 1 >= participante)
		{
			lista_de_participantes.push_back(un_lobby.devolver_bot(participante));
			dificultad_de_los_participantes_bots.push_back(un_lobby.devolver_dificultad_del_bot(participante));
			puntuacion_de_los_participantes.push_back(0);
		}
	}

	identificador_de_pantalla_de_la_tabla = GetStdHandle(STD_OUTPUT_HANDLE);

	posicion_x_y_de_la_tabla.X = 45;
	posicion_x_y_de_la_tabla.Y = 1;
	SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
	printf("PARTICIPANTES");

	posicion_x_y_de_la_tabla.X = 60;
	posicion_x_y_de_la_tabla.Y = 1;
	SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
	printf("PUNTUACION");

	for (int participante = 0; participante < lista_de_participantes.size(); participante++)
	{
		posicion_x_y_de_la_tabla.X = 45;
		posicion_x_y_de_la_tabla.Y = 3 + (participante*2);
		SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
		cout << lista_de_participantes[participante] << ": ";

		posicion_x_y_de_la_tabla.X = 60;
		posicion_x_y_de_la_tabla.Y = 3 + (participante * 2);
		SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
		cout << puntuacion_de_los_participantes[participante];
	}

	posicion_x_y_de_la_tabla.X = 43;
	posicion_x_y_de_la_tabla.Y = 3;
	SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
	printf(">");
}

TablaDePuntuacion::~TablaDePuntuacion()
{
}

void TablaDePuntuacion::modificar_puntuacion(Tablero un_tablero, Cursor un_cursor)
{
	if (un_tablero.cuadros_construidos(un_cursor) > 0)
	{
		puntuacion_de_los_participantes[turno] += un_tablero.cuadros_construidos(un_cursor);
		posicion_x_y_de_la_tabla.X = 60;
		posicion_x_y_de_la_tabla.Y = 3 + (turno * 2);
		SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
		cout << puntuacion_de_los_participantes[turno];
	}
}

void TablaDePuntuacion::pasar_turno(Tablero un_tablero, Cursor un_cursor)
{
	if (un_tablero.cuadros_construidos(un_cursor) == 0)
	{
		posicion_x_y_de_la_tabla.X = 43;
		posicion_x_y_de_la_tabla.Y = 3 + (turno * 2);
		SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
		printf(" ");

		turno++;
		if ((turno >= puntuacion_de_los_participantes.size()) and (turno >= lista_de_participantes.size()))
			turno = 0;

		posicion_x_y_de_la_tabla.X = 43;
		posicion_x_y_de_la_tabla.Y = 3 + (turno * 2);
		SetConsoleCursorPosition(identificador_de_pantalla_de_la_tabla, posicion_x_y_de_la_tabla);
		printf(">");
	}
}

bool TablaDePuntuacion::turno_de_un_bot()
{
	if (dificultad_de_los_participantes_bots[turno] == "0")
		return false;
	else
		return true;
}

string TablaDePuntuacion::devolver_dificultad_del_bot()
{
	return dificultad_de_los_participantes_bots[turno];
}

bool TablaDePuntuacion::fin_del_juego(Lobby un_lobby)
{
	int suma = 0;
	for (int i = 0; i < puntuacion_de_los_participantes.size(); i++)
		suma += puntuacion_de_los_participantes[i];

	if (suma == (un_lobby.devolver_dimencion_x() * un_lobby.devolver_dimencion_y()))
		return true;
	else
		return false;
}

string TablaDePuntuacion::ganador()
{
	int posicion_del_ganador = 0;
	string ganador = "... ninguno!";
	for (int i = 0; i < puntuacion_de_los_participantes.size() - 1; i++)
	{
		if (puntuacion_de_los_participantes[posicion_del_ganador] > puntuacion_de_los_participantes[i + 1])
		{
			ganador = lista_de_participantes[posicion_del_ganador];
		}
		else
		{
			if (puntuacion_de_los_participantes[posicion_del_ganador] < puntuacion_de_los_participantes[i + 1])
			{
				posicion_del_ganador = i + 1;
				ganador = lista_de_participantes[posicion_del_ganador];
			}
			else
			{
				if (puntuacion_de_los_participantes[posicion_del_ganador] = puntuacion_de_los_participantes[i + 1])
				{
					ganador = "... ninguno!";
				}
			}
		}
	}
	
		return ganador;
}
