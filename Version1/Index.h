/*************************************************************************
                           Index  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Interface de la classe <Index> (fichier Index.h) ------
#if ! defined ( INDEX_H )
#define INDEX_H

//--------------------------------------------------- Interfaces utilisées
#include "Table.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Index>
//
//
//------------------------------------------------------------------------

class Index //: public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
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
    Index ( const Index & unIndex );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Index ( );
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
    void Ajouter (int nouvelId, Table *nouvelleTable);

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    int nbCapteurs;
    int *id;
    Table **table;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Index>

#endif // INDEX_H
