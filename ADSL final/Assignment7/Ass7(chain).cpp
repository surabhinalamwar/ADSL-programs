//============================================================================
// Name        : 7chain.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 2
class variable
{
	string name,type;
	int value,flag,chain;
public:
	variable()
	{
		name=" ";
		type=" ";
		value=flag=0;
		chain=-1;
	}
	variable(string n,string t,int v)
	{
		name=n;
		type=t;
		value=v;
		flag=0;
		chain=-1;
	}
	friend class symbolTable;
};
class symbolTable
{
	variable key[10];
	public:
		symbolTable()
		{
	      create();
		}
		 void create()
	    {
	      string a,b;
	      int v;
	       for(int i=0;i<10;i++)
	       {
	    	   key[i].flag=0;
	       }
			for(int j=0;j<MAX;j++)
			  {
				cout<<"\nEnter name of variable";
				cin>>a;
				cout<<"\nEnter type of variable";
				cin>>b;
				cout<<"\nEnter value of variable";
		        cin>>v;
	            insertWR(a,b,v);
			  }
		}
		 int hashf(string s)
		 	 {
		 		 int a=s[0];
		 		 return (a%10);
		 	 }
		 	void insertWR(string x,string y,int z)
		 	{
		 		int repeat=0;
		 	    int get=hashf(x);
		 	    if(key[get].flag==0)
		 	  {
		 	    key[get].name=x;
		 	    key[get].type=y;
		 	    key[get].value=z;
		 	    key[get].flag=1;
		 	    return;
		 	  }
		 	  else
		 	  {
		 		int c=get;
		 		 for(int i=get+1;i<10;i++)
		 		 {
		 			if(key[i].flag==0)
		 			{
		 				key[i].name=x;
		 	            key[i].type=y;
		 	            key[i].value=z;
		 	            key[i].flag=1;
		 	            if(key[c].chain==-1)
		 	            	key[c].chain=i;
		                return;
		 			}
		 			if(i==9&&repeat==0)
		 			{
		 				i=-1;
		 				repeat=1;
		 			}
		 		 }
		 	  }
		    }
		 	 void insertR(string a,string b,int v)
		 	   {
		 	        int repeat=0,z;
		 	        string n,t;
		 		    int get=hashf(a);
		 		    int c=get;
		 		    if(key[get].flag==0)
		 		  {
		 		    key[get].name=a;
		 		    key[get].type=b;
		 		    key[get].value=v;
		 		    key[get].flag=1;
		 		    return;
		 		  }
		 		  else if(hashf(key[get].name)!=get)
		 	        {
		 	              n=key[get].name;
		 	              t=key[get].type;
		 	              z=key[get].value;
		 	              key[get].name=a;
		 		          key[get].type=b;
		 		          key[get].value=v;
		 		          key[get].flag=1;
                 for(int i=get+1;i<10;i++)
		 			 {
		 				if(key[i].flag==0)
		 				{
		 					key[i].name=n;
		 		            key[i].type=t;
		 		            key[i].value=z;
		 		            key[i].flag=1;
		 		            c=hashf(n);
		 		            if(key[c].chain==get)
		 		            	key[c].chain=i;
		 	                return;
		 				}
		 				if(i==9&&repeat==0)
		 				{

		 	                i=-1;
		 					repeat=1;
		 				}
		 			 }
		 		  }
		 	    else
		 	    {
		 	        for(int i=get+1;i<10;i++)
		 			 {
		 				if(key[i].flag==0)
		 				{
		 					key[i].name=a;
		 		            key[i].type=b;
		 		            key[i].value=v;
		 		            key[i].flag=1;
		 		            if(key[get].chain==-1)
		 		              key[get].chain=i;
		 	                return;
		 				}
		 				if(i==9&&repeat==0)
		 				{

		 	                i=-1;
		 					repeat=1;
		 				}
		 			 }
		 	    }
		 	   }
		 	void find(string w)
		 	   {
		 		int get=hashf(w),repeat=0;
		 	       for(int i=get;i<10;)
		 	       {
		 	    	  if(key[i].name==w)
		 	    	  {
		 	    		 cout<<"\nVariable found";
		 	    		 return;
		 	    	  }
		 	    	  else if(key[i].chain!=-1)
		 	    	  {
		 	    		  i=key[i].chain;
		 	    	  }
		 	    	  else
		 	    	  {
		 	    		  i++;
		 	    		  if(i==10&&repeat==0)
		 	    		  {
		 	    			  i=0;
		 	    		     repeat=1;
		 	    		  }
		 	    	  }
		 	       }
		 	       cout<<"\nVariable not found";
		 	   }
		 void retrieve(string w)
	 {
		  	int get=hashf(w),repeat=0;
		    for(int i=get;i<10;)
		  {
		 	  if(key[i].name==w)
		 	  {
		 		 cout<<"\n"<<key[i].name;
		 		 cout<<"\t"<<key[i].type;
		 		 cout<<"\t"<<key[i].value;
		 		 return;
		 	  }
		 	  else if(key[i].chain!=-1)
		 	   i=key[i].chain;
		 	  else
		 	  {
		 	    i++;
		 	   if(i==10&&repeat==0)
		 	     {
		 	   	  i=0;
		 	      repeat=1;
		 	     }
		 	  }
		  }
		 	cout<<"\nVariable not found";
	  }
		 void modify(string w)
	 {
		 	 int get=hashf(w),repeat=0;
		     for(int i=get;i<10;)
		   {
		 	  if(key[i].name==w)
		 	  {
		 		 cout<<"\nEnter new type";
		 		 cin>>key[i].type;
		 		 cout<<"\nEnter new value";
		 		 cin>>key[i].value;
		 		 cout<<"\nVariable updated";
		 		 return;
		 	 }
		 	  else if(key[i].chain!=-1)
		 		   i=key[i].chain;
		 	  else
		 	 {
		 	   i++;
		 	   if(i==10&&repeat==0)
		 	   {
		   	    i=0;
		   	    repeat=1;
		 	   }
		 	 }
		  }
		 	cout<<"\nVariable not found";
		}
		 	   void remove(string w)
		 	   {
		 	       for(int i=0;i<10;i++)
		 	       {
		 	           if(key[i].name==w)
		 	           {
		 	            key[i].name=" ";
		 	            key[i].type=" ";
		 	            key[i].flag=0;
		 	            key[i].value=0;
		 	            key[i].chain=-1;
		 	            cout<<"\nVariable deleted";
		 	            return;
		 	           }
		 	       }
		 	       cout<<"\nVariable not found";
		 	   }
		 	void print()
		 		{
		 			for(int i=0;i<10;i++)
		 			{
		 			    if(key[i].flag!=0)
		 				cout<<endl<<i<<" -> "<<key[i].value<<"->"<<key[i].chain;
		 				else
		 	            cout<<endl<<i;
		 			}
		 		}
};

