
#include <iostream>
#include<string.h>
using namespace std;

class dictionary
{
  char word[20],mean[20];
  dictionary *lc,*rc;
public:
	friend class BST;
	friend class stack;
	dictionary(char x[],char y[])
	{
		strcpy(word,x);
		strcpy(mean,y);
		lc=rc=NULL;
	}
};

class stack
{
	dictionary* st[30];
	int top;
public:
	stack()
{
		top=-1;
}
void push(dictionary* d)
{
	top++;
	st[top]=d;
}
dictionary* pop()
{
	dictionary* x=st[top];
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
class BST
{

public:
	dictionary *root;
	BST()
{
		root=NULL;
}
	dictionary* insert (char[],char[],dictionary*);
	void inorder(dictionary*);
	BST* operator =(BST*);
	dictionary* del_word(char[],dictionary*);
	void update(char*,dictionary*);
	dictionary* search(char[],dictionary*);
	void reverse(dictionary*);
	dictionary* searchP(dictionary*,dictionary*);
};
dictionary* BST::insert(char w[],char m[],dictionary *t)
{
	dictionary *p;
	if(t==NULL)
	{
		p=new dictionary(w,m);
		t=p;
	    return(t);
	}
	else
	{
        if(strcmp(w,t->word)==1)
        	t->rc=insert(w,m,t->rc);
        else
        	t->lc=insert(w,m,t->lc);
		return t;
	}
}
dictionary* BST::search(char w[],dictionary *t)
{
	if(t==NULL)
		return NULL;
	if(strcmp(t->word,w)==0)
		return t;
	if(strcmp(t->word,w)==1)
		return (search(w,t->lc));
	else
		return (search(w,t->rc));
}
dictionary* BST::del_word(char w[],dictionary *t)
{
	dictionary *temp;
if(t==NULL)
  return t;
if(strcmp(t->word,w)==1)
{
	t->lc=del_word(w,t->lc);
	return t;
}
if(strcmp(w,t->word)==1)
{
	t->rc=del_word(w,t->rc);
	return t;
}

   if(t->lc==NULL&&t->rc==NULL)
  {
	temp=t;
	delete temp;
	return NULL;
  }
   if(t->lc==NULL)
   {
	temp=t;
	t=t->rc;
	delete temp;
	return t;
   }
  if(t->rc==NULL)
  {
	temp=t;
	t=t->lc;
	delete temp;
	return t;
  }
   temp=t->rc;
   while(temp->lc!=NULL)
        temp=temp->lc;
   strcpy(t->word,temp->word);
   strcpy(t->mean,temp->mean);
   t->rc=del_word(temp->word,t->rc);
   return t;

}
void BST::inorder(dictionary *t)
{
	if(t==NULL)
    return;
	inorder(t->lc);
	cout<<t->word<<" = "<<t->mean<<"\n";
	inorder(t->rc);
}
void BST::reverse(dictionary *t)
{
    if(t==NULL)
     return;
	inorder(t->rc);
	cout<<t->word<<" = "<<t->mean<<"\n";
	inorder(t->lc);

}
void BST::update(char w[],dictionary *t)
{
	dictionary *p;
	char n[20];
	p=search(w,t);
	if(p==NULL)
	{
		cout<<"\nWord not found";
	    return;
	}
	cout<<"\nEnter new meaning ";
	cin>>n;
	strcpy(p->mean,n);
	return;
}
BST* BST::operator=(BST *t)
{
	BST *lt,*rt,*t1,*t2;
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

int main() {

	BST bt,bt2;
		int ch;
		char a[20],b[20];
		do{
		cout<<"\n1.Insert word\n2.Display ascending\n3.Display descending\n4.Update meaning\n5.Delete word";
		cout<<"\n6.Copy tree\n7.Quit";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nEnter word ";
			cin>>a;
			cout<<"\nEnter meaning ";
			cin>>b;
			bt.root=bt.insert(a,b,bt.root);
			break;
		case 2:  cout<<"\n Ascending : ";
			    bt.inorder(bt.root);
		        break;
		case 3:
			    cout<<"\n Descending : ";
			    bt.reverse(bt.root);
	            break;
		case 4: cout<<"\n Enter word you want to update  ";
			    cin>>b;
			    bt.update(b,bt.root);
			    bt.inorder(bt.root);
		        break;
		case 5: cout<<"\n Enter word you want to delete  ";
	            cin>>b;
	            bt.root=bt.del_word(b,bt.root);
	            bt.inorder(bt.root);
		        break;
		case 6: bt2=bt;
		        cout<<"\nCopied Tree Is :";
		        bt2.inorder(bt2.root);
		        break;
		case 7:
		        break;


		}
		}while(ch!=7);
	return 0;
}
