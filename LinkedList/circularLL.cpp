#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Pelajar
{
    string nama, nrp;
    Pelajar *next;
};

Pelajar *head, *tail, *newNode, *cur, *del;

// buat Circular Single Linked List
void CircularLL(string dataBaru[2])
{

    head = new Pelajar();
    head->nama = dataBaru[0];
    head->nrp = dataBaru[1];
    tail = head;
    tail->next = head;
}

void circularprint()
{
    if (head == NULL)
    {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else
    {
        cout << "Nama NRP" << endl;
        cur = head;
        while (cur->next != head)
        {
            cout << " " << cur->nama << "\t " << cur->nrp << "\t\t" << endl;
            cur = cur->next;
        }
        cout << " " << cur->nama << "\t " << cur->nrp << "\t\t " << endl;
    }
}

void addFirst(string data[2])
{
    if (head == NULL)
    {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else
    {
        newNode = new Pelajar();
        newNode->nama = data[0];
        newNode->nrp = data[1];
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void addLast(string data[2])
{
    if (head == NULL)
    {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else
    {
        newNode = new Pelajar();
        newNode->nama = data[0];
        newNode->nrp = data[1];
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void addMid(string data[2], int posisi)
{
    if (head == NULL)
    {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else
    {
        if (posisi == 1)
        {
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        }
        else
        {
            newNode = new Pelajar();
            newNode->nama = data[0];
            newNode->nrp = data[1];

            // tranversing ke posisi sebelum posisi yang dituju
            int nomor = 1;
            cur = head;
            while (nomor < posisi - 1)
            {
                cur = cur->next;
                nomor++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

int main()
{
    string dataBaru[2] = {"Rangga Aldo", "5027211059"};
    cout << "===== Create Circular =====" << endl;
    CircularLL(dataBaru);
    circularprint();
    cout << "\n"
         << endl;

    string data[2] = {"Shidqi", "5027211059"};
    cout << "===== Add First =====" << endl;
    addFirst(data);
    circularprint();
    cout << "\n"
         << endl;

    string data2[2] = {"Hisyam", "5027211059"};
    cout << "======= Add Last =======" << endl;
    addLast(data2);
    circularprint();
    cout << "\n"
         << endl;

    string data3[2] = {"Dinda", "5027211059"};
    cout << "======= Add Middle =======" << endl;
    addMid(data3, 5);
    circularprint();
    cout << "\n"
         << endl;
}
