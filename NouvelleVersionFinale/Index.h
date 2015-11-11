/*************************************************************************
                           Index  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Interface de la classe <Index> (fichier Index.h) ------
#if ! defined ( INDEX_H )
#define INDEX_H

#include "TabEtats.h"

//------------------------------------------------------------------ Types
enum codeRetour {nbCapteursMaxNonAjuste, nbCapteursMaxAjuste};

//------------------------------------------------------------------------
// Rôle de la classe <Index>
//
//
//------------------------------------------------------------------------

class Index
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	codeRetour AjouterId ( int id );
    // Mode d'emploi :
    //
    // Contrat :
    //

	int ComparerId ( int unId );
	// Mode d'emploi :
	//
    // Contrat :
    //

    void Afficher () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Lecture ( int idCapteur, int mois, int jour, int heure,
    			   int minute, int jourSemaine, char trafic );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void StatsCapteur ( int idCapteur );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void StatsJSem ( int jourSemaine );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void EmbouteillageJSemHeure ( int jourSemaine );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int TempsParcoursSegment( int idCapteur, int jourSemaine,
    						  int heure, int minute );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int TempsParcoursEnsembleSegments ( int nbCapteurs, int * idCapteur,
    									int jourSemaine, int heureDebut,
										int minuteDebut, int &heureFin );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void MomentDepartOpti ( int nbCapteurs, int * idCapteur,
    					int jourSemaine, int heureDebut, int heureFin );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Index ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Index ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Méthodes privées
    void Ajuster ();

//------------------------------------------------------- Attributs privés
    int nbCapteursCourant;
    int nbCapteursMax;
    int * id;
    TabEtats ** index;

};

#endif // INDEX_H
