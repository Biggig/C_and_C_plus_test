#include <iostream>  
#include <stdio.h>  
#include <deque>  
#include <memory.h>  
using namespace std;  
  
  
//���ù�����������п������룬���в���ɵ����յ�ʱ���ò��輴Ϊ��첽�裬����  
struct Node{  
    int x, y;       // ��ʾ���λ��  
    int p;          // ��ʾ��ʱ���ܷɵľ���  
};  
char graph[120][120];  
bool visited[120][120][120];  
int m, n, D;  //�С��С����о��� 
int mov[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}; //�������� 
deque<Node> q;  
  
bool can_vis(int x, int y, int p){  
    if (x >= 0 && x < m && y >= 0 && y < n && graph[x][y] == 'P' && visited[x][y][p] == false) {  
        return true;  
    }  
    else return false;  
}  //���ƶ�����x,y�� ,pΪ�ɷ��о��� 
  
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
        memset(visited, 0, sizeof(visited)); //��ʼ�� 
          
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
                if (tmp.x == (m-1) && tmp.y == (n -1)) {   // �Ѿ������յ㣬ֱ������ �����ȵ����յ㣬������� 
                    flag = 1;  
                    break;  
                }  
                for (i = 0 ; i < 4; i++) {         // ����Χ���ʵĵ���룬  
                    if (can_vis(tmp.x + mov[i][0], tmp.y + mov[i][1], tmp.p) == true) 
					{  
                        tmp1.x = tmp.x + mov[i][0];  
                        tmp1.y = tmp.y + mov[i][1];  
                        tmp1.p = tmp.p;  
                        visited[tmp1.x][tmp1.y][tmp1.p] = true;  
                        q.push_back(tmp1);//���ɲ��е���ĵ�������  
                    }  
                }  
                for (i = 0; i < 4; i++) {               // �����ܷɵ�����  
                    for (j = 0; j <= tmp.p; j++) {  
                        tmp1.x = tmp.x + mov[i][0] * j;  
                        tmp1.y = tmp.y + mov[i][1] * j;  
                        tmp1.p = tmp.p - j;  
                        if (can_vis(tmp1.x, tmp1.y, tmp1.p) == true) {  
                            visited[tmp1.x][tmp1.y][tmp1.p] = true;  
                            q.push_back(tmp1);//���ɷ��е���ĵ�������  
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
