#include "adjmatrix.h"
#include <QStack>
#include <queue>
#include <stack>
AdjMatrix::AdjMatrix(QObject *parent) : QObject(parent)
{
    PathMatrix = nullptr;
}

int AdjMatrix::addPoint(int x, int y)
{
    Path** buffWaysMatrix = new Path*[Points.size()+1];
    for (int i = 0; i < Points.size()+1; i++)
    {
        buffWaysMatrix[i] = new Path[Points.size()+1];
    }

    if (PathMatrix == nullptr)
    {
        PathMatrix = buffWaysMatrix;
        buffWaysMatrix = nullptr;
    }
    else
    {
        for (int i = 0; i < Points.size(); i++)
        {
            for (int j = 0; j < Points.size(); j++)
            {
                buffWaysMatrix[i][j] = PathMatrix[i][j];
            }
        }
        for (int i = 0; i < Points.size(); i++)
        {
            delete[] PathMatrix[i];
        }
        delete[] PathMatrix;

        PathMatrix = buffWaysMatrix;
        buffWaysMatrix = nullptr;
    }

    Points.push_back(new Vertex(x,y,Points.size()));

    for (int i = 0; i < Points.size()-1; i++)
    {
        srand(time(NULL) -  i*100); rand();
        int buff = 1 + rand() % 9999;
        buff = 1 + rand() % 9999 + buff;
        srand(time(NULL) - buff); rand();

        int way = 1 + (rand()&0x7FFF) % 24;

        addLine(i, Points.size()-1, way);
    }

    emit signalSendMatrixSize(Points.size());

    return Points.size()-1;
}

void AdjMatrix::addLine(int firstVert, int secondVert, int size)
{
    PathMatrix[firstVert][secondVert].size = size;

    PathMatrix[firstVert][secondVert].line = new QGraphicsLineItem(Points[firstVert]->x,
                                                                 Points[firstVert]->y,
                                                                 Points[secondVert]->x,
                                                                 Points[secondVert]->y);
    PathMatrix[firstVert][secondVert].line->setPen(QPen(Qt::black));
    PathMatrix[firstVert][secondVert].text = new QGraphicsTextItem(QString::number(size));
    PathMatrix[firstVert][secondVert].text->setFont(QFont("", 10, 70, 0));
    int sizeX = 0, sizeY = 0;
    sizeX = Points[firstVert]->x < Points[secondVert]->x ? Points[firstVert]->x : Points[secondVert]->x;
    sizeY = Points[firstVert]->y < Points[secondVert]->y ? Points[firstVert]->y : Points[secondVert]->y;

    PathMatrix[firstVert][secondVert].text->setPos(sizeX + (std::abs(Points[firstVert]->x - Points[secondVert]->x)/2) - 15
                                                 , sizeY + (std::abs(Points[firstVert]->y - Points[secondVert]->y)/2) - 15);

    PathMatrix[secondVert][firstVert].size = PathMatrix[firstVert][secondVert].size;
    PathMatrix[secondVert][firstVert].line = PathMatrix[firstVert][secondVert].line;
    PathMatrix[secondVert][firstVert].text = PathMatrix[firstVert][secondVert].text;

    emit signalSendMatrixSize(Points.size());
}

void AdjMatrix::deleteLine(int index_i, int index_j)
{

    PathMatrix[index_i][index_j].size = -1;
    delete PathMatrix[index_i][index_j].line;
    delete PathMatrix[index_i][index_j].text;
    PathMatrix[index_i][index_j].line = nullptr;
    PathMatrix[index_i][index_j].text = nullptr;

    PathMatrix[index_j][index_i].size = -1;
    PathMatrix[index_j][index_i].line = nullptr;
    PathMatrix[index_j][index_i].text = nullptr;

    emit signalSendMatrixSize(Points.size());
}

