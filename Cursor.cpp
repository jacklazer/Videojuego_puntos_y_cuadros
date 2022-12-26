/**
Archivo: Cursor.cpp
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

#include "Cursor.h"

Cursor::Cursor(int un_limite_x_del_cursor, int un_limite_y_del_cursor)
{
	if ((un_limite_x_del_cursor > 0) and (un_limite_x_del_cursor < 21) and (un_limite_y_del_cursor > 0) and (un_limite_y_del_cursor < 21))
	{
		limite_x_del_cursor = (un_limite_x_del_cursor*2)+1;
		limite_y_del_cursor = un_limite_y_del_cursor;
	}

	cursor_cursor = GetStdHandle(STD_OUTPUT_HANDLE);
	posicion_x_y_del_cursor.X = limite_x_del_cursor;
	posicion_x_y_del_cursor.Y = 0;
	SetConsoleCursorPosition(cursor_cursor, posicion_x_y_del_cursor);
	printf("_");

	posiciones_prohibidas =
	{
		{{true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}, {true}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}},
		{{false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}, {false}}
	};
}

Cursor::~Cursor()
{
}

void Cursor::mover(int px, int py)
{
	int valor_de_reserva_de_x = posicion_x_y_del_cursor.X;
	int valor_de_reserva_de_y = posicion_x_y_del_cursor.Y;

	SetConsoleCursorPosition(cursor_cursor, posicion_x_y_del_cursor);
	printf(" ");
	
	posicion_x_y_del_cursor.X += px;
	posicion_x_y_del_cursor.Y += py;

	if ((posicion_x_y_del_cursor.X) < 0)
		posicion_x_y_del_cursor.X = 0;
	if ((posicion_x_y_del_cursor.X) > limite_x_del_cursor)
		posicion_x_y_del_cursor.X = limite_x_del_cursor;

	if ((posicion_x_y_del_cursor.Y) < 0)
		posicion_x_y_del_cursor.Y = 0;
	if ((posicion_x_y_del_cursor.Y) > limite_y_del_cursor)
		posicion_x_y_del_cursor.Y = limite_y_del_cursor;

	if ((py == 1) or (py == -1))
	{
		while (posiciones_prohibidas[posicion_x_y_del_cursor.Y][posicion_x_y_del_cursor.X][0])
		{
			if (((posicion_x_y_del_cursor.Y) <= 0) or ((posicion_x_y_del_cursor.Y) >= limite_y_del_cursor))
				posicion_x_y_del_cursor.Y = valor_de_reserva_de_y;
			else
				posicion_x_y_del_cursor.Y += py;
		}
	}

	if ((px == 1) or (px == -1))
	{
		while (posiciones_prohibidas[posicion_x_y_del_cursor.Y][posicion_x_y_del_cursor.X][0])
		{
			if (((posicion_x_y_del_cursor.X) <= 0) or ((posicion_x_y_del_cursor.X) >= limite_x_del_cursor))
				posicion_x_y_del_cursor.X = valor_de_reserva_de_x;
			else
				posicion_x_y_del_cursor.X += px;
		}
	}

	SetConsoleCursorPosition(cursor_cursor, posicion_x_y_del_cursor);
}

int Cursor::posicion_x()
{
	return posicion_x_y_del_cursor.X;
}

int Cursor::posicion_y()
{
	return posicion_x_y_del_cursor.Y;
}

void Cursor::marcar_posicion_prohibida()
{
	if (posicion_x_y_del_cursor.X != limite_x_del_cursor)
	{
		posiciones_prohibidas[posicion_x_y_del_cursor.Y][posicion_x_y_del_cursor.X].erase(posiciones_prohibidas[posicion_x_y_del_cursor.Y][posicion_x_y_del_cursor.X].begin());
		posiciones_prohibidas[posicion_x_y_del_cursor.Y][posicion_x_y_del_cursor.X].push_back(true);
		posicion_x_y_del_cursor.X = limite_x_del_cursor;
		posicion_x_y_del_cursor.Y = 0;
		SetConsoleCursorPosition(cursor_cursor, posicion_x_y_del_cursor);
		printf("_");
	}
}

void Cursor::mover_a(int px, int py)
{
	posicion_x_y_del_cursor.X = px;
	posicion_x_y_del_cursor.Y = py;
	SetConsoleCursorPosition(cursor_cursor, posicion_x_y_del_cursor);
}

int Cursor::devolver_limite_x_del_cursor()
{
	return limite_x_del_cursor;
}

int Cursor::devolver_limite_y_del_cursor()
{
	return limite_y_del_cursor;
}

bool Cursor::posicion_prohibida(int px, int py)
{
	return posiciones_prohibidas[py][px][0];
}
