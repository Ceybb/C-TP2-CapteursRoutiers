/*************************************************************************
                           TabEtats  -  description
                             -------------------
    début                : 21/10/2015
    copyright            : (C) 2015 par abarzasi sdigiovann
*************************************************************************/

//---------- Interface de la classe <TabEtats> (fichier TabEtats.h) ------
#if ! defined ( TABETATS_H )
#define TABETATS_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TabEtats>
//
//
//------------------------------------------------------------------------

class TabEtats
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Afficher () const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	void AjouterMesure (int mois, int jour, int heure, int minute, int jourSemaine, char trafic);
    // Mode d'emploi :
    //
    // Contrat :
    //

	void StatsJSem (int jourSemaine,int &etatV, int &etatJ, int &etatR, int &etatN, int &nbMesures);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void EmbouteillageJSemHeure (int jourSemaine,int * &tabEtatsHeures, int * &nbMesures);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
    TabEtats ( );
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
    char tabEtats[7][5][5][24][60];

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <TabEtats>

#endif // TABETATS_H