int AdjMatrix::deletePoint(int index)
{
    if(Points.size()==0)
    {
        qDebug() << "Points is empty. Element correspond to index " << index << " was not removed";
        return -1;
    }
    if (index >= Points.size())
    {
        qDebug() << "Element correspond to index "<< index << "is not in Points. Element was not removed";
        return -2;
    }

    if (Points.size()==1)
    {
        deleteLine(0,0);

        delete[] PathMatrix[0];
        delete[] PathMatrix;
        PathMatrix = nullptr;
    }
    else
    {
        for (int i = 0; i < Points.size(); i++)
        {
            if (i != index)
            {
                deleteLine(index, i);
                deleteLine(i, index);
            }
        }
        deleteLine(index, index);

    Path** buffWaysMatrix = new Path*[Points.size()-1];

    for (int i = 0; i < Points.size(); i++)
        buffWaysMatrix[i] = new Path[Points.size()-1];

    int I = 0, J = 0;
    for (int i = 0; i < Points.size(); i++)
    {
            I = i;
            if (i!= index)
            {
                if (i > index) {--I;}
                for (int j = 0; j < Points.size(); j++)
                {
                    J = j;
                    if (j!=index)
                    {
                        if (j>index) {--J;}
                        buffWaysMatrix[I][J] = PathMatrix[i][j];
                    }
                }
            }

    }
    for (int i = 0; i < Points.size(); i++)
    {
        delete[] PathMatrix[i];
    }
    delete[] PathMatrix;

    PathMatrix = buffWaysMatrix;
    }



    delete Points[index];

    for (int i = index; i < Points.size()-1; i++)
    {
        Points[i] = Points[i+1];
        Points[i]->Number = i;
        Points[i]->nameOfTop->setPlainText(QString::number(i));
    }

    Points.pop_back();

    emit signalSendMatrixSize(Points.size());

    return 1;
}

void AdjMatrix::deleteAll()
{
    emit signalSendMatrixSize(-1);

    for (int i = 0; i < Points.size(); i++)
    {
        for (int j = 0; j < Points.size(); j++)
        {
            deleteLine(i,j);
        }
    }

    for (int i = 0; i < Points.size(); i++)
    {
        delete[] PathMatrix[i];
    }
    delete[] PathMatrix;
    PathMatrix = nullptr;

    for (int i = 0; i < Points.size(); i++)
    {
        delete Points[i];
    }

    Points.clear();
}

void AdjMatrix::setLineColor(int firstVert, int secondVert, int chose)
{
    if(PathMatrix[firstVert][secondVert].line != nullptr && firstVert >=0 && secondVert >= 0)
    {
        switch(chose)
        {
        case 0:
        {
            PathMatrix[firstVert][secondVert].line->setPen(QPen(Qt::black));
            break;
        }
        case 1:
        {
            PathMatrix[firstVert][secondVert].line->setPen(QPen(Qt::green));
            break;
        }
        case 2:
        {
            PathMatrix[firstVert][secondVert].line->setPen(QPen(Qt::red));
            break;
        }
        }
    }
}

void AdjMatrix::setPointColor(int firstVert, int chose)
{
    if(Points[firstVert]->circle != nullptr && firstVert >=0)
    {
        switch(chose)
        {
        case 0:
        {
            Points[firstVert]->circle->setBrush(Qt::gray);
            Points[firstVert]->circle->setPen(QPen(Qt::gray));
            break;
        }
        case 1:
        {
            Points[firstVert]->circle->setBrush(QColor(Qt::green));
            Points[firstVert]->circle->setPen(QPen(Qt::green));
            break;
        }
        case 2:
        {
            Points[firstVert]->circle->setBrush(QColor(Qt::red));
            Points[firstVert]->circle->setPen(QPen(Qt::red));
            break;
        }
        }
    }
}


void AdjMatrix::setAllPointsOneColor(int chose)
{
    for(int i = 0; i < Points.size(); i++)
    {
        setPointColor(i, chose);
    }
}

