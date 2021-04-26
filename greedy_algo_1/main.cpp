#include <iostream>
#include <vector>
using namespace std;
int main(void){
    const int V[6] = {1, 5, 10, 50, 100, 500};
    vector<int> coin(6);
    int A;
    int ans = 0;
    
    for (int i=0; i<6; i++){
        cin >> coin[i];
    }
    cin >> A;
    
    for (int i=5; i>=0; i--){
        int t = min(A / V[i], coin[i]);
        A -= t * V[i];
        ans += t;
    }
    cout << ans << endl;
    
}
/*
1円、5円、10円、50円、100円、500円の枚数
できるだけ少ない枚数でA円払う
入力
3 2 1 3 0 2
620
*/