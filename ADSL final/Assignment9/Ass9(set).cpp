//============================================================================
// Name        : 9set.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define MAX 10
using namespace std;
template <class t>
class set
{
	t ele[MAX];
	int n;
public:
	set()
{
	for(int i=0;i<MAX;i++)
		ele[i]=0;
	n=0;
}
	void create()
	{
		cout<<"\nEnter number of elements";
	    cin>>n;
		for(int i=0;i<n;i++)
	    {
		cout<<"\nEnter element";
		cin>>ele[i];
		}
	}
 void insert()
 {
	 if(n!=MAX)
	{
		cout<<"\nEnter element";
		cin>>ele[n];
	    n++;
	    return;
	}
	cout<<"\nLimit extends";
 }
 void insert2(t a)
  {
 	 if(n!=MAX)
 	{
 		ele[n]=a;
 	    n++;
 	    return;
 	}
 	cout<<"\nLimit extends";
  }
 void remove()
 {
	 t a;
	 cout<<"\nEnter element";
	 cin>>a;
	 for(int i=0;i<n;i++)
	 {
		 if(ele[i]==a)
		 {
			 for(int j=i;j<n;j++)
				 ele[j]=ele[j+1];
			 n--;
			 cout<<"\nElement deleted";
			 return;
		 }
	 }
	 cout<<"\nElement not found";
 }
 void remove2(t a)
  {
 	 for(int i=0;i<n;i++)
 	 {
 		 if(ele[i]==a)
 		 {
 			 for(int j=i;j<n;j++)
 				 ele[j]=ele[j+1];
 			 n--;
 			 return;
 		 }
 	 }
 	 cout<<"\nElement not found";
  }
 void find()
 {
	 t a;
	 cout<<"\nEnter element";
	 cin>>a;
	 for(int i=0;i<n;i++)
	 {
		 if(ele[i]==a)
		 {
			 cout<<"\nElement fount at "<< i+1 <<" location";
			  return;
		 }
	 }
	 cout<<"\nElement not found";
 }
 int size()
 {
	 return n;
 }
 void iterator()
 {
	 cout<<endl;
	 cout<<"{";
	 for(int i=0;i<n;i++)
	    cout<<ele[i]<<" ";
	 cout<<"}";
 }
 void intersection(set s1,set s2)
 {
	 set s3;
	 for(int i=0;i<s1.n;i++)
	 {
		 for(int j=0;j<s2.n;j++)
		 {
			 if(s1.ele[i]==s2.ele[j])
			   s3.insert2(s1.ele[i]);
		 }
	 }
	 cout<<"\nIntersection set = ";
	 s3.iterator();
 }
 void union1(set s1,set s2)
{
   set s3;
   for(int i=0;i<s1.n;i++)
	   s3.insert2(s1.ele[i]);
   for(int i=0;i<s2.n;i++)
   	   s3.insert2(s2.ele[i]);
   cout<<"\nUnion set =";
   s3.iterator();

}
 void difference(set s1,set s2)
 {
	 set s3;
	 s3=s1;
	 s3.iterator();
	 	 for(int i=0;i<s1.n;i++)
	 	 {
	 		 for(int j=0;j<s2.n;j++)
	 		 {
	 			 if(s1.ele[i]==s2.ele[j])
	 			   s3.remove2(s1.ele[i]);
	 		 }
	 	 }
	 	 cout<<"\nDifference of set =";
	 	 s3.iterator();
 }
 void subset(set s1,set s2)
 {
	 int found=0;
	 for(int i=0;i<s1.n;i++)
	 	 	 {
	 	 		 for(int j=0;j<s2.n;j++)
	 	 		 {
	 	 			 if(s1.ele[i]==s2.ele[j])
	 	 				 found++;
	 	 		 }
	 	 	 }
	 if(found==s2.n)
		 cout<<"\n It is a subset";
	 else
		 cout<<"\n not a subset ";
 }
};
int main() {

    set<int> set1;
    set1.create();
    set<int> set2;
    set2.create();
    int ch;
    do{
    	cout<<"\n1.Insert\n2.delete\n3.find\n4.size of set\n5.intersection\n6.union";
    	cout<<"\n7.Display\n8.Set Difference\n9.Subset\n10.Exit";
    	cin>>ch;
    	switch(ch)
    	{
    	case 1:
    	   set1.insert();
    	   break;
    	case 2:
    	   set1.remove();
    	   break;
    	case 3:
    	   set1.find();
    	   break;
    	case 4:
    	   cout<<"\nNo. of elements in set = "<<set1.size();
    	   break;
    	case 5:
    	   set1.intersection(set1,set2);
    	   break;
    	case 6:
    	   set1.union1(set1,set2);
    	   break;
    	case 7:
    		set1.iterator();
    		break;
    	case 8:
    		set1.difference(set1,set2);
    		break;
    	case 9:
    		set1.subset(set1,set2);
    		break;
    	case 10:
    		cout<<"\nEND!!";
    		break;
    	}
    }while(ch!=10);
	return 0;
}
