#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Node {
	int _num;
	Node* _next;
};

Node* createEmptySet();
bool isEmpty(Node*);
bool inSet(Node*, int);
Node* addFirst(Node*, int);
Node* createSet(int, int, int, string);
int powerOfSet(Node*);
string printSet(Node*, char);
Node* deleteSet(Node*);
bool subSet(Node*, Node*);
bool equalitySet(Node*, Node*);
Node* combinationOfSets(Node*, Node*);
Node* intersectionOfSets(Node*, Node*);
Node* subtractionOfSets(Node*, Node*);
Node* simmetricSubtrOfSets(Node*, Node*);