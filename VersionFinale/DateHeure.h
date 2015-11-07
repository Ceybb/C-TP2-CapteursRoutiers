/*************************************************************************
                           DateHeure  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Interface de la classe <DateHeure> (fichier DateHeure.h) ------
#if ! defined ( DATEHEURE_H )
#define DATEHEURE_H
#include "Mesure.h"


//------------------------------------------------------------------------
// Rôle de la classe <DateHeure>
//
//
//------------------------------------------------------------------------

class DateHeure
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	bool Comparer (DateHeure DH);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Ajouter (int minuteM, int idI, int etatE);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Afficher (int option) const;
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
    DateHeure (int moisM, int jourJ, int heureH);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DateHeure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE
private:
//------------------------------------------------------- Méthodes privées
    void Ajuster ();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------- Attributs privés
    int mois;
    int jour;
    int heure;
    int nbMesuresCourant;
    int nbMesuresMax;
    Mesure * mesures;


};
#endif // DATEHEURE_H
