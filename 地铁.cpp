#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

struct node{
	string name;//����վ�� 
	vector<string> lines;//�ߣ������� 
	node(string n){
		name = n;//����վ����ʼ�� 
	}
};

vector<vector<double> > shortest_path(vector<vector<double> > g);//����Ϊͼ�����Ϊ��¼��������̾���ľ���;
vector<vector<int> > less_change(vector<vector<int> > l);//����Ϊ��¼���ߵľ������Ϊ���ٻ��˴��� 
int findl(string target, vector<string> all_line);//�ҵ�վ�����ߵ��±� 

int main(){
	int n, e;
	cin >> n >> e;
	vector<node> all;//���е�վ�� 
	vector<string> all_line;
	for(int k = 0; k < n; k++){
		string name;
		cin >> name;
		string num;
		node temp = node(name);
		cin >> num;
		if(num == "0")
			continue;//һ��վ����·������� 
		while(num != "0"){
			int i;
			for(i = 0; i < all_line.size(); i++){
				if(num == all_line[i])
					break;
			}
			if(i == all_line.size())
				all_line.push_back(num);//�³��ֵ���·����������· 
			for(i = 0; i < temp.lines.size(); i++){
				if(num == temp.lines[i])
					break;
			}
			if(i == all_line.size())
				temp.lines.push_back(num);//�³��ֵ���·������վ��������· 
			cin >> num;
		}
		all.push_back(temp);
	}
	vector<vector<int> > l = vector<vector<int> >(all_line.size(), vector<int>(all_line.size(), 0));//��ʼ�� 
	for(int k = 0; k < all.size(); k++){
		if(all[k].lines.size() > 1){
			for(int i = 0; i < all[k].lines.size(); i++){
				int a = findl(all[k].lines[i], all_line); 
				for(int j = i+1; j < all[k].lines.size(); j++){
					int b = findl(all[k].lines[j], all_line);
					l[a][b] = 1;
					l[b][a] = 1;//������·��ͨ 
				}
			}
		}
	}
	vector<vector<double> > g = vector<vector<double> >(n, vector<double>(n, 0));//��ʼ�� 
	while(e--){
		int f, s;
		double length;
		cin >> f >> s >> length;
		g[f-1][s-1] = length;
		g[s-1][f-1] = length;
	}
	int cas;//���������� 
	cin >> cas;
	vector<vector<double> > shortest_length = shortest_path(g);
	vector<vector<int> > less_ch = less_change(l);
	while(cas--){
		int f, s;
		cin >> f >> s;
		if(f < 1||s < 1||f > n||s > n){
			cout << "Wrong input!\n";
			continue;
		} 
		int min = numeric_limits<int>::max();
		for(int i = 0; i < all[f-1].lines.size(); i++){
			int lf = findl(all[f-1].lines[i], all_line);
			for(int j = 0; j < all[s-1].lines.size(); j++){
				if(all[f-1].lines[i] == all[s-1].lines[j]){
					min = 0;
					break;
				}
				int ls;
				ls = findl(all[s-1].lines[j], all_line);
				if(less_ch[lf][ls] < min)
					min = less_ch[lf][ls];
			}
			if(min == 0)
				break;
		}
		cout << shortest_length[f-1][s-1] << " " << min << endl;
	}
	return 0;
}

vector<vector<double> > shortest_path(vector<vector<double> > g){
	vector<vector<double> > d = vector<vector<double> >(g.size(), vector<double>(g.size(), 0));
	for(int begin = 0; begin < g.size(); begin++){//begin������վ�����·�� 
		bool visited[g.size()];
		for(int i = 0; i < g.size(); i++){
			visited[i] = false;
			if(g[begin][i] == 0)// begin �� i ������ 
				d[begin][i] = numeric_limits<double>::max();
			else
				d[begin][i] = g[begin][i];
		}
		d[begin][begin] = 0;
		visited[begin] = true;
		int w = -1;
		for(int i = 0; i < g.size(); i++){
			double min = numeric_limits<double>::max();
			int j;
			for(j = 0; j < g.size(); j++){
				if(d[begin][j] < min&&visited[j] == false&&d[begin][j]!=0){
					w = j;
					min = d[begin][j];
				} 
			}
			if(w != -1){
				visited[w] = true;
				for(j = 0; j < g.size(); j++){
					if(min + g[w][j] < d[begin][j]&&visited[j] == false&&g[w][j] != 0){
						d[begin][j] = min + g[w][j];//����j��begin����̾��� 
					}
				}
			}
		}
	}
	return d;
}

vector<vector<int> > less_change(vector<vector<int> > l){
	vector<vector<int> > less = vector<vector<int> >(l.size(), vector<int>(l.size(), 0));
	for(int begin = 0; begin < l.size(); begin++){
		bool visited[l.size()];
		for(int i = 0; i < l.size(); i++){
			visited[i] = false;
		}
		queue<int> q;
		q.push(begin);
		visited[begin] = true;
		less[begin][begin] = 0;
		while(!q.empty()){
			int front = q.front();
			q.pop();
			for(int i = 0; i < l.size(); i++){
				if(l[front][i] == 1&&visited[i] == false){
					less[begin][i] = less[begin][front] + 1;
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}
	return less;
}

int findl(string target, vector<string> all_line){
	for(int i = 0; i < all_line.size(); i++){
		if(target == all_line[i])
			return i;
	}
}

/*
5 4
Wanshengwei 4 8 0
Kecun 3 8 0
Zhongda 8 0
ZhujiangNewTown 3 5 0
GuangzhouTower 3 APM 0
1 2 15.33
3 2 4.00
4 5 1.66
2 5 2.00
3
1 2
4 1
1 3
*/
