#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;

struct AirportPair {
    const char szAirport1[4];
    const char szAirport2[4];
    const unsigned int nMileage;
};

static AirportPair s_rgAirportPairs[] = {
    { "SEA", "DEN", 1024 },
    { "SEA", "LAS", 866 },
    { "SEA", "LAX", 954 },
    { "DEN", "ORD", 888 },
    { "LAS", "ORD", 1514 },
    { "ORD", "DFW", 802 },
    { "LAX", "DFW", 1235 },
    { "JFK", "MIA", 1090 },
    { "MIA", "BIS", 1831 },
    { "SEA", "ANC", 1448 },
    { "ANC", "ORD", 2846 },
    { "JFK", "BIS", 1407 },
    { "DFW", "SMF", 1431 },
    { "JFK", "AUS", 1521 },
    { "DFW", "IAH", 140 },
    { "IAH", "ANC", 3266 },
};

const unsigned int s_nAirportPairCount = 16;

int main() {
    string line;
    int distance = 0;
    string path;
    map<string, int> dest1, dest2, shortest_path;
    bool flag = false;

    while (getline(cin, line)) {
        cout << line << endl;

        istringstream streamInput(line);
        vector<string> tokenInputs{
            istream_iterator<string>{streamInput},
            istream_iterator<string>{}};

        int length = tokenInputs.size();
        if(length < 2)
        {
            cout << "Insufficient Input"<< endl;
        }

        dest1.clear();
        dest2.clear();
        shortest_path.clear();

        for(int i = 0; i < s_nAirportPairCount; i++) 
        {
            if(strcmp(s_rgAirportPairs[i].szAirport1, tokenInputs[0].c_str()) == 0)
            {
                dest2.insert(pair<string, int> (s_rgAirportPairs[i].szAirport2, s_rgAirportPairs[i].nMileage));
            }
            else if(strcmp(s_rgAirportPairs[i].szAirport2, tokenInputs[0].c_str()) == 0)
            {
                dest2.insert(pair<string, int> (s_rgAirportPairs[i].szAirport1, s_rgAirportPairs[i].nMileage));
            }
            else if(strcmp(s_rgAirportPairs[i].szAirport1, tokenInputs[1].c_str()) == 0)
            {
                dest1.insert(pair<string, int> (s_rgAirportPairs[i].szAirport2, s_rgAirportPairs[i].nMileage));
            }
            else if(strcmp(s_rgAirportPairs[i].szAirport2, tokenInputs[0].c_str()) == 0)
            {
                dest1.insert(pair<string, int> (s_rgAirportPairs[i].szAirport1, s_rgAirportPairs[i].nMileage));
            }
            else
            {
                continue;
            }
            
        }

        if((dest2.find(tokenInputs[1]) != dest2.end()) && (stoi(tokenInputs[2]) == 0))
        {
            // cout << "ZERO" << endl;
            cout << tokenInputs[0] << " " << tokenInputs[1] << " " << dest2.find(tokenInputs[1])->second << endl;
            flag = true;
        }
        else
        {
            // cout << "NON ZERO" << endl;
            distance = 999999999;
            path = "";
            for(auto d: dest2)
            {
                if(dest1.find(d.first) != dest1.end())
                {
                    path = tokenInputs[0] + " " + d.first + " " + tokenInputs[1];
                    shortest_path.insert(pair<string, int>(path, (d.second + dest1.find(d.first)->second)));
                    flag = true;
                }
            }

            for(auto p: shortest_path)
            {
                if(distance > p.second)
                {
                    distance = p.second;
                    path = p.first;
                }
            }

            if(distance < 999999999) cout << path << " " << distance << endl;
        }

        if(!flag)
        {
            cout << "NONE" << endl;
        }
    }
}

