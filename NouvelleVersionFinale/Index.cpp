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

int Index::TestId (int unId)
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
	int testId=TestId(idCapteur);
	TabEtats * pointeur;
	pointeur=index[nbCapteursCourant-1];
	TabEtats tab;
	tab=*(index[nbCapteursCourant-1]);
	if(testId==-1)
	{
		AjouterId(idCapteur);
	//	*(index[nbCapteursCourant-1]).Ajouter(int mois, int jour, int heure, int min, int jourSem, char trafic);
	}
	else
	{
	//	*(index[testId]).Ajouter(int mois, int jour, int heure, int min, int jourSem, char trafic);
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
	delete [] id;
	delete [] index;
	id=nouvTabId;
	index=nouvIndex;
}

