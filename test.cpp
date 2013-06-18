/*
 * test.cpp
 *
 *  Created on: Jun 17, 2013
 *      Author: clu1
 */


#include "RBTree.h"

int main(){
  RBTree rb;
	rb.RB_INSERT(new Node("A"));
	rb.RB_INSERT(new Node("L"));
	rb.RB_INSERT(new Node("G"));
	rb.RB_INSERT(new Node("O"));
	rb.RB_INSERT(new Node("R"));
	rb.RB_INSERT(new Node("I"));
	rb.RB_INSERT(new Node("T"));
	rb.RB_INSERT(new Node("H"));
	rb.RB_INSERT(new Node("M"));

	rb.INORDER();


}
