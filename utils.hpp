#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stack>
#include <deque>

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

template<typename T> void print(T a) {
    std::cerr << a;
}
static void print(long long a) {
    std::cerr << a << "L";
}
static void print(std::string a) {
    std::cerr << '"' << a << '"';
}
template<typename T> void print(std::vector<T> a) {
    std::cerr << "{";
    for (int i = 0 ; i != a.size() ; i++) {
        if (i != 0) std::cerr << ", ";
        print(a[i]);
    }
    std::cerr << "}" << std::endl;
}
template<typename T> void eq(int n, T have, T need) {
    if (have == need) {
        std::cerr << "Case " << n << " passed." << std::endl;
    } else {
        std::cerr << "Case " << n << " failed: expected ";
        print(need);
        std::cerr << " received ";
        print(have);
        std::cerr << "." << std::endl;
    }
}
template<typename T> void eq(int n, std::vector<T> have, std::vector<T> need) {
    if(have.size() != need.size() ) {
        std::cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print(have);
        print(need);
        return;
    }
    for(int i= 0; i < have.size(); i++) {
        if(have[i] != need[i]) {
            std::cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print(have);
            print(need);
            return;
        }
    }
    std::cerr << "Case " << n << " passed." << std::endl;
}
static void eq(int n, std::string have, std::string need) {
    if (have == need) {
        std::cerr << "Case " << n << " passed." << std::endl;
    } else {
        std::cerr << "Case " << n << " failed: expected ";
        print(need);
        std::cerr << " received ";
        print(have);
        std::cerr << "." << std::endl;
    }
}
