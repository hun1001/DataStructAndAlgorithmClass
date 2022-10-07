#include<iostream>
#include<list>
using namespace std;
#define MAPSIZE 8
#define UNIT_DISTANCE 10

class Astar {
    struct Node {
        int posX, posY;
        int F, G, H;
        Node* parent;
        bool IsBlock;
    };
    Node mapData[MAPSIZE][MAPSIZE];
    list<Node*> openList;
    Node* Start, * End;

public:
    Astar() {
        for (int y = 0; y < MAPSIZE; y++) {
            for (int x = 0; x < MAPSIZE; x++) {
                mapData[y][x].posX = x;
                mapData[y][x].posY = y;
                mapData[y][x].F = mapData[y][x].G = mapData[y][x].H = 0;
                mapData[y][x].IsBlock = false;
                mapData[y][x].parent = nullptr;
            }
        }
		Start = nullptr;
		End = nullptr;
    }

    void SetObstacleBlock(int y, int x) {
        mapData[y][x].IsBlock = true;
    }

    void InsertOpenList(Node* node, Node* parent, int Gdist = 0) {
		if (node->posX < 0 || node->posY < 0 || node->posX > MAPSIZE - 1 || node->posY > MAPSIZE - 1 || node->IsBlock)
            return;

        list<Node*>::iterator iter1;
        for (iter1 = openList.begin(); iter1 != openList.end(); iter1++) {
            if (node == (*iter1)) {// 이미 openlist에 있는 노드이고
                if ((*iter1)->F > node->F) { // openlist에 있던 기존 노드의 거리가 더 크면  
                    openList.erase(iter1); // 기존 노드를 지우고
                }
                else {  // openlist에 있던 기존 노드의 거리가 더 작으면 그대로 둠.
                    return;
                }
                break;
            }
        }
        node->parent = parent;
        node->G = Gdist;
		node->H = UNIT_DISTANCE * (abs(node->posX - End->posX) + abs(node->posY - End->posY));
        node->F = node->G + node->H;

        //openlist의 맨 앞에 있는 노드의 F값이 가장 작도록 삽입정렬 사용
        list<Node*>::iterator iter;
        for (iter = openList.begin(); iter != openList.end(); iter++) {
            if (node->F < (*iter)->F) {
                openList.insert(iter, node);
                return;
            }
        }
        openList.insert(iter, node);
    }

    void SetStartEndPoints(int StartY, int StartX, int EndY, int EndX) {
        Start = &mapData[StartY][StartX];
        End = &mapData[EndY][EndX];
        InsertOpenList(Start, NULL, 0);
    }

    void FindRoute() {
        Node* node;
        while (!openList.empty()) {
            list<Node*>::iterator iter = openList.begin();
            node = *iter;
            openList.erase(iter);
			node->IsBlock = true;
            if (node == End)
                break;

            InsertOpenList(&mapData[node->posY][node->posX + 1], node, node->G + UNIT_DISTANCE);
            InsertOpenList(&mapData[node->posY + 1][node->posX + 1], node, node->G + 1.4 * UNIT_DISTANCE);
            InsertOpenList(&mapData[node->posY - 1][node->posX + 1], node, node->G + 1.4 * UNIT_DISTANCE);
            InsertOpenList(&mapData[node->posY + 1][node->posX], node, node->G + UNIT_DISTANCE);
            InsertOpenList(&mapData[node->posY][node->posX - 1], node, node->G + UNIT_DISTANCE);
            InsertOpenList(&mapData[node->posY - 1][node->posX], node, node->G + UNIT_DISTANCE);
            InsertOpenList(&mapData[node->posY - 1][node->posX - 1], node, node->G + 1.4 * UNIT_DISTANCE);
            InsertOpenList(&mapData[node->posY + 1][node->posX - 1], node, node->G + 1.4 * UNIT_DISTANCE);
        }
    }

    void PrintPath() {
        for (int y = 0; y < MAPSIZE; y++) {
            for (int x = 0; x < MAPSIZE; x++) {
                cout << "[" << y << "," << x << "]" << " F:";
                cout.width(3);
                cout << mapData[y][x].F << " ";
            }
            cout << endl;
        }
    }

    void MakePath() {
        cout << "Result : ";
        Node* node = End;
        while (node != Start) {
            cout << "[" << node->posY << "," << node->posX << "] ";
            node = node->parent;
        }
        cout << "[" << node->posY << "," << node->posX << "] ";
    }
};


int main() {
    Astar a;
    cout << "A* 알고리즘" << endl;
    a.SetObstacleBlock(2, 5);
    a.SetObstacleBlock(3, 5);
    a.SetObstacleBlock(4, 5);
    a.SetStartEndPoints(3, 3, 3, 7);

    cout << endl << "-----------------초기 세팅----------------" << endl << endl;
    a.PrintPath();
    a.FindRoute(); // a* 알고리즘 실행
    cout << endl << "-----------------전체 결과----------------" << endl << endl;
    a.PrintPath(); // 실행 결과 출력
    cout << endl << "-----------------최단 경로----------------" << endl << endl;
    a.MakePath(); // 최단 경로 출력
}
