/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ------
#if ! defined ( MESURE_H )
#define MESURE_H


//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	void Modifier (int minuteM, int idI, int etatE);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Afficher() const;
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------------------------ PRIVE
private:
//------------------------------------------------------- Attributs privés
    int minute;
    int id;
    char etat;


};
#endif // MESURE_H
