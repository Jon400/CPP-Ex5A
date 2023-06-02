#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Magical containers intializtions"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    CHECK(container.size() == 5);
}
TEST_CASE("ignore adding duplicate numbers"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    CHECK(container.size() == 5);
}
TEST_CASE("remove elemnts from the container"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    container.removeElement(17);
    container.removeElement(2);
    CHECK(container.size() == 3);
    container.removeElement(25);
    container.removeElement(9);
    container.removeElement(3);
    CHECK(container.size() == 0);
}
TEST_CASE("throw an exception on remove unexisting elements"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    CHECK_THROWS(container.removeElement(25));
    CHECK(container.size() == 2);
    container.addElement(17);
    container.addElement(2);
    CHECK_THROWS(container.removeElement(25));
}
TEST_CASE("AscendingIterator initializations"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(ascIter);
    CHECK(ascIter == ascIter2);
    CHECK(ascIter2 == ascIter);
    CHECK(ascIter.begin() == ascIter2.begin());
    CHECK(ascIter2.begin() == ascIter.begin());
    CHECK(ascIter.end() == ascIter2.end());
    CHECK(ascIter2.end() == ascIter.end());
}
TEST_CASE("AscendingIterator pointing on the begin"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    CHECK(*ascIter.begin() == 2);
    SUBCASE("begin doesn't change after add element"){
        container.removeElement(4);
        CHECK(*ascIter.begin() == 2);
    }
    SUBCASE ("begin doesn't change after add element"){
        container.addElement(-30);
        CHECK(*ascIter.begin() == -30);
    }
    SUBCASE("begin doesn't change after remove element"){
        container.removeElement(2);
        CHECK(*ascIter.begin() == 3);
    }
}
TEST_CASE("AscendingIterator pointing on the end"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    CHECK_THROWS(*ascIter.end());
}
TEST_CASE("AscendingIterator equality and unequality operator"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer container2;
    // add in a different order from previous container
    container2.addElement(17);
    container2.addElement(2);
    container2.addElement(25);
    container2.addElement(3);
    container2.addElement(9);
    MagicalContainer::AscendingIterator ascIter1(container1);
    MagicalContainer::AscendingIterator ascIter2(container2);
    CHECK(ascIter1 == ascIter2);
    // now remove an element from container2
    container2.removeElement(3);
    CHECK(ascIter1 != ascIter2);
    // self equality
    CHECK_NOTHROW(bool b = (ascIter1 == ascIter1));
    CHECK(ascIter1 == ascIter1);
}
TEST_CASE("AscendingIterator increment"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container1);
    CHECK(*ascIter == 2);
    ++ascIter;
    CHECK(*ascIter == 3);
    ++ascIter;
    CHECK(*ascIter == 9);
    ++ascIter;
    CHECK(*ascIter == 17);
    ++ascIter;
    CHECK(*ascIter == 25);
    ++ascIter;
    CHECK(ascIter == ascIter.end());
    CHECK_THROWS(++ascIter);
}
TEST_CASE("AscendingIterator GE and LE"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container1);

    MagicalContainer::AscendingIterator ascIter_begin1 = ascIter.begin();
    MagicalContainer::AscendingIterator ascIter_begin2 = ascIter.begin();
    MagicalContainer::AscendingIterator ascIter_end = ascIter.end();
    CHECK(ascIter_begin1 == ascIter_begin2);
    ++ascIter_begin1;
    CHECK(ascIter_begin1 != ascIter_begin2);
    CHECK(ascIter_begin1 > ascIter_begin2);
    CHECK(ascIter_begin2 < ascIter_begin1);
    CHECK(ascIter_begin1 > ascIter_end);
    CHECK(ascIter_end < ascIter_begin1);
}  
TEST_CASE("AscendingIterator assinment operator"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    // in order to check that the copy is deep copy
    MagicalContainer::AscendingIterator ascIter1_begin = ascIter.begin();
    MagicalContainer::AscendingIterator ascIter2 = ascIter1_begin;
    CHECK(ascIter1_begin == ascIter2);
    ++ascIter1_begin;
    CHECK(ascIter1_begin != ascIter2);
}
TEST_CASE("AscendingIterator for each"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    int count = 0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        count++;
    }
    CHECK(count == 5);
}
TEST_CASE("SideCrossIterator initialization"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator sideCrossIter(container);
    MagicalContainer::SideCrossIterator sideCrossIter2(sideCrossIter);
    CHECK(sideCrossIter == sideCrossIter2);
    CHECK(sideCrossIter2 == sideCrossIter);
    CHECK(sideCrossIter.begin() == sideCrossIter2.begin());
    CHECK(sideCrossIter2.begin() == sideCrossIter.begin());
    CHECK(sideCrossIter.end() == sideCrossIter2.end());
    CHECK(sideCrossIter2.end() == sideCrossIter.end());
}
TEST_CASE("SideCrossIterator pointing on the begin"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator sideCrossIter(container);
    CHECK(*sideCrossIter.begin() == 2);
    SUBCASE("begin doesn't change after add element"){
        container.removeElement(4);
        CHECK(*sideCrossIter.begin() == 2);
    }
    SUBCASE ("begin changes after add element"){
        container.addElement(-30);
        CHECK(*sideCrossIter.begin() == -30);
    }
    SUBCASE("begin changes after remove element"){
        container.removeElement(2);
        CHECK(*sideCrossIter.begin() == 3);
    }
}
TEST_CASE("SideCrossIterator pointing on the end"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator sideCrossIter(container);
    CHECK_THROWS(*sideCrossIter.end());
}
TEST_CASE("SideCrossIterator equality and unequality operator"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer container2;
    // add in a different order from previous container
    container2.addElement(17);
    container2.addElement(2);
    container2.addElement(25);
    container2.addElement(3);
    container2.addElement(9);
    MagicalContainer::SideCrossIterator sideCrossIter1(container1);
    MagicalContainer::SideCrossIterator sideCrossIter2(container2);
    CHECK(sideCrossIter1 == sideCrossIter2);
    // now remove an element from container2
    container2.removeElement(3);
    CHECK(sideCrossIter1 != sideCrossIter2);
    // self equality
    CHECK_NOTHROW(bool b = (sideCrossIter1 == sideCrossIter1));
    CHECK(sideCrossIter1 == sideCrossIter1);
}
TEST_CASE("SideCrossIterator increment"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::SideCrossIterator sideCrossIter(container1);
    CHECK(*sideCrossIter == 2);
    ++sideCrossIter;
    CHECK(*sideCrossIter == 25);
    ++sideCrossIter;
    CHECK(*sideCrossIter == 3);
    ++sideCrossIter;
    CHECK(*sideCrossIter == 17);
    ++sideCrossIter;
    CHECK(*sideCrossIter == 9);
    ++sideCrossIter;
    CHECK(sideCrossIter == sideCrossIter.end());
    CHECK_THROWS(++sideCrossIter);
}
TEST_CASE("SideCrossIterator GE and LE"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::SideCrossIterator sideCrossIter(container1);
    MagicalContainer::SideCrossIterator sideCrossIter_begin1 = sideCrossIter.begin();
    MagicalContainer::SideCrossIterator sideCrossIter_begin2 = sideCrossIter.begin();
    MagicalContainer::SideCrossIterator sideCrossIter_end = sideCrossIter.end();
    CHECK(sideCrossIter_begin1 == sideCrossIter_begin2);
    ++sideCrossIter_begin1;
    CHECK(sideCrossIter_begin1 != sideCrossIter_begin2);
    CHECK(sideCrossIter_begin1 > sideCrossIter_begin2);
    CHECK(sideCrossIter_begin2 < sideCrossIter_begin1);
    CHECK(sideCrossIter_begin1 > sideCrossIter_end);
    CHECK(sideCrossIter_end < sideCrossIter_begin1);
     ++sideCrossIter_begin1;
    CHECK(sideCrossIter_begin1 != sideCrossIter_begin2);
    CHECK(sideCrossIter_begin1 > sideCrossIter_begin2);
    CHECK(sideCrossIter_begin2 < sideCrossIter_begin1);
    CHECK(sideCrossIter_begin1 > sideCrossIter_end);
    CHECK(sideCrossIter_end < sideCrossIter_begin1);
}
TEST_CASE("SideCrossIterator for each"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::SideCrossIterator sideCrossIter(container1);
    int count = 0;
    for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
        count++;
    }
    CHECK(count == 5);
}
TEST_CASE("PrimeIterator initialization"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(primeIter);
    CHECK(primeIter == primeIter2);
    CHECK(primeIter2 == primeIter);
    CHECK(primeIter.begin() == primeIter2.begin());
    CHECK(primeIter2.begin() == primeIter.begin());
    CHECK(primeIter.end() == primeIter2.end());
    CHECK(primeIter2.end() == primeIter.end());
}
TEST_CASE("PrimeIterator pointing on the begin"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);
    CHECK(*primeIter.begin() == 2);
    SUBCASE("begin doesn't change after add element"){
        container.removeElement(4);
        CHECK(*primeIter.begin() == 2);
    }
    SUBCASE("begin changes after remove element"){
        container.removeElement(2);
        CHECK(*primeIter.begin() == 3);
    }
    SUBCASE ("begin changes after add element"){
        container.addElement(2);
        CHECK(*primeIter.begin() == 2);
    }
}
TEST_CASE("PrimeIterator pointing on the end"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);
    CHECK_THROWS(*primeIter.end());
}
TEST_CASE("PrimeIterator equality and unequality operator"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer container2;
    // add in a different order from previous container
    container2.addElement(17);
    container2.addElement(2);
    container2.addElement(25);
    container2.addElement(3);
    container2.addElement(9);
    MagicalContainer::PrimeIterator primeIter1(container1);
    MagicalContainer::PrimeIterator primeIter2(container2);
    CHECK(primeIter1 == primeIter2);
    // now remove an element from container2
    container2.removeElement(3);
    CHECK(primeIter1 != primeIter2);
    // self equality
    CHECK_NOTHROW(bool b = (primeIter1 == primeIter1));
    CHECK(primeIter1 == primeIter1);
}
TEST_CASE("PrimeIterator increment"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container1);
    CHECK(*primeIter == 2);
    ++primeIter;
    CHECK(*primeIter == 3);
    ++primeIter;
    CHECK(*primeIter == 17);
    ++primeIter;
    CHECK(primeIter == primeIter.end());
    CHECK_THROWS(++primeIter);
}
TEST_CASE("PrimeIterator GE and LE"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container1);
    MagicalContainer::PrimeIterator primeIter_begin1 = primeIter.begin();
    MagicalContainer::PrimeIterator primeIter_begin2 = primeIter.begin();
    MagicalContainer::PrimeIterator primeIter_end = primeIter.end();
    CHECK(primeIter_begin1 == primeIter_begin2);
    ++primeIter_begin1;
    CHECK(primeIter_begin1 != primeIter_begin2);
    CHECK(primeIter_begin1 > primeIter_begin2);
    CHECK(primeIter_begin2 < primeIter_begin1);
    CHECK(primeIter_begin1 > primeIter_end);
    CHECK(primeIter_end < primeIter_begin1);
     ++primeIter_begin1;
    CHECK(primeIter_begin1 != primeIter_begin2);
    CHECK(primeIter_begin1 > primeIter_begin2);
    CHECK(primeIter_begin2 < primeIter_begin1);
    CHECK(primeIter_begin1 > primeIter_end);
    CHECK(primeIter_end < primeIter_begin1);
}
TEST_CASE("PrimeIterator for each"){
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container1);
    int count = 0;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        count++;
    }
    CHECK(count == 3);
}
TEST_CASE("No primes element in the container"){
    MagicalContainer container1;
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(15);
    container1.addElement(21);
    container1.addElement(27);
    MagicalContainer::PrimeIterator primeIter(container1);
    CHECK(primeIter.begin() == primeIter.end());
}
// TEST_CASE("Using operators on iterators of different type"){
//     MagicalContainer container;
//     container.addElement(17);
//     container.addElement(2);
//     container.addElement(25);
//     container.addElement(9);
//     container.addElement(3);
//     MagicalContainer::AscendingIterator ascIter(container);
//     MagicalContainer::PrimeIterator primeIter(container);
//     MagicalContainer::SideCrossIterator sideCrossIter(container);
//     CHECK_THROWS(ascIter.begin() > primeIter.begin());
//     CHECK_THROWS(ascIter.begin() < primeIter.begin());
//     CHECK_THROWS(ascIter.begin() == primeIter.begin());
//     CHECK_THROWS(ascIter.begin() != primeIter.begin());
//     CHECK_THROWS(sideCrossIter.begin() > primeIter.begin());
//     CHECK_THROWS(sideCrossIter.begin() < primeIter.begin());
//     CHECK_THROWS(sideCrossIter.begin() == primeIter.begin());
//     CHECK_THROWS(sideCrossIter.begin() != primeIter.begin());
//     CHECK_THROWS(ascIter.begin() > sideCrossIter.begin());
//     CHECK_THROWS(ascIter.begin() < sideCrossIter.begin());
//     CHECK_THROWS(ascIter.begin() == sideCrossIter.begin());
//     CHECK_THROWS(ascIter.begin() != sideCrossIter.begin());
// }