/*
 * RBTree.cpp
 *
 *  Created on: Jun 17, 2013
 *      Author: clu1
 */
#include "RBTree.h"

Node::Node(const char* n){
  key = n;
	left = 0;
	right = 0;
	parent = 0;
	color = NULL;
}

Node:: Node(){
	key = NULL;
	left= 0;
	right = 0;
	parent = 0;
	color = NULL;
}

RBTree::RBTree(){

	nil = new Node();
	root = nil;
}

void RBTree::leftRotate(Node* x){
	Node* y = x->right;
	x->right = y->left;
	if(y->left != nil){
		y->left->parent = x;
	}
	y->parent = x->parent;

	if(x->parent == nil){
		root = y;
	}
	else if(x == x->parent->left){
		 x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;

}

void RBTree::rightRotate(Node* x){
	Node* y = x->left;
	x->left = y->right;
	if(y->right != nil){
		y->right->parent = x;
	}
	y->parent = x->parent;

	if(x->parent == nil){
		root = y;
	}
	else if(x == x->parent->right){
		 x->parent->right = y;
	}
	else{
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;

}

void RBTree::treeInsert(Node* z){
	cout << "TI: Here" << endl;
	Node* y = NULL;
	Node* x = root;

	while(x != NULL){
		y = x;
		if(strcmp(z->key, x->key) < 0){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	z->parent =y;
	if(y == NULL){
		root = z;
	}
	else if(strcmp(z->key, y->key) < 0){
		y->left =z;
	}
	else{
		y->right = z;
	}
}

void RBTree::RB_INSERT_FIXUP(Node* z){
	Node* y;

	while(z->parent->color == 'R'){
		if(z->parent == z->parent->parent->left){
			y = z->parent->parent->right;

			if(y->color == 'R'){
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else{
				if(z == z->parent->right){
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				rightRotate(z->parent->parent);
			}

		}
		else{
			y = z->parent->parent->left;

			if(y->color == 'R'){
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else{
				if(z == z->parent->left){
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				leftRotate(z->parent->parent);
			}

		}
	}
	 root->color = 'B';
	 y= NULL;
}

void RBTree::RB_INSERT(Node* z){
	Node* y = nil;
	Node* x = root;

	while(x != nil)	{
		y = x;
		if(strcmp(z->key, x->key) < 0)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	z->color = 'R';
	z->left = z->right = nil;

	if( y == nil)
		root = z;
	else if(strcmp(z->key, y->key) < 0)
		y->left = z;
	else
		y->right = z;

	RB_INSERT_FIXUP(z);


}

void RBTree::INORDER(){
	INORDER(root);
}

void RBTree::INORDER(Node* z){

	if(z != nil){
		INORDER(z->left);
		cout << z->key << " ";
		INORDER(z->right);
	}


}


