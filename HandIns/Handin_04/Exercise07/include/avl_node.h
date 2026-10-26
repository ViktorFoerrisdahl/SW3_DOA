#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <utility>

// Baseret på AvlTree.h fra den udleverede bogkode af Weiss.
// AvlNode er flyttet ud af AvlTree, så testtræer kan bygges manuelt.
// Felterne og begge konstruktører er bevaret fra bogkoden.
template <typename Comparable>
struct AvlNode
{
    Comparable element;
    AvlNode   *left;
    AvlNode   *right;
    int       height;

    AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
      : element{ ele }, left{ lt }, right{ rt }, height{ h } { }

    AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
      : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
};

#endif
