//============================================================================
// Name        : 4Graph.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class city
{
	int flag;
	float time;
	city *next;
public:
	string cname;
	friend class graph;
	city(string c)
	{
		cname=c;
		time=NULL;
		next=NULL;
		flag=0;
	}
};
 class queue
{
	city* data[20];
	int r,f;
public:
	queue()
{
		r=f=-1;
}
void initialize()
{
	r=f=-1;
}
int empty()
{
	if(r==-1)
		return (1);
	else
		return(0);
}
int full()
{
	if(r==20-1)
		return (1);
	else
		return(0);
}
void add(city *job)
{
	if(full())
	{
		cout<<"\nOverflow...";
    }
	else if(r==-1)
	{
		r=f=0;
	    data[r]=job;
	}
	else
    {
     r++;
     data[r]=job;
    }
}
city* remove()
{
	if(empty())
	{
		cout<<"\nUndererflow...";
	    return NULL;
	}
	city *x;
	x=data[f];
	if(r==f)
		initialize();
	else
		f++;
	return x;
}
};
class graph
{

	int n;
public:
    city *g[20];
	graph(int x)
  {
		n=x;
		string s;
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter city name";
		cin>>s;
		g[i]=new city(s);
	}
  }
   void create()
   {
	   city *temp,*node;
	   string s,d;
	   char ch;
	   float t;
	   do
	    {
		   cout<<"\nEnter source and destination";
		   cin>>s>>d;
		   cout<<"\nEnter time";
		   cin>>t;
		   temp=search(s);
		   node=search(d);
		   if(temp==NULL||node==NULL)
		   {
			   cout<<"\nInvalid city name";
			   return;
		   }
		   while(temp->next!=NULL)
			   temp=temp->next;
           city *node=new city(d);
           node->time=t;
		   temp->next=node;
		   cout<<"\nContinue...???";
		   cin>>ch;
		}while(ch=='y'||ch=='Y');
   }

   void BFS_traversal(city *v1)
   {
    for(int i=0;i<n;i++)
        g[i]->flag=0;
     queue q;
     city *temp,*node,*nx;
     q.add(v1);
     v1->flag=1;
     while(!q.empty())
     {
    	 node=q.remove();
    	 temp=node;
    	 cout<<node->cname<<"->";
     while(node->next!=NULL)
      {
         temp=temp->next;
          nx=search(temp->cname);
         if(nx->flag==0)
         {
             nx->flag=1;
        	 q.add(nx);
         }
         node=node->next;
      }
     }
   }
   city* search(string s)
   {
    for(int i=0;i<n;i++)
    {
        if(g[i]->cname==s)
            return g[i];
    }
    return NULL;
   }
void insertCity()
{
    string s;
    cout<<"\nEnter city name";
    cin>>s;
    g[n]=new city(s);
    n++;
    cout<<"\n City added";
}
void insertFlight()
{
    string s,d;
    city *temp,*node;
    float t;
    cout<<"\nEnter source and destination";
    cin>>s>>d;
    cout<<"\nEnter time";
    cin>>t;
    temp=search(s);
    while(temp->next!=NULL)
        temp=temp->next;
    node=new city(d);
    node->time=t;
    temp->next=node;
    cout<<"\nFlight added";
    return;
}
void del_city()
{
    string s;
    city *temp,*node;
    cout<<"\nEnter city to delete";
    cin>>s;
    for(int i=0;i<n;i++)
    {
        node=g[i];
        while(node->next!=NULL)
        {
            temp=node->next;
            if(temp->cname==s)
            {
                node->next=temp->next;
                delete(temp);
                break;
            }
            node=node->next;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(g[i]->cname==s)
        {
            while(i!=n-1)
            {
            g[i]=g[i+1];
            i++;
            }
            n--;
            return;
        }
    }
}
void del_flight()
{
    string s,d;
    city *temp,*node;
    float t;
    cout<<"\nEnter source and destination";
    cin>>s>>d;
    temp=search(s);
    while(temp->next->cname!=d)
        temp=temp->next;
    node=temp->next;
    temp->next=node->next;
    delete(node);
}
int indegree(city *t)
{
	city *temp,*node;
	int in=0;
	for(int i=0;i<n;i++)
	    {
	        node=g[i];
	        while(node->next!=NULL)
	        {
	            temp=node->next;
	            if(temp->cname==t->cname)
	            {
	              in++;
	            }
	            node=node->next;
	        }
	    }
	return in;
}
int outdegree(city *t)
{
	int out=0;
	while(t->next!=NULL)
	{
		out++;
		t=t->next;
	}
	return out;
}
void display()
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<g[i]->cname;
	}
}
void displayflights()
{
	city *temp,*node;
		for(int i=0;i<n;i++)
		    {
		        node=g[i];
		        while(node->next!=NULL)
		        {
		        	temp=node->next;
		        	cout<<"\n "<<g[i]->cname<<" --> "<<temp->cname<<" = "<<temp->time<<" hrs";
		            node=node->next;
		        }
		    }
}
void degree(city *t)
{
	int in,out;
	in=indegree(t);
	out=outdegree(t);
	cout<<"\nDegree of "<<t->cname<<"are "<<in+out;
}
};
int main()
{
	int ch,n,in,out;
	cout<<"\nEnter no of cities";
	cin>>n;
    graph gp(n);
    gp.create();
    string s;
    city *node;
    do{
     cout<<"\n1.Add new city\n2.Add new flight\n3.Display cities\n4.Remove city\n5.Remove flight";
     cout<<"\n6.Count flights to any city(indegree)\n7.Count flights from any city(outdegree)\n8.Traversal";
     cout<<"\n9.Display flights\n10.Degree (undirected)\n11.Quit";
        		cin>>ch;
        		switch(ch)
        		{
        		case 1:
        			gp.insertCity();
        			break;
        		case 2:
        			gp.insertFlight();
        		        break;
        		case 3:
        			    cout<<"\nCities are: ";
        			    gp.display();
        	            break;
        		case 4:
        			   gp.del_city();
        		       break;
        		case 5:
        			    gp.del_flight();
        		        break;
        		case 6:
        			cout<<"\nEnter city";
        			cin>>s;
        			node=gp.search(s);
        			in=gp.indegree(node);
        			cout<<"\nNo of flights for "<<node->cname<<" are "<<in;
        			break;
        		case 7:
        			cout<<"\nEnter city";
        			cin>>s;
        			node=gp.search(s);
        			out=gp.outdegree(node);
        			cout<<"\nNo of flights from "<<node->cname<<" are "<<out;
        			break;
        		case 8:
        		cout<<"\nEnter city to start traversal from";
        		cin>>s;
        		node=gp.search(s);
        		gp.BFS_traversal(node);
        		break;
        		case 9:
        			gp.displayflights();
        			break;
        		case 10:
        			cout<<"\nEnter city";
        			cin>>s;
        		    node=gp.search(s);
        			gp.degree(node);
        			break;
        		case 11:
        			cout<<"\n***END***";
        			break;
                }
        		}while(ch!=11);
	return 0;
}
