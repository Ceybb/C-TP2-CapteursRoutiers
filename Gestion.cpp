
using namespace std;
#include <iostream>

int main(void) 
{
	string sortie;
	string lecture;
	string statsC;
	string embouteillage;
	string stats;
	string optimal;

  while (cin>>sortie != "EXIT")
  {
    if (cin>>lecture == "ADD")
    {
    	// Exécuter la méthode lecture
	}
    if (cin>>statsC == "STATS_C")
    {
    	//Exécuter la méthode StatsCapteur
    }
    if (cin>>embouteillage == "JAM_DH")
    {
    	// Exécuter la méthode Embouteillage
    }
	if (cin>>stats == "STATS_D7")
	{
		//Exécuter la méthode StatsCapteur
    }
	if (cin>>optimal == "OPT")
	{
		//Exécuter la méthode Optimisation
	}
  }
  return 0;
}
