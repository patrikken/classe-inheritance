#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Volaille
{
  char nom;
  public:
  void saisir();
  void affiche();
  char getNom()
{
    return nom;
}
void setNom(string n)
{
    nom=n;
}
};
class Poule : public Volaille{
float poids;
public:
void saisir(int);
void affiche();
void pondre();
float getPoids(){
    return poids;
}
void setPoids(float p)
{
    poids=p;
}

};
void Poule::saisir(int i)
{
    float p;
    string n;
     cout << "\nentrer le nom de la poule "<<i <<" ";
     cin  >>n;
     setNom(n);
     cout << "entrer le poid de la poule "<<i <<" ";
     cin  >> p;
     setPoids(p);
}
void Poule::affiche()
{
    cout << "\n\n poule de nom "<<getNom()<<" et de poids "<<getPoids()<<"";
}

class Cop : public Volaille{
string description;

public:
Cop(string n,string d)
{
    setNom(n);
    description=d;
}
void saisir();
void affiche();
void cocoricot();
void coco();
};
void Cop::affiche()
{
    cout << "\nle Cop creer a pour nom "<<getNom()<<" avec la description "<<description<<endl;
}
class Oeuf : public Poule{
int poids;
public:
void saisir();
void affiche();
void pondre();
};
void menu(Poule *tabp,Cop *cop)
{
    system("cls");
    system("color 9F");
    int x;
    int a=0;
    string n,d;
    string m;
    cout << "\n"<< endl;
    cout << "               ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²" << endl;
    cout << "               ²                                              ²" << endl;
    cout << "               ²                 le poulailler                ²" << endl;
    cout << "               ²                                              ²" << endl;
    cout << "               ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²" << endl;
    cout << "\n "<< endl;
    cout << "         ->Menu\n "<< endl;
    cout << "               1- Creer un Tableau dynamique de poulet + affichage \n"<< endl;
    cout << "               2- Creer Cop plus affichage \n"<< endl;
    cout << "               3- Le Cop fait 'CoCoriCot' et toutes les poules pondent \n"<< endl;
    cout << "               4- Le Cop fait 'CoCo' et une poule sur deux pondent \n"<< endl;
    cout << "               5- Quitter (et detruire tout le poulailler) \n\n"<< endl;
    cout << "                                      Faites votre choix  "<< "";
    cin >> x ;

    switch (x){
    case 1:
    system("cls");
       cout << "     \n   entrer le nombre de poulet "<< "";
       cin >> a ;
       tabp=new Poule[a];
       for(int i=0;i<=a-1;i++)
       {
           tabp[i].saisir(i+1);
       }
       cout << "\nAFFICHAGE DES POULES CREER\n"<<a<<" dans le poulailler"<< "";
       for(int i=0;i<=a-1;i++)
       {
           tabp[i].affiche();
       }
        cout << "\n\n tapez sur une touche pour retourner au menu...\n"<< "";
        cin >> m ;
        menu(tabp,cop);
    break;
    case 2:
    system("cls");
    cout << "\nCREATION D'UN COP\n"<< "";
    cout << "\n entrer le nom du cop :"<< "";
    cin >> n ;
    cout << "\n entrer Une Description sur ce cop :"<< "";
    cin >> d ;
    cop=new Cop(n,d);
    cout << "\nAFFICHAGE DU COP CREER\n"<< "";
    cop->affiche();
    cout << "\n tapez sur une touche pour retourner au menu...\n"<< "";
    cin >> m ;
    menu(tabp,cop);
    break;
    case 3:
    system("cls");
    if(cop==NULL)
    {
      cout << "\n IMPOSSIBLE DE FAIRE COCORICOT CAR AUCUN COP NA ETE CREER \n\n"<< "";
    }else
    {
        if(tabp==NULL)
        {
            cout << "\n  LE COP A FAIT COCORICOT MAIS Y'A AUCUNE POULE DANS LE POULAILLER "<< "";
        }else
        {
            cout << "\n  LE COP A FAIT COCORICOT"<< "";
            cout << "\n TOUTES LES "<<tapb<<" POULES ONT PONDUES"<< "";
        }
    }
    cout << "\n tapez sur une touche pour retourner au menu...\n"<< "";
    cin >> m ;
    menu(tabp,cop);
    break;
    case 4:
    system("cls");
    if(cop==NULL)
    {
      cout << "\n IMPOSSIBLE DE FAIRE COCO CAR AUCUN COP NA ETE CREER \n\n"<< "";
    }else
    {
        if(tabp==NULL)
        {
            cout << "\n  LE COP A FAIT COCORICOT MAIS Y'A AUCUNE POULE DANS LE POULAILLER \n\n"<< "";
        }
    }
    cout << "\n tapez sur une touche pour retourner au menu...\n"<< "";
    cin >> m ;
    menu(tabp,cop);
    break;
    default: menu(NULL,NULL);


    }
}
int main()
{
    Poule *tabp=NULL;
    Cop *cop=NULL;
    menu(tabp,cop);
    return 0;
}
