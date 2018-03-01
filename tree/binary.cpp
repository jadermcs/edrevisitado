#include <iostream>
#include <cstdlib>

template <class T>
class bintree {
    struct Node {
        T value;
        Node * left;
        Node * right;
    };
    Node * root;
    void pushit(T, Node *);
    void prefixprint(Node *);
    public:
        bintree(){
            root = NULL;
        }
        void pushit(T);
        void print();
};
template <class T>
void bintree<T>::pushit(T val, Node * leaf){
  if (val < leaf->value){
    if (leaf->left != NULL)
     pushit(val, leaf->left);
    else {
      leaf->left=new Node;
      leaf->left->value=val;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }
  }
  else if (val >= leaf->value){
    if(leaf->right != NULL)
      pushit(val, leaf->right);
    else {
      leaf->right=new Node;
      leaf->right->value=val;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}
template <class T>
void bintree<T>::pushit(T val){
  if(root!=NULL)
    pushit(val, root);
  else {
    root=new Node;
    root->value=val;
    root->left=NULL;
    root->right=NULL;
  }
}

template <class T>
void bintree<T>::prefixprint(Node * leaf){
    if (leaf){
        prefixprint(leaf->left);
        std::cout << leaf->value << std::endl;
        prefixprint(leaf->right);
    }
}


template <class T>
void bintree<T>::print(){
    if (root)
        prefixprint(root);
    else
        std::cout << "Empty tree." << std::endl;
}

int main(int argc, char *argv[]){
    bintree<int> intbintree;
    for (int i = 0; i < 10; ++i) {
        int r = rand() % 100;
        intbintree.pushit(r);
    }
    intbintree.print();
    return 0;
}
