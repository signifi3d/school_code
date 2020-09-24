//list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied
void duplicate(node * & new_copy); //provides a duplicate copy of the list

int sumOfList(node * head);
void insert(node *& head, int position, int newInt);
#endif
