#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i, int sum, int n, vector<int> a, int k, vector<int> &b){
    printf("i:%d , sum:%d\n", i, sum);
    if(i == n)return sum==k;
    // a.at(i)を使わない場合
    if(dfs(i+1, sum, n, a, k, b)){
        //printf("使う\n");
        b.at(i) = 0;
        return true;
    }
    // a.at(i)を使う場合
    if(dfs(i+1, sum+a.at(i), n, a, k, b)){
        //printf("使わない\n");
        b.at(i) = 1;
        return true;
    } 
    printf("false\n");
    return false;
}
int main(void){
    // Your code here!
    int n, k;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i< n; i++){
        cin >> a.at(i);
    }
    cin >> k;
    if(dfs(0, 0, n, a, k, b)) printf("Yes\n");
    else printf("No\n");
    
    for(int i=0; i< n; i++){
        //cout << b.at(i);
        if (b.at(i) > 0){
            cout << a.at(i) << " ";
        }
    }
    cout << endl;

}
