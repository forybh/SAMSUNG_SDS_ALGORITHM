
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;
int V, E, K;
int u, v, w;
int dist[20001];
vector<pii> arr[20001];
priority_queue<pii> pq;

int main(int argc, const char * argv[]) {
    scanf("%d%d", &V, &E);
    scanf("%d", &K);
    
    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        arr[u].push_back(pii(w,v));
    }
    fill(dist, dist+V+1, INF);
    
    pq.push(pii(0, K));
    dist[K] = 0;
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int to = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < arr[to].size(); i++) {
            int next = arr[to][i].second;
            int nextcost = arr[to][i].first;
            
            if(dist[next] > dist[to] + nextcost) {
                dist[next] = dist[to] + nextcost;
                pq.push(pii(-dist[next], next));
            }
        }
    }
    for(int i = 1; i <=V; i++) {
        if(dist[i] == INF) {
            printf("INF\n");
            continue;
        }
        printf("%d\n", dist[i]);
    }
}
