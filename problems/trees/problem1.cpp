#include<iostream>
using namespace std;
void findInorderSucc(Tree * node , int data , int * succ , bool * node_found , bool * succ_found) {
    if (node == NULL) {
        return;
    }

    findInorderSucc(node->left , data , succ , node_found , succ_found);
    if (*succ_found) {
        return;
    }
    if (*node_found) {
        *succ = node->data;
        *succ_found = true;
        return;
    }
    if (node->data == data) {
        *node_found = true;
    }
    findInorderSucc(node->right , data , succ , node_found , succ_found);
}

int findInorderSucc(Tree * root , int data) {
    if (root == NULL) {
        return -1;
    }
    int succ = -1;
    bool node_found = false , succ_found = false;
    findInorderSucc(root , data , &succ , &node_found , &succ_found);
    return succ;
}
