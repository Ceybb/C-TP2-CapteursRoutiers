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

#define MAP
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void TestMesure1() {
	Mesure mesure;
} //----- Fin de Méthode

void TestMesure2() {
	Mesure mesure(45, 1234, 'V');
} //----- Fin de Méthode

void TestsMesure() {
	TestMesure1();
	TestMesure2();
} //----- Fin de Méthode

void Tests() {
	TestsMesure();
} //----- Fin de Méthode

int main() {
	Tests();;
	return 0;
}
