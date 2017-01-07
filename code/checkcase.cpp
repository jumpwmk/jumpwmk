/*
For check task: Modulo Six
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <fstream>

using namespace std;

struct pt
{
	int a, b;
};

fstream input_file, key_file, ans_file;

int aa,bb;
int searchja;
int cntt = 1;

void correct(){
	cout << "$#1";
	exit(0);
}

void wrong(){
	cout << "$#0";
	exit(0);
}

void prepareData(){
	string key, ans;
	// cin >> key;
	// cin >> ans;
	key = "key.sol";
	ans = "ans.sol";
	key_file.open(key.c_str());
	ans_file.open(ans.c_str());
}

vector<int > x[30010];
int chk[30030];

void dfs(int ii)
{
	if(chk[ii] == cntt)
		return;
	chk[ii] = cntt;
	searchja++;
	for(int i = 0; i < x[ii].size(); i++)
	{
		if( ii == aa && i == bb )
			continue;
		dfs(x[ii][i]); 
	}
}

int main()
{
	int n,m,ans,key;
	prepareData();

	key_file >> m;
	ans_file >> ans;

	key_file >> n;

	if(m != ans)
		wrong();

	while(not key_file.eof())
	{
		int a, b;
		key_file >> a;
		key_file >> b;
		x[a].push_back(b);
		x[b].push_back(a);
	}


	int cnt = 0;
	while(not ans_file.eof())
	{
		int a, b;
		cnt++;
		ans_file >> a;
		ans_file >> b;
		// cout << a << " " << b << endl;
		if(a < 1 || a > n || b < 1 || b > n)
			wrong();
		x[a].push_back(b);
		x[b].push_back(a);
		if(cnt == m)
			break;
	}
	// cout << "cnt " << cnt << endl;

	if(cnt != m)
		wrong();

	for(int i = 1; i <= n; i++)
	{
		for(int k = 0; k < x[i].size(); k++)
		{
			searchja = 0;
			aa = i, bb = k;
			dfs(1);
			cntt++;
			if(searchja != n)
				wrong();
		}
	}

	correct();

	return 0;
}
