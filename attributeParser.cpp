#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <sstream>
#include <cstring>
#include <map>
#include <cctype>
#include <locale>
using namespace std;

map<string, string> attrValMap;

void createAttrValMap(int &N, string pretag) {
    if(!N)
        return;

    string line, tag, attr, val;

    getline(cin, line);

    int i = 1, j;

    if(line[i] == '/') {
        while(line[i] != '>')
            i++;

        if(pretag.size() > i-2)
            tag = pretag.substr(0, pretag.size() - i + 1);

        else
            tag = "";
    }

    else {
        while(line[i] != ' ' && line[i] != '>')
            i++;

        tag = line.substr(1, i-1);
        if(pretag != "")
            tag = pretag + "." + tag;

        while(line[i] != '>') {
            j = ++i;
            while(line[i] != ' ')
                i++;
            attr = line.substr(j, i-j);
            
            while(line[i] != '\"')
                i++;
            j = ++i;
            while(line[i] != '\"')
                i++;
            val = line.substr(j, i-j);
            i++;

            attrValMap[tag + "~" + attr] = val;
        }
    }
    createAttrValMap(--N, tag);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N, Q;
    string attr, val;
    
    cin >> N >> Q;
    cin.ignore();
    createAttrValMap(N, "");

    cout << "<<======================>>" << endl;
    for(auto m: attrValMap)
        cout << m.first  << " = " << m.second << endl;
    cout << "<<======================>>" << endl;


    while(Q--) {
        getline(cin, attr);

        val = attrValMap[attr];
        if(val == "")
            val = "Not Found!";

        cout << val << endl;
    }
    return 0;
}



//=========================================================================//

// trim from start (in place)
static inline void ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline string ltrim_copy(string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline string rtrim_copy(string s) {
    rtrim(s);
    return s;
}