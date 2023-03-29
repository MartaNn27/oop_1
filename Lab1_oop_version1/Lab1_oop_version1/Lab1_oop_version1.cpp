
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;


// об'єднання
template<typename T>
T set_Union(const T& first, const T& second)
{
    T res{};
    set_union(first.cbegin(), first.cend(),
        second.cbegin(), second.cend(),
        insert_iterator<T>{res, res.begin()});
    return res;
}

/// різниця
template<typename T>
T set_Difference(const T& first, const T& second)
{
    T res{};
    set_difference(first.cbegin(), first.cend(),
        second.cbegin(), second.cend(),
        insert_iterator<T>{res, res.begin()});
    return res;
}

// перетин
template<typename T>
T set_Intersection(const T& first, const T& second)
{
    T res{};
    set_intersection(first.cbegin(), first.cend(),
        second.cbegin(), second.cend(),
        insert_iterator<T>{res, res.begin()});
    return res;
}

int main()
{

    std::set<int> A;
    std::set<int> B;

    cout << " count for A" << endl;
    int countA;
    cin >> countA;
    cout << "enter numbers for A" << endl;
    int z;
    for (int i = 0; i < countA; i++) {

        cin >> z;
        A.insert(z);
    }

    set<int>::const_iterator iter;
    iter = A.begin();
    cout << "  ";
    while (iter != A.end()) {
        cout << *iter << " ";
        ++iter;
    }

    cout << "\n";


    cout << " count for B" << endl;
    int countB;

    cin >> countB;
    int y;
    cout << "enter numbers for B" << endl;
    for (int i = 0; i < countB; i++) {

        cin >> y;
        B.insert(y);
    }

    set<int>::const_iterator iter2;
    iter2 = B.begin();
    cout << "  ";
    while (iter2 != B.end()) {
        cout << *iter2 << " ";
        ++iter2;
    }

    cout << "\n";




    std::set<int> res{};

    {
        cout << " Result for union: ";

        res = set_Union(A, B);
        for (const auto& it : res)  cout << it << ' ';
        cout << endl;

        cout << "  Result for difference:  ";
        res = set_Difference(A, B);

        for (const auto& it : res) cout << it << ' ';
        cout << std::endl;

        cout << " Result for intersection: ";
        res = set_Intersection(A, B);
        for (const auto& it : res) cout << it << ' ';
        cout << endl;


    }


    cout << "A refers to B as  " << A.size() << "/" << B.size();

    std::cout << std::less<int>{}(A.size(), B.size()) << " A < B" << '\n';
    std::cout << std::equal_to<int>{}(A.size(), B.size()) << " A = B" << '\n';
    std::cout << std::greater<int>{}(A.size(), B.size()) << " A > B" << '\n';


    int del = 0;
    cout << "\nfind ";
    cin >> del;
    if (A.count(del) and B.count(del)) {

        cout << "A i B";
    }
    else if (A.count(del)) {

        cout << "element " << *A.find(del) << " - found in A!" << endl;

    }
    else if (B.count(del)) {
        cout << "element " << *B.find(del) << " - found in B!" << endl;
    }
    else {
        cout << "not found";
    }






}
