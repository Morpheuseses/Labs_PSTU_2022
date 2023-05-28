#include <QApplication>

#include "bst.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    BST* b = new BST();
    b->init(&scene, &view);

    b->insert(7);
    b->insert(5);
    b->insert(8);
    b->insert(10);
    b->insert(6);
    b->insert(9);
    b->insert(45);
    b->insert(67);
    b->insert(51);
    b->insert(1);

    //b->show();
    b->deleteNode(7);

    cout << "Find element: " << b->findElem(8) << endl;

    b->inOrder();
    b->preOrder();
    b->postOrder();

    b->showHor();


    return a.exec();
}
