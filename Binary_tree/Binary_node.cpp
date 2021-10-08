#include "Binary_node.h"

template <class Entry>
Binary_node<Entry>::Binary_node()
{
    left=NULL;
    right=NULL;
}

template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x)
{
    data=x;
    left=NULL;
    right=NULL;
}