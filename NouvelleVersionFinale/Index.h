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

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

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
	codeRetour AjouterId (int id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Index & operator = ( const Index & unIndex );
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

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    void Ajuster ();

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    int nbCapteursCourant;
    int nbCapteursMax;
    int * id;
    TabEtats ** index;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Index>

#endif // INDEX_H
