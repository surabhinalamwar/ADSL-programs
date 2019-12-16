#include"pch.h"
#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

struct node {
	char keyword[15], meaning[30];
	struct node *left, *right;
	int height;
};
class avldictionary
{
public:
	struct node *insertkeyword(struct node *r, char ik[15], char im[15]);
	struct node *searchkeyword(struct node *trav, char sk[15]);
	int balanceFactor(struct node *r);
	int maxheight(struct node *r);
	struct node *LL(struct node *r);
	struct node *RR(struct node *r);
	struct node *RL(struct node *r);
	struct node *LR(struct node *r);
	void ascending(struct node *r);
	void descending(struct node *r);
	struct node *del(struct node *r, char k[15]);
};
int avldictionary::balanceFactor(struct node *r)
{
	int lheight, rheight;
	if (r->left == NULL)
		lheight = 0;
	else
		lheight = 1 + r->left->height;

	if (r->right == NULL)
		rheight = 0;
	else
		rheight = 1 + r->right->height;
	return (lheight - rheight);	
}

int avldictionary::maxheight(struct node *r)
{
	int lheight, rheight;

	if (r->left == NULL)
		lheight = 0;
	else
		lheight = 1 + r->left->height;

	if (r->right == NULL)
		rheight = 0;
	else
		rheight = 1 + r->right->height;

	if (lheight > rheight)
		return lheight;
	else
		return rheight;
}

struct node *avldictionary::insertkeyword(struct node *r, char ik[15],char im[15]) {
	if (r == NULL) {
		r = new struct node;
		strcpy(r->keyword, ik);	
		strcpy(r->meaning, im);
		r->left = r->right = NULL;
	}
	else if (strcmp(ik, r->keyword) > 0) {
		r->right = insertkeyword(r->right, ik, im);

		if (balanceFactor(r) == -2)
		{
			if (strcmp(ik, r->right->keyword) > 0) {
				r = RR(r);
			}
			else {
				r = RL(r);	
			}
		}
	}
	else if (strcmp(ik, r->keyword) < 0) {
		r->left = insertkeyword(r->left, ik, im);

		if (balanceFactor(r) == 2)
		{
			if (strcmp(ik, r->left->keyword) < 0) {
				r = LL(r);
			}
			else {
				r = LR(r);
			}
		}

	}

	r->height = maxheight(r);

	return r;
}

struct node *avldictionary::LL(struct node *parent) 
{
	struct node *lchild = NULL;
	if (parent) {
		lchild = parent->left;
		if (lchild) {
			parent->left = lchild->right;
			lchild->right = parent;
			parent->height = maxheight(parent);
			lchild->height = maxheight(lchild);
		}
	}
	return lchild;
}

struct node *avldictionary::RR(struct node *parent) 
{
	struct node *rchild = NULL;

	if (parent) {
		rchild = parent->right;
		if (rchild) {
			parent->right = rchild->left;
			rchild->left = parent;

			parent->height = maxheight(parent);
			rchild->height = maxheight(rchild);
		}
	}
	return rchild;
}
struct node *avldictionary::LR(struct node *parent) {
	parent->left = RR(parent->left);
	parent = LL(parent);

	return parent;
}

struct node *avldictionary::RL(struct node *parent) {
	parent->right = LL(parent->right);	
	parent = RR(parent);

	return parent;
}

void avldictionary::ascending(struct node *r) {
	if (r != NULL) {
		ascending(r->left);
		cout << r->keyword;
		cout << "\t";
		cout << r->meaning;
		cout << "\t";
		cout << "\n";
		ascending(r->right);
	}
}

void avldictionary::descending(struct node *r) {
	if (r != NULL) {
		descending(r->right);
		cout << r->keyword;
		cout << "\t";
		cout << r->meaning;
		cout << "\t";
		cout << "\n";
		descending(r->left);
	}
}

struct node *avldictionary::searchkeyword(struct node *trav, char sk[15]) {	
	int count = 0;
	while (trav != NULL) {
		count++;
		if (strcmp(sk, trav->keyword) == 0) {
			cout << "\n\n Keyword FOUND Successfullly...!";	
			cout << "\n No. of comparions required are: " << count;
			return trav;
		}
		else if (strcmp(sk, trav->keyword) > 0) {
			trav = trav->right;	
		}
		else {
			trav = trav->left;
		}
	}
	return trav;	
}
struct node * avldictionary::del(struct node *r, char k[15]) {
    node *temp;
	if (r == NULL)
		return NULL;
	else {
		if (strcmp(r->keyword, k) < 0) {
			r->right = del(r->right, k);
			if (balanceFactor(r) == 2) {
				if (balanceFactor(r->left) >= 0)
					r = LL(r);
				else
					r = LR(r);
			}
		}
		else if (strcmp(r->keyword, k) > 0) {
			r->left = del(r->left, k);
			if (balanceFactor(r) == -2) {
				if (balanceFactor(r->right) <= 0)
					r = RR(r);
				else
					r = RL(r);
			}
		}
		else	
		{
			if (r->right != NULL) {
				temp = r->right;
				while (temp->left != NULL)
					temp = temp->left;
				strcpy(r->keyword, temp->keyword);
				strcpy(r->meaning, temp->meaning);
				r->right = del(r->right, temp->keyword);
				if (balanceFactor(r) == 2) {
					if (balanceFactor(r->left) >= 0)
						r = RR(r);
					else
						r = RL(r);
				}
			}
			else
				return (r->left);
		}
		if (r)
			r->height = maxheight(r);
		return r;
	}
}
int main() {
	char k[15], m[30];
	int choice, n;
	struct node *root = NULL, *found = NULL;
	avldictionary obj;	

	do {
		cout << endl;
		cout << "1. ENTER NEW KEYWORD." << endl;
		cout << "2. SEARCH KEYWORD." << endl;
		cout << "3. PRINT	DICTIONARY ASCENDING ORDER." << endl;
		cout << "4. PRINT	DICTIONARY DESCENDING ORDER." << endl;
		cout << "5. DELETE." << endl;
		cout << "6. UPDATE THE MEANING OF KEYWORD." << endl;
		cout << "7. EXIT." << endl;
		cout << "	Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\n How many keyword you want to insert: ";
			cin >> n;

			for (int i = 0; i < n; i++)	
			{
				cout << "\n Enter keyword: ";
				cin >> k;
				cout << " Enter meaning: ";
				cin>>m;
				root = obj.insertkeyword(root, k, m);
			}
			cout << "\n Keyword inserted Successfully....!\n";
			break;

		case 2:
			cout << "\n Enter keyword to be searched: ";
			cin >> k;
			found = obj.searchkeyword(root, k);
			if (found == NULL) {
				cout << "\n Keyword NOT present...\n";
			}
			else 
				cout << endl << "found";
			break;

		case 3:
			cout << "\n Keywords in Ascending Order\n";
			obj.ascending(root);	
			break;

		case 4:
			cout << "\n Descending Order\n";
			obj.descending(root);
			break;
		case 5:
			cout << "Enter rhe Keyword to be Deleted";
			cin >> k;
			root = obj.del(root, k);
			break;
		case 6:
			cout << "Enter the Keyword Whose meaning needs to be Updated";
			cin >> k;
			found = obj.searchkeyword(root, k);
			if (found == NULL)
				cout << "No such Keyword present to update meaning";
			else {
				cout << "Enter the new Meaning";
				cin >> m;
				strcpy(found->meaning, m);
				cout << "Keyword's Meaning is updated successfully";
			}
		}
	} while (choice != 7);
	return 0;
}
