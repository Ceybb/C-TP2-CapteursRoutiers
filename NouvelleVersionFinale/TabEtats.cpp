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


//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void TabEtats::Afficher () const
{	int etatA=0;
	int etatV=0;
	int etatJ=0;
	int etatR=0;
	int etatN=0;
	for (int jourSem=0;jourSem<7;jourSem++)
	{	for (int mois=0;mois<5;mois++)
		{	for (int numJour=0;numJour<5;numJour++)
			{	for (int heure=0;heure<24;heure++)
				{	for (int minute=0;minute<60;minute++)
					{	switch (tabEtats[jourSem][mois][numJour]
												 [heure][minute])
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
	cout << etatA << " | " << etatV << " | " << etatJ << " | " << etatR
									<< " | " <<  etatN << endl;
} //----- Fin de Méthode

void TabEtats::AjouterMesure ( int mois, int jour, int heure, int minute,
										 int jourSemaine, char trafic )
{	int numJour=0;
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
} //----- Fin de Méthode

void TabEtats::StatsCapteur ( int &etatV, int &etatJ, int &etatR,
										  int &etatN, int &nbMesures )
{	for (int jourSemaine=0;jourSemaine<7;jourSemaine++)
	{	for (int mois=0;mois<5;mois++)
		{	for (int numJour=0;numJour<5;numJour++)
			{	for (int heure=0;heure<24;heure++)
				{	for (int minute=0;minute<60;minute++)
					{	switch (tabEtats[jourSemaine][mois][numJour]
													 [heure][minute])
						{	case 'V':
								etatV++;
								nbMesures++;
								break;
							case 'J':
								etatJ++;
								nbMesures++;
								break;
							case 'R':
								etatR++;
								nbMesures++;
								break;
							case 'N':
								etatN++;
								nbMesures++;
								break;
						}
					}
				}
			}

		}
	}
} //----- Fin de Méthode

void TabEtats::StatsJSem ( int jourSemaine,int &etatV, int &etatJ,
						   int &etatR, int &etatN, int &nbMesures )
{	for (int mois=0;mois<5;mois++)
	{	for (int numJour=0;numJour<5;numJour++)
		{	for (int heure=0;heure<24;heure++)
			{	for (int minute=0;minute<60;minute++)
				{	switch (tabEtats[jourSemaine][mois][numJour]
												 [heure][minute])
					{	case 'V':
							etatV++;
							nbMesures++;
							break;
						case 'J':
							etatJ++;
							nbMesures++;
							break;
						case 'R':
							etatR++;
							nbMesures++;
							break;
						case 'N':
							etatN++;
							nbMesures++;
							break;
					}
				}
			}
		}
	}
} //----- Fin de Méthode

void TabEtats::EmbouteillageJSemHeure ( int jourSemaine,
								int * &tabEtatsHeures, int * &nbMesures )
{	for (int mois=0;mois<5;mois++)
	{	for (int numJour=0;numJour<5;numJour++)
		{	for (int heure=0;heure<24;heure++)
			{	for (int minute=0;minute<60;minute++)
				{	switch (tabEtats[jourSemaine][mois][numJour]
												 [heure][minute])
					{	case 'V':
							nbMesures[heure]++;
							break;
						case 'J':
							nbMesures[heure]++;
							break;
						case 'R':
							tabEtatsHeures[heure]++;
							nbMesures[heure]++;
						break;
						case 'N':
							tabEtatsHeures[heure]++;
							nbMesures[heure]++;
						break;
					}
				}
			}
		}
	}
} //----- Fin de Méthode

int TabEtats::TempsParcoursSegmentAvecMesures ( int jourSemaine,
												int heure, int minute )
{	int tempsParcours=0;
	int nbMesures=0;
	for (int mois=0;mois<5;mois++)
	{	for (int numJour=0;numJour<5;numJour++)
		{	switch (tabEtats[jourSemaine][mois][numJour][heure][minute])
			{	case 'V':
					tempsParcours=tempsParcours+1;
					nbMesures++;
					break;
				case 'J':
					tempsParcours=tempsParcours+2;
					nbMesures++;
					break;
				case 'R':
					tempsParcours=tempsParcours+4;
					nbMesures++;
					break;
				case 'N':
					tempsParcours=tempsParcours+10;
					nbMesures++;
					break;
			}
		}
	}
	if (nbMesures!=0)
	{	return tempsParcours/nbMesures;
	} else
	{	return 0;
	}
} //----- Fin de Méthode

int TabEtats::TempsParcoursSegment ( int jourSemaine, int heure,
										int minute )
{	int tempsParcours=TempsParcoursSegmentAvecMesures(jourSemaine,
												heure,minute);
	if (tempsParcours!=0)
	{	return tempsParcours;
	} else
	{	int jourSemainePrec=jourSemaine;
		int heurePrec=heure;
		int minutePrec=minute;
		int compteurTempsPrec=0;
		int tempsParcoursPrec=0;

		int jourSemaineSuiv=jourSemaine;
		int heureSuiv=heure;
		int minuteSuiv=minute;
		int compteurTempsSuiv=0;
		int tempsParcoursSuiv=0;

		do
		{	if (minutePrec!=0)
			{	minutePrec--;
			} else
			{	minutePrec=59;
				if (heurePrec!=0)
				{	heurePrec--;
				} else
				{	heurePrec=23;
					if (jourSemainePrec!=0)
					{	jourSemainePrec--;
					} else
					{	jourSemainePrec=6;
					}
				}
			}
			compteurTempsPrec++;
			tempsParcoursPrec=TempsParcoursSegmentAvecMesures
								(jourSemainePrec,heurePrec,minutePrec);
		} while (tempsParcoursPrec==0);

		do
		{	if (minuteSuiv!=59)
			{	minuteSuiv++;
			} else
			{	minuteSuiv=0;
				if (heureSuiv!=23)
				{	heureSuiv++;
				} else
				{	heureSuiv=0;
					if (jourSemaineSuiv!=6)
					{	jourSemaineSuiv++;
					} else
					{	jourSemaineSuiv=0;
					}
				}
			}
			compteurTempsSuiv++;
			tempsParcoursSuiv=TempsParcoursSegmentAvecMesures
								(jourSemaineSuiv,heureSuiv,minuteSuiv);
		} while (tempsParcoursSuiv==0);

		int diffTempsParcours;
		if (tempsParcoursPrec<=tempsParcoursSuiv)
		{	diffTempsParcours=tempsParcoursSuiv-tempsParcoursPrec;
		} else
		{ 	diffTempsParcours=tempsParcoursPrec-tempsParcoursSuiv;
		}

		return tempsParcoursPrec+compteurTempsPrec*diffTempsParcours/
								  (compteurTempsPrec+compteurTempsSuiv);
	}
} //----- Fin de Méthode


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
					{	tabEtats[jourSem][mois][numJour]
										 [heure][minute]='A';
					}
				}
			}
		}
    }
} //----- Fin de TabEtats
