#include "include/menu.hpp"
#include "include/Graphe.hpp"
///source :
///Les TP réalisés pendant le semestre, donc une partie de code de Mme.Palasi et de M.Fercoq
/// Cpluplus.com reference
///Forte connexite tarjan: http://www.dptinfo.ens-cachan.fr/Agregation/Algo13-14/6-graphes.pdf et https://iq.opengenus.org/tarjans-algorithm/
int main()
{
    ///Initialisations
    int finwhile=0;
    int topo;
    ///Boucle tant que la fin n'est pas demandée
    do
    {
        ///Récupérations du ou des fichier topologiques et ponderation
        std::string nomFichier;
        std::cout<<"Bienvenue"<<std::endl<<"Pour commencer veuillez saisir le nom d'un fichier topologique :"<<std::endl;
        std::cin>>nomFichier;
        Graphe g(nomFichier+".txt");
        g.afficherSVG();
        system("cls");
        std::cout<<"Voulez vous charger un fichier de ponderation?"<<std::endl<<"0) OUI"<<std::endl<<"1) NON"<<std::endl;
        std::cin>>topo;
        ///Si chargement topo +ponde
        if(topo==0)
        {
            std::cout<<"Veuillez saisir le nom du fichier"<<std::endl;
            std::cin>>nomFichier;
            g.chargerPonderation(nomFichier+".txt");
            g.afficherSVG();
            topo=1;
            system("cls");
        }
        ///Si juste chargement topo
        if(topo==1)
        {
            menu(g);
            finwhile=1;
        }
    }
    while(finwhile==0);
}
