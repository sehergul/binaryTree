#include <iostream>
//Çocugu olmayan dügümler- yaprak dügüm

using namespace std;

struct node{
    int data;
    node *left, *right;
};


node *kokDugum(int key){
    node *root = new node();
    root->data=key;
    root->left= root->right =NULL;
    return root;
}


node *dugumEkle(node *root, int key){
    if(root==NULL){
        root = kokDugum(key);}

    else{
        if(key < (root->data)) //Küçükse soluna eklenir
            root->left= dugumEkle(root->left, key);
        else //Büyükse sagina eklenir
            root->right= dugumEkle(root->right, key);
    }
    return root;
}


void preorder(node *root){ //Kök önde
    if(root!=NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(node *root){ //Kök ortada
    if(root!=NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void postorder(node *root){ //Kök sonda
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int dugumSayisi(node *root){
    if(root==NULL){ return 0; }

    else{
        return (dugumSayisi(root->left) + dugumSayisi(root->right) + 1);}
}

int depth(node *root){
    if(root==NULL){ return 0; }

    else{
        int left = depth(root->left);
        int right = depth(root->right);

        if(left>=right){return left + 1;}
        else {return right + 1;}
    }
}

void swap(node *root){
    node *temp= NULL;
    if(root!=NULL){
        swap(root->left);
        swap(root->right);
        temp= root->left;
        root->left= root->right;
        root->right=temp;
    }
}


int main()
{
    struct node *root=NULL;
    int sayi;
    int i=0;
    while(i<7){
        cout << "Sayi giriniz: "; cin >> sayi;
        root = dugumEkle(root, sayi);
        i++;
    }

    cout << "\nPreorder: "; preorder(root);
    cout << "\nPostorder: "; postorder(root);
    cout << "\nInorder: "; inorder(root);
    cout << "\nEklenen dugum sayisi: " << dugumSayisi(root);
    cout << "\nAgacin derinligi: " << depth(root);
    swap(root);
    cout << "\nYer degistirmeden sonra inorder: "; inorder(root);

    //AVL agac bilgisi

    return 0;
}
