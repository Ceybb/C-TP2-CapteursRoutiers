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
void TestsTabEtatsConstructeur1 ()
{
	TabEtats unTabEtats;
	unTabEtats.Afficher();

}

void TestsTabEtatsAjouterMesure1 ()
{
	TabEtats unTabEtats;
	unTabEtats.AjouterMesure(2,24,5,21,3,'V');
	unTabEtats.Afficher();
}

void TestsTabEtatsStatsJSem1 ()
{
	TabEtats tab;
	int etatV=0;
	int etatJ=0;
	int etatR=0;
	int etatN=0;
	int nbMesures=0;
	tab.AjouterMesure(3,12,17,45,3,'V');
	tab.AjouterMesure(1,17,11,21,3,'J');
	tab.AjouterMesure(2,5,9,33,3,'J');
	tab.AjouterMesure(4,21,5,37,3,'N');
	tab.AjouterMesure(0,28,14,51,3,'R');
	tab.StatsJSem(3,etatV,etatJ,etatR,etatN,nbMesures);
	cout << etatV << endl;
	cout << etatJ << endl;
	cout << etatR << endl;
	cout << etatN << endl;
	cout << nbMesures << endl;
}

void TestsTabEtatEmbouteillageJSemHeure1 ()
{
	TabEtats tab;
	int * tabEtatsHeures = new int [24];
	int * nbMesures = new int [24];
	for (int i=0;i<24;i++)
	{	tabEtatsHeures[i]=0;
		nbMesures[i]=0;
	}
	tab.AjouterMesure(3,12,17,45,3,'V');
	tab.AjouterMesure(1,17,11,21,3,'J');
	tab.AjouterMesure(2,5,9,33,3,'J');
	tab.AjouterMesure(4,21,5,37,3,'N');
	tab.AjouterMesure(0,28,14,51,3,'R');
	tab.EmbouteillageJSemHeure(3,tabEtatsHeures,nbMesures);
	for (int i=0;i<24;i++)
	{	cout << "heure : " << i << " : " << tabEtatsHeures[i] << " / " << nbMesures[i] << endl;
	}
}

void TestsIndexConstructeur1 ()
{
	Index unIndex;
	unIndex.Afficher();
}

void TestsIndexAjouterId1 ()
{
	Index unIndex;
	TabEtats unTabEtats;
	codeRetour unCodeRetour=unIndex.AjouterId(0);
	cout << unCodeRetour << endl;
	unIndex.Afficher();
}

