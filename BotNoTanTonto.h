/**
Archivo: BotNoTanTonto.h
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

/**
CLASE: Bot No Tan Tonto
INTENCION: Crear un bot que marque posiciones en el tablero al azar, pero que cuando vea unaposicion que pueda
marcar un cuadro marcar alli.
RELACIONES: Es un Bot y conoce las clases Lobby, Tabla De Puntuacion y Cursor.
*/

#ifndef _BOTNOTANTONTO_H_
#define _BOTNOTANTONTO_H_

#include "Bot.h"
#include "TablaDePuntuacion.h"
#include "Tablero.h"
#include "Cursor.h"

using namespace std;

class BotNoTanTonto: public Bot
{
	public:
		BotNoTanTonto(); /** Crea un bot */
		~BotNoTanTonto(); /** Destructor */
		void jugar_bot(TablaDePuntuacion& una_tabla_de_puntuacion, Tablero& un_tablero, Cursor& un_cursor); /** Permite al bot marcar una linea en el tablero y obtener un punto en caso de haber marcado un cuadro */
};

#endif

