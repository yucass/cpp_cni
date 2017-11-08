#include <iostream>
#include <ostream>
#include <string>
#include "Identity.h"
//definition de la constante TAILLE, qui limite le nombre de carte créé a 15
#define TAILLE 15

//Utilisation du namespace standard
using namespace std;


//*************************************************************PROTOTYPES
void menu(Identity id[TAILLE]);
void read(Identity id[TAILLE]);
int modifyId (Identity id[TAILLE]);
void createIdSubmenu (Identity id[TAILLE]);

//************************************************************* FONCTION MAIN
int main()
{
//creation de l'objet id issu de la classe Identity
    Identity id[TAILLE];
//initialisation des numeros de carte
    for (int i = 0; i<TAILLE+1; i++)
    {
        id[i].setIdNumber(i);
    }
//chargement du menu principal
    menu(id);


    return 0;
}
//************************************************************* SOUS MENU DE CREATION D'ID
void createIdSubmenu (Identity id[TAILLE])
{
//variables
    int idnum = 0;
    int i = 0;

//verification de la derniere entrée de nom (si getIdName est different de "", alors il y a une entrée et on passe a la suivante
    while (id[idnum].getIdName() != "")
    {
        idnum++;
    }
//appel de createId en se basant sur la premiere entrée vide.
        for (idnum; idnum<TAILLE; idnum++)
    {
        id[idnum].createId();

        int choice = 0;
        cout << "Carte cree.\n1-Continuer\n2-quitter\n"<<endl;

//Mini menu pour continuer ou revenir au menu principal
        cin >> choice;
        switch(choice)
        {
            case 1 : break;
            case 2 : menu(id); break;
            default : break;
        }
    }

}

//************************************************************* MENU PRINCIPAL DE L'APP
void menu (Identity id[TAILLE])
{
//variables
    int choix = 0;
//affichage du choix du menu
    cout << "\nMenu principal\n\n1-Lire\n2-Creer\n3-Modifier\n"<<endl;
    cin >> choix;

// switch permettant de choisir quelle fonction appeller
    switch (choix)
    {
        case 1 : if (id[0].getIdName() == ""){cout << "aucune entree disponible, veuillez en creer une" << endl; menu(id);} else read(id);;break; // verification qu'il y a bien 1 entrée dispo
        case 2 : createIdSubmenu(id); break;
        case 3 : if (id[0].getIdName() == ""){cout << "aucune entree disponible, veuillez en creer une" << endl; menu(id);} else modifyId(id);; break;// verification qu'il y a bien 1 entrée dispo
        default : menu(id); break;

    }
}

//************************************************************* LECTURE DES CARTES
void read(Identity id[TAILLE])
{
    for (int i = 0; i < TAILLE; i++)
    {
        if(id[i].getIdName() != "") // verification que l'entrée n'est pas vide
        id[i].affiche(); // affichage de l'entrée
    }
    menu(id); // retour au menu
}

//************************************************************* MODIFICATION DES CARTES EXISTANTES
int modifyId (Identity id[TAILLE])
{
// variables
    int modifychoose = 0;
    int modifyvalue = 0;
    string nom, prenom, zip, adresse, ville;

    for (int i = 0; i < TAILLE; i++)
    {
        if(id[i].getIdName() != "") // eternel verification de l'entrée
        {id[i].afficheModify();}
    }
        cout << "Choisissez quelle carte modifier : ";
        cin>> modifychoose; // choix de la carte a modifier

        cout << "vous avez choisi de modifier :" << endl;

        cout << "1 - Nom : " << id[modifychoose].getIdName()<<endl;
        cout << "2 - Prenom : " << id[modifychoose].getIdFirstName()<<endl;
        cout << "3 - Code Postal : " << id[modifychoose].getIdZipCode()<<endl;
        cout << "4 - Adresse : " << id[modifychoose].getIdStreet()<<endl;
        cout << "5 - Ville : " << id[modifychoose].getIdCity()<<endl;
        cout << "0 - Quitter sans modifier !" << endl;

        cout << "quelle champs voulez vous modifier ?";
        cin >> modifyvalue; //choix du champs a modifier

        switch (modifyvalue)// switch renvoyant vers la fonction modifiant tel ou tel champs
            {
                case 1 : cout << "Saisissez  un Nom : "; cin >> nom; id[modifychoose].setIdName(nom);break;
                case 2 : cout << "Saisissez  un Prenom : "; cin >> prenom; id[modifychoose].setIdFirstName(prenom);break;
                case 3 : cout << "Saisissez  un Code Postal : "; cin >> zip; id[modifychoose].setIdZipCode(zip);break;
                case 4 : cout << "Saisissez  un Adresse : "; cin >> adresse; id[modifychoose].setIdStreet(adresse);break;
                case 5 : cout << "Saisissez  un Ville : "; cin >> ville; id[modifychoose].setIdCity(ville);break;
                default : menu(id);break;
            }
            cout << "Carte modifie avec succes" << endl;
            menu(id); // retour au menu


}
