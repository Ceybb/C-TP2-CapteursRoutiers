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
#include "Mesure.h"
#include "DateHeure.h"



//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
bool DateHeure::Comparer (DateHeure DH)
{
	if (mois==DH.mois && jour==DH.jour && heure==DH.heure)
	{	return true;
	} else
	{	return false;
	}
}

void DateHeure::Ajouter (int minuteM, int idI, int etatE)
{
	if (nbMesuresCourant==nbMesuresMax)
	{	Ajuster();
	}
	mesures[nbMesuresCourant].Modifier(minuteM, idI, etatE);
	nbMesuresCourant++;
}

void DateHeure::Afficher (int option) const
{
	cout << mois << " / " << jour << " / " << heure << " / " << nbMesuresCourant << "/" << nbMesuresMax <<  endl;
	if (option==1)
		{	for (int i=0;i<nbMesuresCourant;i++)
			{	mesures[i].Afficher();
			}
		}
}


//-------------------------------------------- Constructeurs - destructeur
DateHeure::DateHeure (int moisM, int jourJ, int heureH)
{
#ifdef MAP
    cout << "Appel au constructeur de <DateHeure>" << endl;
#endif
    mois=moisM;
    jour=jourJ;
    heure=heureH;
    nbMesuresCourant=0;
    nbMesuresMax=10000;
    mesures = new Mesure[10000];
} //----- Fin de DateHeure


DateHeure::~DateHeure ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <DateHeure>" << endl;
#endif
    delete [] mesures;
} //----- Fin de ~DateHeure


//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
void DateHeure::Ajuster ()
{
	int AncienNbMesuresMax=nbMesuresMax;
	nbMesuresMax=1.5*nbMesuresMax;
	Mesure * tabAjuste = new Mesure[nbMesuresMax];
	for (int i=0;i<AncienNbMesuresMax;i++)
	{	tabAjuste[i]=mesures[i];
	}
	delete [] mesures;
	mesures=tabAjuste;
} //----- Fin de Méthode
