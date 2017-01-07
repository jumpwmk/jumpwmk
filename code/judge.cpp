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

fstream input_file, key_file, ans_file;
string key, ans;

void correct(){
	cout << "$#1";
	exit(0);
}

void wrong(){
	cout << "$#0";
	exit(0);
}

void prepareData(){
	cin >> key;
	cin >> ans;
	key_file.open(key.c_str());
	ans_file.open(ans.c_str());
}

int getInt(string x){
    int num=0;
    for(int i=0; i<x.length(); i++){
        num=10*num+x[i]-'0';
    }
    return num;
}

vector<string> key_arr, ans_arr;

int main()
{
	prepareData();

	while(not key_file.eof())
	{
		key_file >> key;
		key_arr.push_back(key);
	}

	while(not ans_file.eof())
	{
		ans_file >> ans;
		ans_arr.push_back(ans);
	}

    key_arr.erase(key_arr.end()-1);
    ans_arr.erase(ans_arr.end()-1);

	if(ans_arr.size() == 1)
	{
		ans = ans_arr[0];
		int corr = getInt(key_arr[0]);
		int n = getInt(key_arr[1]);
		int s = getInt(key_arr[2]);
		if(corr == 0)
        {
            if(ans=="-1") correct();
            else wrong();
        }
		if(ans.length() == n)
        {
            for(int i=0; i<n; i++){
                if(not isdigit(ans[i]))
                    wrong();
            }
            if(ans[n-1]&1) wrong();
            if(ans[0] == '0') wrong();
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += ans[i] - '0';
            }
            if(sum == s) correct();
            else wrong();
		}

		wrong();
	}

	wrong();

	return 0;
}
