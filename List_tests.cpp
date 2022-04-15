// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(EMPTY) {
List<int> myList;
List<int> myList2;
myList2.push_front(63);
ASSERT_FALSE(myList2.empty());
ASSERT_TRUE(myList.empty());
}

TEST(testfront) {
List<int> myList;
myList.push_front(45);
ASSERT_EQUAL(myList.front(), 45);

}

TEST(pushFront) {
 List<int> myList;
 List<int> myList2;
myList.push_front(45);
myList2.push_front(77);
myList2.push_front(88);
myList2.push_front(12);
ASSERT_EQUAL(myList2.size(), 3);
ASSERT_EQUAL(myList.front(), 45);   

}

TEST(testCLEAR) {
List<int> myList;
myList.push_front(45);
myList.push_back(65);
myList.clear();
ASSERT_TRUE(myList.empty());

}

TEST(testBack) {
List<int> myList;
myList.push_back(47);
myList.push_back(45);
ASSERT_EQUAL(myList.back(), 45);
}

TEST(testSize) {
List<int> myList;
myList.push_front(45);
myList.push_back(65);
ASSERT_EQUAL(myList.size(), 2);
}

TEST(popBack) {
List<int> myList;
myList.push_front(45); 
myList.push_back(64);
myList.pop_back();
ASSERT_NOT_EQUAL(myList.back(), 64);
myList.pop_back();
ASSERT_TRUE(myList.empty());
}

TEST(popFront) {
List<int> myList;
myList.push_front(45); 
myList.push_back(64);
myList.pop_front();
ASSERT_NOT_EQUAL(myList.front(), 45);
myList.pop_front();
ASSERT_TRUE(myList.empty());
}

TEST(test_empty_func) {
    // Add test code here
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_size) {
    // Add test code here
    List<int> empty_list;
    ASSERT_TRUE(empty_list.size() == 0);
}

TEST(test_front) {
    // Add test code here
    int a = 3;
    int b = 4;
    int c = 5;
    int d = 6;
    int e = 7;
    List<int> empty_list;
    
    empty_list.push_front(e);
    empty_list.push_front(d);
    empty_list.push_front(c);
    empty_list.push_front(b);
    empty_list.push_front(a);
    ASSERT_TRUE(empty_list.front() == 3);
    empty_list.pop_front();
    ASSERT_TRUE(empty_list.front() == 4);
    empty_list.pop_front();
    ASSERT_TRUE(empty_list.front() == 5);
    empty_list.pop_front();
    ASSERT_TRUE(empty_list.front() == 6);
    empty_list.pop_front();
    ASSERT_TRUE(empty_list.front() == 7);
    empty_list.pop_front();
}

TEST(test_back) {
    // Add test code here
    int a = 3;
    int b = 4;
    int c = 5;
    int d = 6;
    int e = 7;
    List<int> empty_list;
    
    empty_list.push_back(e);
    empty_list.push_back(d);
    empty_list.push_back(c);
    empty_list.push_back(b);
    empty_list.push_back(a);
    ASSERT_TRUE(empty_list.back() == 3);
    empty_list.pop_back();
    ASSERT_TRUE(empty_list.back() == 4);
    empty_list.pop_back();
    ASSERT_TRUE(empty_list.back() == 5);
    empty_list.pop_back();
    ASSERT_TRUE(empty_list.back() == 6);
    empty_list.pop_back();
    ASSERT_TRUE(empty_list.back() == 7);
    empty_list.pop_back();
}

TEST(test_clear) {
    // Add test code here
    int a = 3;
    int b = 4;
    int c = 5;
    int d = 6;
    int e = 7;
    List<int> empty_list;
    
    empty_list.push_back(e);
    empty_list.push_back(d);
    empty_list.push_back(c);
    empty_list.push_back(b);
    empty_list.push_back(a);
    ASSERT_TRUE(empty_list.back() == 3);
    ASSERT_TRUE(empty_list.size()==5);
    empty_list.clear();
    ASSERT_TRUE(empty_list.size()==0);
}

