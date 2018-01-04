#include <iostream>
#include <vector>
using namespace std;

class Node {
    Node *parent;
    int value;
    
    public:
        Node() {
            parent = this;
            value = -1;
        }
        Node(int val) {
            parent = this;
            value = val;
        }
        Node(Node *n, int val) {
            parent = n;
            value = val;
        }

        int getVal() {
            return value;
        }
        void setVal(int val) {
            value = val;
        }

        Node* getParent() {
            return parent;
        }
        void setParent(Node *par) {
            parent = par;
        }

};


void printList(vector<Node*> list) {
    for (Node* each : list) {
        Node *tmp = each;
        while (tmp) {
            cout << each->getVal() << " (" << each->getParent()->getVal() << ") ";
            if (tmp == tmp->getParent())
                break;
            tmp = tmp->getParent();
        }
        cout << "\n";
    }
}


void freeSpace(vector<Node*> list) {
    for (int i = 0; i < list.size(); ++i) {
        delete list[i];
        list[i] = NULL;
    }
}

vector<Node*> createNodes(int n) {
    vector<Node*> list;
    for (int i = 0; i < n; ++i) {
        Node *tmp = new Node(i);
        list.push_back(tmp);
    }
    // printList(list);
    // freeSpace(list);
    return list;
}


int main() {
    vector <Node*> list = createNodes(10);
    printList(list);
    freeSpace(list);
    return 0;
}
