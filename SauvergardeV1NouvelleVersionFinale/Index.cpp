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
	nbCapteursCourant++;
	return unCodeRetour;
} //----- Fin de Méthode

void Index::Afficher () const
{
	cout << nbCapteursCourant << "/" << nbCapteursMax << endl;
	for (int i=0;i<nbCapteursCourant;i++)
	{	cout << id[i] << endl;
	}
	cout << "Essai1" << endl;
	(*(index[5])).Afficher();
	cout << "Essai2" << endl;
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
		(*(index[nbCapteursCourant-1])).AjouterMesure(mois,jour,heure,minute,jourSemaine,trafic);
	}
	else
	{
		(*(index[testId])).AjouterMesure(mois,jour,heure,minute,jourSemaine,trafic);
	}
}

void Index::StatsJSem (int jourSemaine)
{
	int etatV=0;
	int etatJ=0;
	int etatR=0;
	int etatN=0;
	int nbMesures=0;
	for (int idCapteur=0;idCapteur<nbCapteursCourant;idCapteur++)
	{
		(*index[idCapteur]).StatsJSem(jourSemaine,etatV,etatJ,etatR,etatN,nbMesures);
	}
	cout << "V " << etatV/nbMesures*100 << "%" << endl;
	cout << "J " << etatJ/nbMesures*100 << "%" << endl;
	cout << "R " << etatR/nbMesures*100 << "%" << endl;
	cout << "N " << etatN/nbMesures*100 << "%" << endl;
}

void Index::EmbouteillageJSemHeure (int jourSemaine)
{
	int * tabEtatsHeures = new int [24];
	for (int i=0;i<24;i++)
	{	tabEtatsHeures[i]=0;
	}
	int nbMesures=0;
	for (int idCapteur=0;idCapteur<nbCapteursCourant;idCapteur++)
	{
		(*index[idCapteur]).EmbouteillageJSemHeure(jourSemaine,tabEtatsHeures,nbMesures);
	}
	for (int i=0;i<24;i++)
	{
		cout << jourSemaine+1 << " " << i << " " << tabEtatsHeures[i]/nbMesures*100 << "%" << endl;
	}
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

    /*TabEtats * tab = new TabEtats[nbCapteursMax];
    for (int i=0;i<nbCapteursMax;i++)
    {	index[i]=&tab[i];
    }*/
} //----- Fin de Index


Index::~Index ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Index>" << endl;
#endif
    delete [] id;
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
	TabEtats * tab = new TabEtats[nbCapteursMax-nbCapteursCourant];
	for (int i=nbCapteursCourant;i<nbCapteursMax;i++)
	{	index[i]=&tab[i-nbCapteursCourant];
	}
	delete [] id;
	delete [] index;
	id=nouvTabId;
	index=nouvIndex;
}

