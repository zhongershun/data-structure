#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include<iostream>

template<class Entry>
struct Binary_node
{
    Entry data;
    Binary_node<Entry> *left;
    Binary_node<Entry> *right;

    Binary_node();
    Binary_node(const Entry &x);
};

#endif