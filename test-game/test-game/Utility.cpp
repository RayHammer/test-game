#include "Utility.h"

bool util::parse_CSV_int(const string &s, vector<int> &v) {
    string t;
    v.clear();
    size_t begin = 0;
    size_t end = s.find_first_of(",", begin);
    while (end != std::string::npos) {
        t = s.substr(begin, end - begin);
        v.push_back(stoi(t));
        begin = end + 1;
        end = s.find_first_of(",", begin);
    }
    t = s.substr(begin, s.size() - begin);
    v.push_back(stoi(t));
    return true;
}