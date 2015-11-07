/*************************************************************************
 Tests  -  description
 -------------------
 début                : 21/10/2015
 copyright            : (C) 2015 par abarzasi sdigiovann
 *************************************************************************/

//---------- Réalisation de la classe <Tests> (fichier Tests.cpp) --
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Mesure.h"
#include "DateHeure.h"


//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void TestMesure1() {
	Mesure mesure;
	mesure.Modifier(42,348,'V');
	mesure.Afficher();
} //----- Fin de Méthode

void TestDateHeure1() {
	DateHeure dateHeure(3,22,16);
	dateHeure.Afficher(1);
} //----- Fin de Méthode

void TestDateHeure2() {
	DateHeure dateHeure(4,13,5);
	dateHeure.Ajouter(55,1356,'R');
	dateHeure.Afficher(1);
} //----- Fin de Méthode

void TestDateHeure3() {
	DateHeure dateHeure(4,13,5);
	for (int i=0;i<10010;i++)
	{	dateHeure.Ajouter(55,1356,'R');
	}
	dateHeure.Afficher(0);
} //----- Fin de Méthode

void TestDateHeure4() {
	DateHeure dateHeure1(4,13,5);
	DateHeure dateHeure2(3,13,5);
	DateHeure dateHeure3(4,14,5);
	DateHeure dateHeure4(4,13,4);
	DateHeure dateHeure5(4,13,5);
	cout << dateHeure1.Comparer(dateHeure2) << endl;
	cout << dateHeure1.Comparer(dateHeure3) << endl;
	cout << dateHeure1.Comparer(dateHeure4) << endl;
	cout << dateHeure1.Comparer(dateHeure5) << endl;
} //----- Fin de Méthode

void TestsMesure() {
	TestMesure1();
} //----- Fin de Méthode

void TestsDateHeure() {
	TestDateHeure1();
	TestDateHeure2();
	TestDateHeure3();
	TestDateHeure4();
} //----- Fin de Méthode



void Tests() {
	TestsMesure();
	TestsDateHeure();
} //----- Fin de Méthode



int main() {
	Tests();
	return 0;
}
