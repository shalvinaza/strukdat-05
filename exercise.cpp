/*
Author   : Shalvina Zahwa Aulia
NPM      : 140810180052
Deskripsi: Doubly linked list pembalap
Tahun    : 2019
*/
#include <iostream>
using namespace std;

struct pembalap {
    int nomor;
    char nama;
    int waktu;
    pembalap* next;
    pembalap* prev;
};

void createNode(pembalap* &p,  int nomor, char nama);
void insertFirst(pembalap* &head, pembalap* node);
void insertBefore(pembalap* &head, int nomorKey, pembalap* node);
void deleteByKey(pembalap* &head, int nomorKey, pembalap* &deletedNode);
void Search(pembalap* &firstNode, int nomorKey, pembalap* &pToUpdate);
void traversal(pembalap* head);
void sortingByNomor(pembalap* &head);
void update(pembalap* firstNode, int nomorKey);

int main (){
    pembalap* head = NULL;
    pembalap* pBaru = NULL;
    pembalap* pToUpdate = NULL;
    char nama = 'a';

    for (int i=0; i<4; i++){
        createNode(pBaru, i+1, nama++);
        insertFirst(head, pBaru);
    }
    cout << "\n>>> List" << endl;
    traversal(head);

    int keyNomor = 2;

    cout << "\n>>> Insert Before Nomor "<< keyNomor << endl;
    createNode(pBaru,99,'z');
    insertBefore(head, keyNomor, pBaru);
    traversal(head);

    cout << "\nSortingByNomor\n";
    sortingByNomor(head);
    traversal(head);

    keyNomor = 3;
    cout << "\nDelete Nomor" << keyNomor << endl;
    pembalap* pHapus = NULL;
    deleteByKey(head, keyNomor,pHapus);
    traversal(head);

    keyNomor = 4;
    cout << "\n>>> Upadate Nomor"<< keyNomor << endl;
    update(head,keyNomor);

    cout << "\n>> Updated List\n";
    traversal(head);
}
void createNode(pembalap* &p,  int nomor, char nama){
    p = new pembalap;
    p->nama = nama;
    p->nomor= nomor;
    cout << "Waktu\t : "; cin >> p->waktu;
    p->next=NULL;
    p->prev=NULL;
}
void inserFirst(pembalap* &head, pembalap* node){
    if (head=NULL){
        head=node;
    }
    else {
        node->next = head;
        node->prev = node;
        head=node;
    }
}
void insertBefore(pembalap* &head, int nomorKey, pembalap* node){
    pembalap* pCari;
    if (pCari->next==NULL){
        pCari->prev = node;
        node->next=pCari;
        head=node;
    }
    else{
        node->next=pCari;
        node->prev=pCari->prev;
        pCari->prev->next=node;
        pCari->prev=node;
    }
}
void deleteByKey(pembalap* &head, int nomorKey, pembalap*& deletedNode){
    pembalap* pCari;
    pembalap* pHapus;

    pCari=head;
    while(pCari!=NULL){
        pHapus=pCari;
        pCari->prev->next = pCari->next;
        pCari->next->prev = pCari->prev;
        pCari->next = NULL;
        pCari->prev = NULL;
    }
}
void Search(pembalap*& firstNode, int nomorKey, pembalap*& pToUpdate){
    pToUpdate=firstNode;
    while(pToUpdate->nomor!=nomorKey){
        pToUpdate = pToUpdate->next;
    }
}
void traversal(pembalap* head){
    pembalap* pBantu;
    if (head=NULL){
        cout << "\nKOSONG\n";
    }
    else {
        pBantu=head;
        cout << "Nomor\t : " << pBantu->nomor<< endl;
        cout << "Nama\t : "<< pBantu->nama << endl;
        cout << "Waktu \t : "<< pBantu->waktu << endl << endl;
        pBantu=pBantu->next;
    }
}
void sortingByNomor(pembalap*& head){
    pembalap* temp;
    for (int i=0; i<4;i++){
        for (int j=1; j<4;j++){
            if (head->nomor > head->next->nomor){
                temp=head;
                head=head->next;
                head->next=temp;
            }
        }
    }
}
void update(pembalap* firstNode, int nomorKey){}
