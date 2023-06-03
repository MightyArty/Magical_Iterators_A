#include "doctest.h"

#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Magical Container")
{
    SUBCASE("Constructors")
    {
        MagicalContainer container1;
        MagicalContainer container2;
        MagicalContainer container3;

        CHECK(container1.size() == 0);
        CHECK(container2.size() == 0);

        MagicalContainer::AscendingIterator iter1(container1);
        CHECK_EQ(iter1.begin(), iter1.end());

        MagicalContainer::SideCrossIterator iter2(container2);
        CHECK_EQ(iter2.begin(), iter2.end());

        MagicalContainer::PrimeIterator iter3(container3);
        CHECK_EQ(iter3.begin(), iter3.end());
    }

    SUBCASE("Add element method")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);

        MagicalContainer::AscendingIterator iter(container);

        CHECK((*iter) == 5);
        ++iter;
        CHECK((*iter) == 10);
        ++iter;
        CHECK((*iter) == 15);
    }

    SUBCASE("Remove element method")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        container.addElement(20);

        container.removeElement(10);

        MagicalContainer::AscendingIterator iter(container);
        for (auto i = iter.begin(); i != iter.end(); ++i)
        {
            CHECK(*i != 10);
        }
    }

    SUBCASE("Size of Magical Container")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        container.addElement(20);

        CHECK(container.size() == 4);
    }
}

TEST_CASE("Ascending Iterator")
{
    SUBCASE("Constructor, checking that the container is sorted")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        container.addElement(1);
        container.addElement(-20);

        MagicalContainer::AscendingIterator iter(container);

        vector<int> sorted = {-20, 1, 5, 10, 15};
        size_t currentIndex = 0;

        for (auto i = iter.begin(); i != iter.end(); ++i)
        {
            CHECK(*i == sorted[currentIndex]);
            currentIndex++;
        }
    }

    SUBCASE("Operator ++")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(9);

        MagicalContainer::AscendingIterator iter(container);

        ++iter;
        CHECK(*iter == 3);

        ++iter;
        CHECK(*iter == 9);
    }

    SUBCASE("Operator *")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(9);

        MagicalContainer::AscendingIterator iter(container);

        CHECK(*iter == 2);
    }

    SUBCASE("Operator ==")
    {
        MagicalContainer container1;
        container1.addElement(2);
        container1.addElement(3);
        container1.addElement(9);

        MagicalContainer container2;
        container2.addElement(2);
        container2.addElement(3);
        container2.addElement(9);

        MagicalContainer::AscendingIterator iter1(container1);
        MagicalContainer::AscendingIterator iter2(container2);

        CHECK(iter1 == iter2);
    }

    SUBCASE("Operator !=")
    {
        MagicalContainer container1;
        container1.addElement(2);
        container1.addElement(3);
        container1.addElement(9);

        MagicalContainer container2;
        container2.addElement(4);
        container2.addElement(6);
        container2.addElement(8);

        MagicalContainer::AscendingIterator iter1(container1);
        MagicalContainer::AscendingIterator iter2(container2);

        CHECK(iter1 != iter2);
    }
}

TEST_CASE("Side Cross Iterator")
{
    SUBCASE("Constructor, checking that the container is in cross order")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::SideCrossIterator iter(container);

        vector<int> crossed = {1, 14, 2, 5, 4};
        size_t currentIndex = 0;

        for (auto i = iter.begin(); i != iter.end(); ++i)
        {
            CHECK(*i == crossed[currentIndex]);
            currentIndex++;
        }
    }

    SUBCASE("Operator ++")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::SideCrossIterator iter(container);

        ++iter;
        CHECK(*iter == 14);

        ++iter;
        CHECK(*iter == 2);

        ++iter;
        CHECK(*iter == 5);
    }

    SUBCASE("Operator *")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::SideCrossIterator iter(container);

        CHECK(*iter == 1);
    }

    SUBCASE("Operator ==")
    {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(4);
        container1.addElement(5);
        container1.addElement(14);

        MagicalContainer container2;
        container2.addElement(1);
        container2.addElement(2);
        container2.addElement(4);
        container2.addElement(5);
        container2.addElement(14);

        MagicalContainer::SideCrossIterator iter1(container1);
        MagicalContainer::SideCrossIterator iter2(container2);

        CHECK(iter1 == iter2);
    }

    SUBCASE("Operator !=")
    {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(4);
        container1.addElement(5);
        container1.addElement(14);

        MagicalContainer container2;
        container2.addElement(1);
        container2.addElement(2);
        container2.addElement(4);
        container2.addElement(5);
        container2.addElement(13);

        MagicalContainer::SideCrossIterator iter1(container1);
        MagicalContainer::SideCrossIterator iter2(container2);

        CHECK(iter1 != iter2);
    }
}

