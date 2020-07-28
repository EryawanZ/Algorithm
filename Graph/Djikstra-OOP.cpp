#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

class Graph{
private:
    int node, dist[3001];
    vector<unsigned int> relation[3001];
    map<pair<unsigned int, unsigned int>, int> cost;
    

public:
    Graph(int node) {
        this->node = node;
        memset(dist, -1, sizeof(dist));
    }
    vector<unsigned int> getRelation(int node){
        return relation[node];
    }
    void setRelation(unsigned int nodeA, unsigned int nodeB, unsigned int cost){
        relation[nodeA].push_back(nodeB);
        relation[nodeB].push_back(nodeA);
        this -> cost[{nodeA, nodeB}] = cost;
        this -> cost[{nodeB, nodeA}] = cost;
    }
    int getCost(unsigned int nodeA, unsigned int nodeB){
        return cost[{nodeA, nodeB}];
    }
    void setCost(unsigned int nodeA, unsigned int nodeB, int cost){
        this -> cost[{nodeA, nodeB}] = cost;
        this -> cost[{nodeB, nodeA}] = cost;
    }
    void setDist(unsigned int node, unsigned int distance){
        dist[node] = distance;
    }
    int getDist(unsigned int node){
        return dist[node];
    }
};

void djikstra(Graph *G, queue<unsigned int> *Que){
    while(!Que->empty()){
        int node = Que->front();
        Que->pop();
        for(auto i : G->getRelation(node)){
            if(G->getCost(node, i)+G->getDist(node) < G->getDist(i) || G->getDist(i) == -1){
                G->setDist(i, G->getCost(node, i)+G->getDist(node));
                Que->push(i);
            }
        }
    }
}

bool inputed[3001][3001];
int main() {
    int t;
    cin >> t;
    while (t--) { queue<unsigned int> Que;
        memset(inputed, 0, sizeof(inputed));
        int nN, nE, start;
        cin >> nN >> nE;
        Graph G(nN);
        for (int i = 0; i < nE; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if(inputed[x][y]){
                if(z < G.getCost(x, y)){
                    G.setCost(x, y, z);
                }
                continue;
            }
            G.setRelation(x, y, z);
            inputed[x][y] = 1, inputed[y][x] = 1;
        }
        cin >> start;
        Que.push(start);
        G.setDist(start, 0);
        djikstra(&G, &Que);
        for(int i=1; i<= nN; i++){
            if(i == start) continue;
            cout << G.getDist(i) << " ";
        }
        cout << endl;
    }

    return 0;
}