#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
int oo;
vector<int>BFS(vector<vector<int> > &adj, int s){
	queue<int>q;
	vector<int>prev(adj.size(), -1);
	vector<int>dist(adj.size(), oo);
	dist[s] = 0;
	q.push(s);//s
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			if (dist[adj[v][i]] == oo){
				q.push(adj[v][i]);
				dist[adj[v][i]] = dist[v] + 1;
				prev[adj[v][i]] = v;
			}
		}
	}
	return prev;
}

int distance(vector<vector<int> > &adj, int s, int t) {
	//write your code here
	vector<int>prev = BFS(adj, s);
	int temp = t;
	int d = 0;
	while (prev[temp] != -1){
		temp = prev[temp];
		d++;
	}
	if (d == 0)
		return -1;
	return d;
	//return -1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	oo = n + 1;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	//BFS(adj);
	std::cout << distance(adj, s, t);

	//system("pause");
}
