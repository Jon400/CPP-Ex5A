# include "MagicalContainer.hpp"

/*
    here is empty implementation for magical container and its iterators
*/
int ariel::MagicalContainer::operator[](int) const{
    return -1;
}
ariel::MagicalContainer::MagicalContainer(){
    this->elements = std::vector<int>();
    this->numOfElements = 0;
}
ariel::MagicalContainer::~MagicalContainer(){}
void ariel::MagicalContainer::addElement(int element){
    return;
}
void ariel::MagicalContainer::removeElement(int element){
    return;
}
int ariel::MagicalContainer::size(){
    return -1;
}
ariel::MagicalContainer * ariel::MagicalContainer::Iterator::getContainer() const
{
    return nullptr;
}
int *ariel::MagicalContainer::Iterator::getCurrent() const
{
    return nullptr;
}
ariel::MagicalContainer::Iterator::Iterator() : container(nullptr), current(nullptr) {}
ariel::MagicalContainer::Iterator::Iterator(MagicalContainer &container) : container(&container), current(nullptr) {}
ariel::MagicalContainer::Iterator::Iterator(const Iterator &other_iterator) : container(other_iterator.container), current(other_iterator.current) {}
ariel::MagicalContainer::Iterator::~Iterator(){}
bool ariel::MagicalContainer::Iterator::operator==(const Iterator & other) const
{
    return false;
}
bool ariel::MagicalContainer::Iterator::operator!=(const Iterator & other) const
{
    return false;
}
bool ariel::MagicalContainer::Iterator::operator<(const Iterator & other) const
{
    return false;
}
bool ariel::MagicalContainer::Iterator::operator>(const Iterator & other) const
{
    return false;
}
ariel::MagicalContainer::AscendingIterator::AscendingIterator() : Iterator() {}
ariel::MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer & container) : Iterator(container){}
ariel::MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator & other_iterator): Iterator(other_iterator){}
ariel::MagicalContainer::AscendingIterator::~AscendingIterator() {}
ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator& Iterator){
    return *this;
}
bool ariel::MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
    return false;
}
// bool ariel::MagicalContainer::AscendingIterator::operator==(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::AscendingIterator::operator!=(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::AscendingIterator::operator<(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::AscendingIterator::operator>(const Iterator &) const{
//     return false;
// }
int ariel::MagicalContainer::AscendingIterator::operator*() const{
    return -1;
}
ariel::MagicalContainer::Iterator& ariel::MagicalContainer::AscendingIterator::operator++(){
    return *this;
}
ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::begin() const{
    return AscendingIterator();
}
ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::end() const
{
    return AscendingIterator();
}
ariel::MagicalContainer::SideCrossIterator::SideCrossIterator() {}
ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer & container): Iterator(container){}
ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &){}
ariel::MagicalContainer::SideCrossIterator::~SideCrossIterator() {}
ariel::MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
    return *this;
}
// bool ariel::MagicalContainer::SideCrossIterator::operator==(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::SideCrossIterator::operator!=(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::SideCrossIterator::operator<(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::SideCrossIterator::operator>(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return false;
}
int ariel::MagicalContainer::SideCrossIterator::operator*(){
    return -1;
}
ariel::MagicalContainer::Iterator& ariel::MagicalContainer::SideCrossIterator::operator++(){
    return *this;
}
ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator();
}
ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator();
}
ariel::MagicalContainer::PrimeIterator::PrimeIterator(){}
ariel::MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer & container): Iterator(container){}
ariel::MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &){}
ariel::MagicalContainer::PrimeIterator::~PrimeIterator() {}
ariel::MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator&){
    return *this;
}
// bool ariel::MagicalContainer::PrimeIterator::operator==(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::PrimeIterator::operator!=(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::PrimeIterator::operator<(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return false;
}
// bool ariel::MagicalContainer::PrimeIterator::operator>(const Iterator &) const{
//     return false;
// }
bool ariel::MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return false;
}
int ariel::MagicalContainer::PrimeIterator::operator*(){
    return -1;
}
ariel::MagicalContainer::Iterator& ariel::MagicalContainer::PrimeIterator::operator++(){
    return *this;
}
ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator();
}
ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::end() const{
    return PrimeIterator();
}

bool ariel::isPrime(){
    return false;
}
