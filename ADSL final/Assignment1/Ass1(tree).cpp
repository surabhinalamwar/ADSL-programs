

//============================================================================
// Name        : tree.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
	int data;
	node *lc,*rc;
public:
	friend class tree;
	friend class stack;
	node(int x)
	{
		data=x;
		lc=rc=NULL;
	}
};

class stack
{
	node* st[30];
	int top;
public:
	stack()
{
		top=-1;
}
void push(node* d)
{
	top++;
	st[top]=d;
}
node* pop()
{
	node* x=st[top];
	top--;
	return (x);
}
int empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
};

class flag
{
	bool st[30];
	int top;
public:
	flag()
{
		top=-1;
}
void push(bool x)
{
	top++;
	st[top]=x;
}
bool pop()
{
	bool x=st[top];
	top--;
	return (x);
}
bool empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
};

class tree
{

public:
	node *root;
	tree()
{
		root=NULL;
}
	void create();
	node* insert (int,node*);
	void inorder(node*);
	void preorder(node*);
	void preorder2(node*);
	void postorder(node*);
	void postorder2(node*);
	void mirror(node*);
	node* mirror2(node*);
	int height(node*);
	tree* operator =(tree*);
	void del_tree(node*);
	int count_leaf(node*);
	int count_internal(node*);
};

void tree::create()
{
	root=insert(100,root);
	cout<<"\n Created";
}

node* tree::insert(int x,node *t)
{
	node *p;
	if(t==NULL)
	{
		p=new node(x);
	    return(p);
	}
	else
	{
		char ans;
		cout<<"\n where you want to insert "<<x<<" on left or right(l/r)"<<t->data;
		cin>>ans;
		if(ans=='l'|| ans=='L')
			t->lc=insert(x,t->lc);
		else
			t->rc=insert(x,t->rc);
		return t;
	}
}

void tree::inorder(node *t)
{
	if(t==NULL)
		return;
	inorder(t->lc);
	cout<<t->data<<" ";
	inorder(t->rc);
}
void tree::preorder(node *t)
{
	if(t==NULL)
	  return;
	cout<<t->data<<" ";
	preorder(t->lc);
	preorder(t->rc);

}
void tree::postorder(node *t)
{
	if(t==NULL)
	  return;
	postor1der(t->lc);
	postorder(t->rc);
	cout<<t->data<<" ";

}

void tree::preorder2(node *t)
{
	stack s;
			while(t!=NULL)
			{
				s.push(t);
				cout<<" "<<t->data;
				t=t->lc;
			}
			while(!s.empty())
			{
			    t=s.pop();
			    t=t->rc;
			           while(t!=NULL)
			    			{
			    				s.push(t);
			    				cout<<" "<<t->data;
			    				t=t->lc;
			    			}


			}

}

void tree::postorder2(node* t)
{
	stack s;
	flag f;
	bool a;
	node* b;
	while(1)
	{
		while(t!=NULL)
		{
			s.push(t);
			f.push(0);
			t=t->lc;
		}
		if(!s.empty())
		{
			b=s.pop();
			a=f.pop();
		}
		else
        {
            return;
        }
		while(a==1)
		{
			cout<<" "<<b->data;
		    if(!s.empty())
		    {
			b=s.pop();
		    a=f.pop();
		    }
		    else
            {
		    	return;
            }
        }
		if(a==0)
		{
		s.push(b);
	    f.push(1);
		t=b->rc;
		}
	}

}

