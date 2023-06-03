#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer() {}

void MagicalContainer::addElement(int element)
{
    this->elements.push_back(element);
}

void MagicalContainer::removeElement(int element)
{
    return;
}

int MagicalContainer::size()
{
    return this->elements.size();
}

// const vector<int> &MagicalContainer::getElements() const
// {

// }

// ------------------- Ascending Iterator -------------------

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(&container), currentIndex(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &other) {}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    ++currentIndex;
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    return this->container->elements[currentIndex];
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    if (container == other.container)
        return true;
    else
        return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    if (container != other.container)
        return true;
    else
        return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return false;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(*container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator iter(*container);
    // point to the end of the container
    iter.currentIndex = container->elements.size();
    return iter;
}

// ------------------- SideCross Iterator -------------------

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(&container), currentIndex(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &other) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    currentIndex++;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    return this->container->elements[currentIndex];
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if (this->container == other.container)
        return true;
    else
        return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    if (this->container != other.container)
        return true;
    else
        return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return false;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(*container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator iter(*container);
    // point to the end of the container
    iter.currentIndex = this->container->elements.size();
    return iter;
}

// ------------------- Prime Iterator -------------------

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(&container), currentIndex(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &other) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    ++currentIndex;
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return this->container->elements[currentIndex];
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    if (this->container == other.container)
        return true;
    else
        return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    if (this->container != other.container)
        return true;
    else
        return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return false;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(*container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator iter(*container);
    // point to the end of the container
    currentIndex = this->container->elements.size();
    return iter;
}