int main() {
	symbolTable st;
	    int ch,r;
	    string p,q;
	    do
	    {
	        cout<<"\n1.Insert Without Replacement\n2.Insert With Replacement\n3.Display";
	        cout<<"\n4.Find word\n5.Delete word\n6.Retrieve Variable\n7.Modify variable\n8.Exit";
	        cin>>ch;
	        switch(ch)
	        {
	        case 1:
	              cout<<"\nEnter name";
	              cin>>p;
	              cout<<"\nEnter type";
	              cin>>q;
	              cout<<"\nEnter value";
	              cin>>r;
	              st.insertWR(p,q,r);
	              break;
	        case 2:
	        	cout<<"\nEnter name";
	            cin>>p;
	            cout<<"\nEnter type";
	            cin>>q;
	        	cout<<"\nEnter value";
	            cin>>r;
	            st.insertR(p,q,r);
	        	break;
	              break;
	        case 3:
	            st.print();
	            break;
	        case 4:
	            cout<<"\nEnter variable name to find";
	            cin>>p;
	            st.find(p);
	            break;
	        case 5:
	            cout<<"\nEnter word to delete";
	            cin>>p;
	            st.remove(p);
	            break;
	        case 6:
	            cout<<"\nEnter word to retrieve";
	            cin>>p;
	        	st.retrieve(p);
	        	break;
	        case 7:
	           cout<<"\nEnter word to modify";
	           cin>>p;
	           st.modify(p);
	           break;
	        case 8:
	            cout<<"\nEND!!!";
	            break;
	        default:
	            cout<<"\nInvalid choice";
	        }
	    }while(ch!=8);
	return 0;
}
