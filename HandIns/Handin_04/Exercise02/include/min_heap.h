#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;

    // Constructor
    Node(T value)
    {
        data = value;
        left = right = nullptr;
        parent = nullptr;
    }
};

/**
 * @brief Min-Heap Class
 *
 * @tparam T
 */

template <typename T>
class MinHeap
{
public:
    /**
     * @brief Hjælperfunktion til at swappe values i to noder
     *  Laver en ny temp værdi til temp og gemmer vores n1 data.
     *  Kopierer n2 over i n1 og omvendt
     *
     */
    void swapValues(Node<T> *N1, Node<T> *N2)
    {
        T temp = N1->data;
        N1->data = N2->data;
        N2->data = temp;
    }

    /**
     * @brief Hjælperfunktion til at finde den korrekte parent efter indsættelse
     * @return Pointer til den nye parent
     */
    Node<T> *findNextParent()
    {
        Node<T> *cur = last_;                                       // Starter ved den sidst indsatte node og bruger en lokal pointer, så last_ ikke ændres. Dette gøres for at kunne finde den nye parent.
        while (cur->parent != nullptr && cur->parent->right == cur) // imens parent ikke er nullptr (roden) og vi er højrebarn skal vi gå opad
        {
            cur = cur->parent;
        }
        if (cur->parent == nullptr) // vi er stoppet på roden og skal gå ned langs venstre for at finde næste indsættelses sted
        {
            while (cur->left != nullptr) // går nedad indtil vores næste barn er et nullptr, som angiver, at vi er kommet til næste indsættelses sted
            {
                cur = cur->left;
            }
            return cur; // returnerer cur, som den nye parent
        }
        else // Vi stoppede på et venstre barn. Næste ledige plads ligger i søsterens (højre) undertræ.
        {
            cur = cur->parent->right;    // Går over til søsteren (højre barn af samme parent)
            while (cur->left != nullptr) // Går helt ned ad venstre side, indtil vi finder første node uden barn
            {
                cur = cur->left;
            }
            return cur; // Returnerer noden, som den nye node skal hænges på som venstre barn
        }
    }

    /**
     * @brief Inserts an element and updates the Heap
     *
     * @param x Element to insert
     */
    void insert(const T &x)
    {
        size_++; // inkrementere size inden den nye node er sat ind. Dermed bliver size den nye nodes position. Dermed kan size angive om
        // vi skal indsætte på venstre eller højre side. Lige = venstre barn, ulige = højre barn

        Node<T> *newNode = new Node<T>(x); // Allokere plads til vores nye node og danner den

        if (root_ == nullptr) // hvis heapen er tom dannes vores nye root
        {
            root_ = newNode; // root pointer peger nu på den nye node, da den bliver til root
            last_ = newNode; // samme med last pointer
            return;
        }

        Node<T> *parent; // Vi danner en pointer til en parent for at kunne bruge den senere

        if (size_ % 2 == 0) // hvis size er et lige tal betyder det, at vi skal indsætte på venstre side
        {
            parent = findNextParent(); // Dermed finder vi vores nye parent med vores hjælperfunktion
            parent->left = newNode;    // Da vi ved, at vi skal indsætte til venstre dannes vores node pointere
            newNode->parent = parent;  // sætter vores nye node parent pointer til den korrekte parent.
            // Nu ved vi, at vi har opsat vores pointere korrekt og derved kan vi gå videre til at tjekke om værdien er korrekt indsat
        }
        else // Hvis vi rammer else betyder det, at vi skal indsætte på højre side. Dette er noget nemmere, da vi blot skal indsætte til højre for vores parent uden at tænke på
        // om det er det korrekte sted. Vi skal nemlig altid fylde parent ud.
        {
            parent = last_->parent;   // Sætter parent til at være last_->parent, da det er parent til venstre node, som vi indsatte sidste gang (last_)
            parent->right = newNode;  // opsætter parent right til at være den nye node
            newNode->parent = parent; // opsætter den nye nodes pointer parent til parent
            // Nu ved vi, at vi har opsat vores pointere korrekt og derved kan vi gå videre til at tjekke om værdien er korrekt indsat
        }
        last_ = newNode; // den nye node sættes til last_, da det er den sidst nye, som vi indsatte

        // Derefter skal vi sørge for at minheap, ved et while loop, som kører indtil enten at vi rammer root, eller parentens værdi er mindre end eller lig med barnets
        //  Ellers laves swap og den nye node skifter til parent for at gå videre op i kæden
        while (newNode->parent != nullptr && newNode->data < newNode->parent->data) // imens vi ikke rammer roden OG parent er større end sit barn
        {
            swapValues(newNode, newNode->parent); // swapper deres værdier
            newNode = newNode->parent;            // går et skridt op af kæden
            // det er kun værdierne, som byttes og vi ændrer ikke på last_ pointerens værdi mens newnode bevæger sig opad.
        }
    }

