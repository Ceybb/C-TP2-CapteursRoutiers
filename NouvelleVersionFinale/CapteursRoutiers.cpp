/*************************************************************************
                           CapteursRoutiers  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

// Réalisation de la classe <CapteursRoutiers> (fichier CapteursRoutiers.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TabEtats.h"
#include "Index.h"


//----------------------------------------------------------------- PUBLIC
void TestsTabEtatsConstructeur1 ()
{	TabEtats unTabEtats;
	unTabEtats.Afficher();
}

void TestsTabEtatsAjouterMesure1 ()
{	TabEtats unTabEtats;
	unTabEtats.AjouterMesure(2,24,5,21,3,'V');
	unTabEtats.Afficher();
}

void TestsTabEtatsStatsCapteur1 ()
{	TabEtats tab;
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
	tab.StatsCapteur(etatV,etatJ,etatR,etatN,nbMesures);
	cout << etatV << endl;
	cout << etatJ << endl;
	cout << etatR << endl;
	cout << etatN << endl;
	cout << nbMesures << endl;
}

void TestsTabEtatsStatsJSem1 ()
{	TabEtats tab;
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
{	TabEtats tab;
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
	{	cout << "heure : " << i << " : " << tabEtatsHeures[i] << " / "
										 << nbMesures[i] << endl;
	}
	delete tabEtatsHeures;
	delete nbMesures;
}

void TestsTabEtatsTempsParcoursSegmentAvecMesures1 ()
{	TabEtats tab;
	tab.AjouterMesure(3,12,17,45,3,'R');
	int tempsParcours=tab.TempsParcoursSegment(3,17,45);
	cout << tempsParcours << endl;
}

void TestsTabEtatsTempsParcoursSegmentAvecMesures2 ()
{	TabEtats tab;
	tab.AjouterMesure(3,12,17,45,3,'R');
	tab.AjouterMesure(1,17,17,45,3,'J');
	tab.AjouterMesure(4,24,17,45,3,'R');
	tab.AjouterMesure(2,9,17,45,3,'R');
	tab.AjouterMesure(1,4,17,45,3,'N');
	tab.AjouterMesure(3,18,17,45,3,'N');
	int tempsParcours=tab.TempsParcoursSegment(3,17,45);
	cout << tempsParcours << endl;
}

void TestsTabEtatsTempsParcoursSegment1 ()
{	TabEtats tab;
	tab.AjouterMesure(3,12,17,35,3,'R');
	tab.AjouterMesure(1,17,17,35,3,'J');
	tab.AjouterMesure(4,24,17,50,3,'R');
	tab.AjouterMesure(2,9,17,35,3,'R');
	tab.AjouterMesure(1,4,17,50,3,'N');
	tab.AjouterMesure(3,18,17,50,3,'N');
	int tempsParcours=tab.TempsParcoursSegment(3,17,45);
	cout << tempsParcours << endl;
}

void TestsTabEtatsTempsParcoursSegment2 ()
{	TabEtats tab;
	tab.AjouterMesure(3,12,23,50,6,'R');
	tab.AjouterMesure(1,17,23,50,6,'J');
	tab.AjouterMesure(4,24,0,5,0,'R');
	tab.AjouterMesure(2,9,23,50,6,'R');
	tab.AjouterMesure(1,4,0,5,0,'N');
	tab.AjouterMesure(3,18,0,5,0,'N');
	int tempsParcours=tab.TempsParcoursSegment(0,0,0);
	cout << tempsParcours << endl;
}

void TestsTabEtatsTempsParcoursSegment3 ()
{	TabEtats tab;
	tab.AjouterMesure(3,12,23,50,6,'R');
	tab.AjouterMesure(1,17,23,50,6,'J');
	tab.AjouterMesure(4,24,0,5,0,'R');
	tab.AjouterMesure(2,9,23,50,6,'R');
	tab.AjouterMesure(1,4,0,5,0,'N');
	tab.AjouterMesure(3,18,0,5,0,'N');
	int tempsParcours=tab.TempsParcoursSegment(6,23,59);
	cout << tempsParcours << endl;
}

void TestsIndexConstructeur1 ()
{	Index unIndex;
	unIndex.Afficher();
}

void TestsIndexAjouterId1 ()
{	Index unIndex;
	codeRetour unCodeRetour=unIndex.AjouterId(0);
	cout << unCodeRetour << endl;
	unIndex.Afficher();
}

void TestsIndexAjouterId2 ()
{	Index unIndex;
	codeRetour unCodeRetour=unIndex.AjouterId(1243);
	cout << unCodeRetour << endl;
	unIndex.Afficher();
}

void TestsIndexAjouterId3 ()
{	Index unIndex;
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
{	Index unIndex;
	cout << unIndex.ComparerId(0) << endl;
}

void TestsIndexComparerId2 ()
{	Index unIndex;
	cout << unIndex.ComparerId(1345) << endl;
}

void TestsIndexComparerId3 ()
{	Index unIndex;
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
{	Index unIndex;
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
{	Index unIndex;
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
{	Index unIndex;
	unIndex.Lecture(458,3,10,4,17,4,'V');
	unIndex.Lecture(1124,4,23,21,44,0,'J');
	unIndex.Lecture(1124,1,4,17,22,2,'J');
	unIndex.Lecture(1124,4,25,14,55,2,'R');
	unIndex.Lecture(748,2,18,23,12,1,'N');
	unIndex.Lecture(-134,2,4,13,32,3,'R');
	unIndex.Afficher();
}

void TestsIndexStatsCapteur1 ()
{	Index unIndex;
	unIndex.Lecture(458,8,11,4,17,5,'V');
	unIndex.Lecture(1124,9,24,21,44,1,'J');
	unIndex.Lecture(1124,6,5,17,22,3,'J');
	unIndex.Lecture(1124,9,26,14,55,3,'R');
	unIndex.Lecture(748,7,19,23,12,2,'N');
	unIndex.Lecture(-134,7,5,13,32,4,'R');
	unIndex.StatsCapteur(1124);
}

void TestsIndexStatsJSem1 ()
{	Index unIndex;
	unIndex.Lecture(458,8,11,4,17,5,'V');
	unIndex.Lecture(1124,9,24,21,44,1,'J');
	unIndex.Lecture(1124,6,5,17,22,3,'J');
	unIndex.Lecture(1124,9,26,14,55,3,'R');
	unIndex.Lecture(748,7,19,23,12,2,'N');
	unIndex.Lecture(-134,7,5,13,32,4,'R');
	unIndex.StatsJSem(3);
}

void TestsIndexEmbouteillageJSemHeure1 ()
{	Index unIndex;
	unIndex.Lecture(458,8,11,4,17,5,'V');
	unIndex.Lecture(1124,9,24,21,44,1,'J');
	unIndex.Lecture(1124,6,5,17,22,3,'J');
	unIndex.Lecture(1124,9,26,14,55,3,'R');
	unIndex.Lecture(748,7,19,23,12,2,'N');
	unIndex.Lecture(-134,7,5,13,32,4,'R');
	unIndex.EmbouteillageJSemHeure(3);
}

void TestsIndexTempsParcoursSegment1 ()
{	Index unIndex;
	unIndex.Lecture(1247,3,12,17,35,3,'R');
	unIndex.Lecture(1247,1,17,17,35,3,'J');
	unIndex.Lecture(1247,4,24,17,50,3,'R');
	unIndex.Lecture(1247,2,9,17,35,3,'R');
	unIndex.Lecture(1247,1,4,17,50,3,'N');
	unIndex.Lecture(1247,3,18,17,50,3,'N');
	int tempsParcours=unIndex.TempsParcoursSegment(1247,3,17,45);
	cout << tempsParcours << endl;
}

void TestsIndexTempsParcoursSegment2 ()
{	Index unIndex;
	unIndex.Lecture(1247,3,12,23,50,6,'R');
	unIndex.Lecture(1247,1,17,23,50,6,'J');
	unIndex.Lecture(1247,4,24,0,5,0,'R');
	unIndex.Lecture(1247,2,9,23,50,6,'R');
	unIndex.Lecture(1247,1,4,0,5,0,'N');
	unIndex.Lecture(1247,3,18,0,5,0,'N');
	int tempsParcours=unIndex.TempsParcoursSegment(1247,0,0,0);
	cout << tempsParcours << endl;
}

void TestsIndexTempsParcoursSegment3 ()
{	Index unIndex;
	unIndex.Lecture(1247,3,12,23,50,6,'R');
	unIndex.Lecture(1247,1,17,23,50,6,'J');
	unIndex.Lecture(1247,4,24,0,5,0,'R');
	unIndex.Lecture(1247,2,9,23,50,6,'R');
	unIndex.Lecture(1247,1,4,0,5,0,'N');
	unIndex.Lecture(1247,3,18,0,5,0,'N');
	int tempsParcours=unIndex.TempsParcoursSegment(1247,6,23,59);
	cout << tempsParcours << endl;
}

void TestsIndexTempsParcoursEnsembleSegments1 ()
{	Index unIndex;
	int * tabId = new int[3];
	tabId[0]=1001;
	tabId[1]=1002;
	tabId[2]=1003;
	int heureFin;
	unIndex.Lecture(1001,1,10,11,0,4,'R');
	unIndex.Lecture(1002,1,10,11,4,4,'N');
	unIndex.Lecture(1003,1,10,11,14,4,'J');
	int tempsParcours=unIndex.TempsParcoursEnsembleSegments
								(3,tabId,4,11,0,heureFin);
	cout << tempsParcours << " | " << heureFin << endl;
	delete tabId;
}

void TestsIndexMomentDepartOpti1 ()
{	Index unIndex;
	int * tabId = new int[3];
	tabId[0]=1001;
	tabId[1]=1002;
	tabId[2]=1003;
	int heureFin;
	unIndex.Lecture(1001,1,10,11,0,3,'V');
	unIndex.Lecture(1001,1,10,11,10,3,'J');
	unIndex.Lecture(1001,1,10,11,20,3,'V');
	unIndex.Lecture(1001,1,10,11,30,3,'R');
	unIndex.Lecture(1001,1,10,11,40,3,'J');
	unIndex.Lecture(1001,1,10,11,50,3,'V');
	unIndex.Lecture(1001,1,10,12,0,3,'j');
	unIndex.Lecture(1001,1,10,12,10,3,'R');
	unIndex.Lecture(1001,1,10,12,20,3,'N');
	unIndex.Lecture(1001,1,10,12,30,3,'J');
	unIndex.Lecture(1001,1,10,12,40,3,'J');
	unIndex.Lecture(1001,1,10,12,50,3,'V');
	unIndex.Lecture(1002,1,10,11,0,3,'R');
	unIndex.Lecture(1002,1,10,11,10,3,'J');
	unIndex.Lecture(1002,1,10,11,20,3,'J');
	unIndex.Lecture(1002,1,10,11,30,3,'J');
	unIndex.Lecture(1002,1,10,11,40,3,'R');
	unIndex.Lecture(1002,1,10,11,50,3,'V');
	unIndex.Lecture(1002,1,10,12,0,3,'N');
	unIndex.Lecture(1002,1,10,12,10,3,'J');
	unIndex.Lecture(1002,1,10,12,20,3,'V');
	unIndex.Lecture(1002,1,10,12,30,3,'R');
	unIndex.Lecture(1002,1,10,12,40,3,'J');
	unIndex.Lecture(1002,1,10,12,50,3,'N');
	unIndex.Lecture(1003,1,10,11,0,3,'V');
	unIndex.Lecture(1003,1,10,11,10,3,'V');
	unIndex.Lecture(1003,1,10,11,20,3,'R');
	unIndex.Lecture(1003,1,10,11,30,3,'J');
	unIndex.Lecture(1003,1,10,11,40,3,'V');
	unIndex.Lecture(1003,1,10,11,50,3,'N');
	unIndex.Lecture(1003,1,10,12,0,3,'J');
	unIndex.Lecture(1003,1,10,12,10,3,'R');
	unIndex.Lecture(1003,1,10,12,20,3,'J');
	unIndex.Lecture(1003,1,10,12,30,3,'J');
	unIndex.Lecture(1003,1,10,12,40,3,'V');
	unIndex.Lecture(1003,1,10,12,50,3,'V');
	for (int min=0;min<59;min++)
	{	cout << unIndex.TempsParcoursEnsembleSegments
				(3,tabId,3,11,min,heureFin) << endl;
	}
	for (int min=0;min<49;min++)
	{	cout << unIndex.TempsParcoursEnsembleSegments
				(3,tabId,3,12,min,heureFin) << endl;
	}
	unIndex.MomentDepartOpti(3,tabId,3,11,13);
	delete tabId;
}



void TestsTabEtatsConstructeur ()
{	TestsTabEtatsConstructeur1();
}

void TestsTabEtatsAjouterMesure ()
{	TestsTabEtatsAjouterMesure1();
}

void TestsTabEtatsStatsCapteur ()
{	TestsTabEtatsStatsCapteur1();
}

void TestsTabEtatsStatsJSem ()
{	TestsTabEtatsStatsJSem1();
}

void TestsTabEtatEmbouteillageJSemHeure ()
{	TestsTabEtatEmbouteillageJSemHeure1();
}

void TestsTabEtatsTempsParcoursSegmentAvecMesures ()
{	TestsTabEtatsTempsParcoursSegmentAvecMesures1();
	TestsTabEtatsTempsParcoursSegmentAvecMesures2();
}

void TestsTabEtatsTempsParcoursSegment ()
{	TestsTabEtatsTempsParcoursSegment1();
	TestsTabEtatsTempsParcoursSegment2();
	TestsTabEtatsTempsParcoursSegment3();
}

void TestsIndexConstructeur ()
{	TestsIndexConstructeur1();
}

void TestsIndexAjouterId ()
{	TestsIndexAjouterId1();
	TestsIndexAjouterId2();
	TestsIndexAjouterId3();
}

void TestsIndexComparerId ()
{	TestsIndexComparerId1();
	TestsIndexComparerId2();
	TestsIndexComparerId3();
	TestsIndexComparerId4();
	TestsIndexComparerId5();
}

void TestsIndexLecture ()
{	TestsIndexLecture1();
}

void TestsIndexStatsCapteur ()
{	TestsIndexStatsCapteur1();
}

void TestsIndexStatsJSem ()
{	TestsIndexStatsJSem1();
}

void TestsIndexEmbouteillageJSemHeure ()
{	TestsIndexEmbouteillageJSemHeure1();
}

void TestsIndexTempsParcoursSegment ()
{	TestsIndexTempsParcoursSegment1();
	TestsIndexTempsParcoursSegment2();
	TestsIndexTempsParcoursSegment3();
}

void TestsIndexTempsParcoursEnsembleSegments ()
{	TestsIndexTempsParcoursEnsembleSegments1();
}

void TestsIndexMomentDepartOpti ()
{	TestsIndexMomentDepartOpti1();
}



void TestsTabEtats ()
{	TestsTabEtatsConstructeur();
	TestsTabEtatsAjouterMesure();
	TestsTabEtatsStatsCapteur();
	TestsTabEtatsStatsJSem();
	TestsTabEtatEmbouteillageJSemHeure();
	TestsTabEtatsTempsParcoursSegmentAvecMesures();
	TestsTabEtatsTempsParcoursSegment();
}

void TestsIndex ()
{	TestsIndexConstructeur();
	TestsIndexAjouterId();
	TestsIndexComparerId();
	TestsIndexLecture();
	TestsIndexStatsCapteur();
	TestsIndexStatsJSem();
	TestsIndexEmbouteillageJSemHeure();
	TestsIndexTempsParcoursSegment();
	TestsIndexTempsParcoursEnsembleSegments();
	TestsIndexMomentDepartOpti();
}



void Tests ()
{	TestsTabEtats();
	TestsIndex();
}



int main ()
{	cout << "Debut des tests" << endl;
	Tests();
	cout << "Fin des tests" << endl;

	/*Index unIndex;
	string commande;
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
		{	cin >> idCapteur >> annee >> mois >> jour >> heure
							 >> min >> jourSemaine >> trafic;
			unIndex.Lecture
				(idCapteur,mois-5,jour-1,heure,min,jourSemaine-1,trafic);
		} else if (commande == "STATS_C")
		{	cin >> idCapteur;
			unIndex.StatsCapteur(idCapteur);
		} else if (commande=="JAM_DH")
		{	cin >> jourSemaine;
			unIndex.EmbouteillageJSemHeure(jourSemaine);
		} else if (commande=="STATS_D7")
		{	cin >> jourSemaine;
			unIndex.StatsJSem(jourSemaine);
		}
		cin >> commande;
	}*/
	return 0;
}
