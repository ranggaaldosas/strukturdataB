#include <iostream>
using namespace std;

class MHS
{

    // Acces Specifier
public:
    // member function()
    void printname()
    {
        cout << "Nama Mahasiswa nya adalah : " << namemhs;
    }

    string getNama()
    {
        return namemhs;
    }

    MHS(string nama)
    {
        namemhs = nama;
    }

private:
    string namemhs; // data member
};

int main()
{ // declare an object of class geeks
    MHS mhs1("Nathania");
    MHS mhs2("Ali");
    MHS mhs3("Sastrowardoyo");

    // accesing member function
    mhs2.printname();

    cout << mhs2.getNama();

    return 0;
}