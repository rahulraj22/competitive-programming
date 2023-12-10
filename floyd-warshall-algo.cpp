int floyd(vector<vector<int>> &matrix, int n){
    // n => number of nodes
    // matrix => contains data of node connnections with given weights
    int inf = 1e9;
    // initially defining distance b/w any node with other is infinite
    vector<vector<int>> dist(n, vector<int> (n, inf));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dist[i][j] = matrix[i][j]; // initially assign the given distance as it is.
        }
    }
    // finding smallest distance b/w any node with every other nodes
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    // we can also return the maximum / minimum distance among all possible node with other nodes
    int mx = 0, mn = 1e9;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            mx = max(mx, dist[i][j]);
            mn = min(mn, dist[i][j]);
        }
    }
    return mx; // or return based on given condition/situations
}