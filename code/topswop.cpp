#include <stdio.h>
#include <algorithm>
#define INF 1000000000

using namespace std;

struct pt
{
	int i,size,mark;
	pt *l,*r,*parent;
};

pt *head,*node;
int m;

void checkchild(pt *tmp)
{
	tmp -> size = 0;
	if(tmp -> l != NULL)
		tmp->size += tmp->l->size;
	if(tmp -> r != NULL)
		tmp->size += tmp->r->size;
	tmp->size++;
}

void rotateright(pt *tmp)
{
	pt *child = tmp -> l;
	child -> parent = tmp -> parent;
	int sizetmp = 1;
	checkchild(tmp);
	checkchild(child);
	child -> size = tmp -> size;
	if(child -> r != NULL)
		sizetmp += child -> r -> size;
	if(tmp -> r != NULL)
		sizetmp += tmp -> r -> size;
	tmp -> size = sizetmp;
	if(tmp->parent != NULL)
	{
		if(tmp->parent->r == tmp)
			tmp -> parent -> r = child;
		else
			tmp -> parent -> l = child;
	}
	tmp -> l = child -> r;
	if(child -> r != NULL)
		child -> r -> parent = tmp;
	tmp -> parent = child;
	child -> r = tmp;
}

void rotateleft(pt *tmp)
{
	pt *child = tmp -> r;
	int sizetmp = 1;
	checkchild(tmp);
	checkchild(child);
	child -> size = tmp -> size;
	if(child -> l != NULL)
		sizetmp += child -> l -> size;
	if(tmp -> l != NULL)
		sizetmp += tmp -> l -> size;
	tmp -> size = sizetmp;
	child -> parent = tmp -> parent;
	if(tmp->parent != NULL)
	{
		if(tmp->parent->r == tmp)
			tmp -> parent -> r = child;
		else
			tmp -> parent -> l = child;
	}
	tmp -> r = child -> l;
	if(child -> l != NULL)
		child -> l -> parent = tmp;
	tmp -> parent = child;
	child -> l = tmp;
}

void splay(pt *tmp)
{
	while(tmp->parent != NULL)
	{
		if(tmp -> parent -> parent == NULL)
		{
			if(tmp -> parent -> r == tmp)
				rotateleft(tmp->parent);
			else rotateright(tmp->parent);
		}
		else
		{
			if(tmp->parent->r == tmp)
			{
				if(tmp->parent->parent->r == tmp->parent)
				{
					rotateleft(tmp->parent->parent);
					rotateleft(tmp->parent);
				}
				else
				{
					rotateleft(tmp->parent);
					rotateright(tmp->parent);
				}
			}
			else
			{
				if(tmp->parent->parent->l == tmp->parent)
				{
					rotateright(tmp->parent->parent);
					rotateright(tmp->parent);
				}
				else
				{
					rotateright(tmp->parent);
					rotateleft(tmp->parent);
				}
			}
		}
	}
}

void creatsplaytree(pt *tmp)
{
	if(tmp -> r == NULL)
	{
		node -> parent = tmp;
		tmp -> r = node;
		tmp -> size++;
		node -> size = 1;
		node -> mark = 0;
		splay(node);
		return ;
	}
	creatsplaytree(tmp -> r);
}

void find(pt *tmp)
{
	if(tmp -> mark == 1)
	{
		tmp -> mark = 0;
		swap(tmp->l,tmp->r);
		if(tmp->l != NULL)
			tmp->l->mark = 1;
		if(tmp->r != NULL)
			tmp->r->mark = 1;
	}
	if(tmp -> l == NULL)
	{
		splay(tmp);
		head = tmp;
		return;
	}
	find(tmp->l);
}

void findm(pt *tmp)
{
	if(tmp -> mark == 1)
	{
		tmp -> mark = 0;
		swap(tmp->l,tmp->r);
		if(tmp->l != NULL)
			tmp->l->mark = 1;
		if(tmp->r != NULL)
			tmp->r->mark = 1;
	}
	if(tmp -> l != NULL)
	{
		if(m <= tmp->l->size)
		{
			findm(tmp->l);
			return;
		}
		m -= tmp->l->size;
	}
	if(m == 1)
	{
		splay(tmp);
		head = tmp;
		return;
	}
	m--;
	if(tmp -> r != NULL)
	{
		findm(tmp->r);
		return;
	}
}

void read(pt *tmp)
{
	if(tmp -> mark == 1)
	{
		tmp -> mark = 0;
		swap(tmp->l,tmp->r);
		if(tmp->l != NULL)
			tmp->l->mark = 1;
		if(tmp->r != NULL)
			tmp->r->mark = 1;
	}
	if(tmp -> l != NULL){
		// printf("L\n");
		read(tmp->l);
	}
	printf(" %d\n",tmp->i);
	if(tmp -> r != NULL)
	{
		// printf("R\n");
		read(tmp->r);
	}
	// printf("B\n");
}

int main()
{
	int i,j,n,cnt = 0;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	head = new pt;
	head -> size = 1;
	head -> i = m;
	head -> mark = 0;
	head -> r = head -> l = head -> parent = NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&m);
		node = new pt;
		node -> r = node -> l = node -> parent = NULL;
		node -> i = m;
		creatsplaytree(head);
		head = node;
	}
	while(1)
	{
		find(head);
		// printf("%d\n",head->i);
		cnt++;
		if(head->i == 1)
			break;
		if(head->i == n)
		{
			head -> mark = 1;
			// read(head);
			continue;
		}
		m = head->i + 1;
		findm(head);
		if(head->l != NULL)
			head->l->mark = 1;
		// read(head);
	}
	printf("%d\n",cnt-1);
	return 0;
}