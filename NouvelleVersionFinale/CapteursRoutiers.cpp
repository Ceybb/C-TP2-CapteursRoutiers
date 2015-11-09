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

void TestsTabEtatAjouter1()
{
	TabEtats unTabEtats;
	unTabEtats.Ajouter(2,24,5,21,3,'V');
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

void TestsIndexTestId1()
{
	Index unIndex;
	cout << unIndex.TestId(322) << endl;
	unIndex.AjouterId(322);
	cout << unIndex.TestId(322) << endl;
	unIndex.AjouterId(144);
	unIndex.AjouterId(555);
	cout << unIndex.TestId(555) << endl;
	unIndex.Afficher();
}

void TestsLecture1()
{
	Index unIndex;
	unIndex.Lecture(122,2,31,12,48,1,'V');
}

void TestsTabEtatConstructeur ()
{
	TestsTabEtatConstructeur1();
}

void TestsTabEtatAjouter()
{
	TestsTabEtatAjouter1();
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

void TestsIndexTestId()
{
	TestsIndexTestId1();
}

void TestsTabEtats ()
{
	TestsTabEtatConstructeur();
	TestsTabEtatAjouter();
}

void TestsIndex ()
{
	TestsIndexConstructeur();
	TestsIndexAjouterId();
	TestsIndexTestId();
}

void TestsLecture ()
{
	TestsLecture1();
}


void Tests ()
{
	TestsTabEtats();
	TestsIndex();
	TestsLecture();
}



int main ()
{
	cout << "Debut des tests" << endl;
	Tests();
	cout << "Fin des tests" << endl;

	string commande;
	int idCapteur;
	int annee;
	int mois;
	int jour;
	int heure;
	int min;
	int jourSemaine;
	char trafic;
	Index unIndex;

	while (cin>>commande != "EXIT")
	 {
	    if (commande == "ADD")
	    {	// Exécuter la méthode lecture
			cout << " Boucle lecture " << endl;
			cin >> idCapteur >> annee >> mois >> jour >> heure >> min >> jourSemaine >> trafic;
			unIndex.Lecture(idCapteur, mois, jour, heure, min, jourSemaine, trafic);
			cout << idCapteur << " / " << annee << " / " << mois << " / " << jour << " / " << heure <<" / " << min << " / " << jourSemaine << " / " << trafic << endl;
		}
	    else if (commande == "STATS_C")
	    {	//Exécuter la méthode StatsCapteur
	    	cout << " Boucle StatsCapteur " << endl;
	    	cin >> idCapteur;
	    	cout << idCapteur << endl;
	    }
	    else if (commande == "JAM_DH")
	    {	// Exécuter la méthode Embouteillage
	    	cout << " Boucle Embouteillage " << endl;
	    	cin >> jourSemaine;
	    	cout << jourSemaine << endl;
	    }
	    else if (commande == "STATS_D7")
		{	//Exécuter la méthode StatsJour
			cout << " Boucle StatsJour " << endl;
			cin >> jourSemaine;
			cout << jourSemaine << endl;

	    }
	    else if (commande == "OPT")
		{	//Exécuter la méthode Optimisation
			cout << " Boucle Optimisation " << endl;
	    	/* cin >> ?; A faire
			cout << ? << endl;*/
		}
		cin >> commande;
	  }
	return 0;
}
