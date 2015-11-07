/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Mesure.h"

#define MAP

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Mesure::Modifier (int minuteM, int idI, int etatE)
{
	minute=minuteM;
	id=idI;
	etat=etatE;
}

void Mesure::Afficher () const
{
	cout << minute << " / " << id << " / " << etat << endl;
}
