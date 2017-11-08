#ifndef IDENTITY_H
#define IDENTITY_H
#include <string>

using namespace std;
class Identity
{
    private:
        //************************************************************* MEMBRES DE LA CLASSE
        int IdNumber;
        string IdName;
        string IdFirstName;
        string IdZipCode;
        string IdStreet;
        string IdCity;

    public:

        Identity();
        //************************************************************* PROTOTYPES
        // GET ET SET
        int getIdNumber();
        string getIdName();
        string getIdFirstName();
        string getIdZipCode();
        string getIdStreet();
        string getIdCity();

        void setIdNumber(int IdNumber);
        void setIdName(string IdName);
        void setIdFirstName(string IdFirstName);
        void setIdZipCode(string IdZipCode);
        void setIdStreet(string IdStreet);
        void setIdCity(string IdCity);

        void createId ();
        void affiche();
        void afficheModify();

    static int counter;

        virtual ~Identity();


    protected:




};

#endif // IDENTITY_H
