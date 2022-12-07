#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser
{
    string nama, nrp;
    DataUser *prev;
    DataUser *next;
};

DataUser *head, *tail, *cur, *newNode, *del, *afterNode;

// Create Double Linked List
void createDoubleLinkedList(string data[2])
{
    head = new DataUser();
    head->nama = data[0];
    head->nrp = data[1];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

// count Double Linked List
int countDoubleLinkedList()
{
    if (head == NULL)
    {
        cout << "Buatlah DoubleLinkedList terlebih dahulu!";
    }
    else
    {
        cur = head;
        int jumlah = 0;
        while (cur != NULL)
        {
            jumlah++;
            // step
            cur = cur->next;
        }
        return jumlah;
    }
}

// Add First
void addFirst(string data[2])
{
    if (head == NULL)
    {
        cout << "Buatlah DoubleLinkedList terlebih dahulu!";
    }
    else
    {
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->nrp = data[1];
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Add Last
void addLast(string data[2])
{
    if (head == NULL)
    {
        cout << "Buatlah DoubleLinkedList terlebih dahulu!";
    }
    else
    {
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->nrp = data[1];
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

// Add Middle
void addMiddle(string data[2], int posisi)
{
    if (head == NULL)
    {
        cout << "Buatlah DoubleLinkedList terlebih dahulu!";
    }
    else
    {

        if (posisi == 1)
        {
            cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
        }
        else if (posisi < 1 || posisi > countDoubleLinkedList())
        {
            cout << "Posisi out of range" << endl;
        }
        else
        {
            newNode = new DataUser();
            newNode->nama = data[0];
            newNode->nrp = data[1];

            // tranversing
            cur = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                cur = cur->next;
                nomor++;
            }

            afterNode = cur->next;
            newNode->prev = cur;
            newNode->next = afterNode;
            cur->next = newNode;
            afterNode->prev = newNode;
        }
    }
}

// Print Double Linked List
void printDoubleLinkedList()
{
    if (head == NULL)
    {
        cout << "Buatlah DoubleLinkedList terlebih dahulu!";
    }
    else
    {
        cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
        cur = head;
        while (cur != NULL)
        {
            // print
            cout << "Name :" << cur->nama << endl;
            cout << "nrp :" << cur->nrp << "\n"
                 << endl;
            // step
            cur = cur->next;
        }
    }
}

int main()
{
    string newData[2] = {"Ahnaf Santoso", "5027211054"};
    createDoubleLinkedList(newData);

    printDoubleLinkedList();

    string data2[2] = {"Nas Nus Nus", "5027211033"};

    cout << "===== Add first =====" << endl;
    addFirst(data2);

    printDoubleLinkedList();

    string data3[2] = {"Agoy", "5027211023"};

    cout << "===== Add last =====" << endl;
    addLast(data3);

    printDoubleLinkedList();

    string data4[2] = {"Reynold Purwanto", "5027211021"};

    cout << "===== Add Middle =====" << endl;
    addMiddle(data4, 3);

    printDoubleLinkedList();
}