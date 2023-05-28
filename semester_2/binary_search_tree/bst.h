#ifndef BST_H
#define BST_H
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>

using namespace std;

struct Node
{
    Node *p;
    int key;
    Node *left;
    Node *right;
};





class BST
{
public:
    void init(QGraphicsScene* scene, QGraphicsView* view);
    void insert(int data);

    void preOrder();
    void postOrder();
    void inOrder();

    void deleteNode(int val);
    void deleteNode(Node* p);
    void show();
    void showHor();

    int countNodes();
    int countLevels();
    int countLeftNodes();
    Node* findElem(int val);
private:
    int countNodes(Node* p);
    int countLevels(Node* p);
    int countLeftNodes(Node* p);

    void preOrder(Node* p);
    void postOrder(Node* p);
    void inOrder(Node* p);

    Node* findSuccessor(int val);

    QByteArray prepareGraph();
    QByteArray prepareGraphHor();
    void graphWalk(Node* p, QTextStream* stream);
    Node* findElem(int val, Node* p);

    Node* root;
    QGraphicsScene* scene;
    QGraphicsView* view;
};

#endif // BST_H
