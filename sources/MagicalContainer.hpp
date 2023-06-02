#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

#include<iostream>
#include <functional>


using namespace std;
namespace ariel{



class MagicalContainer {
private:
    vector<int> elements;
    bool isPrime(int n); // Helper function for prime checking
public:

    void addElement(int elem);
    void removeElement(int elem);
    vector<int> getElement();
    int size();
    

    class AscendingIterator {
    private:
        MagicalContainer* container;
        int index;

    public:
        AscendingIterator begin();
        AscendingIterator end();
        //AscendingIterator();
        AscendingIterator(MagicalContainer* container, int index);
        AscendingIterator(MagicalContainer& container);
        AscendingIterator& operator++();
        bool operator==(const AscendingIterator& it) const;
        bool operator!=(const AscendingIterator& it) const;
        bool operator>(const AscendingIterator& it) const;
        bool operator<(const AscendingIterator& it) const;
        AscendingIterator& operator<<(int steps);
        AscendingIterator& operator>>(int steps);
        int operator*() const;
        void sort(MagicalContainer*);
   
    };

    class SideCrossIterator {
    private:
        MagicalContainer* container;
        int index;
        int direction;  // 1 for right, -1 for left

    public:
        SideCrossIterator begin();
        SideCrossIterator end();
        SideCrossIterator();
        SideCrossIterator(MagicalContainer* container, int index, int direction);
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator& operator++();
        bool operator==(const SideCrossIterator& it) const;
        bool operator!=(const SideCrossIterator& it) const;
        bool operator>(const SideCrossIterator& it) const;
        bool operator<(const SideCrossIterator& it) const;
        SideCrossIterator& operator<<(int steps);
        SideCrossIterator& operator>>(int steps);
        int operator*() const;
    };

    class PrimeIterator {
    private:
        MagicalContainer* container;
        int index;

    public:
        PrimeIterator();
        PrimeIterator(MagicalContainer* container, int index);
        PrimeIterator(MagicalContainer& container);
        PrimeIterator& operator++();
        bool operator==(const PrimeIterator& it) const;
        bool operator!=(const PrimeIterator& it) const;
        bool operator>(const PrimeIterator& it) const;
        bool operator<(const PrimeIterator& it) const;
        PrimeIterator& operator<<(int steps);
        PrimeIterator& operator>>(int steps);
        int operator*() const;
           
    PrimeIterator begin();
    PrimeIterator end();
    };

   

};

}
#endif 
