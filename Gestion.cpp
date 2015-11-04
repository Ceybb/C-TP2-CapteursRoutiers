
using namespace std;
#include <iostream>

int main(void) 
{
	string commande;
	int idCapteur;
	int annee;
	int mois;
	int jour;
	int heure;
	int min;
	int jourSemaine;
	char trafic;

  while (cin>>commande != "EXIT")
  {
    if (commande == "ADD")
    {
    	// Exécuter la méthode lecture
		cout << " Boucle lecture " << endl;
		cin >> idCapteur >> annee >> mois >> jour >> heure >> min >> jourSemaine >> trafic;
		cout << idCapteur << " / " << annee << " / " << mois << " / " << jour << " / " << heure <<" / " << min << " / " << jourSemaine << " / " << trafic << endl;
	}
    else if (commande == "STATS_C")
    {
    	//Exécuter la méthode StatsCapteur
    	cout << " Boucle StatsCapteur " << endl;
    	cin >> idCapteur;
    	cout << idCapteur << endl;
    }
    else if (commande == "JAM_DH")
    {
    	// Exécuter la méthode Embouteillage
    	cout << " Boucle Embouteillage " << endl;
    	cin >> jourSemaine;
    	cout << jourSemaine << endl;
    }
    else if (commande == "STATS_D7")
	{
		//Exécuter la méthode StatsJour
		cout << " Boucle StatsJour " << endl;
		cin >> jourSemaine;
		cout << jourSemaine << endl;

    }
    else if (commande == "OPT")
	{
		//Exécuter la méthode Optimisation
		cout << " Boucle Optimisation " << endl;
    	/* cin >> ?; A faire
		cout << ? << endl;*/
	}
	cin >> commande;
  }
  return 0;
}