    /**
     * @brief Remove minimum (top) element and update Heap
     *
     */
    void remove()
    {
        if (size_ == 0) // returnere, hvis heapen er tom
        {
            return;
        }
        if (size_ == 1) // Hvis det kun er vores root, som er lavet
        {
            delete root_;    // sletter noden
            last_ = nullptr; // sætter last til nullptr
            root_ = nullptr; // sætter root til nullptr
            size_ = 0;       // opdaterer size
            return;
        }
        // Hvis vores heap er større, skal vi flytte noget data og derfor starter vi med at gemme den sidste indsatte nodes værdi i rooten:
        root_->data = last_->data;

        // Derefter laver vi en pointer til last_, så vi kan slette last_ noden, når vi har rykket på alt dataen rigtigt
        Node<T> *temp = last_;

        // Hvis vi er højre barn er det nemt at finde den sidste last_, da det blot er vores søster (venstre barn)
        if (last_->parent->right == last_) // hvis vi er højrebarn og last
        {
            last_ = last_->parent->left; // Højre barn: den forrige node i niveau-rækkefølgen er søsteren (venstre barn)
        }
        else // Ellers skal vi gå opad imens vi er venstre barn,
        {

            while (last_->parent != nullptr && last_->parent->left == last_) // Vi går opad indtil vi enten rammer root, eller vi ikke er venstre barn
            {
                last_ = last_->parent; // går op ad indtil while er false
            }


            if (last_->parent == nullptr) // vi har ramt root og dermed var den slettede node den første på sit eget lag. Den var yderst til venstre).
            // Derfor er vores nye last altså helt ude til højre, da det er her, at den sidste node i hver niveau placeres. Dermed skal vi sætte den som last_
            {
                while (last_->right != nullptr) // vi bevæger os ud mod højre indtil vi last_ right er nullptr. 
                {
                    last_ = last_->right; // Gå ned ad højre side og last_ sættes til den korrekte node helt ude til højre
                }
            }
            else //hvis ikke vi rammer roden i vores while loop ender vi her. Vores whileloop er derfor stoppet ved et højrebarn
            // Den forrige node er yderst til højre i søsterens (venstre) undertræ.
            {
                last_ = last_->parent->left;  // Gå over til søsteren
                while (last_->right != nullptr) // Gå helt ned ad højre side
                {
                    last_ = last_->right;
                }
            }
        }

        //Når vi har fundet den nye last, skal vi slette vores gamle last_, som er node, som temp peger på:
        if (temp->parent->left == temp) // Hvis temp var et venstre barn skal vi sætte forældres venstre pointer til null:
        {
            temp->parent->left = nullptr;
            delete temp; //sletter vores node
            size_--; //dekrementerer size
        }
        else if (temp->parent->right == temp) // Hvis temp var et højre barn skal vi sætte forældres højre pointer til null:
        {
            temp->parent->right = nullptr;
            delete temp; //sletter vores node
            size_--; //dekrementerer size
        }

        // til sidst skal vi tjekke om værdierne er mindre ned fra roden for igen at sørge for en korrekt minheap
        // Vi laver en ny pointer, som peger på root. Dermed kan vi ændre i den pointer uden at ødelægge det, som root allerede peger på.
        Node<T> *tempRoot_ = root_;
        // Først tjekker vi om vores root har nogle børn.
        // Vi skal kun tjekke om left != nullptr, da vi altid opretter en left først.
        // Derved kan vi nøjes med at tjekke om den findes og derefter se på børnenes værdi
        // Fortsætter til, at vi har dannet heapify igen
        while (tempRoot_->left != nullptr) //hvis vi har et venstre barn:
        {
            if (tempRoot_->right == nullptr) //hvis right er nullptr har vi "kun" et venstre barn og skal kun sammenligne med den
            {
                if (tempRoot_->data > tempRoot_->left->data) //hvis forældrenes data er større end barnets laves swap
                {
                    swapValues(tempRoot_, tempRoot_->left);
                }
                break; //Vi ved at når der kun er et child må det være et leaf. Derfor laver vi et break, da vi er nået bunden uanset om vi swapper eller ej
            }
            else // vi ender her, hvis tempRoot har både en right og left child.
            {
                //Dermed skal vi finde ud af, hvilket barn der er mindst af de to.
                //vi Tjekker først om left-data er mindre end root OG om left-data er mindre eller lig med right-data
                if (tempRoot_->left->data < tempRoot_->data && tempRoot_->left->data <= tempRoot_->right->data)
                {
                    // Er dette tilfældet er vores left child mindst og vi skal dermed skifte dens værdi med vores temproot
                    swapValues(tempRoot_, tempRoot_->left);
                    tempRoot_ = tempRoot_->left; // vi sætter vores nye temp root og kan dermed gå videre ned langs vores heap
                }
                //Hvis ikke venstre barn er mindst, skal vi tjekke om højre barn er mindst: (mindre end både root og venstre)
                else if (tempRoot_->right->data < tempRoot_->data && tempRoot_->right->data < tempRoot_->left->data)
                {
                    //Hvis dette tilfældet laves swap med temproot
                    swapValues(tempRoot_, tempRoot_->right);
                    tempRoot_ = tempRoot_->right; // vi sætter vores nye temp root og kan dermed gå videre ned langs vores heap
                }
                else //er ingen af børnene mindre end root er vores MinHeap okay og vi kan dermed break.
                {
                    break;
                }
            }
        }
    }

    /**
     * @brief Inspect if Heap is empty
     *
     * @return true Heap is empty
     * @return false Heap is not empty
     */
    bool
    isEmpty() const
    {
        return root_ == nullptr;
    }

    /**
     * @brief Access the minimum (top) element of the Heap
     *
     * @return T Minimum element in Heap
     */
    T peek()
    {
        if (root_ == nullptr)
        {
            throw std::runtime_error("Heapen er tom og derfor findes ingen minimum / top element :( \n");
        }
        else
        {
            return root_->data;
        }
    }

private:
    Node<T> *root_ = nullptr;
    Node<T> *last_ = nullptr;
    int size_ = 0;
};

#endif