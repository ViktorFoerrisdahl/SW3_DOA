#include "avl_check.h"
#include <iostream>

using Node = AvlNode<int>;

int main()
{
    std::cout << std::boolalpha;

    // Træ 1: Roden 10 har børnene 5 og 15. Alle højder er korrekte.
    Node left1{5, nullptr, nullptr, 0};
    Node right1{15, nullptr, nullptr, 0};
    Node root1{10, &left1, &right1, 1};
    std::cout << "Korrekt træ: " << checkAVL(&root1) << '\n'; // true

    // Træ 2: Samme form, men rodens gemte højde er 7 i stedet for 1.
    Node left2{5, nullptr, nullptr, 0};
    Node right2{15, nullptr, nullptr, 0};
    Node root2{10, &left2, &right2, 7};
    std::cout << "Forkert gemt højde: " << checkAVL(&root2) << '\n'; // false

    // Træ 3: En kæde fra 10 til 20 til 30. Korrekte højder, men ubalance.
    Node leaf3{30, nullptr, nullptr, 0};
    Node child3{20, nullptr, &leaf3, 1};
    Node root3{10, nullptr, &child3, 2};
    std::cout << "Ubalanceret træ: " << checkAVL(&root3) << '\n'; // false

    return 0;
}
