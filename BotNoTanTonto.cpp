/**
Archivo: BotNoTanTonto.cpp
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

#include "BotNoTanTonto.h"

BotNoTanTonto::BotNoTanTonto()
	:Bot()
{
}

BotNoTanTonto::~BotNoTanTonto()
{
}

void BotNoTanTonto::jugar_bot(TablaDePuntuacion& una_tabla_de_puntuacion, Tablero& un_tablero, Cursor& un_cursor)
{
	int fila = 0;
	int columna = un_cursor.devolver_limite_x_del_cursor() + 1;

	un_cursor.mover_a(columna, fila);
	un_cursor.mover(-1, 0);
	int columna_auxiliar = columna;
	columna = un_cursor.posicion_x();

	while ((columna == columna_auxiliar) and (fila < un_cursor.devolver_limite_y_del_cursor()))
	{
		fila++;
		columna = un_cursor.devolver_limite_x_del_cursor() + 1;
		un_cursor.mover_a(columna, fila);
		un_cursor.mover(-1, 0);
		columna_auxiliar = columna;
		columna = un_cursor.posicion_x();
	}

	while ((fila < un_cursor.devolver_limite_y_del_cursor()) and (un_tablero.cuadros_construidos(un_cursor) <= 0))
	{
		while ((columna != columna_auxiliar) and (un_tablero.cuadros_construidos(un_cursor) <= 0))
		{
			un_cursor.mover(-1, 0);
			columna_auxiliar = columna;
			columna = un_cursor.posicion_x();
		}

		if (un_tablero.cuadros_construidos(un_cursor) <= 0)
		{
			fila++;
			columna_auxiliar = columna;
			columna = un_cursor.devolver_limite_x_del_cursor() + 1;
			un_cursor.mover_a(columna, fila);
			un_cursor.mover(-1, 0);
			columna_auxiliar = columna;
			columna = un_cursor.posicion_x();

			while ((columna == columna_auxiliar) and (fila < un_cursor.devolver_limite_y_del_cursor()))
			{
				fila++;
				columna_auxiliar = columna;
				columna = un_cursor.devolver_limite_x_del_cursor() + 1;
				un_cursor.mover_a(columna, fila);
				un_cursor.mover(-1, 0);
				columna_auxiliar = columna;
				columna = un_cursor.posicion_x();
			}
		}
	}


	if (un_tablero.cuadros_construidos(un_cursor) <= 0)
	{
		fila = rand() % (un_cursor.devolver_limite_y_del_cursor() + 1);
		columna = rand() % (un_cursor.devolver_limite_x_del_cursor() + 1);

		while (un_cursor.posicion_prohibida(columna, fila) == true)
		{
			fila = rand() % (un_cursor.devolver_limite_y_del_cursor() + 1);
			columna = rand() % (un_cursor.devolver_limite_x_del_cursor() + 1);
		}
	}

	un_cursor.mover_a(columna, fila);
	un_tablero.modificar_tablero(un_cursor);

	una_tabla_de_puntuacion.modificar_puntuacion(un_tablero, un_cursor);
	una_tabla_de_puntuacion.pasar_turno(un_tablero, un_cursor);
	un_tablero.guardar_modificacion_del_tablero(un_cursor);
	un_cursor.marcar_posicion_prohibida();
}
