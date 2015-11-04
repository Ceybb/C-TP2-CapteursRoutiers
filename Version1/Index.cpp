/*************************************************************************
                           Index  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Réalisation de la classe <Index> (fichier Index.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Index.h"
#include "Table.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Index::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Index & Index::operator = ( const Index & unIndex )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
/*Index::Index ( const Index & unIndex )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Index>" << endl;
#endif
} //----- Fin de Index (constructeur de copie) */


Index::Index ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Index>" << endl;
#endif
    nbCapteurs = 0;
    id = new int [1500];
    table = new Table * [1500];
} //----- Fin de Index


Index::~Index ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Index>" << endl;
#endif
    delete [] id;
    delete [] *table;
} //----- Fin de ~Index


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void Index::Ajouter (int nouvelId, Table *nouvelleTable){
	if (nbCapteurs <= 1500)
	{
		id[nbCapteurs] = nouvelId;
		table[nbCapteurs] = nouvelleTable;
		nbCapteurs++;
	}
}