void TestsIndexAjouterId2 ()
{
	Index unIndex;
	TabEtats unTabEtats;
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

void TestsIndexComparerId1 ()
{
	Index unIndex;
	cout << unIndex.ComparerId(0) << endl;
}

void TestsIndexComparerId2 ()
{
	Index unIndex;
	cout << unIndex.ComparerId(1345) << endl;
}

void TestsIndexComparerId3 ()
{
	Index unIndex;
	unIndex.AjouterId(154);
	unIndex.AjouterId(785);
	unIndex.AjouterId(964);
	unIndex.AjouterId(1243);
	unIndex.AjouterId(498);
	unIndex.AjouterId(853);
	unIndex.AjouterId(1347);
	unIndex.AjouterId(438);
	cout << unIndex.ComparerId(0) << endl;
}

void TestsIndexComparerId4 ()
{
	Index unIndex;
	unIndex.AjouterId(154);
	unIndex.AjouterId(785);
	unIndex.AjouterId(964);
	unIndex.AjouterId(1243);
	unIndex.AjouterId(498);
	unIndex.AjouterId(853);
	unIndex.AjouterId(1347);
	unIndex.AjouterId(438);
	cout << unIndex.ComparerId(514) << endl;
}

void TestsIndexComparerId5 ()
{
	Index unIndex;
	unIndex.AjouterId(154);
	unIndex.AjouterId(785);
	unIndex.AjouterId(964);
	unIndex.AjouterId(1243);
	unIndex.AjouterId(498);
	unIndex.AjouterId(853);
	unIndex.AjouterId(1347);
	unIndex.AjouterId(438);
	cout << unIndex.ComparerId(498) << endl;
}

void TestsIndexLecture1 ()
{
	Index unIndex;
	unIndex.Lecture(458,8,11,4,17,5,'V');
	unIndex.Lecture(1124,9,24,21,44,1,'J');
	unIndex.Lecture(1124,6,5,17,22,3,'J');
	unIndex.Lecture(1124,9,26,14,55,3,'R');
	unIndex.Lecture(748,7,19,23,12,2,'N');
	unIndex.Lecture(-134,7,5,13,32,4,'R');
	unIndex.Afficher();
}

void TestsIndexStatsJSem1 ()
{
	Index unIndex;
	unIndex.Lecture(458,8,11,4,17,5,'V');
	unIndex.Lecture(1124,9,24,21,44,1,'J');
	unIndex.Lecture(1124,6,5,17,22,3,'J');
	unIndex.Lecture(1124,9,26,14,55,3,'R');
	unIndex.Lecture(748,7,19,23,12,2,'N');
	unIndex.Lecture(-134,7,5,13,32,4,'R');
	unIndex.StatsJSem(3);
}

void TestsIndexEmbouteillageJSemHeure1 ()
{
	Index unIndex;
	unIndex.Lecture(458,8,11,4,17,5,'V');
	unIndex.Lecture(1124,9,24,21,44,1,'J');
	unIndex.Lecture(1124,6,5,17,22,3,'J');
	unIndex.Lecture(1124,9,26,14,55,3,'R');
	unIndex.Lecture(748,7,19,23,12,2,'N');
	unIndex.Lecture(-134,7,5,13,32,4,'R');
	unIndex.EmbouteillageJSemHeure(3);
}



void TestsTabEtatsConstructeur ()
{
	TestsTabEtatsConstructeur1();
}

void TestsTabEtatsAjouterMesure ()
{
	TestsTabEtatsAjouterMesure1();
}

void TestsTabEtatsStatsJSem ()
{
	TestsTabEtatsStatsJSem1();
}

void TestsTabEtatEmbouteillageJSemHeure ()
{
	TestsTabEtatEmbouteillageJSemHeure1();
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

void TestsIndexComparerId ()
{
	TestsIndexComparerId1();
	TestsIndexComparerId2();
	TestsIndexComparerId3();
	TestsIndexComparerId4();
	TestsIndexComparerId5();
}

void TestsIndexLecture ()
{
	TestsIndexLecture1();
}

void TestsIndexStatsJSem ()
{
	TestsIndexStatsJSem1();
}

void TestsIndexEmbouteillageJSemHeure ()
{
	TestsIndexEmbouteillageJSemHeure1();
}



void TestsTabEtats ()
{
	TestsTabEtatsConstructeur();
	TestsTabEtatsAjouterMesure();
	TestsTabEtatsStatsJSem();
	TestsTabEtatEmbouteillageJSemHeure();
}

void TestsIndex ()
{
	//TestsIndexConstructeur();
	//TestsIndexAjouterId();
	//TestsIndexComparerId();
	//TestsIndexLecture();
	TestsIndexStatsJSem();
	TestsIndexEmbouteillageJSemHeure();
}



void Tests ()
{
	//TestsTabEtats();
	TestsIndex();
}



int main ()
{
	cout << "Debut des tests" << endl;
	Tests();
	cout << "Fin des tests" << endl;

	/*string commande;
	int idCapteur;
	int annee;
	int mois;
	int jour;
	int heure;
	int min;
	int jourSemaine;
	char trafic;

	cin >> commande;
	while (commande != "EXIT")
	{	if (commande == "ADD")
		{	cout << "Effectuer boucle ADD" << endl;
			cin >> idCapteur >> annee >> mois >> jour >> heure >> min >> jourSemaine >> trafic;
			cout << idCapteur << " / " << annee << " / " << mois << " / " << jour << " / " << heure <<" / " << min << " / " << jourSemaine << " / " << trafic << endl;
		} else if (commande == "STATS_C")
		{	cout << "Effectuer boucle STATS_C" << endl;
			cin >> idCapteur;
			cout << idCapteur << endl;
		} else if (commande=="JAM_DH")
		{	cout << "Effectuer boucle Jam_DH" << endl;
			cin >> jourSemaine;
			cout << jourSemaine << endl;
		} else if (commande=="STATS_D7")
		{	cout << "Effectuer boucle STATS_D7" << endl;
			cin >> jourSemaine;
			cout << jourSemaine << endl;
		}
		cin >> commande;
	}*/
	return 0;
}