void tree::mirror(node *t)
{
	node *temp;
	if(t!=NULL)
	{
		mirror(t->lc);
	    mirror(t->rc);
	    temp=t->lc;
	    t->lc=t->rc;
	    t->rc=temp;
	}
}
node* tree::mirror2(node *t)
{
	node *temp;
	if(t!=NULL)
	{
		temp=new node(t->data);
		temp->lc=mirror2(t->rc);
	    temp->rc=mirror2(t->lc);
	    return temp;
	}
	else
		return NULL;
}
int tree::count_leaf(node *t)
{
    int l1,l2;
	if(t==NULL)
		return 0;
    if(t->lc==NULL&&t->rc==NULL)
    {
    return(1);
    }
    l1=count_leaf(t->lc);
    l2=count_leaf(t->rc);
    return(l1+l2);
}
int tree::count_internal(node *t)
{
    int l1,l2;
	if(t==NULL)
		return 0;
	 if(t->lc==NULL&&t->rc==NULL)
	    return 0;
    if(t->lc!=NULL||t->rc!=NULL)
    {
     l1=count_internal(t->lc);
     l2=count_internal(t->rc);
     return(l1+l2+1);
    }
}

int tree::height(node *t)
{
	int h1,h2;
	if(t==NULL)
		return 0;
	if(t->lc==NULL&&t->rc==NULL)
		return 0;
	h1=height(t->lc);
	h2=height(t->rc);
	if(h1>h2)
		return (h1+1);
	else
		return (h2+1);
}

tree* tree::operator=(tree *t)
{
	tree *lt,*rt,*t1,*t2;
		if(t!=NULL)
		{
			this->root=t->root;
			lt->root=t->root->lc;
			rt->root=t->root->rc;
			t1=lt;
			t2=rt;
			this->root->lc=lt->root;
		    this->root->rc=rt->root;
		    return this;
		}
		else
			return NULL;
}

void tree::del_tree(node* t)
{
	stack s;
	flag f;
	int a;
	node* b;
	while(1)
	{
		while(t!=NULL)
		{
			s.push(t);
			f.push(0);
			t=t->lc;
		}
		if(!s.empty())
		{
			b=s.pop();
			a=f.pop();
		}
		else
        {
            return;
        }

		while(a==1)
		{
			delete(b);
		    if(!s.empty())
		    {
			b=s.pop();
		    a=f.pop();
		    }
		    else
            {
		    	return;
            }
		}
		if(a==0)
		{
		s.push(b);
	    f.push(1);
		t=b->rc;
		}
	}
}

int main() {

	tree tr,t2;
	int ch,x;
	tr.create();
	tr.insert(80,tr.root);
	tr.insert(180,tr.root);
	tr.insert(200,tr.root);
	tr.insert(50,tr.root);
	do{
	cout<<"\n1.Insert\n2.Display\n3.Preorder Recursive\n4.Preorder\n5.Postorder recursive\n6.Postorder";
	cout<<"\n7.Mirror\n8.Height\n9.Copy tree\n10.Count leaf nodes\n11.Count internal nodes\n12.Delete\n13.Quit";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"\nEnter data ";
		cin>>x;
		tr.insert(x,tr.root);
		break;
	case 2:  cout<<"\n Tree is: ";
		    tr.inorder(tr.root);
	        break;
	case 3:
		    cout<<"\n Preorder Tree is: ";
		    tr.preorder(tr.root);
            break;
	case 4: cout<<"\n Preorder Tree is: ";
		    tr.preorder2(tr.root);
	        break;
	case 5: cout<<"\n Postorder Tree is: ";
	        tr.postorder(tr.root);
	        break;
	case 6: cout<<"\n Postorder Tree is: ";
	        tr.postorder2(tr.root);
	        break;
	case 7: t2.root=tr.mirror2(tr.root);
	        cout<<"\n Mirrored Tree is: ";
		    t2.inorder(t2.root);
	        break;
	case 8: cout<<"\n Height of Tree is: "<<tr.height(tr.root);
	        break;
	case 9: t2=tr;
	        cout<<"\n Copied Tree is: ";
	        t2.inorder(t2.root);
	        break;
    case 10: cout<<"\nNo.of leaf nodes "<<tr.count_leaf(tr.root);
             break;
    case 11: cout<<"\nNo.of internal nodes "<<tr.count_internal(tr.root);
             break;
	case 12: tr.del_tree(tr.root);
	         cout<<"\nTree deleted";
	         break;
    case 13:
            break;
	}
	}while(ch!=13);
	return 0;
}
