#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class node {
public:
    int id;
    int reward_score;
    int count;
    node* left;
    node* right;
    int height;

    node(int id, int reward_score) {
        this->id = id;
        this->reward_score = reward_score;
        this->count = 1;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

int height(node* Node) {
    if (Node == nullptr) {
        return 0;
    }
    return Node->height;
}

int balanceFactor(node* Node) {
    if (Node == nullptr) {
        return 0;
    }
    return height(Node->left) - height(Node->right);
}

void updateHeight(node* Node) {
    Node->height = max(height(Node->left), height(Node->right)) + 1;
}

node* llRotate(node* Node) {
    node* left = Node->left;
    node* right = left->right;
    left->right = Node;
    Node->left = right;
    updateHeight(Node);
    updateHeight(left);
    return left;
}

node* rrRotate(node* Node) {
    node* right = Node->right;
    node* left = right->left;
    right->left = Node;
    Node->right = left;
    updateHeight(Node);
    updateHeight(right);
    return right;
}

node* lrRotate(node* Node) {
    Node->left = rrRotate(Node->left);
    return llRotate(Node);
}

node* rlRotate(node* Node) {
    Node->right = llRotate(Node->right);
    return rrRotate(Node);
}

node* insert(node* &Node, int id, int reward_score) {
    if (Node == nullptr) {
        return new node(id, reward_score);
    }
    if (id < Node->id) {
        Node->left = insert(Node->left, id, reward_score);
    }
    else if (id > Node->id) {
        Node->right = insert(Node->right, id, reward_score);
    }
    else{
        Node->count++;
        Node->reward_score += reward_score;
        return Node;
    }
    updateHeight(Node);
    int balance = balanceFactor(Node);
    if (balance > 1 && id < Node->left->id) {//elements at left are greater than elements at right
        return llRotate(Node);
    }
    if (balance < -1 && id > Node->right->id) {//elements at right are greater than elements at left

        return rrRotate(Node);
    }
    if (balance > 1 && id > Node->left->id) {//element on left side are greater but the key is in right node lr case
        return lrRotate(Node);
    }
    if (balance < -1 && id < Node->right->id) {//rl case
        return rlRotate(Node);
    }
    return Node;
}

node* minValueNode(node* Node) {
    node* current = Node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
//node* deleteNode(node* &Node, int id) {
//    if (Node == nullptr) {
//        return Node;    
//    }
//    if (id < Node->id) {
//        Node->left = deleteNode(Node->left, id);
//    }
//    else if (id > Node->id) {
//        Node->right = deleteNode(Node->right, id);
//    }
//    else {
//        if (Node->count > 1) {
//            Node->count--;
//            Node->reward_score -= 0;/*some value*/ // update the reward score accordingly
//            return Node;
//        }
//        else {
//
//            if (Node->left == NULL) {
//                node* temp=NULL;
//
//                if (temp->right != NULL) {
//                    temp = temp->right;
//
//                }
//                if (temp == NULL) {
//                    temp = Node;
//                    Node = NULL;
//                }
//                else {
//                    *Node = *temp;
//                }
//                delete temp;
//            }
//
//
//            if (Node->right == NULL) {
//                node* temp=NULL;
//
//                if (temp->left != NULL) {
//                    temp = temp->left;
//
//                }
//                if (temp == NULL) {
//                    temp = Node;
//                    Node = NULL;
//                }
//                else {
//                    *Node = *temp;
//                }
//                delete temp;
//            }
//
//            else if(Node->left!=NULL && Node->right!=NULL)
//         
//            {
//                node* temp = Node->right;
//                while (temp->left != NULL) {
//                    temp = temp->left;
//                    cout << temp->id;
//                }
//                temp->left = Node->left;
//                temp = Node;
//                Node = Node->right;
//                
//                delete temp;
//            }
//        }
//    }
//    
//    if (Node == nullptr) {
//        return Node;
//    }
//    updateHeight(Node); //to check if the avl tree got unbalanced
//    int balance = balanceFactor(Node);
//    if (balance > 1 && balanceFactor(Node->left) >= 0) {
//        return llRotate(Node);
//    }
//    if (balance > 1 && balanceFactor(Node->left) < 0) {
//        return lrRotate(Node);
//    }
//    if (balance < -1 && balanceFactor(Node->right) <= 0) {
//        return rrRotate(Node);
//    }
//    if (balance < -1 && balanceFactor(Node->right) > 0) {
//        return rlRotate(Node);
//    }
//    return Node;
//}
node* deleteNode(node*& Node, int id) {
    if (Node == nullptr) {
        return Node;
    }
    if (id < Node->id) {
        Node->left = deleteNode(Node->left, id);
    }
    else if (id > Node->id) {
        Node->right = deleteNode(Node->right, id);
    }
    else {
        if (Node->count > 1) {
            Node->count--;
            Node->reward_score -= 0;/*some value*/ // update the reward score accordingly
            return Node;
        }
        else {
            if (Node->left == nullptr && Node->right == nullptr) {
                delete Node;
                Node = nullptr;
            }
            else if (Node->left == nullptr) {
                node* temp = Node;
                Node = Node->right;
                delete temp;
            }
            else if (Node->right == nullptr) {
                node* temp = Node;
                Node = Node->left;
                delete temp;
            }
            else {
                node* temp = Node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }


                temp->left = Node->left;
                temp = Node;
                Node = Node->right;
                delete temp;
            }
        }
    }

    if (Node == nullptr) {
        return Node;
    }
    updateHeight(Node); //to check if the avl tree got unbalanced
    int balance = balanceFactor(Node);
    if (balance > 1 && balanceFactor(Node->left) >= 0) {
        return llRotate(Node);
    }
    if (balance > 1 && balanceFactor(Node->left) < 0) {
        return lrRotate(Node);
    }
    if (balance < -1 && balanceFactor(Node->right) <= 0) {
        return rrRotate(Node);
    }
    if (balance < -1 && balanceFactor(Node->right) > 0) {
        return rlRotate(Node);
    }
    return Node;
}
static int sc = 0;

void PrintTree(struct node* root)
{

    if (root != NULL)
    {

        cout << root->id << " " << root->reward_score << endl;
        sc += root->reward_score;
        cout << sc << endl;
        PrintTree(root->left);

        //cout << "Right Root:" << endl;
        PrintTree(root->right);
    }
}
