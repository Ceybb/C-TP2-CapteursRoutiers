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
#include "TabEtats.h"
#include "Index.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TestsTabEtatConstructeur1 ()
{
	TabEtats unTabEtats;
}

void TestsIndexConstructeur1 ()
{
	Index unIndex;
	unIndex.Afficher();
}

void TestsIndexAjouterId1 ()
{
	Index unIndex;
	codeRetour unCodeRetour=unIndex.AjouterId(0);
	cout << unCodeRetour << endl;
	unIndex.Afficher();
}

void TestsIndexAjouterId2 ()
{
	Index unIndex;
	codeRetour unCodeRetour=unIndex.AjouterId(1243);
	cout << unCodeRetour << endl;
	unIndex.Afficher();
}

void TestsIndexAjouterId3 ()
{
	Index unIndex;
	cout << unIndex.AjouterId(154) << endl;
	cout << unIndex.AjouterId(785) << endl;
	cout << unIndex.AjouterId(964) << endl;
	cout << unIndex.AjouterId(1243) << endl;
	cout << unIndex.AjouterId(498) << endl;
	cout << unIndex.AjouterId(853) << endl;
	cout << unIndex.AjouterId(1347) << endl;
	cout << unIndex.AjouterId(438) << endl;
	cout << unIndex.AjouterId(963) << endl;
	cout << unIndex.AjouterId(134) << endl;
	cout << unIndex.AjouterId(1285) << endl;
	cout << unIndex.AjouterId(745) << endl;
	unIndex.Afficher();
}



void TestsTabEtatConstructeur ()
{
	TestsTabEtatConstructeur1();
}

void TestsIndexConstructeur ()
{
	TestsIndexConstructeur1();
}

void TestsIndexAjouterId ()
{
	TestsIndexAjouterId1();
	TestsIndexAjouterId2();
	TestsIndexAjouterId3();
}



void TestsTabEtats ()
{
	TestsTabEtatConstructeur();
}

void TestsIndex ()
{
	TestsIndexConstructeur();
	TestsIndexAjouterId();
}



void Tests ()
{
	TestsTabEtats();
	TestsIndex();
}



int main ()
{
	cout << "Debut des tests" << endl;
	Tests();
	cout << "Fin des tests" << endl;
	return 0;
}
