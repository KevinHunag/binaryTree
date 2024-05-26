#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

int search(Node* root, int target){
    if(target > root->value){
        if(root->right == NULL){
            return false;
        }
        return search(root->right, target);
    }
    else if(target < root->value){
        if (root->left == NULL){
            return false;
        }
        return search(root->left, target);
    }
    else{
        return true;
    }
}
int searchInsertposition(Node* root, int target){
    if(target > root->value){
        if(root->right == NULL){
            root->right = new Node;
            root->right->value = target;
            return 1;
        }
        return searchInsertposition(root->right, target); 
    }
    else if(target < root->value){
        if(root->left == NULL){
            root->left = new Node;
            root->left->value = target;
            return 1;
        }
        return searchInsertposition(root->left, target);
    }
    else 
        return 0;
}
int main(){
    bool found;
    srand(time(NULL));
    Node root;
    root.value = rand() %(655*2) +1;
    int count = 0;
    while(count < 6553){
        int randomNumber = rand() %(655*2) +1;
        int insertPosition = searchInsertposition(&root, randomNumber);
        count++;
    }
    found =search(&root, 100);
    cout<<found<<endl;
}