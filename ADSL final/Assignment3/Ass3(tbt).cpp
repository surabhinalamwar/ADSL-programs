#include<iostream>
using namespace std;
class tbt_node
{

    int lb,rb;
    tbt_node *lc,*rc;
public:
    int data;
    friend class tbt;
    tbt_node()
    {
      data=NULL;
      lc=NULL;
      rc=NULL;
      lb=rb=1;

    }
    tbt_node(int d)
    {
      data=d;
      lc=NULL;
      rc=NULL;
      lb=rb=1;
    }
};

class tbt
{
public:
tbt_node *root,*head;
    tbt()
    {
        root=NULL;
        head=new tbt_node();
        head->lc=head;
        head->rc=head;
        head->lb=head->rb=1;
    }
    void create();
    void insert(int);
    void LInsert(tbt_node*,tbt_node*);
    void RInsert(tbt_node*,tbt_node*);
    void tbt_inorder();
    void tbt_preorder();
    tbt_node* search_parent(int);
    tbt_node* search(int,tbt_node*);
    void tbt_del(tbt_node*,tbt_node*);
};
void tbt::create()
{
   tbt_node *p;
   if(head->data==NULL)
   {
   head->data=999;
   head->lc=root;
   head->rc=head;
   head->lb=0;
   head->rb=1;
   }
   else
   {
       cout<<"\nTree head is created";
   }
}
void tbt::insert(int x)
{
    tbt_node *temp,*p;
    char ans;
    if(root==NULL)
    {
    	p=new tbt_node(x);
    	root=p;
    	root->lc=head;
    	root->rc=head;
    	root->lb=root->rb=1;
    	head->lb=0;
    	return;
    }
    temp=root;
    while(true)
    {
        if(x<temp->data)
        {
          if(temp->lb==0)
           {
        	   temp=temp->lc;
           }
           else
           {
        	   p=new tbt_node(x);
        	   LInsert(temp,p);
        	   return;
           }
        }
        else if(temp!=head)
        {
        if(x>temp->data)
        {
        	 if(temp->rb==0)
        	 {
        	    temp=temp->rc;
        	 }
        	 else
        	 {
        	    p=new tbt_node(x);
        	    RInsert(temp,p);
        	    return;
        	 }
         }
        }
     }
}
void tbt::RInsert(tbt_node *s,tbt_node *t)
{
    t->rc=s->rc;
    t->lc=s;
    t->rb=s->rb;
    t->lb=1;
    s->rc=t;
    s->rb=0;
}
void tbt::LInsert(tbt_node *s,tbt_node *t)
{
    t->lc=s->lc;
    t->rc=s;
    t->lb=s->lb;
    t->rb=1;
    s->lc=t;
    s->lb=0;
}
void tbt::tbt_inorder()
{
   tbt_node *temp;
   temp=this->root;
    while(temp!=head)
    {
        while(temp->lb!=1)
            temp=temp->lc;
        while(temp->rb!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->rc;
            if(head==temp)
            return;
        }
        if(head==temp)
           break;
        cout<<temp->data<<" ";
        temp=temp->rc;
    }
}
void tbt::tbt_preorder()
{
   tbt_node *temp;
   temp=this->root;
   while(true)
   {
       if(head==temp)
        return;
       cout<<temp->data<<" ";
       if(temp->lb==0)
       {
        temp=temp->lc;
       }
       else if(temp->rb==0)
       {
        temp=temp->rc;
       }
       else
        {
            while(temp->rb!=0)
            {
               temp=temp->rc;
               if(head==temp)
                 return;
            }
            temp=temp->rc;
        }
   }
}
tbt_node* tbt::search(int w,tbt_node *t)
{
	if(t==NULL)
		return NULL;
	if(t->data==w)
		return t;
	if(t->data>w)
		return (search(w,t->lc));
	else
		return (search(w,t->rc));
}

tbt_node* tbt::search_parent(int x)
{
  if(x==root->data)
  {
      tbt_node *p=new tbt_node(NULL);
      return p;
  }
  tbt_node *temp=this->root;
  while(1)
  {
      if(temp->data>x)
      {
          if(temp->lc->data==x)
            return temp;
          else
            temp=temp->lc;
      }
      else
      {
          if(temp->rc->data==x)
            return temp;
          else
            temp=temp->rc;
      }
  }
}
void tbt::tbt_del(tbt_node *p,tbt_node *t)
{
  if(t->lb==0&&t->rb==0)
  {
      p=t;
      tbt_node *cs=t->rc;
      while(cs->lb!=1)
      {
          p=cs;
          cs=cs->lc;
      }
      t->data=cs->data;
      t=cs;
  }
  if(t->lb==1||t->rb==1)
  {
      if(p->lb==0)
      {
          p->lc=t->lc;
          p->lb=1;
      }
      else
      {
         p->rc=t->rc;
         p->rb=1;
      }
      delete(t);
  }
}
int main()
{
    tbt tt;
    int ch,no;
    tbt_node *p,*n;
    tt.create();

       do{
    		cout<<"\n1.Insert\n2.Display inorder\n3.Display preorder\n4.Delete element\n5.Quit";
    		cin>>ch;
    		switch(ch)
    		{
    		case 1:
    			cout<<"\nEnter data";
    			cin>>no;
    			tt.insert(no);
    			break;
    		case 2:  cout<<"\n Inorder: ";
    		         tt.tbt_inorder();
    		        break;
    		case 3:
    			    cout<<"\n Preorder: ";
    			    tt.tbt_preorder();
    	            break;
    		case 4: cout<<"\n Enter data you want to delete ";
    			    cin>>no;
    			    n=tt.search(no,tt.root);
    			    p=tt.search_parent(no);
    			    tt.tbt_del(p,n);
    			    cout<<endl;
    			    tt.tbt_inorder();
    		        break;
    		case 5:
    		        break;
            }
    		}while(ch!=5);
       return 0;
}