//Above are the tests for the list

TEST(test_it_basic_add) {
    List<int> list;
    for (int i = 1; i < 5; ++i) {
        list.push_back(i);
    }
    int cur = 1;

    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        ASSERT_TRUE((*it) == cur);
        cur++;
    }
}

TEST(test_it2) {
    List<double> list;
    List<double>::Iterator it_end;
    
    for (double i = 1.0; i < 5.0; ++i) {
        list.push_back(i+0.1);
    }
    double cur = 4.1;
    int cnt = 0;
    for (List<double>::Iterator it = list.begin(); it != list.end(); ++it) {
        if(cnt == 3){
            it_end = it;
        }
        cnt++;
    }
    for (List<double>::Iterator it = it_end; it != list.begin(); --it) {
        //ASSERT_EQUAL((*it), cur);
        cur--;
    }
}

TEST(test_it_basic_insert_erase) {
    List<double> list;
    for (double i = 1; i < 5; ++i) {
        list.push_back(i+0.1);
    }
    ASSERT_TRUE(list.size() == 4);
    list.insert(list.begin(), 5.1);
    ASSERT_TRUE(list.front() == 5.1);//insert at the front
    ASSERT_TRUE(list.size() == 5);
    list.erase(list.begin());//erase at the front
    ASSERT_TRUE(list.front() == 1.1);
    ASSERT_TRUE(list.size() == 4);
    list.insert(list.end(),5.1);//insert at the end
    ASSERT_TRUE(list.back() == 5.1);
    ASSERT_TRUE(list.size() == 5);
    List<double>::Iterator it_test = list.begin();
    ASSERT_TRUE(*it_test == 1.1);
    ++it_test;
    ASSERT_TRUE(*it_test == 2.1);
    ++it_test;
    ASSERT_TRUE(*it_test == 3.1);
    --it_test;
    ASSERT_TRUE(*it_test == 2.1);
    ASSERT_TRUE(*++--it_test == 2.1);
    ASSERT_TRUE(*--++it_test == 2.1);
    list.erase(it_test);
    ASSERT_TRUE(*++list.begin() == 3.1);//erase in the middle
    ASSERT_TRUE(list.size() == 4);
    list.insert(++list.begin(), 2.1);
    ASSERT_TRUE(*++list.begin() == 2.1);//insert in the middle
    ASSERT_TRUE(list.size() == 5);//size changes
    it_test = list.begin();
    ++it_test;
    ++it_test;
    ++it_test;
    ++it_test;
    ASSERT_TRUE(*it_test == 5.1);
    list.erase(it_test);    //erase the end
    it_test = list.begin();
    ++it_test;
    ++it_test;
    ++it_test;
    ASSERT_TRUE(*it_test == 4.1);
    ++it_test;
    ASSERT_TRUE(it_test == list.end());
}

TEST(test_list_copy) {
    List<double> list;
    for (double i = 1; i < 5; ++i) {
        list.push_back(i+0.1);
    }
    List<double> copy_list(list);//copy ctor
    double cur = 1.1;
    for (List<double>::Iterator it = copy_list.begin(); it != copy_list.end(); ++it) {
        ASSERT_TRUE(*it == cur);
        cur++;
    }
}

TEST(test_list_copy_1) {
    List<double> list;
    for (double i = 1; i < 2; ++i) {
        list.push_back(i+0.1);
    }
    List<double> copy_list(list);//copy ctor
    double cur = 1.1;
    for (List<double>::Iterator it = copy_list.begin(); it != copy_list.end(); ++it) {
        ASSERT_TRUE(*it == cur);
        cur++;
    }
}

TEST(test_list_assignment) {
    List<double> list;
    for (double i = 1; i < 5; ++i) {
        list.push_back(i+0.1);
    }
    List<double> test_list = list;//list assignment op
    double cur = 1.1;
    for (List<double>::Iterator it = test_list.begin(); it != test_list.end(); ++it) {
        ASSERT_TRUE(*it == cur);
        cur++;
    }
}

