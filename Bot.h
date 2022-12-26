/**
Archivo: Bot.h
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

/**
CLASE: Bot
INTENCION: Crear un bot que juegue contra una o varias personas reales.
RELACIONES: Ninguna.
*/

#ifndef _BOT_H_
#define _BOT_H_

#include <iostream>

using namespace std;

class Bot
{
	public:
		Bot(); /** Crea un bot */
		~Bot(); /** Destructor */
		virtual void jugar_bot(); /** Permite al bot marcar una linea en el tablero y obtener un punto en caso de haber marcado un cuadro */
};

#endif

