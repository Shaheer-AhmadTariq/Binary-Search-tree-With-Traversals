#include<iostream>
#include <bits/stdc++.h>
#define SPACE 10
int countNodes = 0;
using namespace std;
//I have written these method 
void insert(int data);
struct Node* FindNode(int data);
int FindDepth(int data);
struct Node* ParentNode(int data);
int findHeight(Node* temp);
Node* FindMax(int data);
void Delete(int data);
//i have taken this method from internet to display in 2d
void print2D(struct Node *r , int space);
//i have used these recursion method after understanding them
void inorderTraversal(struct Node* temp) ;
void PreorderTraversal(struct Node* temp);
void postorderTraversal(struct Node* temp);
void levelOrderTraversal(Node* temp);
//Used this method for Testing purposes
void InsertionForTesting();

//to create binary tree Node
struct Node {
        int data;
        Node* left;
        Node* right;
    };



struct Node* root;
void insert(int data)
{
    	
    if(root == NULL)
    {	
    	countNodes = 1;
        root = new Node;
        root->data = data;
        root->left = root->right = NULL;
    }
    else
	{
		Node* temp = root;
		Node* ptr = new Node();
		while(temp != NULL)
		{
		
				if(data < temp->data){
					
					if(temp->left == NULL){
						//cout<<"Value Inserted to left!"<<endl;
						ptr->data = data; 
						ptr->left = ptr->right = NULL;
						temp->left = ptr;
						countNodes++;//to count number of nodes
						break;
					}
					else
					temp = temp->left;
				}
			
					
				
				else if(data > temp->data)
				{
					if(temp->right == NULL)
					{
						countNodes++;//to count Number of nodes
						//cout<<"Value Inserted to right!"<<endl;
						ptr->data = data;
						ptr->left = ptr->right = NULL;
						temp->right = ptr;
						break;
					}
					temp = temp->right;
					
				}
				
		}
        	
	}
        
}
struct Node* FindNode(int data)
{
	if(root == NULL)
	{
		return 0;
	}
    else if(root->data == data)
    {
    	return root;
    }
    else
	{
		struct Node* temp = root;
		while(temp != NULL)
		{
			if(data == temp->data){
				//cout<<"Value Found: "<<temp->data<<endl;
				
				return temp;
			}
			else if(data < temp->data){
					temp = temp->left;
				}
			else if(data > temp->data)
				{
					temp = temp->right;
					
				}
				
		}
        return 0;	
	}	
}
int FindDepth(int data)
{
	struct Node* ptr;
	ptr = FindNode(data);
	if(ptr == NULL)
		return -1;
    else if(root->data == data)
    {
    	return 0;
    }
    else
	{
		struct Node* temp = root;
		int count = 0;
		while(temp != NULL)
		{
			if(data == temp->data){
			//	cout<<"Value Found: "<<temp->data<<endl;
				
				return count;
			}
			else if(data < temp->data){
					temp = temp->left;
				}
			else if(data > temp->data)
				{
					temp = temp->right;
					
				}
			count++;	
		}
        	
	}	
}
//passing data of child node to finds parent node
struct Node* ParentNode(int data)
{
	struct Node* temp = root;
	struct Node* ptr = FindNode(data);
	
		while(temp != NULL)
		{
		
			if(temp->left == ptr){
				break;
			}
			else if(temp->right == ptr){
				break;
			}
			else if(data < temp->data){
					temp = temp->left;
				}
			else if(data > temp->data)
				{
					temp = temp->right;
					
				}	
				
		}
		//return parent node
		return temp;
        	
}	

int findMax(int a, int b){
  if(a >= b)
    return a;
  else
    return b;
}

int findHeight(Node* temp){
  if(temp == NULL)
    return 0;

  return findMax(findHeight(temp->left), findHeight(temp->right)) + 1;
}
Node* FindMax(int data)
{
	struct Node* temp = FindNode(data);
	if(temp == NULL)
	{
		return NULL;	
	}
	while(temp != NULL)
	{
		if(temp->right == NULL)
		{
			return temp;
		}
		else
		{
			temp = temp->right;	
		}
	}
	
}

void Delete(int data)
{
	if(root == NULL)
	{
		cout<<"Tree Empty"<<endl;
	}
	else{
		//it Finds the Node which is to be deleted
		struct Node* del = FindNode(data);
		if(del != NULL)
		{
		
		if(del->left == NULL && del->right == NULL)
		{
			struct Node* parent = ParentNode(del->data);
			if(parent->left == del)
				parent->left = NULL;
			else
				parent->right = NULL;	
			free(del);
		}
		else if(del->right == NULL)
		{
			struct Node* parent = ParentNode(del->data);
		
			if(parent->left = del)
				if(del->right == NULL)
				parent->left = del->left;
			else	
				parent->right = del->left;	
			free(del);
		}
		else if(del->left == NULL)
		{
			struct Node* parent = ParentNode(del->data);
			if(parent->left == del)
				parent->left = del->right;	
			else
				parent->right = del->right;	
			free(del);
				
		}
		else if(del->left && del->right)
		{
			
			struct Node* max = FindMax(del->data);
			
			struct Node* maxParent = ParentNode(max->data);
		 	if(maxParent->left == max)
		 		maxParent->left = NULL;
		 	else
			 	maxParent->right = NULL;	
			
			del->data = max->data;
			free(max);
		}	
	}
	else
		cout<<"Value Not Found!!"<<endl;
}
	
}
void print2D(struct Node *r , int space){
			if(r==NULL)
				return;
			space += SPACE;
			print2D(r->right , space);
			for(int i = SPACE; i < space; i++){
				cout<<" ";
			}
			cout<<r->data<<"\n";
			print2D(r->left , space);
		}
    
