#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int INF = 100100100;
//int INF = 100;
typedef pair<int, int> P;

int N, M;
int sx, sy;  // スタート地点の座標
int gx, gy;  // ゴール地点の座標
// 移動4方向のベクトル
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(vector<vector<char>> &maze, vector<vector<int>> &d) {
    queue<P> que;
    // INFで初期化
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            d[i][j] = INF;
        }
    }
    // スタート地点をキューに入れ、距離を0に
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    
    while (que.size()) {
        P p = que.front();  // 一番下のデータ
        que.pop();  // 一番下のデータを取り除く
        
        if (p.first == gx && p.second == gy) break;
        
        // 移動
        for (int i=0; i<4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            // 移動可能な範囲でかつ、すでに訪れていない地点 INF出なければすでに訪れている
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                // 移動できるならqueに入れ、その点の距離をpから+1で確定
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    /*
    // 各地点へ何回で辿り着けるか表示
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/
    return d[gx][gy];
}

int main(void){
    
    cin >> N >> M;
    vector<vector<char>> maze(N,vector<char>(M));  //迷路の配列 蟻本はM+1
    vector<vector<int>> d(N,vector<int>(M));  // 各点までの最短距離配列
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> maze.at(i).at(j);
            if (maze.at(i).at(j) == 'S') {
                sx = i;
                sy = j;
            }
            if (maze.at(i).at(j) == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    int ans = bfs(maze, d);
    printf("%d\n", ans);
    /*
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << maze.at(i).at(j);
        }
        cout << endl;
    }
    printf("sx:%d sy:%d gx:%d gy:%d", sx, sy, gx, gy);
    */
}

/*
入力
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/