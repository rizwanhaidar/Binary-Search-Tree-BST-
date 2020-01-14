#include<iostream>
using namespace std;
#include<string>

/*********Ist Tree********/
struct Node {
public:

	int data;
	Node* right_Child;
	Node* left_Child;
	Node() {
		left_Child = right_Child = NULL;
	}
};


class BSTree {
private:
	Node* minValueNode(Node* node)
	{
		Node* current = node;

		/* loop down to find the leftmost leaf */
		while (current && current->left_Child != NULL)
			current = current->left_Child;

		return current;
	}
	int findHeight(Node* aNode) {
		if (aNode == NULL) {
			return -1;
		}

		int lefth = findHeight(aNode->left_Child);
		int righth = findHeight(aNode->right_Child);

		if (lefth > righth) {
			return lefth + 1;
		}
		else {
			return righth + 1;
		}
	}
	Node* insert(int  newDataItem, Node* t) {
		//bool placed=false;
		if (t == NULL) {
			t = new Node;
			t->data = newDataItem;
			t->left_Child = t->right_Child = NULL;
		}
		else if (newDataItem < t->data)
			t->left_Child = insert(newDataItem, t->left_Child);
		else if (newDataItem > t->data)
			t->right_Child = insert(newDataItem, t->right_Child);

		return t;

	}
	Node* deleteNode(Node* root, int key)
	{
		// base case 
		if (root == NULL) return root;

		// If the key to be deleted is smaller than the root's key, 
		// then it lies in left subtree 
		if (key < root->data)
			root->left_Child = deleteNode(root->left_Child, key);

		// If the key to be deleted is greater than the root's key, 
		// then it lies in right subtree 
		else if (key > root->data)
			root->right_Child = deleteNode(root->right_Child, key);

		// if key is same as root's key, then This is the node 
		// to be deleted 
		else
		{
			// node with only one child or no child 
			if (root->left_Child == NULL)
			{
				Node* temp = root->right_Child;
				free(root);
				return temp;
			}
			else if (root->right_Child == NULL)
			{
				Node* temp = root->left_Child;
				free(root);
				return temp;
			}

			// node with two children: Get the print successor (smallest 
			// in the right subtree) 
			Node* temp = minValueNode(root->right_Child);

			// Copy the print successor's content to this node 
			root->data = temp->data;

			// Delete the print successor 
			root->right_Child = deleteNode(root->right_Child, temp->data);
		}
		return root;
	}
public:
	Node* root;
	BSTree() {
		root = NULL;
	}
	void insert(int newDataItem) {
		root = insert(newDataItem, root);
	}
	bool isEmpty() {
		return root == NULL ? true : false;
	}
	int getHeight() {
		return findHeight(root);
			
	}

	bool find(Node* t, int x) {

		if (t == NULL)
			return 0;
		else if (x < t->data)
			return find(t->left_Child, x);
		else if (x > t->data)
			return find(t->right_Child, x);
		else
			return 1;
	}
	void print(Node* root)
	{
		if (root != NULL)
		{
			print(root->left_Child);
			printf("%d ", root->data);
			print(root->right_Child);
		}
	}
	bool retrieve(int searchDataItem) {
		return find(root, searchDataItem);
	}

	bool delete_Data(int data) {
		cout << endl;
		print(root);
		Node* temp = deleteNode(root, data);
		//cout << temp->data;
		cout << endl;
		print(root);
		return true;
	}
	~BSTree() {

	}

};

/*************2nd Tree***************/
struct Account {
public:

