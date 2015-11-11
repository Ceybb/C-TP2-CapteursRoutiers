/*************************************************************************
                           Index  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Réalisation de la classe <Index> (fichier Index.cpp) --
#define MAP
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Index.h"
#include "TabEtats.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
codeRetour Index::AjouterId (int unId)
{
	codeRetour unCodeRetour=nbCapteursMaxNonAjuste;
	if (nbCapteursCourant==nbCapteursMax)
	{	Ajuster();
		unCodeRetour=nbCapteursMaxAjuste;
	}
	id[nbCapteursCourant]=unId;
	index[nbCapteursCourant]=new TabEtats;
	nbCapteursCourant++;
	return unCodeRetour;
} //----- Fin de Méthode

void Index::Afficher () const
{
	cout << nbCapteursCourant << "/" << nbCapteursMax << endl;
	for (int i=0;i<nbCapteursCourant;i++)
	{	cout << id[i] << endl;
		(*(index[i])).Afficher();
	}
}

/*codeRetour Index::AjouterDate (int mois, int jour, int heure, int minute, int jourSemaine)
{
	codeRetour unCodeRetour=nbCapteursMaxNonAjuste;
	if (nbCapteursCourant==nbCapteursMax)
	{	Ajuster();
		unCodeRetour=nbCapteursMaxAjuste;
	}
	index[nbCapteursCourant];
	nbCapteursCourant++;
	return unCodeRetour;
}*/

int Index::ComparerId (int unId)
{
	int idExiste = -1;
	for (int i=0;i<nbCapteursCourant;i++)
	{	if(id[i]==unId)
		{idExiste=i;
		break;
		}
	}
	return idExiste;
} //----- Fin de Méthode

void Index::Lecture(int idCapteur, int mois, int jour, int heure, int minute, int jourSemaine, char trafic)
{
	int testId=ComparerId(idCapteur);
	if(testId==-1)
	{
		AjouterId(idCapteur);
		(*(index[nbCapteursCourant-1])).AjouterMesure(mois-5,jour-1,heure,minute,jourSemaine-1,trafic);
	}
	else
	{
		(*(index[testId])).AjouterMesure(mois-5,jour-1,heure,minute,jourSemaine-1,trafic);
	}
}

void Index::StatsCapteur (int idCapteur)
{
	int etatV=0;
	int etatJ=0;
	int etatR=0;
	int etatN=0;
	int nbMesures=0;
	int compteur=0;
	while (id[compteur]!=idCapteur)
	{	compteur++;
	}
	(*index[compteur]).StatsCapteur(etatV,etatJ,etatR,etatN,nbMesures);
	if (nbMesures==0)
	{	cout << "V " << "UNKNOWN" << "%" << endl;
		cout << "J " << "UNKNOWN" << "%" << endl;
		cout << "R " << "UNKNOWN" << "%" << endl;
		cout << "N " << "UNKNOWN" << "%" << endl;
	} else
	{	cout << "V " << etatV*100/nbMesures << "%" << endl;
		cout << "J " << etatJ*100/nbMesures << "%" << endl;
		cout << "R " << etatR*100/nbMesures << "%" << endl;
		cout << "N " << etatN*100/nbMesures << "%" << endl;
	}
}

void Index::StatsJSem (int jourSemaine)
{
	int etatV=0;
	int etatJ=0;
	int etatR=0;
	int etatN=0;
	int nbMesures=0;
	for (int i=0;i<nbCapteursCourant;i++)
	{
		(*index[i]).StatsJSem(jourSemaine-1,etatV,etatJ,etatR,etatN,nbMesures);
	}
	if (nbMesures==0)
	{	cout << "V " << "UNKNOWN" << "%" << endl;
	cout << "J " << "UNKNOWN" << "%" << endl;
	cout << "R " << "UNKNOWN" << "%" << endl;
	cout << "N " << "UNKNOWN" << "%" << endl;
	} else
	{	cout << "V " << etatV*100/nbMesures << "%" << endl;
	cout << "J " << etatJ*100/nbMesures << "%" << endl;
	cout << "R " << etatR*100/nbMesures << "%" << endl;
	cout << "N " << etatN*100/nbMesures << "%" << endl;
	}
}

void Index::EmbouteillageJSemHeure (int jourSemaine)
{
	int * tabEtatsHeures = new int [24];
	int * nbMesuresHeures = new int [24];
	for (int i=0;i<24;i++)
	{	tabEtatsHeures[i]=0;
		nbMesuresHeures[i]=0;
	}
	for (int i=0;i<nbCapteursCourant;i++)
	{
		(*index[i]).EmbouteillageJSemHeure(jourSemaine-1,tabEtatsHeures,nbMesuresHeures);
	}
	for (int i=0;i<24;i++)
	{	if (nbMesuresHeures[i]==0)
		{	cout << jourSemaine << " " << i << " " << "UNKNOWN" << endl;
		} else
		{	cout << jourSemaine << " " << i << " " << tabEtatsHeures[i]*100/nbMesuresHeures[i] << "%" << endl;
		}
	}
	delete tabEtatsHeures;
	delete nbMesuresHeures;
}

//-------------------------------------------- Constructeurs - destructeur
Index::Index ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Index>" << endl;
#endif
    nbCapteursCourant=0;
    nbCapteursMax=10;
    id=new int[nbCapteursMax];
    index=new TabEtats*[nbCapteursMax];
} //----- Fin de Index


Index::~Index ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Index>" << endl;
#endif
    delete [] id;
    for (int i=0;i<nbCapteursCourant;i++)
    {	delete index[i];
    }
    delete [] index;
} //----- Fin de ~Index


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void Index::Ajuster ()
{
	nbCapteursMax=1.5*nbCapteursMax;
	int * nouvTabId = new int [nbCapteursMax];
	TabEtats ** nouvIndex = new TabEtats*[nbCapteursMax];
	for (int i=0;i<nbCapteursCourant;i++)
	{	nouvTabId[i]=id[i];
		nouvIndex[i]=index[i];
	}
	delete [] id;
	delete [] index;
	id=nouvTabId;
	index=nouvIndex;
}

