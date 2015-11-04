/*************************************************************************
                           Table  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Interface de la classe <Table> (fichier Table.h) ------
#if ! defined ( TABLE_H )
#define TABLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Table>
//
//
//------------------------------------------------------------------------

class Table //: public Ancetre
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
    Table & operator = ( const Table & unTable );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Table ( const Table & unTable );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Table ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Table ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    void Ajouter (int mois, int jour, int heure, int minute, int jourSemaine, int etat);

    void Afficher() const;

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    int table[5][31][24][60][7];
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Table>

#endif // TABLE_H