TEST(test_from_compile_check) {
    List<int> my_list;

    List<int> list2(my_list);
    list2 = my_list;//assign empty list

    List<int>::Iterator iter = my_list.begin();
    my_list.insert(iter, 42);
    iter = my_list.begin();
    ASSERT_TRUE(*iter == 42);
    my_list.erase(iter);
    iter = my_list.begin();

    List<int>::Iterator iter2 = my_list.end();
    const List<int>::Iterator iter3 = iter2;

    bool b = iter == iter2;
    ASSERT_TRUE(b);
    b = iter3 == my_list.end();
    ASSERT_TRUE(b);
    b = my_list.end() == iter3;
    ASSERT_TRUE(b);
    my_list.push_front(42);
    my_list.push_back(43);
    iter = my_list.begin();
    ASSERT_TRUE(*iter == 42);
    b = iter != iter2;
    ASSERT_TRUE(b);
    b = iter3 != my_list.end();
    ASSERT_TRUE(!b);
    b = my_list.end() != iter3;
    ASSERT_TRUE(!b);
    ++iter;

    List<int>::Iterator iter_cpy(iter); //it copy op
    ASSERT_TRUE(iter_cpy == iter);
    List<int>::Iterator iter_cpy1 = iter_cpy;  //it assignment op
    ASSERT_TRUE(iter_cpy1 == iter);

    my_list.insert(my_list.begin(), 3);
    ASSERT_TRUE(my_list.front() == 3);
    my_list.erase(my_list.begin());

    List<int> list3;
    list3.push_back(3);
    ASSERT_TRUE(*list3.begin() == 3);

    List<int> list4;
    list4.push_back(4);
    ASSERT_TRUE(list4.size() == 1);

    my_list.clear();
    ASSERT_TRUE(my_list.size() == 0);//clear check
}

TEST(test_it_operator_tests) {
    List<int> list;
    for (int i = 1; i < 5; ++i) {
        list.push_back(i);
    }
    List<int>::Iterator it_test = list.begin();
    ++it_test;
    ASSERT_FALSE(it_test == list.begin());
    ASSERT_TRUE(it_test != list.begin());
}

TEST(test_oppIT) {
    List<int> list1;
    list1.push_front(1);
    list1.push_back(2);
    list1.push_back(4);
    List<int> list2;
    List<int>::Iterator iter = list1.begin();
    ++iter;
    List<int>::Iterator iter2 = iter;
    ++iter2;
    ASSERT_EQUAL(*iter2, 4);
}
TEST(test_oppNotEQ) {
List<int> list1;
    list1.push_front(5);
    list1.push_back(2);
    list1.push_back(4);

    List<int>::Iterator iter = list1.begin();
    List<int>::Iterator iter2 = list1.begin();
    ++iter;
    ++iter;
    ++iter2;

    ASSERT_TRUE(iter != iter2);
}

TEST(test_oppEQ) {
    List<int> list1;
    list1.push_front(7);
    list1.push_back(6);
    list1.push_back(5);

    List<int>::Iterator iter = list1.begin();
    List<int>::Iterator iter2 = list1.begin();
    ++iter;
    ++iter2;

    ASSERT_TRUE(iter == iter2);
}

TEST(test_oppMINUS) {
    List<int> list1;
    list1.push_front(5);
    list1.push_back(2);
    list1.push_back(4);
    List<int>::Iterator iter = list1.begin();
    ++iter;
    ++iter;
    --iter;

    ASSERT_EQUAL(*iter, 2);
}

TEST(test_oppBEG) {
List<int> list1;
    list1.push_front(6);
    list1.push_front(3);
    list1.push_back(2);
    List<int>::Iterator Beg = list1.begin();

    ASSERT_EQUAL(*Beg, 3);
}

TEST(test_oppEND) {
    List<int> list1;
    list1.push_front(7);
    list1.push_back(4);

    List<int>::Iterator End = list1.end();
    List<int>::Iterator null;
    
    ASSERT_EQUAL(End, null);
}


TEST_MAIN()