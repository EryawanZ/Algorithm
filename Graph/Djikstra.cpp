#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dist[3003][3003], ans[3003]; bool inputed[3003][3003];
void djikstra(vector<unsigned int> G[3003], queue<unsigned int> &Que){
    while(!Que.empty()){
        int node = Que.front();
        Que.pop();
        for(auto i : G[node]){
            if(dist[node][i]+ans[node] < ans[i] || ans[i] == -1){
                ans[i] = dist[node][i]+ans[node];
                Que.push(i);
            }
        }
    }
}

int main(){ int t;
    cin >> t;
    while(t--){ int nN, nE, start; vector<unsigned int> G[3003]; queue<unsigned int> Que;
        memset(dist, -1, sizeof(dist));
        memset(inputed, 0, sizeof(inputed));
        memset(ans, -1, sizeof(ans));
        cin >> nN >> nE;
        for (int i=0; i<nE; i++){ int x, y, z;
            cin >> x >> y >> z;
            if(inputed[x][y]){
                if(z < dist[x][y]){
                    dist[x][y] = z, dist[y][x] = z;
                }
                continue;
            }
            G[x].push_back(y), G[y].push_back(x);
            dist[x][y] = z, dist[y][x] = z;
            inputed[x][y] = 1, inputed[y][x] = 1;
        }
        cin >> start;
        ans[start] = 0;
        Que.push(start);
        djikstra(G, Que);
        for (int i=1; i<=nN; i++){
            if(i == start) continue;
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }
    
    return 0;
}
