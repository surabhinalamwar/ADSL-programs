//============================================================================
// Name        : 5Graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class edge
{
	int c,s,d;
public:
	edge(int x,int y,int z)
	{
		c=x;
		s=y;
		d=z;
	}
	friend class graph;
};
class office
{
	int flag,ofno;
public:
	office(int n)
    {
		ofno=n;
		flag=0;
    }
	friend class graph;
};
class graph
{
	int n;
public:
	office *g[20];
	int adj[20][20];
	graph(int x)
	  {
			n=x;
			int s;
		for(int i=0;i<n;i++)
		{
			cout<<"\n Enter office number";
			cin>>s;
			g[i]=new office(s);
		}
	  }
	void create()
	{
		int s,d,c;
		char ans='y';
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				adj[i][j]=0;
		}
		while(ans=='y'||ans=='Y')
		{
		cout<<"\nEnter source and destination office no. ";
		cin>>s>>d;
		cout<<"\nEnter cost of communication";
		cin>>c;
		adj[s-1][d-1]=c;
		adj[d-1][s-1]=c;
		cout<<"\nContinue..??";
		cin>>ans;
		}
	}
	void print_adj()
	{
		cout<<"\n";
		for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
						cout<<" "<<adj[i][j];
					cout<<"\n";
				}
	}
	void display()
	{
		for(int i=0;i<n;i++)
		{

		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(adj[i][j]!=0)
				cout<<"\n office"<<i+1<<"--> office"<<j+1<<" = "<<adj[i][j];
			}
	   }
	}
	void prims_algo(int v)
	{
		int count=0,count1=0,visited[20],min=999,cost=0;
		int res[20][20],t1,t2,t3,found=0,found2=0,v1;
		visited[count1]=v;
		count1++;
		while(count<n-1)
		{
			min=999;
			found=found2=0;
			for(int i=0;i<count1;i++)
			{
				v1=visited[i]-1;
				for(int v2=0;v2<n;v2++)
				{
					if(adj[v1][v2]!=0)
					{
						if(min>adj[v1][v2])
						{
							min=adj[v1][v2];
							t1=visited[v1];
							t2=v2+1;
							t3=v1+1;
						}
					}
				}
		   }
			for(int temp=0;temp<count1;temp++)
			{
			  if(visited[temp]==t2)
					found=1;
			  if(visited[temp]==t3)
					found2=1;
			}
			if(found==0||found2==0)
			{
				res[t3-1][t2-1]=res[t2-1][t3-1]=min;
				cost=cost+res[t3-1][t2-1];
				count++;
				visited[count1]=t2;
				count1++;
				;adj[t1][t2]=adj[t2][t1]=0;
			}
		}
		  cout<<"\n";
		  for(int i=0;i<n;i++)
		  {
			for(int j=0;j<n;j++)
				cout<<" "<<res[i][j];
				cout<<"\n";
		 }
		  cout<<"\nMinimum cost = "<<cost;

	}
	void kruskal_algo()
	{
		edge *ed[10],*temp;
		int k=0,visited[20],mincost=0;
		 for(int i=0;i<n;i++) //collect costs in one array
		 {
			for(int j=0;j<n;j++)
			{
				if(adj[i][j]!=0)
				{
				ed[k]=new edge(adj[i][j],i+1,j+1);
				k++;
				}
			}
		 }
		 for(int i=0;i<k;i++) // sort edges
		 {
		   for(int j=0;j<k-1;j++)
		   {
		    if(ed[j]->c>ed[j+1]->c)
		    {
		     temp=ed[j];
		     ed[j]=ed[j+1];
		     ed[j+1]=temp;
		    }
		   }
		 }
		int i=0,count=0,found=0,found2=0;
		while(k!=0)
		{
			found=found2=0;
			for(int temp=0;temp<count;temp++)
			{
			  if(visited[temp]==ed[i]->s)
					found=1;
			  if(visited[temp]==ed[i]->d)
					found2=1;
			}
			if(found==0&&found2==0)
			{
				visited[count]=ed[i]->s;
				count++;
				visited[count]=ed[i]->d;
				count++;
				cout<<"\n"<<ed[i]->s<<"-->"<<ed[i]->d<<" = "<<ed[i]->c;
				mincost=mincost+ed[i]->c;
				k--;
			}
			else if(found==0&&found2==1)
			{
				visited[count]=ed[i]->s;
				count++;
				cout<<"\n"<<ed[i]->s<<"-->"<<ed[i]->d<<" = "<<ed[i]->c;
				mincost=mincost+ed[i]->c;
				k--;
			}
			else if(found==1&&found2==0)
			{
				visited[count]=ed[i]->d;
				count++;
				cout<<"\n"<<ed[i]->s<<"-->"<<ed[i]->d<<" = "<<ed[i]->c;
				mincost=mincost+ed[i]->c;
				k--;
			}
			else if(found==1&&found2==1)
				k--;
			i++;
		}
		 cout<<"\nMinimum cost="<<mincost;
	}
};
int main() {
    graph ph(5);
    ph.create();
    ph.print_adj();
    ph.display();
    //ph.prims_algo(1);
    ph.kruskal_algo();
	return 0;
}
