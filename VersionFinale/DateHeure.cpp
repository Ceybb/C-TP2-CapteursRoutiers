/*************************************************************************
                           DateHeure  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Réalisation de la classe <DateHeure> (fichier DateHeure.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "DateHeure.h"
#include "Mesure.h"


//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void DateHeure::Ajuster ()
{
	int AncienNbMesures=nbMesures;
	nbMesures=1.5*nbMesures;
	Mesure * tabAjuste = new Mesure[nbMesures];
	for (int i=0;i<AncienNbMesures;i++)
	{	tabAjuste[i]=mesures[i];
	}
	delete [] mesures;
	mesures=tabAjuste;
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
DateHeure::DateHeure (int moisM, int jourJ, int heureH)
{
#ifdef MAP
    cout << "Appel au constructeur de <DateHeure>" << endl;
#endif
    mois=moisM;
    jour=jourJ;
    heure=heureH;
    nbMesures=10000;
    mesures = new Mesure[10000];
} //----- Fin de DateHeure


DateHeure::~DateHeure ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <DateHeure>" << endl;
#endif
    delete [] mesures;
} //----- Fin de ~DateHeure
