/**
Archivo: Tablero.cpp
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

#include "Tablero.h"

Tablero::Tablero(int una_dimension_x_del_tablero, int una_dimension_y_del_tablero)
{
	if ((una_dimension_x_del_tablero > 0) and (una_dimension_x_del_tablero <21) and (una_dimension_y_del_tablero > 0) and (una_dimension_y_del_tablero < 21))
	{
		dimension_x_del_tablero = (una_dimension_x_del_tablero*2)+1;
		dimension_y_del_tablero = una_dimension_y_del_tablero;
	}

	identificador_de_pantalla_del_tablero = GetStdHandle(STD_OUTPUT_HANDLE);
	posicion_x_y_del_tablero.X = 0;
	posicion_x_y_del_tablero.Y = 0;
	SetConsoleCursorPosition(identificador_de_pantalla_del_tablero, posicion_x_y_del_tablero);

	posiciones_con_rayas =
	{
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}}
	};
}

Tablero::~Tablero()
{
}

void Tablero::ver_tablero()
{
	for (int f = 0; f <= dimension_y_del_tablero; f++)
	{
		posicion_x_y_del_tablero.Y = f;

		for (int c = 0; c <= dimension_x_del_tablero; c++)
		{
			posicion_x_y_del_tablero.X = c;
			SetConsoleCursorPosition(identificador_de_pantalla_del_tablero, posicion_x_y_del_tablero);

			if ((posicion_x_y_del_tablero.X) % 2 == 0)
				printf(".");
			else
				printf(" ");
		}
	}
}

void Tablero::modificar_tablero(Cursor un_cursor)
{
	for (int f = 0; f <= dimension_y_del_tablero; f++)
	{
		posicion_x_y_del_tablero.Y = f;

		for (int c = 0; c <= dimension_x_del_tablero; c++)
		{
			posicion_x_y_del_tablero.X = c;
			SetConsoleCursorPosition(identificador_de_pantalla_del_tablero, posicion_x_y_del_tablero);

			if (un_cursor.posicion_x() == c and un_cursor.posicion_y() == f)
			{
				if ((posicion_x_y_del_tablero.X) % 2 == 0)
					printf("|");
				else
					printf("_");
			}
			else
			{
				if (posiciones_con_rayas[f][c][0] == true)
				{
					if ((posicion_x_y_del_tablero.X) % 2 == 0)
						printf("|");
					else
						printf("_");
				}
				else
				{
					if ((posicion_x_y_del_tablero.X) % 2 == 0)
						printf(".");
					else
						printf(" ");
				}
			}
		}
	}
}

void Tablero::guardar_modificacion_del_tablero(Cursor un_cursor)
{
	if (un_cursor.posicion_x() != dimension_x_del_tablero)
	{
		posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x()].erase(posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x()].begin());
		posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x()].push_back(true);
	}
}

int Tablero::cuadros_construidos(Cursor un_cursor)
{
	int numero_de_cuadros_construidos = 0;

	if (un_cursor.posicion_y() == 0)
	{
		if ((posiciones_con_rayas[un_cursor.posicion_y() + 1][un_cursor.posicion_x() - 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() + 1][un_cursor.posicion_x()][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() + 1][un_cursor.posicion_x() + 1][0] == true))
			numero_de_cuadros_construidos++;
	}

	if ((un_cursor.posicion_y() == 20) and (un_cursor.posicion_x() % 2 == 0))
	{
		if ((posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() - 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() + 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() - 1][un_cursor.posicion_x()][0] == true))
			numero_de_cuadros_construidos++;
	}

	if (un_cursor.posicion_x() == 0)
	{
		if ((posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() + 2][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() + 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() - 1][un_cursor.posicion_x() + 1][0] == true))
			numero_de_cuadros_construidos++;
	}

	if (un_cursor.posicion_x() == 40)
	{
		if ((posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() - 2][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() - 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() - 1][un_cursor.posicion_x() - 1][0] == true))
			numero_de_cuadros_construidos++;
	}

	if ((un_cursor.posicion_y() != 0) and (un_cursor.posicion_y() != 20) and (un_cursor.posicion_x() != 0) and (un_cursor.posicion_x() != 40))
	{
		if (un_cursor.posicion_x() % 2 == 0)
		{
			if ((posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() - 2][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() - 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() - 1][un_cursor.posicion_x() - 1][0] == true))
				numero_de_cuadros_construidos++;
			if ((posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() + 2][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() + 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() - 1][un_cursor.posicion_x() + 1][0] == true))
				numero_de_cuadros_construidos++;
		}
		else
		{
			if ((posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() - 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y()][un_cursor.posicion_x() + 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() - 1][un_cursor.posicion_x()][0] == true))
				numero_de_cuadros_construidos++;
			if ((posiciones_con_rayas[un_cursor.posicion_y() + 1][un_cursor.posicion_x() - 1][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() + 1][un_cursor.posicion_x()][0] == true) and (posiciones_con_rayas[un_cursor.posicion_y() + 1][un_cursor.posicion_x() + 1][0] == true))
				numero_de_cuadros_construidos++;
		}
	}

	return numero_de_cuadros_construidos;
}