	int rc_n, id;
	string f_name, l_name, balance;
	Account* right_Child;
	Account* left_Child;
	Account() {
		left_Child = right_Child = NULL;
	}
};
class BSTAccount {
	Account* insert(Account acc_, Account* ptr) {
		if (ptr == NULL) {
			ptr = new Account;
			ptr->balance = acc_.balance;
			ptr->f_name = acc_.f_name;
			ptr->id = acc_.id;
			ptr->l_name = acc_.l_name;
			ptr->rc_n = acc_.rc_n;//record number
			ptr->left_Child = ptr->right_Child = NULL;
		}
		else if (acc_.id < ptr->id)
			ptr->left_Child = insert(acc_, ptr->left_Child);
		else if (acc_.id > ptr->id)
			ptr->right_Child = insert(acc_, ptr->right_Child);

		return ptr;
	}
	int findHeight(Account* aNode) {
		if (aNode == NULL) {
			return -1;
		}

		int lefth = findHeight(aNode->left_Child);
		int righth = findHeight(aNode->right_Child);

		if (lefth > righth) {
			return lefth + 1;
		}
		else {
			return righth + 1;
		}
	}
	Account* find(Account* t, int x) {

		if (t == NULL)
			return NULL;
		else if (x < t->id)
			return find(t->left_Child, x);
		else if (x > t->id)
			return find(t->right_Child, x);
		else
			return t;
	}
	Account* deleteNode(Account* root, int key)
	{
		// base case 
		if (root == NULL) return root;

		// If the key to be deleted is smaller than the root's key, 
		// then it lies in left subtree 
		if (key < root->id)
			root->left_Child = deleteNode(root->left_Child, key);

		// If the key to be deleted is greater than the root's key, 
		// then it lies in right subtree 
		else if (key > root->id)
			root->right_Child = deleteNode(root->right_Child, key);

		// if key is same as root's key, then This is the node 
		// to be deleted 
		else
		{
			// node with only one child or no child 
			if (root->left_Child == NULL)
			{
				Account* temp = root->right_Child;
				free(root);
				return temp;
			}
			else if (root->right_Child == NULL)
			{
				Account* temp = root->left_Child;
				free(root);
				return temp;
			}

			// node with two children: Get the print successor (smallest 
			// in the right subtree) 
			Account* temp = minValueNode(root->right_Child);

			// Copy the print successor's content to this node 
			root->id = temp->id;

			// Delete the print successor 
			root->right_Child = deleteNode(root->right_Child, temp->id);
		}
		return root;
	}
	Account* minValueNode(Account* node)
	{
		Account* current = node;

		/* loop down to find the leftmost leaf */
		while (current && current->left_Child != NULL)
			current = current->left_Child;

		return current;
	}
public:
	Account* root;
	BSTAccount() {
		root = NULL;
	}
	void insert(Account acc_) {
		root = insert(acc_, root);
	}
	double getHeight() {
		return findHeight(root);
	}
	bool retrieve(int searchDataItem) {
		if (find(root, searchDataItem)!=NULL) {
			cout<<"\nFound\n";
			return true;
		}
		else {
			cout<<"\nNot Found\n";
			return false;
		}
		
	}
	bool isEmpty() {
		return root == NULL ? true : false;
	}

	void print(Account* root)
	{
		if (root != NULL)
		{
			print(root->left_Child);
			cout << root->rc_n << "\t";
			cout<<root->id<<"\t";
			cout << root->f_name<<" ";
			cout << root->l_name<<"\t";
			cout << root->balance<<"\t";
			cout << endl;
			print(root->right_Child);
		}
	}
	bool delete_Data(int data) {
		cout <<"Before Deleting" <<endl;
		print(root);
		Account* temp = deleteNode(root, data);
		//cout << temp->data;
		cout << endl;
		print(root);
		return true;
	}

	~BSTAccount() {

	}
};

