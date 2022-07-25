#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

int get_rank(std::string input) {
    std::stringstream ss(input);
    std::string s;
    // keep extracting strings, last one would be your 'int' rank
    for(; ss >> s; );
    return std::atoi(s.c_str());
}

int main() {
    std::ifstream infile("movies.txt");
    std::vector<std::string> v;
    std::string line;
    std::getline(infile, line);
    for( ; getline( infile, line ); )
        v.push_back(line);
    std::sort(v.begin(), v.end(), [](std::string s1, std::string s2) -> bool { return get_rank(s1) > get_rank(s2); });
    for(int i = 0;i < 10;i++)
        cout << i + 1 << "," << v[i].substr(v[i].find(",") + 1) << endl;
    return 0;
}