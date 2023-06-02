#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;



bool MagicalContainer::isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> MagicalContainer::getElement(){
    return elements;
}

void MagicalContainer::addElement(int elem) {
    //elements.push_back(elem);
    elements.emplace_back(elem);
}

void MagicalContainer::removeElement(int elem) {
      
 
    elements.erase( std::remove(elements.begin(), elements.end(), elem), elements.end());

    cout << "remove-------------------" << endl;
    for (auto it : elements) {
        cout << it << ", ";
    }
    cout << endl;
(elements.end())--;
    if (!elements.empty()) {
        int num = elements.back();
        cout << "end = " << num << endl;
    }
}





int MagicalContainer::size() {
    return elements.size();
}

void MagicalContainer::AscendingIterator::sort(MagicalContainer* container){
  //  auto elements = container->getElement();
    std::sort( container->elements.begin(), container->elements.end());
    
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(container, 0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return AscendingIterator(container, container->size());
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer* container, int index)
    : container(container), index(index) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : container(&container), index(0)
{
sort(&container);

}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : container(&container), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : container(&container), index(0) {}




MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& it) const {
    return index == it.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& it) const {
    return index != it.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& it) const {
    return index > it.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& it) const {
    return index < it.index;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator<<(int steps) {
    index -= steps;
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator>>(int steps) {
    index += steps;
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const {
    unsigned long jhg=  static_cast<unsigned long>(index);
    return container->elements[jhg];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(container, 0, 1);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return SideCrossIterator(container, container->size(), 1);
}

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), index(0), direction(1) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer* container, int index, int direction)
    : container(container), index(index), direction(direction) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    index += direction;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& it) const {
    return index == it.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& it) const {
    return index != it.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& it) const {
    return index > it.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& it) const {
    return index < it.index;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator<<(int steps) {
    index -= steps * direction;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator>>(int steps) {
    index += steps * direction;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    unsigned long jhg=  static_cast<unsigned long>(index);
    return container->elements[jhg];
}

MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer* container, int index)
    : container(container), index(index) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    unsigned long jhg;
    do {
        ++index;
        jhg=  static_cast<unsigned long>(index);
    } while (index < container->size() && !container->isPrime(container->elements[jhg]));
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& it) const {
    return index == it.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& it) const {
    return index != it.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& it) const {
    return index > it.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& it) const {
    return index < it.index;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator<<(int steps) {
    int count = 0;
    unsigned long jhg;
    while (count < steps) {
        --index;
        jhg=  static_cast<unsigned long>(index);
        if (container->isPrime(container->elements[jhg]))
            ++count;
    }
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator>>(int steps) {
    int count = 0;
    unsigned long jhg;
    while (count < steps) {
        ++index;
        jhg=  static_cast<unsigned long>(index);
        if (container->isPrime(container->elements[jhg]))
            ++count;
    }
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const {
    unsigned long jhg=  static_cast<unsigned long>(index);
    return container->elements[jhg];
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(container, 0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return PrimeIterator(container, container->size());
}
