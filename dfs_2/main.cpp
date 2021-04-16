#include <iostream>
#include <vector>
using namespace std;
void dfs(int x, int y, vector<vector<char>> &field, int &H, int &W) {
    //.に置き換え
    field.at(x).at(y) = '.';
    for (int dx=-1; dx<=1; dx++) {
        for (int dy=-1; dy<=1; dy++) {
            int nx = x + dx, ny = y + dy;
            /*
            printf("nx:%d ny:%d\n", nx, ny);
            if (0 <= nx && nx < H && 0 <= ny && ny < W) {
                printf("値:%c\n", field.at(nx).at(ny));
            }*/
            if (0 <= nx && nx < H && 0 <= ny && ny < W && field.at(nx).at(ny) == 'W') {
                 dfs(nx, ny, field, H, W);
            }
        }
        
    }
    return;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> field(H,vector<char>(W));
  for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        cin >> field.at(i).at(j);
      }
  }
  
  int ans = 0;
  for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
          if (field.at(i).at(j) == 'W') {
              dfs(i, j, field, H, W);
              ans++;
          }
      }
  }
  printf("%d\n", ans);
  
}
