/*************************************************************************
                           CapteursRoutiers  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Interface de la classe <CapteursRoutiers> (fichier CapteursRoutiers.h) ------
#if ! defined ( CAPTEURSROUTIERS_H )
#define CAPTEURSROUTIERS_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CapteursRoutiers>
//
//
//------------------------------------------------------------------------

class CapteursRoutiers //: public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
  void Lecture (int idCapteur, int mois, int jour, int heure, int minute, int jourSemaine, char trafic);
	// Mode d'emploi :
	// Ajoute les infos données en entrée à tabValeurs
	// Contrat : aucun

//------------------------------------------------- Surcharge d'opérateurs
    CapteursRoutiers & operator = ( const CapteursRoutiers & unCapteursRoutiers );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CapteursRoutiers ( const CapteursRoutiers & unCapteursRoutiers );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CapteursRoutiers ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CapteursRoutiers ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    char tabValeurs[7][5][31][24][60][1500];

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CapteursRoutiers>

#endif // CAPTEURSROUTIERS_H