TEST_CASE("Prime iterator")
{
    SUBCASE("Constructor, checking that the container has only prime numbers left")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::PrimeIterator iter(container);

        vector<int> primes = {2, 5};
        size_t currentIndex = 0;

        for (auto i = iter.begin(); i != iter.end(); ++i)
        {
            CHECK(*i == primes[currentIndex]);
            currentIndex++;
        }
    }

    SUBCASE("Operator ++")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::PrimeIterator iter(container);

        ++iter;
        CHECK(*iter == 5);
    }

    SUBCASE("Operator *")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::PrimeIterator iter(container);

        CHECK(*iter == 2);
    }

    SUBCASE("Operator ==")
    {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(4);
        container1.addElement(5);
        container1.addElement(14);

        MagicalContainer container2;
        container2.addElement(1);
        container2.addElement(2);
        container2.addElement(4);
        container2.addElement(5);
        container2.addElement(14);

        MagicalContainer::PrimeIterator iter1(container1);
        MagicalContainer::PrimeIterator iter2(container2);

        CHECK(iter1 == iter2);
    }

    SUBCASE("Operator !=")
    {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(4);
        container1.addElement(5);
        container1.addElement(14);

        MagicalContainer container2;
        container2.addElement(1);
        container2.addElement(2);
        container2.addElement(4);
        container2.addElement(7);
        container2.addElement(14);

        MagicalContainer::PrimeIterator iter1(container1);
        MagicalContainer::PrimeIterator iter2(container2);

        CHECK(iter1 != iter2);
    }
}

TEST_CASE("Throw/NoThrow Exceptions")
{
    SUBCASE("Compering Iterators of different containers")
    {
        MagicalContainer container1;
        MagicalContainer container2;
        MagicalContainer::AscendingIterator iter1(container1);
        MagicalContainer::AscendingIterator iter2(container2);

        CHECK_THROWS_AS(iter1.operator==(iter2), invalid_argument);
        CHECK_THROWS_AS(iter1.operator!=(iter2), invalid_argument);
        CHECK_THROWS_AS(iter1.operator<(iter2), invalid_argument);
        CHECK_THROWS_AS(iter1.operator>(iter2), invalid_argument);

        MagicalContainer container3;
        MagicalContainer container4;
        MagicalContainer::SideCrossIterator iter3(container3);
        MagicalContainer::SideCrossIterator iter4(container4);

        CHECK_THROWS_AS(iter3.operator==(iter4), invalid_argument);
        CHECK_THROWS_AS(iter3.operator!=(iter4), invalid_argument);
        CHECK_THROWS_AS(iter3.operator<(iter4), invalid_argument);
        CHECK_THROWS_AS(iter3.operator>(iter4), invalid_argument);

        MagicalContainer container5;
        MagicalContainer container6;
        MagicalContainer::PrimeIterator iter5(container5);
        MagicalContainer::PrimeIterator iter6(container6);

        CHECK_THROWS_AS(iter5.operator==(iter6), invalid_argument);
        CHECK_THROWS_AS(iter5.operator!=(iter6), invalid_argument);
        CHECK_THROWS_AS(iter5.operator<(iter6), invalid_argument);
        CHECK_THROWS_AS(iter5.operator>(iter6), invalid_argument);
    }

    SUBCASE("Add Method")
    {
        MagicalContainer container;

        CHECK_NOTHROW(container.addElement(1));
        CHECK_NOTHROW(container.addElement(2));
        CHECK_NOTHROW(container.addElement(4));
    }

    SUBCASE("Magical Container Remove Method")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(2);
        container.addElement(4);

        CHECK_THROWS_AS(container.removeElement(3), runtime_error);

        CHECK_NOTHROW(container.removeElement(1));
        CHECK_NOTHROW(container.removeElement(2));
        CHECK_NOTHROW(container.removeElement(4));

        CHECK_THROWS_AS(container.removeElement(5), runtime_error);
    }

    SUBCASE("Ascending Iterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::AscendingIterator iter(container);

        CHECK_NOTHROW(iter.begin());
        CHECK_NOTHROW(iter.end());

        container.removeElement(1);
        container.removeElement(2);
        container.removeElement(4);
        container.removeElement(5);
        container.removeElement(14);

        CHECK_THROWS_AS(iter.begin(), runtime_error);
        CHECK_THROWS_AS(iter.end(), runtime_error);
    }

    SUBCASE("Side Cross Iterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::SideCrossIterator iter(container);

        CHECK_NOTHROW(iter.begin());
        CHECK_NOTHROW(iter.end());

        container.removeElement(1);
        container.removeElement(2);
        container.removeElement(4);
        container.removeElement(5);
        container.removeElement(14);

        CHECK_THROWS_AS(iter.begin(), runtime_error);
        CHECK_THROWS_AS(iter.end(), runtime_error);
    }

    SUBCASE("Prime Iterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::PrimeIterator iter(container);

        CHECK_NOTHROW(iter.begin());
        CHECK_NOTHROW(iter.end());

        container.removeElement(1);
        container.removeElement(2);
        container.removeElement(4);
        container.removeElement(5);
        container.removeElement(14);

        CHECK_THROWS_AS(iter.begin(), runtime_error);
        CHECK_THROWS_AS(iter.end(), runtime_error);
    }
}