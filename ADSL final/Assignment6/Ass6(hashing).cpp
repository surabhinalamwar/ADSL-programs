//============================================================================
// Name        : 6hashing.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 2
class hash
{
	string word,mean;
	int flag;
public:
	hash()
{
	word=" ";
	mean=" ";
	flag=0;
}
hash(string w,string m)
{
	word=w;
	mean=m;
	flag=0;
}
friend class dict;
};
class dict
{
	hash key[10];
public:
	dict()
	{
      create();
	}
	 void create()
    {
      string a,b;
       for(int i=0;i<10;i++)
       {
    	   key[i].flag=0;
       }
		for(int j=0;j<MAX;j++)
		  {
			cout<<"\nEnter word";
			cin>>a;
			cout<<"\nEnter meaning";
			cin>>b;
            insertR(a,b);
		  }

	}
	 int hashf(string s)
	 {
		 int a=s[0];
		 return (a%10);
	 }
	void insertWR(string x,string y)
	{
		int repeat=0;
	    int get=hashf(x);
	    if(key[get].flag==0)
	  {
	    key[get].word=x;
	    key[get].mean=y;
	    key[get].flag=1;
	    return;
	  }
	  else
	  {
		 for(int i=get+1;i<10;i++)
		 {
			if(key[i].flag==0)
			{
				key[i].word=x;
	            key[i].mean=y;
	            key[i].flag=1;
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
   void insertR(string a,string b)
   {
        int repeat=0;
        string w,m;
	    int get=hashf(a);
	    if(key[get].flag==0)
	  {
	    key[get].word=a;
	    key[get].mean=b;
	    key[get].flag=1;
	    return;
	  }
	  else if(hashf(key[get].word)!=get)
        {
              w=key[get].word;
              m=key[get].mean;
              key[get].word=a;
	          key[get].mean=b;
	          key[get].flag=1;

         for(int i=get+1;i<10;i++)
		 {
			if(key[i].flag==0)
			{
				key[i].word=w;
	            key[i].mean=m;
	            key[i].flag=1;
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
				key[i].word=a;
	            key[i].mean=b;
	            key[i].flag=1;
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
       for(int i=0;i<10;i++)
       {
           if(key[i].word==w)
           {
            cout<<"\nWord found at "<<i;
            return;
           }
       }
       cout<<"\nword not found";
   }
   void remove(string w)
   {
       for(int i=0;i<10;i++)
       {
           if(key[i].word==w)
           {
            key[i].word=" ";
            key[i].mean=" ";
            key[i].flag=0;
            cout<<"\nword deleted";
            return;
           }
       }
       cout<<"\nword not found";
   }
	void print()
	{
		for(int i=0;i<10;i++)
		{
		    if(key[i].flag!=0)
			cout<<endl<<i<<" -> "<<key[i].word<<"="<<key[i].mean;
			else
            cout<<endl<<i;
		}
	}
};

int main()
{
    dict d;
    int ch;
    string p,q;
    do
    {
        cout<<"\n1.Insert Without Replacement\n2.Insert With Replacement\n3.Display\n4.Find word5.\n5.Delete word\n6.Exit";
        cin>>ch;
        switch(ch)
        {
          case 1:
              cout<<"\nEnter word";
              cin>>p;
              cout<<"\nEnter meaning";
              cin>>q;
              d.insertWR(p,q);
              break;
        case 2:
              cout<<"\nEnter word";
              cin>>p;
              cout<<"\nEnter meaning";
              cin>>q;
              d.insertR(p,q);
              break;
        case 3:
            d.print();
            break;
        case 4:
            cout<<"\nEnter word to find";
            cin>>p;
            d.find(p);
            break;
        case 5:
            cout<<"\nEnter word to delete";
            cin>>p;
            d.remove(p);
            break;
        case 6:
            cout<<"\nEND!!!";
            break;
        default:
            cout<<"\nInvalid choice";
        }
    }while(ch!=6);
	return 0;
}
