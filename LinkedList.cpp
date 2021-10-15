#include <bits/stdc++.h>
using namespace std;

struct Node{
	int value;
	Node* prev;
	Node* next;
};

Node* startNode;
Node* endNode;

Node* getNewNode(int value){
	Node* newNode = new Node();
	newNode->value = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertNode(int value){
	if(endNode == NULL){
		startNode = getNewNode(value);
		endNode = startNode;
	}
	else{
		Node* newNode = getNewNode(value);
		endNode->next = newNode;
        newNode->prev = endNode;
		endNode = newNode;
	}
}

void displayForward(){
	for(Node* node=startNode; node!=NULL; node=node->next){
		cout<<(node->value)<<" -> ";
	}
    cout<<"NULL\n";
}

void displayBackward(){
	for(Node* node=endNode; node!=NULL; node=node->prev){
		cout<<(node->value)<<" -> ";
	}
    cout<<"NULL\n";
}


// deletes first occurence
void deleteNode(int value){
	Node* node = startNode;
	if(startNode==NULL) return;
	if(startNode->value==value) startNode = startNode->next;
	while(1){
		if(node==NULL)break;
		if(node->value==value){
			Node* left = node->prev;
			Node* right = node->next;
			
			if(left!=NULL) left->next = right;
			if(right!=NULL) right->prev = left;

			if(node==endNode){
				endNode=left;
			}

			delete node;
			break;
		}
		node=node->next;
	}
}


int main(){
	insertNode(1);
	insertNode(2);
	insertNode(3);
	insertNode(4);

	displayForward();
	displayBackward();

	deleteNode(3);

	displayForward();
	displayBackward();

	return 0;
}


// 1, 2, 3, 4
