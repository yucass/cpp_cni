#include <iostream>
#include <string>
#include "Identity.h"
#include <stdio.h>
#include <string.h>

int main();
using namespace std;

Identity::Identity()//constructeur
{
    //ctor
}

Identity::~Identity()//destructeur
{
    //dtor
}

//************************************************************* SET
void Identity::setIdNumber(int Number)
{

    IdNumber = Number;
}

void Identity::setIdFirstName(string FirstName)
{

    IdFirstName = FirstName;
}
void Identity::setIdName(string Name)
{
    IdName = Name;
}
void Identity::setIdZipCode(string ZipCode)
{
    //cin >> ZipCode;
    IdZipCode = ZipCode;
}
void Identity::setIdStreet(string Street)
{

    IdStreet = Street;
}
void Identity::setIdCity(string City)
{

    IdCity = City;
}

//************************************************************* GET
int Identity::getIdNumber ()
{
    return IdNumber;
}
string Identity::getIdName()
{
    return IdName;
}
string Identity::getIdFirstName()
{
    return IdFirstName;
}
string Identity::getIdZipCode()
{
    return IdZipCode;
}
string Identity::getIdStreet()
{
    return IdStreet;
}
string Identity::getIdCity()
{
    return IdCity;
}



//************************************************************* AFFICHAGES DE LA CARTE
void Identity::affiche()
{
	cout << "Numero d'Identification : " << getIdNumber()<<endl;
	cout << "Nom : " << getIdName()<<endl;
	cout << "Prenom : " << getIdFirstName()<<endl;
	cout << "Code Postal : " << getIdZipCode()<<endl;
	cout << "Adresse : " << getIdStreet()<<endl;
	cout << "Ville : " << getIdCity()<<endl;
}

//************************************************************* AFFICHAGE DE BRIBE DE CARTE POUR LA MODIFICATION
void Identity::afficheModify()
{
    cout << getIdNumber() << "). Numero d'Identification : " << getIdNumber() << " - Nom : " << getIdName() << " - Prenom : " << getIdFirstName()<<endl;
}

//************************************************************* CREATION DE LA CARTE
void Identity::createId ()
{
    int creatorIsOn = 1;

        string nom; // variable
        cout << "Saisissez  un Nom : ";
        cin >> nom; // saisi de l'utilisateur
        setIdName(nom); // set la saisi dans la variable de l'objet

        string prenom;
        cout << "Saisissez  un Prenom : ";
        cin >> prenom;
        setIdFirstName(prenom);

        string zip;
        cout << "Saisissez  un code postal : ";
        cin >> zip;
        setIdZipCode(zip);

        string adresse;
        cout << "Saisissez  une adresse : ";
        getline(cin.ignore(),adresse);
        setIdStreet(adresse);

        string ville;
        cout << "Saisissez  une ville : ";
        cin >> ville;
        setIdCity(ville);



}
