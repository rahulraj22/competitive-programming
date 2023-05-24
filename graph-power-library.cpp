#include<bits/stdc++.h>
using namespace std;

typedef long long int  ll;
#define endl   "\n"
#define pb     push_back
#define all(x) (x).begin(),(x).end()
const int M = 1e9+7;

//****************BLACKBOX START*****************/ src: https://github.com/phpduke
//START COPYING FROM HERE 

class Graph {
    
    bool is_directed;
    
    public:
        vector<vector<pair<int,ll>>>adj;
        int n,N=2000000;
        Graph(int n_, bool is_directed_){
            n=n_; is_directed = is_directed_;
            adj.resize(N,vector<pair<int,ll>>());
        }

        int hash(int u, int v){
            return u*1873+v;
        }
        int hash(int u, int v, int k){
            return k*1873*1873+u*1873+v;
        }
        bool node_has_edges(int u) {
            return (adj[u].size()!=0);
        }
        bool node_has_edges(int u, int v) {
            int x = hash(u,v);
            return (adj[x].size()!=0);
        }
        bool node_has_edges(int u, int v, int k) {
            int x = hash(u,v,k);
            return (adj[x].size()!=0);
        }
        
        void add_edge(int u, int v, ll c=0){
            add_edge_weighted_undirected(u,v,c);
            if(!is_directed)
                add_edge_weighted_undirected(v,u,c);
        }
        void add_edge(int ui, int uj, int vi, int vj, ll c=0){
            int u=hash(ui,uj), v=hash(vi,vj);
            add_edge_weighted_undirected(u,v,c);
            if(!is_directed)
                add_edge_weighted_undirected(v,u,c);
        }
        void add_edge(int ui, int uj,int uk, int vi, int vj, int vk, ll c=0){
            int u=hash(ui,uj,uk), v=hash(vi,vj,vk);
            add_edge_weighted_undirected(u,v,c);
            if(!is_directed)
                add_edge_weighted_undirected(v,u,c);
        }

    private :
        
        void add_edge_weighted_undirected(int u, int v, ll c) {
            pair<int,ll>p = make_pair(v,c);
            adj[u].push_back(p);
        }
    
};

class BFS { 
    vector<ll>min_dist_from_source;
    vector<bool> visited;

    public:
        BFS(Graph *g_) {
            g = g_;
            min_dist_from_source.resize(g->N,-1);
            visited.resize(g->N, false);
        }
        Graph *g;


     void run(int source) {
            queue<int> q;
            q.push(source);
            
            visited[source] = true;
            min_dist_from_source[source] = 0;
            
            while(!q.empty()) {
                int cur_node = q.front();
                for (unsigned int i = 0; i < (g->adj[cur_node]).size(); ++i) {
                    int adj_node =  (g->adj[cur_node])[i].first;
                    if (visited[adj_node] == false) {
                        visited[adj_node] = true;
                        min_dist_from_source[adj_node] = min_dist_from_source[cur_node] + 1;
                        q.push(adj_node);
                    }
                }
                q.pop();
            }
            
            return;
        }
        
        void run(int sourcei, int sourcej){
            int source = (g->hash)(sourcei, sourcej);
            run(source);
        }
        void run(int sourcei, int sourcej, int sourcek){
            int source = (g->hash)(sourcei, sourcej, sourcek);
            run(source);
        }
        
        int min_dist(int targeti, int targetj){
            int target = (g->hash)(targeti,targetj);
            return min_dist_from_source[target];
        }
        int min_dist(int targeti,int targetj,int targetk){
            int target = (g->hash)(targeti,targetj,targetk);
            return min_dist_from_source[target];
        }
        int min_dist(int target){
            return min_dist_from_source[target];
        }
        
        bool is_visisted(int targeti,int targetj){
            int target = (g->hash)(targeti,targetj);
            return visited[target];
        }
        bool is_visisted(int targeti,int targetj,int targetk){
            int target = (g->hash)(targeti,targetj,targetk);
            return visited[target];
        }
        bool is_visisted(int target){
            return visited[target];
        }

};
//END COPYING HERE
//********************BLACKBOX END******************

int main(){
ios::sync_with_stdio(false); cin.tie(NULL);

    cout << "Hello World" << endl;
}

