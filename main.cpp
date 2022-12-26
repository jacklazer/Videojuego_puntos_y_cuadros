/**
Archivo: main.cpp
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

/**
HISTORIA: Este programa es un videojuego basado en el juego llamado puntos y cuadros, en este se dibuja 
una serie de puntos ordenados de tal manera que quedan varias filas paralelas y columnas paralelas de 
ellos dentro de un cuadro, este juego admite un mínimo de 2 jugadores y cada uno tiene un turno cada 
cierto número de turnos dependiendo del número de jugadores, en cada turno el jugador deberá unir con 
una línea vertical u horizontal dos puntos cualquiera que no intersectan ningún otro punto, si el jugador
logra dibujar un cuadrado obtiene un punto (en su puntaje) y obtiene un turno extra inmediato, el juego 
acaba cuando no quedan mas puntos que puedan unirse y el ganador es el jugador con mayor puntaje. 

Esta version del juego permite ceder turnos, lo que da pie para realizar nuevas estrategias.
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Lobby.h"
#include "TablaDePuntuacion.h"
#include "Bot.h"
#include "BotTonto.h"
#include "BotNoTanTonto.h"
#include "Tablero.h"
#include "Cursor.h"

using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77

void ocultar_cursor_automatico()
{
	HANDLE identificador_de_pantalla_del_ocultador;
	identificador_de_pantalla_del_ocultador = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_1_0;
	cursor_1_0.dwSize = 1;
	cursor_1_0.bVisible = FALSE;

	SetConsoleCursorInfo(identificador_de_pantalla_del_ocultador, &cursor_1_0);
}

void limpiar_pantalla()
{
	HANDLE identificador_de_pantalla_del_limpiador;
	identificador_de_pantalla_del_limpiador = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD posicion_x_y_del_limpiador;
	posicion_x_y_del_limpiador.X = 0;

	for (int linea = 0; linea < 30; linea++)
	{
		posicion_x_y_del_limpiador.Y = linea;
		SetConsoleCursorPosition(identificador_de_pantalla_del_limpiador, posicion_x_y_del_limpiador);
		printf("                                                                        ");
	}
}

int main() 
{
	Lobby el_lobby;
	limpiar_pantalla();
	el_lobby.preguntar_las_dimenciones_del_tablero();
	limpiar_pantalla();
	el_lobby.preguntar_por_jugadores();
	limpiar_pantalla();
	el_lobby.preguntar_por_bots();
	limpiar_pantalla();

	ocultar_cursor_automatico();

	TablaDePuntuacion la_tabla_de_puntuacion(el_lobby);

	BotTonto el_bot_tonto;
	BotNoTanTonto el_bot_no_tan_tonto;

	Tablero el_tablero(el_lobby.devolver_dimencion_x(), el_lobby.devolver_dimencion_y());
	el_tablero.ver_tablero();

	Cursor el_cursor(el_lobby.devolver_dimencion_x(), el_lobby.devolver_dimencion_y());

	char tecla_presionada;
	int movimiento_horizontal, movimiento_vertical;
	while (la_tabla_de_puntuacion.fin_del_juego(el_lobby) == false)
	{
		movimiento_horizontal = 0;
		movimiento_vertical = 0;

		if (_kbhit())
		{
			tecla_presionada = _getch();
			if (tecla_presionada == ARRIBA or tecla_presionada == ABAJO or tecla_presionada == IZQUIERDA or tecla_presionada == DERECHA)
			{
				if (tecla_presionada == ARRIBA)
					movimiento_vertical = -1;
				if (tecla_presionada == ABAJO)
					movimiento_vertical = 1;
				if (tecla_presionada == IZQUIERDA)
					movimiento_horizontal = -1;
				if (tecla_presionada == DERECHA)
					movimiento_horizontal = 1;
				el_cursor.mover(movimiento_horizontal, movimiento_vertical);
				el_tablero.modificar_tablero(el_cursor);
			}

			if (la_tabla_de_puntuacion.turno_de_un_bot() == true)
			{
				if (la_tabla_de_puntuacion.devolver_dificultad_del_bot() == "2")
					el_bot_no_tan_tonto.jugar_bot(la_tabla_de_puntuacion, el_tablero, el_cursor);
				else
					el_bot_tonto.jugar_bot(la_tabla_de_puntuacion, el_tablero, el_cursor);
			}
			else
			{
				if (tecla_presionada == ' ')
				{
					la_tabla_de_puntuacion.modificar_puntuacion(el_tablero, el_cursor);
					la_tabla_de_puntuacion.pasar_turno(el_tablero, el_cursor);
					el_tablero.guardar_modificacion_del_tablero(el_cursor);
					el_cursor.marcar_posicion_prohibida();
				}
			}
		}

		Sleep(10);
	}

	limpiar_pantalla();

	cout << "El ganador es " << la_tabla_de_puntuacion.ganador();
	cout << endl;

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

	cout << endl;

	return 0;
}
