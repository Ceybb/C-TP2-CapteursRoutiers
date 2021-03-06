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
void TabEtats::Afficher () const
{
	int etatA=0;
	int etatV=0;
	int etatJ=0;
	int etatR=0;
	int etatN=0;
	for (int jourSem=0;jourSem<7;jourSem++)
	{	for (int mois=0;mois<5;mois++)
		{	for (int numJour=0;numJour<5;numJour++)
			{	for (int heure=0;heure<24;heure++)
				{	for (int minute=0;minute<60;minute++)
					{	switch (tabEtats[jourSem][mois][numJour][heure][minute])
						{
							case 'A':
								etatA++;
								break;
							case 'V':
								etatV++;
								break;
							case 'J':
								etatJ++;
								break;
							case 'R':
								etatR++;
								break;
							case 'N':
								etatN++;
								break;
						}
					}
				}
			}
		}
	}
	cout << etatA << " | " << etatV << " | " << etatJ << " | " << etatR << " | " <<  etatN << endl;
}

void TabEtats::AjouterMesure (int mois, int jour, int heure, int minute, int jourSemaine, char trafic)
{
	int numJour=0;
	if(8<=jour && jour<=14)
	{numJour=1;
	}
	else if(15<=jour && jour<=21)
		{numJour=2;
		}
	else if(22<=jour && jour<=28)
		{numJour=3;
		}
	else if(29<=jour && jour<=31)
		{numJour=4;
		}
	tabEtats[jourSemaine][mois][numJour][heure][minute]=trafic;
} //} //----- Fin de Méthode


void TabEtats::StatsJSem (int jourSemaine,int &etatV, int &etatJ, int &etatR, int &etatN, int &nbMesures)
{
	for (int mois=0;mois<5;mois++)
	{	for (int numJour=0;numJour<5;numJour++)
		{	for (int heure=0;heure<24;heure++)
			{	for (int minute=0;minute<60;minute++)
				{	switch (tabEtats[jourSemaine][mois][numJour][heure][minute])
					{	case 'V':
							etatV++;
							break;
						case 'J':
							etatJ++;
							break;
						case 'R':
							etatR++;
							break;
						case 'N':
							etatN++;
							break;
					}
					nbMesures++;
				}
			}
		}
	}
}

void TabEtats::EmbouteillageJSemHeure (int jourSemaine,int * &tabEtatsHeures, int &nbMesures)
{	for (int mois=0;mois<5;mois++)
	{	for (int numJour=0;numJour<5;numJour++)
		{	for (int heure=0;heure<24;heure++)
			{	for (int minute=0;minute<60;minute++)
				{	switch (tabEtats[jourSemaine][mois][numJour][heure][minute])
					{	case 'R':
							tabEtatsHeures[heure]++;
						break;
						case 'N':
							tabEtatsHeures[heure]++;
						break;
					}
				nbMesures++;
				}
			}
		}
	}
}



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
