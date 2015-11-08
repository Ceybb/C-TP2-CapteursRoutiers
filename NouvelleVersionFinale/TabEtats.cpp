/*************************************************************************
                           TabEtats  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Réalisation de la classe <TabEtats> (fichier TabEtats.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TabEtats.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type TabEtats::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode





//-------------------------------------------- Constructeurs - destructeur
TabEtats::TabEtats ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <TabEtats>" << endl;
#endif
for (int jourSem=0;jourSem<7;jourSem++)
{	for (int mois=0;mois<5;mois++)
	{	for (int numJour=0;numJour<5;numJour++)
		{	for (int heure=0;heure<24;heure++)
			{	for (int minute=0;minute<60;minute++)
				{	tabEtats[jourSem][mois][numJour][heure][minute]='A';
				}
			}
		}
	}
}
} //----- Fin de TabEtats




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
