#include <stdio.h>
#include <algorithm>
#define INF 1000000000

using namespace std;

struct pt
{
	int i,size;
	pt *l,*r,*parent;
};

int cmd,m;
pt *node,*head[300100];
char str[20];

int checksize(pt *tmp)
{
	int cnt = 0;
	if(tmp -> l != NULL)
		cnt += tmp -> l -> size;
	if(tmp -> r != NULL)
		cnt += tmp -> r -> size;
	cnt++;
	return cnt;
}

void rotateleft(pt *tmp)
{
	pt *child = tmp -> r;
	child -> parent = tmp -> parent;
	if(tmp -> parent != NULL)
	{
		if(tmp -> parent -> r == tmp)
			tmp -> parent -> r = child;
		else tmp -> parent -> l = child;
	}
	tmp -> r = child -> l;
	if(child -> l != NULL)
		child -> l -> parent = tmp;
	child -> l = tmp;
	tmp -> parent = child;
	tmp -> size = checksize(tmp);
	child -> size = checksize(child);
}

void rotateright(pt *tmp)
{
	pt *child = tmp -> l;
	child -> parent = tmp -> parent;
	if(tmp -> parent != NULL)
	{
		if(tmp -> parent -> r == tmp)
			tmp -> parent -> r = child;
		else tmp -> parent -> l = child;
	}
	tmp -> l = child -> r;
	if(child -> r != NULL)
		child -> r -> parent = tmp;
	child -> r = tmp;
	tmp -> parent = child;
	tmp -> size = checksize(tmp);
	child -> size = checksize(child);
}

void splay(pt *tmp)
{
	while(tmp -> parent != NULL)
	{
		if(tmp -> parent -> parent == NULL)
		{
			if(tmp -> parent -> r == tmp)
				rotateleft(tmp -> parent);
			else rotateright(tmp -> parent);
		}
		else
		{
			if(tmp -> parent -> r == tmp)
			{
				if(tmp -> parent -> parent -> r == tmp -> parent)
				{
					rotateleft(tmp -> parent -> parent);
					rotateleft(tmp -> parent);
				}
				else
				{
					rotateleft(tmp -> parent);
					rotateright(tmp -> parent);
				}
			}
			else
			{
				if(tmp -> parent -> parent -> l == tmp -> parent)
				{
					rotateright(tmp -> parent -> parent);
					rotateright(tmp -> parent);
				}
				else
				{
					rotateright(tmp -> parent);
					rotateleft(tmp -> parent);
				}
			}
		}
	}
}

void play(pt *tmp,int b)
{
	if(tmp -> i > node -> i && tmp -> l == NULL)
	{
		tmp -> l = node;
		tmp -> size++;
		node -> parent = tmp;
		splay(node); 
		head[b] = node;
		return;
	}
	if(tmp -> i < node -> i && tmp -> r == NULL)
	{
		tmp -> size++;
		tmp -> r = node;
		node -> parent = tmp;
		splay(node);
		head[b] = node;
		return;
	}
	if(tmp -> i > node -> i)
		play(tmp->l,b);
	else play(tmp->r,b);
}

void read(pt *tmp,int b)
{
	if(tmp -> l != NULL)
		read(tmp -> l,b);
	node = new pt;
	node -> i = tmp -> i;
	node -> l = node -> r = node -> parent = NULL;
	play(head[b],b);
	if(tmp -> r != NULL)
		read(tmp -> r,b);
}

int find(pt *tmp,int m)
{
	if(tmp -> l != NULL)
	{
		if(m <= tmp -> l -> size)
			return find(tmp -> l,m);
		m -= tmp -> l -> size;
	}
	if(m == 1)
		return tmp -> i;
	m--;
	return find(tmp->r,m);
}

void merge(int a,int b)
{
	if(head[a] -> size > head[b] -> size)
		swap(a,b);
	read(head[a],b);
	head[a] = NULL;
	head[m] = head[b];
	head[b] = NULL;
}

void read2(pt *tmp)
{
	if(tmp -> l != NULL)
		read2(tmp -> l);
	printf("%d\n",tmp->i);
	if(tmp -> r != NULL)
		read2(tmp -> r);
}

int main()
{
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	int i,j,n,q,a,b;
	scanf("%d",&n);
	scanf("%d",&q);
	for(i=1;i<=n;i++)
	{
		head[i] = new pt;
		head[i] -> i = i;
		head[i] -> size = 1;
		head[i] -> r = head[i] -> l = head[i] -> parent = NULL;
	}
	m = n+1;
	while(q--)
	{
		scanf(" %s %d %d",str,&a,&b);
		if(str[0] == 'G')
		{
			printf("%d\n",find(head[a],b));
		}
		else
		{
			merge(a,b);
			m++;
		}
	}
	return 0;
}