int main() {

	cout << "\n/***************** Simple Binary Tree *******************/ ";
	BSTree a1;
	cout << "\nInserting 34 in the Tree";
	a1.insert(34);
	cout << "\nInserting 0 in the Tree";
	a1.insert(0);
	cout << "\nInserting 76 in the Tree";
	a1.insert(76);
	cout << "\nInserting 2 in the Tree";
	a1.insert(2);
/*	cout << "\nInserting 789 in the Tree";
	a1.insert(789);
	cout << "\nInserting -12 in the Tree";
	a1.insert(-12);
	cout << "\nInserting 67 in the Tree";
	a1.insert(67);
	cout << "\nInserting 32 in the Tree";
	a1.insert(32);*/
	cout << "\nI have Inserted few Data Items in the Tree\nNow its Your Turn to enter data\n";
	bool insert = true;
	do {
		int x = 0;
		cout << "ENter Int value = ";
		cin >> x;
		a1.insert(x);
		cout << "\nInserting "<<x<<" in the Tree";
		cout << "\nDo you want to Enter More data 'y' or 'Y' for yes = ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			insert = true;
		}
		else {
			insert = false;
		}
	} while (insert);

	cout << "\n/**********Checking the Implemented Function***************/\n";
	
	cout<<"\n\n\nShowing the Height of the Tree = "<<a1.getHeight()<<endl<<endl<<endl;
	cout << "\nChecking if different Elements exist in the Tree\n";
	bool search = true;
	do {
		int x = 0;
		cout << "Enter Int value to Retrieve in Tree = ";
		cin >> x;
		cout << "Finding/Retrieving " << x << " in the Tree";

		if (a1.retrieve(x)) {
			cout << "\nRetrieved";
		}
		else {
			cout << "\nNot retrieved";
		}
	
		cout << "\nDo you want to Enter More data 'y' or 'Y' for yes = ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			search = true;
		}
		else {
			search = false;
		}
	} while (search);
	cout << "\n/********** Printing the Tree ***********/"<<endl;
	a1.print(a1.root);
	cout << "\n\n\n\n\n/************ Checking If empty *******************/";
	if (a1.isEmpty()) {
		cout << "\nEmpty\n";
	}
	else {
		cout << "\nNot Empty\n";
	}
	cout << "\n/*************** Deleting few Nodes and Printing Data *****************/\n";

	bool deleted = true;
	do {
		int x = 0;
		cout << "Enter Int value to delete in Tree ";
		cin >> x;
		cout << "\nDeleting " << x << " in the Tree = ";
	
		//a1.print(a1.root);
		a1.delete_Data(x);
		//a1.print(a1.root);
		cout << "\nDo you want to delete More data 'y' or 'Y' for yes = ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			deleted = true;
		}
		else {
			deleted = false;
		}
	} while (deleted);

	cout << "\n/***************** Account Binary Tree *******************/ ";
	BSTAccount a2;
	cout << "\nInserting Data 1 in the Tree";
	Account z;
	z.balance = "121";
	z.f_name = "Ali";
	z.l_name = "Khan";
	z.rc_n = 0;
	z.id = 685713;
	a2.insert(z);
	/*	cout << "\nInserting 789 in the Tree";
		a1.insert(789);
		cout << "\nInserting -12 in the Tree";
		a1.insert(-12);
		cout << "\nInserting 67 in the Tree";
		a1.insert(67);
		cout << "\nInserting 32 in the Tree";
		a1.insert(32);*/
	cout << "\nI have Inserted few Data Items in the Tree\nNow its Your Turn to enter data\n";
	bool insert1 = true;
	int k = 1;
	do {
		Account x;
		
		cout << "ENter Balance (A string) = ";
		cin >> x.balance;
		cout << "ENter First Name (A string) = ";
		cin >> x.f_name;
		cout << "ENter Last Name (A string) = ";
		cin >> x.l_name;
		cout << "ENter Id (An Integer) = ";
		cin >> x.id;
		x.rc_n = k+1;
		k++;
		a2.insert(x);
		cout << "\nInserting data 2 in the Tree";
		cout << "\nDo you want to Enter More data 'y' or 'Y' for yes = ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			insert1 = true;
		}
		else {
			insert1 = false;
		}
	} while (insert1);

	cout << "\n/**********Checking the Implemented Function***************/\n";

	cout << "\n\n\nShowing the Height of the Tree = " << a2.getHeight() << endl << endl << endl;
	cout << "\nChecking if different Elements exist in the Tree\n";
	bool search1 = true;
	do {
		int x = 0;
		cout << "Enter ID to Retrieve in Tree = ";
		cin >> x;
		cout << "Finding/Retrieving " << x << " in the Tree";

		if (a2.retrieve(x)) {
			cout << "\nRetrieved";
		}
		else {
			cout << "\nNot retrieved";
		}

		cout << "\nDo you want to retrieve More data 'y' or 'Y' for yes = ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			search1 = true;
		}
		else {
			search1 = false;
		}
	} while (search1);
	cout << "\n/********** Printing the Tree ***********/" << endl;
	a2.print(a2.root);
	cout << "\n\n\n\n\n/************ Checking If empty *******************/";
	if (a2.isEmpty()) {
		cout << "\nEmpty\n";
	}
	else {
		cout << "\nNot Empty\n";
	}
	cout << "\n/*************** Deleting few Nodes and Printing Data *****************/\n";

	bool deleted1 = true;
	do {
		int x = 0;
		cout << "Enter Id to delete in Tree ";
		cin >> x;
		cout << "\nDeleting data of Id "<<x<<" in the Tree = ";

		//a1.print(a1.root);
		a2.delete_Data(x);
		//a1.print(a1.root);
		cout << "\nDo you want to delete More data 'y' or 'Y' for yes = ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			deleted = true;
		}
		else {
			deleted1 = false;
		}
	} while (deleted1);


}