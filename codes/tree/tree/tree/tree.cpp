// tree.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>


using namespace std;

class Node {

    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {


    private:

        void printTree(Node* currentNode) const{
            if (currentNode == nullptr) return;

            

            printTree(currentNode->left);
            cout << currentNode->value << "->";
            printTree(currentNode->right);
        }


        Node* rInsert(Node* currentNode, int value) {
            if (currentNode == nullptr) return new Node(value);

            if (value < currentNode->value) {
                currentNode->left = rInsert(currentNode->left, value);
            }
            else if (value > currentNode->value) {
                currentNode->right = rInsert(currentNode->right, value);
            }
            return currentNode;

        }


        bool rContains(Node* currentNode, int value) {
            if (currentNode == nullptr) return false;
            if (currentNode->value == value) return true;

            if (value < currentNode->value) {
                return rContains(currentNode->left, value);
            }
            else if (value > currentNode->value) {
                return rContains(currentNode->right, value);
            }
        }

        void leftToRoot(Node* currentNode, int sum) {

            if (currentNode == nullptr) return;
            cout << currentNode->value << endl;
            sum = sum + currentNode->value;
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                cout << sum << endl;
                return;
            }

            leftToRoot(currentNode->left, sum);
            leftToRoot(currentNode->right, sum);

        }

        Node* deleteNode(Node* cuurrentNode, int value) const {
            if (cuurrentNode == nullptr) {
                return nullptr;
            }

            if (cuurrentNode->value > value) {
                cuurrentNode->left = deleteNode(cuurrentNode->left, value);
            }
            else if (cuurrentNode->value < value) {
                cuurrentNode->right = deleteNode(cuurrentNode->right, value);
            }
            else {
                if (cuurrentNode->left == nullptr && cuurrentNode->right == nullptr) {
                    delete(cuurrentNode);
                    return nullptr;
                }
                else if (cuurrentNode->left == nullptr) {
                    Node* temp = cuurrentNode->right;
                    delete(cuurrentNode);
                    return temp;
                }
                else if (cuurrentNode->right == nullptr) {
                    Node* temp = cuurrentNode->left;
                    delete(cuurrentNode);
                    return temp;
                }
                else {
                    int subTreeMain = minValue(cuurrentNode->right);
                    cuurrentNode->value = subTreeMain;
                    cuurrentNode->right = deleteNode(cuurrentNode->right, cuurrentNode->value);

                }
            }
            return cuurrentNode;
        }


        int minValue(Node* currentNode) const {
            while (currentNode->left != nullptr) {
                currentNode = currentNode->left;
            }
            return currentNode->value;
        }

    public:
        Node* root;
        BinarySearchTree() {
            root = nullptr;
        }



        void printTree() const{
            return printTree(root);
        }

        bool Insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            else {
                Node* temp = root;
                while (true) {
                    if (newNode->value == root->value) return  false;
                    else if (value > temp->value) {
                        if (temp->right == nullptr) {
                            temp->right = newNode;
                            return true;
                        }
                        else {
                            temp = temp->right;
                        }

                    }
                    else {
                        if (temp->left == nullptr) {
                            temp->left = newNode;
                            return true;
                        }
                        else {
                            temp = temp->left;
                        }
                    }
                }
            }
        }


        bool contains(int value) {
            if (root == nullptr) return false;
            Node* temp = root;

            while (temp != nullptr) {
                if (value < temp->value) {
                    temp = temp->left;
                }
                else if (value > temp->value) {
                    temp = temp->right;
                }
                else {
                    return true;
                }
            }
            return false;
        }


        bool rContains(int value) {
            return rContains(root, value);
        }

        void rInsert( int value) {
            if (root == nullptr) root = new Node(value);
            rInsert(root, value);
        }

        void leftToRoot() {
            if (root == nullptr) return;
            leftToRoot(root,0);
        }

        void deleteNode(int value)  {
            root = deleteNode(root, value);
        }
};




int main()
{
    BinarySearchTree* tree = new BinarySearchTree();
    
    tree->rInsert(10);
    tree->rInsert(7);
    tree->rInsert(8);
    tree->rInsert(16);
    tree->rInsert(28);
    tree->rInsert(3);
    tree->rInsert(5);
    tree->rInsert(15);
    tree->rInsert(14);
    tree->rInsert(2);
    tree->rInsert(8);
    tree->rInsert(17);
    tree->rInsert(20);
    tree->rInsert(19);

    tree->printTree();
    

    tree->deleteNode(10);
    cout << endl;
    tree->printTree();

}

