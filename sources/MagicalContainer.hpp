#include <vector>

namespace ariel{
    class MagicalContainer{
        private:
            std::vector<int> elements; // dynamic array of ints
            std::vector<int*> prime_elements; // dynamic array of pointers to prime ints
            int numOfElements; // number of elements in the array
            int operator[](int) const; // subscript operator
            void validate(); // validate the index
        public:
            MagicalContainer(); // constructor
            ~MagicalContainer(); // destructor
            void addElement(int); // add element to the array
            void removeElement(int); // remove element from the array
            int size(); // return the number of elements in the array

            // for tidy
            MagicalContainer& operator=(const MagicalContainer&) = default; // assignment operator
            MagicalContainer(const MagicalContainer&) = default; // copy constructor
            MagicalContainer& operator=(MagicalContainer&&) = default; // move assignment operator
            MagicalContainer(MagicalContainer&&) = default; // move constructor

            class Iterator{ // This will function as an interface for the other iterators, only implemteation for the constructor
               private:
                    MagicalContainer* container; // reference to the MagicalContainer object
                    int* current; // pointer to the current element in dynamic array implemented with vector in MagicalContainer
                protected:
                    MagicalContainer* getContainer() const; // return the MagicalContainer object
                    int* getCurrent() const; // return the current element in the dynamic array
                    void setCurrent(int*); // set the current element in the dynamic array
                public:
                    Iterator(); // default constructor
                    Iterator(MagicalContainer&); // constructor
                    Iterator(const Iterator&); // copy constructor
                    virtual ~Iterator(); // destructor
                    Iterator& operator=(const Iterator&); // assignment operator
                    virtual bool operator==(const Iterator&) const; // equality operator
                    virtual bool operator!=(const Iterator&) const; // inequality operator
                    virtual bool operator<(const Iterator&) const; // less than operator
                    virtual bool operator>(const Iterator&) const; // greater than operator
                    int operator*() const; // dereference operator
                    Iterator& operator++(); // prefix increment operator ++it

                    // for tidy
                    Iterator& operator=(Iterator&&) = default; // move assignment operator
                    Iterator(Iterator&&) = default; // move constructor
                                    
            };
            class AscendingIterator: public Iterator{
                public:
                    AscendingIterator(); // default constructor
                    AscendingIterator(MagicalContainer&); // constructor
                    AscendingIterator(const AscendingIterator&); // copy constructor
                    ~AscendingIterator() override; // destructor
                    AscendingIterator& operator=(const AscendingIterator&); // assignment operator
                    bool operator==(const AscendingIterator&) const; // equality operator
                    bool operator!=(const AscendingIterator&) const; // inequality operator
                    bool operator<(const AscendingIterator&) const; // less than operator
                    bool operator>(const AscendingIterator&) const; // greater than operator
                    int operator*() const; // dereference operator
                    Iterator& operator++(); // prefix increment operator ++it
                    AscendingIterator begin() const; // return iterator to the first element
                    AscendingIterator end() const; // return iterator to the last element

                    // for tidy
                    AscendingIterator& operator=(AscendingIterator&&) = default; // move assignment operator
                    AscendingIterator(AscendingIterator&&) = default; // move constructor
            };
            class SideCrossIterator: public Iterator{
                public:
                    SideCrossIterator(); // default constructor
                    SideCrossIterator(MagicalContainer&); // constructor
                    SideCrossIterator(const SideCrossIterator&); // copy constructor
                    ~SideCrossIterator() override; // destructor
                    SideCrossIterator& operator=(const SideCrossIterator&); // assignment operator
                    bool operator==(const SideCrossIterator&) const; // equality operator
                    bool operator!=(const SideCrossIterator&) const; // inequality operator
                    bool operator<(const SideCrossIterator&) const; // less than operator
                    bool operator>(const SideCrossIterator&) const; // greater than operator
                    int operator*(); // dereference operator
                    Iterator& operator++(); // prefix increment operator ++it
                    SideCrossIterator begin() const; // return iterator to the first element
                    SideCrossIterator end() const; // return iterator to the last element

                    // for tidy
                    SideCrossIterator& operator=(SideCrossIterator&&) = default; // move assignment operator
                    SideCrossIterator(SideCrossIterator&&) = default; // move constructor
            };
            class PrimeIterator: public Iterator{
                public:
                    PrimeIterator(); // default constructor
                    PrimeIterator(MagicalContainer&); // constructor
                    PrimeIterator(const PrimeIterator&); // copy constructor
                    ~PrimeIterator() override; // destructor
                    PrimeIterator& operator=(const PrimeIterator&); // assignment operator
                    bool operator==(const PrimeIterator&) const; // equality operator
                    bool operator!=(const PrimeIterator&) const; // inequality operator
                    bool operator<(const PrimeIterator&) const; // less than operator
                    bool operator>(const PrimeIterator&) const; // greater than operator
                    int operator*(); // dereference operator
                    Iterator& operator++(); // prefix increment operator ++it
                    PrimeIterator begin() const; // return iterator to the first element
                    PrimeIterator end() const; // return iterator to the last element

                    // for tidy
                    PrimeIterator& operator=(PrimeIterator&&) = default; // move assignment operator
                    PrimeIterator(PrimeIterator&&) = default; // move constructor
            };
    };
    bool isPrime(); // return true if the number is prime, false otherwise
}
