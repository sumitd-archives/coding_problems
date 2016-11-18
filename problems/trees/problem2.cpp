#include<iostream>
using namespace std;

void setInorderSucc(Tree * node) {
    if(node->left != NULL) {
        setInorderSucc(node->left) = node;
    }
    if(node->right == NULL) {
        return setInorderSucc(node->right);
    }
    return node->inorderSucc;        
}
