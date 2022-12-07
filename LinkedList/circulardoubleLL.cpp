#include <iostream>

using namespace std;

// struktur linked list
struct dataBarang
{
    string MerkMobil;
    int Quantitas;

    // pointer
    dataBarang *prev;
    dataBarang *next;
};

dataBarang *head, *tail, *cur, *del, *newNode, *afterNode;

// fungsi membuat circular double Linked list
void createDataBarang(string MerkMobil, int Quantitas)
{
    head = new dataBarang();
    head->MerkMobil = MerkMobil;
    head->Quantitas = Quantitas;
    head->prev = head;
    head->next = head;
    tail = head;
}

// add First
void addFirst(string MerkMobil, int Quantitas)
{
    if (head == NULL)
    {
        cout << "Buat Linked List dahulu!!" << endl;
    }
    else
    {
        newNode = new dataBarang();
        newNode->MerkMobil = MerkMobil;
        newNode->Quantitas = Quantitas;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// add Last
void addLast(string MerkMobil, int Quantitas)
{
    if (head == NULL)
    {
        cout << "Buat Linked List dahulu!!" << endl;
    }
    else
    {
        newNode = new dataBarang();
        newNode->MerkMobil = MerkMobil;
        newNode->Quantitas = Quantitas;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}

// add Middle
void addMid(string MerkMobil, int Quantitas, int posisi)
{
    if (head == NULL)
    {
        cout << "Buat Linked List dahulu!!" << endl;
    }
    else
    {
        if (posisi == 1)
        {
            cout << "Posisi 1 bukan posisi tengah" << endl;
        }
        else if (posisi < 1)
        {
            cout << "Posisi diluar jangkauan" << endl;
        }
        else
        {
            newNode = new dataBarang();
            newNode->MerkMobil = MerkMobil;
            newNode->Quantitas = Quantitas;

            // tranversing
            cur = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                cur = cur->next;
                nomor++;
            }
            afterNode = cur->next;
            cur->next = newNode;
            afterNode->prev = newNode;
            newNode->prev = cur;
            newNode->next = afterNode;
        }
    }
}

// Print
void printDataBarang()
{
    if (head == NULL)
    {
        cout << "Buat Linked List dahulu!!" << endl;
    }
    else
    {
        cout << "Indonesian Limited Luxury Cars" << endl;
        cur = head;
        while (cur->next != head)
        {
            // print
            cout << "Car Brand =" << cur->MerkMobil << endl;
            cout << "Quantity = " << cur->Quantitas << "\n"
                 << endl;

            // step
            cur = cur->next;
        }
        // print last node
        cout << "Car Brand =" << cur->MerkMobil << endl;
        cout << "Quantity = " << cur->Quantitas << "\n"
             << endl;
    }
}

int main()
{
    createDataBarang(" Ferrari F40 1980", 3);
    printDataBarang();

    cout << "====== AddFirst =======" << endl;
    addFirst(" Lexus LFA", 1);
    printDataBarang();

    cout << "====== AddLast =======" << endl;
    addLast(" Lamborghini Countach 1990", 2);
    printDataBarang();

    cout << "====== AddMid =======" << endl;
    addMid(" Porsche Carrera 1983", 3, 2);
    printDataBarang();
}