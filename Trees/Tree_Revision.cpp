#include<bits/stdc++.h>
using namespace std;


/*------------------------------------Node Structure------------------------------------------*/
struct Node{
	int data;
	struct Node *left, *right;
	Node(int data){
		this->data=data;
		left = right = NULL;
	} 
};
// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
    Node *temp = new Node(data); 
    temp->left = temp->right = NULL; 
    return temp; 
}
/*------------------------------------Inorder LNR------------------------------------------*/
void Inorder(Node * node){
	if(node==NULL)
		return;
	Inorder(node->left);
	cout<<node->data<<" ";
	Inorder(node->right);
}

/*------------------------------------Preorder NLR------------------------------------------*/
void Preorder(Node *node){
	if(node==NULL)
		return;
	cout<<node->data<<" ";
	Preorder(node->left);
	Preorder(node->right);
}

/*------------------------------------Postorder LRN------------------------------------------*/
void Postorder(Node *node){
	if(node==NULL)
		return;
	Postorder(node->left);
	Postorder(node->right);
	cout<<node->data<<" ";
}

/*------------------------------------Level Order------------------------------------------*/
void LevelOrder(Node *root){
	if(root==NULL) 
		return;
	queue<Node *> q;

	q.push(root);
	while(!q.empty()){
		Node* temp=q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

/*------------------------------------LeftView(level order)------------------------------------------*/
void LeftView(Node* root){
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	while(1){
		int size = q.size();
		if(size==0)
			break;

		cout<<q.front()->data<<" ";
		while(size>0){
			Node *temp = q.front();
			q.pop();
			if(temp->left)	q.push(temp->left);
			if(temp->right)	q.push(temp->right);

			size--;
		}
	}
}

/*------------------------------------RightView(level order)------------------------------------------*/
void RightView(Node* root){
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	while(1){
		int size = q.size();
		if(size==0)
			break;

		cout<<q.back()->data<<" ";
		while(size>0){
			Node *temp = q.front();
			q.pop();
			if(temp->left)	q.push(temp->left);
			if(temp->right)	q.push(temp->right);

			size--;
		}
	}
}

/*------------------------------------Vertical Order(Recur)------------------------------------------*/
//Utility Function
void VerticalOrderUtil(Node *root, int hd, map<int,vector<int>> &m){
	if(root==NULL)
		return;

	m[hd].push_back(root->data);

	VerticalOrderUtil(root->left,hd-1,m);

	VerticalOrderUtil(root->right,hd+1,m);
}

//Main Function
void VerticalOrder(Node* root){
	map<int,vector<int>> m;
	int hd=0;
	VerticalOrderUtil(root,hd,m);

	for(auto c:m){
		for(int i=0; i < c.second.size(); i++)
			cout<<c.second[i]<<" ";
		cout<<endl;
	}
} 
/*------------------------------------Vertical Order(iterative)------------------------------------------*/
void VerticalOrderIterative(Node* root){
	if(root==NULL)
		return;
	map<int,vector<int>> m;
	int hd=0;
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,hd));
	while(!q.empty()){
		pair<Node*,int> temp=q.front();
		q.pop();
		hd=temp.second;
		Node* node = temp.first;
		m[hd].push_back(node->data);	//push_back since map.second is vector

		if(node->left!=NULL)
			q.push(make_pair(node->left,hd-1));
		if(node->right!=NULL)
			q.push(make_pair(node->right,hd+1));
	}
	for(auto c:m){
		for(int i=0; i<c.second.size();i++)
			cout<<c.second[i]<<" ";
		cout<<endl;
	}
}

/*------------------------------------TopView(Vertical order)------------------------------------------*/
void TopView(Node* root){
	if(!root)
		return;
	map<int,queue<int>> m;
	int hd=0;
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,hd));
	while(!q.empty()){
		pair<Node*,int> temp = q.front();
		q.pop();
		hd=temp.second;
		Node* node = temp.first;
		m[hd].push(node->data);			//push since map.second is queue

		if(node->left!=NULL)
			q.push(make_pair(node->left,hd-1));
		
		if(node->right!=NULL)
			q.push(make_pair(node->right,hd+1));
	}
	for(auto c:m){
		cout<<c.second.front()<<" ";
	}
}

/*------------------------------------BottomView(Vertical order)------------------------------------------*/
void BottomView(Node* root){
	if(!root)
		return;
	map<int,queue<int>> m;
	int hd=0;
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,hd));
	while(!q.empty()){
		pair<Node*,int> temp = q.front();
		q.pop();
		hd=temp.second;
		Node* node = temp.first;
		m[hd].push(node->data);

		if(node->left!=NULL)
			q.push(make_pair(node->left,hd-1));
		
		if(node->right!=NULL)
			q.push(make_pair(node->right,hd+1));
	}
	for(auto c:m){
		cout<<c.second.back()<<" ";
	}
}



/*------------------------------------Diameter------------------------------------------*/
int height(Node* root,int &ans){
	if(root==NULL)
		return 0;
	int left_height=height(root->left,ans);
	int right_height=height(root->right,ans);
	ans=max(ans,1+left_height+right_height); //updating diameter
	return 1+max(left_height,right_height);
}
int diameter(Node* root){
	if(root==NULL)
		return 0;
	int ans=0;
	height(root,ans);
	return ans;
}


/*------------------------------------Driver Code------------------------------------------*/
int main()
{
    // Contrust the Tree
    //       1
    //     /   \
    //    2     3
    //   / \   / \
    //  4   5 6   7				//6 is below 5 theoritically
    //         \   \
    //          8   9
    
    Node *root = newNode(1);
    root->left = newNode(2);  		//root->left = new Node(2);
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9);
    //root->right->left->right->right = newNode(10); 
    //root->right->right->right->right = newNode(11);  

    cout << "Preorder traversal of binary tree is \n";
    Preorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root); 

    cout << "\nPostorder traversal of binary tree is \n";
    Postorder(root);

    cout << "\nLevel Order traversal of binary tree is \n"; 
    LevelOrder(root); 

    cout << "\nVertical order traversal is \n"; 
    VerticalOrderIterative(root);
    //VerticalOrder(root);

    cout << "\nLeft View of binary tree is \n"; 
    LeftView(root); 

    cout << "\nRight View of binary tree is \n"; 
    RightView(root);

    cout << "\nTop View of binary tree is \n"; 
    TopView(root); 

    cout << "\nBottom View of binary tree is \n"; 
    BottomView(root);  

    cout<<"\nDiameter of the given binary tree is = "<<diameter(root);

    return 0;
}

