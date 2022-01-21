#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef vector<vector<char>> graph;
typedef pair<int,int> P;

int movi[4] = {-1, 1, 0, 0};
int movj[4] = {0, 0, -1, 1};

int min(vector<int> v){
	int min;
	if (v.empty()){
		cout << "ERROR: min(vector vacío)" << endl;
		return min;
	}
	min = v[0];
	for(int i; i < v.size(); i++){
		int x = v[i];
		if (min > x)
			min = x;
	}
	return min;
}

int shortest_path(graph &g, int x, int y){
	queue<pair<P,int>> C; C.push(make_pair(make_pair(r,c),0));
	g[r][c] = 'X';
	int counter;
	while (not C.empty()) {
    		pair<P,int> p = C.front(); C.pop();
		counter = p.second;
    		for (int i=0; i < 4; ++i) {
      			int r = (p.first).first + movi[i];
      			int c = (p.first).second + movj[i];
      			if (g[r][c] == 't') 
				return 1+counter;
      			else if (g[r][c] != 'X'){
	 			g[r][c] = 'X';
	 			C.push(make_pair(make_pair(r,c),1+counter));
      			}
		}	
	}
	return -1;
}

  
int pot(int a, int p){
	if (p <= 1) return a;
	else return a*pot(a,p-1);
}

int main(){
	float p,result;
	cin >> p;
	result = 0;
	for (float i = 1.0; i < p+0.5; i++){
		result += i*i*i;
	}
	float d = p*p*p*p;
	result = result/d;
	cout << result << endl;
	int n, m, u, v, c, x, y; cin >> n >> m;
	vector<int> v;
	graph g(n, v);
  	for (int i = 1; i <= m ; ++i) {
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = c;
    	}
	cin >> x >> y;
	int result = shortest_path(g,x,y); 
	if (result!= -1)
		cout << "minimum distance: " << result << endl;
	else
		cout << "no treasure can be reached" << endl;