void inorderTraversal(struct Node* temp) {
        if(temp == NULL)
            return;
        inorderTraversal(temp->left);
        cout << temp->data << " ";
        inorderTraversal(temp->right);
    }



void PreorderTraversal(struct Node* temp)
{
    if (temp == NULL)
        return;
 
    cout << temp->data << " ";
 
    PreorderTraversal(temp->left);
 
    PreorderTraversal(temp->right);
}
void postorderTraversal(struct Node* temp)
{
	if(temp == NULL)
		return;
	postorderTraversal(temp->left);
	
	postorderTraversal(temp->right);
	
	cout<<temp->data<<" ";	
}

void levelOrderTraversal(Node* temp)
{
    if (temp == NULL) return;
  
    queue<Node *> q;
      

    Node* ptr;
    q.push(root);
    
  
    while (q.empty() == false)
    {
        ptr = q.front();
        q.pop();
          
        if (ptr == NULL)
        {
           q.push(NULL);
           cout << "\n";
        }
          
        else {
            
            if(ptr->left)
            q.push(ptr->left);
            
            if(ptr->right)
            q.push(ptr->right);
              
            cout << ptr->data << " ";
        }
    }
}
  

void InsertionForTesting()
{
	/*insert(49);
	insert(37);
	insert(55);
	insert(39);
	insert(38);
	insert(46);
	insert(28);
	insert(64);
	insert(50);
	insert(69);
	insert(75);
	insert(70);
	insert(19);
	insert(31);
	insert(20);
	insert(29);*/
    
    
    cout<<"I have inserted some nodes for testing"<<endl;
    print2D(root,5);
}
int main()
{
	//You can use this method to test methods without having to insert 
	//every Node  
	int choice;
	InsertionForTesting();
	
	int data;
	struct Node* temp;
	cout<<".............Menu.............."<<endl;
	cout<<"1. Enter New Node"<<endl;
	cout<<"2. Delete Node"<<endl;
	cout<<"3. Search Node"<<endl;
	
	cout<<"4. Display Tree in Inorder"<<endl;
	cout<<"5. Display Tree in Preorder"<<endl;
	cout<<"6. Display Tree in Postorder"<<endl;
	cout<<"7. Display Tree in Level Order"<<endl;
	
	cout<<"8. To find and return parent of given node"<<endl;
	cout<<"9. To find and return depth of given node"<<endl;
	cout<<"10. To find and return Level of given node"<<endl;
	cout<<"11. To find and return height of tree"<<endl;
	cout<<"12. To find if two nodes are at same level of tree or not"<<endl;
	cout<<"13. To find and return total number of nodes"<<endl;
	cout<<"14. To Exit!!"<<endl;
	cout<<endl<<"Enter Your Choice: ";
	cin>>choice;
	while(choice != 14)
	{
		if(choice == 1)
		{
			cout<<"Enter value of New Node: ";
			cin>>data;
			insert(data);
			print2D(root,5);
		}
		else if(choice == 2)
		{
			cout<<"Enter value to Delete Node: ";
			cin>>data;
			Delete(data);
			print2D(root,5);
		}
		else if(choice == 3)
		{
			cout<<"Enter value to Search if Exits in tree: ";
			cin>>data;
			temp = FindNode(data);
			if(temp != NULL)
				cout<<"Value Found!!"<<endl;
			else
				cout<<"Value Not Found!!"<<endl;	
		}
		else if(choice == 4)
		{
			cout<<"Tree in Inorder: "<<endl;
			inorderTraversal(root);
		}
		else if(choice == 5)
		{
			cout<<"Tree in Preorder: "<<endl;
			PreorderTraversal(root);
		}
		else if(choice == 6)
		{
			cout<<"Tree in Postorder: "<<endl;
			postorderTraversal(root);
		}
		else if(choice == 7)
		{
			cout<<"Tree in Level Order: "<<endl;
			levelOrderTraversal(root);
		}
		else if(choice == 8)
		{
			cout<<"Enter value to Find Parent Node: ";
			cin>>data;
			temp = ParentNode(data);
			if(temp)
				cout<<"Parent Node is: "<<temp->data<<endl;
			else
				cout<<"Parent Node Not Found!!"<<endl;	
		}
		else if(choice == 9)
		{
			cout<<"Enter value to Find Depth of Node: ";
			cin>>data;
			if(FindDepth(data) != -1) 
				cout<<"Depth of Node: "<<FindDepth(data)<<endl;
			else 
				cout<<"Node Not Found!!"<<endl;	
		}
		else if(choice == 10)
		{
			cout<<"Enter value to Find Level of Node: ";
			cin>>data;
			if(FindDepth(data) != -1)
				cout<<"Level of Node: "<<FindDepth(data)+1<<endl;
			else 
				cout<<"Node Not Found!!"<<endl;	
		}
		else if(choice == 11)
		{
			cout<<"Enter value to Find Height of Node: ";
			cin>>data;
			temp = FindNode(data);
			if(temp)
				cout<<"Height of Node: "<<findHeight(temp)<<endl;
			else
				cout<<"Node Not Found!!"<<endl;	
		}
		else if(choice == 12)
		{
			cout<<"To find if two nodes are at same level of tree or not? "<<endl;
			cout<<"Enter value of First Node: ";
			cin>>data;
			int data2;
			cout<<"Enter value of Second Node: ";
			cin>>data2;
			if((FindDepth(data)+1) == (FindDepth(data2)+1))
				cout<<"They are at Same Level"<<endl;
			else
				cout<<"They are not at Same Level!!"<<endl;	
		}
		else if(choice == 13)
		{
			cout<<"Total Number of Nodes are: "<<countNodes<<endl;
		}
		cout<<endl<<"Enter Your Choice: ";
		cin>>choice;
	}
}		   

