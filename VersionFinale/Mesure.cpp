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

//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure (int minuteM, int idI, int etatE)
{
    minute=minuteM;
    id=idI;
    etat=etatE;
#ifdef MAP
cout << "Appel au constructeur de <Mesure>" << endl;
cout << minute << " / " << id << " / " << etat << endl;
#endif
} //----- Fin de Mesure

Mesure::Mesure ()
{
    minute=0;
    id=0;
    etat='A';
#ifdef MAP
cout << "Appel au constructeur de <Mesure>" << endl;
cout << minute << " / " << id << " / " << etat << endl;
#endif
} //----- Fin de Mesure
