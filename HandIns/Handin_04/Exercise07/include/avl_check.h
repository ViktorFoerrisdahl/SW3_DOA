#ifndef AVL_CHECK_H
#define AVL_CHECK_H

#include <algorithm>
#include <cstdlib>
#include "avl_node.h"

// Vores kontrol til opgave 7.
struct CheckResult
{
    int height; // Deltræets faktisk beregnede højde
    bool correct; // Om hele deltræet har korrekte højder og balance
};

template <typename Comparable>
CheckResult checkSubtree(const AvlNode<Comparable>* node)
{
    if (node == nullptr)
        return {-1, true}; // Basecase: Et tomt deltræ har højde -1 og ingen fejl

    // Rekursive kald: Find begge deltræers højder og resultater først.
    const CheckResult left = checkSubtree(node->left);
    const CheckResult right = checkSubtree(node->right);

    // Nodens højde er 1 plus det højeste af de to deltræer.
    const int actualHeight = 1 + std::max(left.height, right.height);
    const bool heightCorrect = node->height == actualHeight; // Sammenlign den gemte og den beregnede højde
    const bool balanced = std::abs(left.height - right.height) <= 1; // Højderne må højst afvige med 1
    // En fejl i et deltræ eller ved noden selv giver false.
    const bool correct = left.correct && right.correct
                         && heightCorrect && balanced;

    return {actualHeight, correct}; // Send højde og resultat tilbage uden at ændre træet
}

template <typename Comparable>
bool checkAVL(const AvlNode<Comparable>* root)
{
    return checkSubtree(root).correct; // Start ved roden og returner kun true eller false
}

#endif
