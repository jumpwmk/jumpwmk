#include <iostream>

using namespace std;

class node {
public:
	int type;
	char ch;
	node *left, *right;

	node (int _type, char _ch, node *_left, node *_right) :
		type(_type), ch(_ch), left(_left), right(_right) {}
};

string str;
int idx = 0;

node* getNodeFromStr(void) {
	if ('a' <= str[idx] and str[idx] <= 'z') {
		return new node(0, str[idx++], nullptr, nullptr);
	}
	if ('A' <= str[idx] and str[idx] <= 'Z') {
		return new node(1, str[idx++], getNodeFromStr(), nullptr);
	}
	return new node(2, str[idx++], getNodeFromStr(), getNodeFromStr());
}
string getStrFromNode(node *n) {
	if (n == nullptr) return "";
	return string(1, n->ch) + getStrFromNode(n->left) + getStrFromNode(n->right);
}
node* dfs_replace(char ch, node *n, node *rep) {
	if (n->type == 0) return (n->ch-'a' == ch-'A' ? new node(rep->type, rep->ch, rep->left, rep -> right): n);
	if (n->type == 1) {
		if (n->ch == ch) {
			return n;
		}
		return new node(n->type, n->ch, dfs_replace(ch, n->left, rep), nullptr);
	}
	return new node(n->type, n->ch, dfs_replace(ch, n->left, rep), dfs_replace(ch, n->right, rep));
}
node* reduce(node *n) {
	if (n->type == 0) return n;
	if (n->type == 1) {
		return new node(n->type, n->ch, reduce(n->left), nullptr);
	}
	node *left = n->left, *right = n->right;
	right = reduce(right);
	if (left->type == 1) {
		return reduce(dfs_replace(left->ch, left->left, right));
	} else {
		node *result = new node(n->type, n->ch, reduce(left), reduce(right));
		if (result->left->type == 1) return reduce(result);
		return result;
	}
}

int main(void) {
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	cin >> str;

	node *ans = reduce(getNodeFromStr());
	cout << getStrFromNode(ans) << endl;
	
	return 0;
}
