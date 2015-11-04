/*************************************************************************
                           CapteursRoutiers  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Réalisation de la classe <CapteursRoutiers> (fichier CapteursRoutiers.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CapteursRoutiers.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CapteursRoutiers::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/* CapteursRoutiers & CapteursRoutiers::operator = ( const CapteursRoutiers & unCapteursRoutiers )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
/*CapteursRoutiers::CapteursRoutiers ( const CapteursRoutiers & unCapteursRoutiers )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CapteursRoutiers>" << endl;
#endif
} //----- Fin de CapteursRoutiers (constructeur de copie) */


CapteursRoutiers::CapteursRoutiers ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CapteursRoutiers>" << endl;
#endif
    for (int i=0;i<7;i++)
    {	for (int j=0;j<5;j++)
    	{	for (int k=0;k<31;k++)
    		{	for (int l=0;l<24;l++)
    			{	for (int m=0;m<60;m++)
    				{	for (int n=0;n<1500;n++)
    					{	tabValeurs[i][j][k][l][m][n]='A';
    					}
    				}
    			}
    		}
    	}
    }
} //----- Fin de CapteursRoutiers


CapteursRoutiers::~CapteursRoutiers ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CapteursRoutiers>" << endl;
#endif
    for (int i=0;i<7;i++)
        {	for (int j=0;j<5;j++)
        	{	for (int k=0;k<31;k++)
        		{	for (int l=0;l<24;l++)
        			{	for (int m=0;m<60;m++)
        				{	delete[] tabValeurs[i][j][k][l][m];
        				}
        				delete[] tabValeurs[i][j][k][l];
        			}
        			delete[] tabValeurs[i][j][k];
        		}
        		delete[] tabValeurs[i][j];
        	}
        	delete[] tabValeurs[i];
        }
    	delete[] tabValeurs;
} //----- Fin de ~CapteursRoutiers


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
