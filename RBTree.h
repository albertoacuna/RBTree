/*
 * RBTree.h
 *
 *  Created on: Jun 17, 2013
 *      Author: clu1
 */

#ifndef RBTREE_H_
#define RBTREE_H_

#include <vector>
#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

class Node{
  public:
		const char* key;
		Node* left;
		Node* right;
		Node* parent;
		char color;
		Node();
		Node(const char*);
};

class RBTree{
	private:
		Node* root;
		Node* nil;

	public:
		RBTree();
		void leftRotate(Node*);
		void rightRotate(Node*);
		void treeInsert(Node*);
		void RB_INSERT_FIXUP(Node*);
		void RB_INSERT(Node*);
		void INORDER();
		void INORDER(Node*);
};

#endif /* RBTREE_H_ */
