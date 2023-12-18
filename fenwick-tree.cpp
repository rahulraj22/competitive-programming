const int N = 1e5 + 10;
int tree[N];  // Binary Tree is represented in array
int a[N];
int n; // size of the array/nums

void update(int i, int x){ // NOTE: i index is 1 based indexing 
    while(i <= n){
        tree[i] += x;
        i += (i & (-i));
    }
}
int getSum(int i){
    // to get sum till ith index
    long long sum = 0;
    while(i > 0){
        sum += tree[i];
        i -= (i & (-i));
    }
    return sum;
}