#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
Node *newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
bool isIsomorphic(Node *root1,Node *root2);
int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		int m=n;
		Node *root1=NULL;
		Node *root2=NULL;
		while(n-->0){
			int a1,a2;
			cin>>a1>>a2;
			char lr;
			scanf(" %c",&lr);
			if(root1==NULL){
				root1=newNode(a1);
				switch(lr){
					case 'L':root1->left=newNode(a2);
					break;
					case 'R':root1->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root1,a1,a2,lr);
			}
		}
		while(m-->0){
			int a1,a2;
			cin>>a1>>a2;
			char lr;
			scanf(" %c",&lr);
			if(root2==NULL){
				root2=newNode(a1);
				switch(lr){
					case 'L':root2->left=newNode(a2);
					break;
					case 'R':root2->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root2,a1,a2,lr);
			}
		}
		/*inorder(root1);
		cout<<endl;
		inorder(root2);*/
		if(isIsomorphic(root1,root2)){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}

bool isIsomorphic(Node *root1, Node *root2)
{
    // ===== root level
    if( 0 == root1 && 0 == root2 ) { // empty
        return true;
    }
    if( 0 == root1 || 0 == root2 ) { // xor empty
        return false;
    }
    if( root1->data != root2->data ) { // not equal
        return false;
    }

    //  ===== node level
    Node* left1  = root1->left;
    Node* right1 = root1->right;
    Node* left2  = root2->left;
    Node* right2 = root2->right;

    if( 0 == left1 && 0 == right1 ) { // children empty
        return 0 == left2 && 0 == right2; 
    } else if( 0 == left2 && 0 == right2 ) { // xor empty
        return false;
    }
    if( 0 == left1 ) {
    	
        Node* temp = left1;
        left1      = right1;
        right1     = temp;
    }
    if( 0 == left2 ) {
        Node* temp = left2;
        left2      = right2;
        right2     = temp;
    }
    
    // ===== left are non-empty. right may or may not be
    if( left1->data != left2->data ) { // reverse
        if( 0 == right1 || 0 == right2 ) {
            return false;
        }

        if( left1->data == right2->data && right1->data == left2->data ) {
            return isIsomorphic( left1, right2 ) && isIsomorphic( left2, right1 );
        }
        return false;
    } else {
        if( 0 == right1 || 0 == right2 ) {
            return true;
        }
        if( 0 == right1 || 0 == right2 ) {
            return false;
        }
        if( right1->data == right2->data ) {
            return isIsomorphic( right1, right2 ) && isIsomorphic( left1, left2 );
        }
        return false;
    }
}