void AdjMatrix::setPathSize(int firstVert, int secondVert, int size)
{
    PathMatrix[firstVert][secondVert].size = size;
    PathMatrix[secondVert][firstVert].size = size;
    PathMatrix[firstVert][secondVert].text->setHtml(QString::number(size));
}

void AdjMatrix::setAllLinesOneColor(int chose)
{
    for(int i = 0; i < Points.size(); i++)
    {
        for(int j = 0; j < Points.size(); j++)
        {
            setLineColor(i, j, chose);
        }
    }
}

int AdjMatrix::degreeOfTop(int numbOfTop)
{
    int count = 0;
    for(int j = 0; j < Points.size(); j++)
    {
        if(PathMatrix[numbOfTop][j].size != -1) {++count;}
    }

    return count;
}

 QVector<QPair<int, int>> AdjMatrix::getEdges(int index)
{
    QVector<QPair<int, int >> res;
    for (int j = 0; j < Points.size(); j++)
    {
        if (PathMatrix[index][j].size > 0)
            res.push_back(qMakePair(index, j));
    }
    return res;
}

QVector<int> AdjMatrix::dijkstra(int vertexIndex)
{
    int Adj_matrix[Points.size()][Points.size()];
    for(int i=0;i<Points.size();i++)
    {
        for(int j=0;j<Points.size();j++)
        {
            if(i==j) Adj_matrix[i][j] = 0;
            else Adj_matrix[i][j] = 1000000;
        }
    }

    PriorityQueue<int> queue;

    for(int i=0;i<Points.size();i++)
    {
        queue.enqueue(Adj_matrix[vertexIndex][i],i);
    }

    while(queue.count()>0)
    {
        int Curr_vertex = queue.dequeue();
        auto edges = getEdges(Curr_vertex);

        for(int i=0;i<edges.size();i++)
        {
            int edge_data = PathMatrix[Curr_vertex][edges[i].second].size;
            int dest = edges[i].second;

            if(Adj_matrix[vertexIndex][Curr_vertex]+edge_data < Adj_matrix[vertexIndex][dest])
            {
                int old = Adj_matrix[vertexIndex][dest];

                Adj_matrix[vertexIndex][dest] = Adj_matrix[vertexIndex][Curr_vertex]+edge_data;

                queue.update(old,dest,Adj_matrix[vertexIndex][dest]);
            }
        }
    }
    QVector<int> new_vector;

    for(int i=0;i<Points.size();i++)
    {
        new_vector.push_back(Adj_matrix[vertexIndex][i]);
    }
    return new_vector;
}

QVector<int> AdjMatrix::getNbrsVertex(int index)
{
    QVector<int> res;

    for (int i = 0; i < Points.size(); i++)
    {
        if (PathMatrix[index][i].size > 0)
        {
            res.push_back(i);
        }
    }
    return res;
}
QVector<int> AdjMatrix::DFS(int vertexIndex)
{
    QVector<int> res;
    stack<int> stack;
    stack.push(vertexIndex);
    QVector<bool> visited = QVector<bool>(Points.size(), false);
    visited[vertexIndex] = true;


    while (!stack.empty())
    {
        auto frontVertex = stack.top();
        stack.pop();
        res.push_back(frontVertex);
        for (auto nbr : getNbrsVertex(frontVertex))
        {
            if (visited[nbr] != true)
            {
                stack.push(nbr);
                visited[nbr] = true;

            }
        }
    }
    return res;
}
QVector<int> AdjMatrix::BFS(int vertexIndex)
{
    QVector<int> res;
    queue<int> queue;
    queue.push(vertexIndex);
    QVector<bool> visited = QVector<bool>(Points.size(), false);
    visited[vertexIndex] = true;


    while (!queue.empty())
    {
        int frontVertex = queue.front();
        queue.pop();
        res.push_back(frontVertex);
        for (auto nbr : getNbrsVertex(frontVertex))
        {
            if (visited[nbr] != true)
            {
                queue.push(nbr);
                visited[nbr] = true;

            }
        }
    }
    return res;
}
AdjMatrix::~AdjMatrix()
{

}





















