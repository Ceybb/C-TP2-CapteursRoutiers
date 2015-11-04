/*************************************************************************
                           Table  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Réalisation de la classe <Table> (fichier Table.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Table.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Table::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Table & Table::operator = ( const Table & unTable )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
Table::Table ( const Table & unTable )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Table>" << endl;
#endif
} //----- Fin de Table (constructeur de copie)


Table::Table ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Table>" << endl;
#endif
} //----- Fin de Table


Table::~Table ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Table>" << endl;
#endif
} //----- Fin de ~Table


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void Table::Ajouter (int mois, int jour, int heure, int minute, int jourSemaine, int etat)
{
	table[mois][jour][heure][minute][jourSemaine] = etat;
}

void Table::Afficher () const
{
	for (int a=0 ; a<5 ; a++)
	{
		for (int b=0 ; b<31 ; b++)
		{
			for (int c=0 ; c<24 ; c++)
			{
				for (int d=0 ; d<60 ; d++)
				{
					for (int e=0 ; e<7 ; e++)
					{
							cout << "a" << "b" << "c" << "d" << "e" << table[a][b][c][d][e] <<endl
					}
				}
			}
		}
	}
}

