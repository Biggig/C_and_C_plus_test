#include <iostream>  
#include <stdio.h>  
#include <deque>  
#include <memory.h>  
using namespace std;  
  
  
//利用广度搜索将所有可能输入，当有步骤可到达终点时，该步骤即为最快步骤，跳出  
struct Node{  
    int x, y;       // 表示点的位置  
    int p;          // 表示此时还能飞的距离  
};  
char graph[120][120];  
bool visited[120][120][120];  
int m, n, D;  //行、列、飞行距离 
int mov[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}; //上下左右 
deque<Node> q;  
  
bool can_vis(int x, int y, int p){  
    if (x >= 0 && x < m && y >= 0 && y < n && graph[x][y] == 'P' && visited[x][y][p] == false) {  
        return true;  
    }  
    else return false;  
}  //可移动到（x,y） ,p为可飞行距离 
  
int main() {  
    // insert code here...  
    int i,j,size;  
    Node tmp, tmp1;  
    int result, flag;  
    while (scanf("%d",&m)!=EOF) {  
        scanf("%d%d", &n,&D);  
        for(i = 0; i<m; i++){  
            scanf("%s",&graph[i]);  
        }  
        memset(visited, 0, sizeof(visited)); //初始化 
          
        tmp.x = 0;  
        tmp.y = 0;  
        tmp.p = D;  
        result = 0;  
        flag = 0;  
        visited[tmp.x][tmp.y][tmp.p] = true;  
        q.clear();  
        q.push_back(tmp);  
        while (!q.empty()) {  
            size = q.size();  
            while (size --) {  
                tmp = q.front();  
                q.pop_front();  
                if (tmp.x == (m-1) && tmp.y == (n -1)) {   // 已经到达终点，直接跳出 ，最先到达终点，就是最快 
                    flag = 1;  
                    break;  
                }  
                for (i = 0 ; i < 4; i++) {         // 将周围合适的点存入，  
                    if (can_vis(tmp.x + mov[i][0], tmp.y + mov[i][1], tmp.p) == true) 
					{  
                        tmp1.x = tmp.x + mov[i][0];  
                        tmp1.y = tmp.y + mov[i][1];  
                        tmp1.p = tmp.p;  
                        visited[tmp1.x][tmp1.y][tmp1.p] = true;  
                        q.push_back(tmp1);//将可步行到达的点存入队列  
                    }  
                }  
                for (i = 0; i < 4; i++) {               // 查找能飞的区域  
                    for (j = 0; j <= tmp.p; j++) {  
                        tmp1.x = tmp.x + mov[i][0] * j;  
                        tmp1.y = tmp.y + mov[i][1] * j;  
                        tmp1.p = tmp.p - j;  
                        if (can_vis(tmp1.x, tmp1.y, tmp1.p) == true) {  
                            visited[tmp1.x][tmp1.y][tmp1.p] = true;  
                            q.push_back(tmp1);//将可飞行到达的点存入队列  
                        }  
                    }  
                }  
            }  
            if (flag == 1) break;  
            result ++;  
        }  
        if (flag == 1) cout << result << endl;  
        else cout << "impossible" << endl;  
          
    }  
    return 0;  
}
