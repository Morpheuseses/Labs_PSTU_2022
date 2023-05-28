#include "bst.h"

void BST::init(QGraphicsScene* scene, QGraphicsView* view)
{
    this->root = NULL;
    this->scene = scene;
    this->view = view;
}

void BST::insert(int data)
{
    Node* tmp = new Node;
    tmp->key = data;
    tmp->left = NULL;
    tmp->right = NULL;

    if (this->root == NULL)
    {
        tmp->p = NULL;
        this->root = tmp;
    }
    else
    {
        Node* cElem = this->root;
        Node*  parent = NULL;

        while (cElem != NULL)
        {
            parent = cElem;
            if (data < cElem->key)
                cElem = cElem->left;
            else
                cElem = cElem->right;
        }

        tmp->p = parent;

        if (data < parent->key)
            parent->left = tmp;
        else
            parent->right = tmp;
    }


}

void BST::preOrder(Node* p)
{
    if (p != NULL)
    {
        cout << p->key << " ";
        this->preOrder(p->left);
        this->preOrder(p->right);
    }
}
void BST::preOrder()
{
    cout << "Preordered walk: " << endl;
    this->preOrder(this->root);
    cout << endl;
}
void BST::postOrder(Node* p)
{
    if (p != NULL)
    {
        this->postOrder(p->left);
        this->postOrder(p->right);
        cout << p->key << " ";
    }
}
void BST::postOrder()
{
    cout << "Postordered walk: " << endl;
    this->postOrder(this->root);
    cout << endl;
}
void BST::inOrder(Node* p)
{
    if (p != NULL)
    {
        this->inOrder(p->left);
        cout << p->key << " ";
        this->inOrder(p->right);
    }
}
void BST::inOrder()
{
    cout << "Inordered walk: " << endl;
    this->inOrder(this->root);
    cout << endl;
}
Node* BST::findElem(int val, Node* p)
{
    if (p != NULL)
    {
        if (val == p->key) return p;

        if (val < p->key)
            return findElem(val, p->left);
        else
            return findElem(val, p->right);
    }
    else
    {
        return NULL;
    }
}
Node* BST::findElem(int val)
{
    return this->findElem(val, this->root);
}

Node* BST::findSuccessor(int val)
{
    Node* startNode = this->findElem(val);
    Node* parent = startNode;

    startNode = startNode->right;
    while (startNode != NULL && startNode->left != NULL)
    {
        parent = startNode;
        startNode = startNode->left;
    }
    return startNode;
}

void BST::deleteNode(Node* p)
{
    Node* q = NULL;
    Node* r = NULL;

    if (p->left == NULL || p->right == NULL)
    {
        q = p;
    }
    else
    {
        q = this->findSuccessor(p->key);
    }

    if (q->left != NULL)
    {
        r =  q->left;
    }
    else
    {
        r = q->right;
    }

    if (r != NULL)
    {
        r->p = q->p;
    }

    if (q->p == NULL)
    {
        this->root = r;
    }
    else
    {
        if (q == q->p->left)
        {
            q->p->left = r;
        }
        else
        {
            q->p->right = r;
        }
    }

    if (q != p)
    {
        p->key = q->key;
    }
}

void BST::deleteNode(int val)
{
    this->deleteNode(this->findElem(val));
}


int BST::countLevels(Node *p)
{
    int h1 = 0;
    int h2 = 0;

    if (p == NULL) return 0;

    if (p->left)
    {
        h1 = countLevels(p->left);
    }

    if (p->right)
    {
        h2 = countLevels(p->right);
    }

    return (max(h1, h2) + 1);
}

int BST::countLevels()
{
    return this->countLevels(this->root);
}

int BST::countNodes(Node* p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return (countNodes(p->left) + countNodes(p->right)+1);
    }
}

int BST::countNodes()
{
    return this->countNodes(this->root);
}

int BST::countLeftNodes(Node* p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return (countLeftNodes(p->left) + countLeftNodes(p->right)) + (p->left != NULL && p->right == NULL)? 1 : 0;
    }

}

int BST::countLeftNodes()
{
    return this->countLeftNodes(this->root);
}

void BST::graphWalk(Node* p, QTextStream *stream) {
    if (p != NULL){
        *stream << "\t\t" << "n" << p->key << "[label=\"" << p->key <<"\"];" << endl;

        if(p->left != NULL){
            *stream << "\t\tn" << p->key << "--" << "n" << p->left->key << ";" << endl;
            this->graphWalk(p->left, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "leftNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "leftNull" << endl;
        }

        if(p->right != NULL){
            *stream << "\t\tn" << p->key << "--" << "n" << p->right->key << ";" << endl;
            this->graphWalk(p->right, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "rightNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "rightNull" << endl;
        }
    }
}

QByteArray BST::prepareGraph(){
    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;

    //stream << "size = \"6, 6\";" << endl;
    //stream << "rankdir = \"LR\";" << endl;

    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;

    stream << "\tsubgraph cluster17{" << endl;

    this->graphWalk(this->root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return a;
}


void BST::show(){
    QProcess* p = new QProcess();
    QByteArray a = this->prepareGraph();

    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();

    while(p->waitForReadyRead(100)){
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);

    this->scene->addPixmap(pixmap);
    this->view->show();
}

void BST::showHor(){
    QProcess* p = new QProcess();
    QByteArray a = this->prepareGraphHor();

    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();

    while(p->waitForReadyRead(100)){
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);

    this->scene->addPixmap(pixmap);
    this->view->show();
}

QByteArray BST::prepareGraphHor(){
    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;

    stream << "rankdir = \"LR\";" << endl;

    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;

    stream << "\tsubgraph cluster17{" << endl;

    this->graphWalk(this->root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return a;
}
