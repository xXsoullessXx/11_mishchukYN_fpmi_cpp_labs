#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct Segment {
    string content;
    bool is_word;
    bool is_number;
};

bool is_number_word(const string& word) {
    if (word.empty()) return false;
    for (char c : word) {
        if (!isdigit(c)) return false;
    }
    return true;
}

vector<Segment> parse_string(const string& str, const string& delimiters) {
    vector<Segment> segments;
    size_t start = 0;
    size_t end = 0;
    
    while ((end = str.find_first_of(delimiters, start)) != string::npos) {
        if (end != start) {
            string word = str.substr(start, end - start);
            segments.push_back({word, true, is_number_word(word)});
        }
        
        start = end;
        end = str.find_first_not_of(delimiters, start);
        string delim = str.substr(start, end - start);
        if (!delim.empty()) {
            segments.push_back({delim, false, false});
        }
        start = end;
    }
    
    if (start < str.length()) {
        string word = str.substr(start);
        segments.push_back({word, true, is_number_word(word)});
    }
    
    return segments;
}

int main() {
    string input_str;
    string delimiters;
    
    cout << "Enter string: ";
    getline(cin, input_str);
    
    cout << "Enter delimiters: ";
    getline(cin, delimiters);
    
    vector<Segment> segments = parse_string(input_str, delimiters);
    
    int max_length = -1;
    int min_length = 10000;
    int first_max_index = -1;
    int last_min_index = -1;
    
    for (int i = 0; i < segments.size(); i++) {
        if (segments[i].is_word && segments[i].is_number) {
            int len = segments[i].content.length();
            
            if (len > max_length) {
                max_length = len;
                first_max_index = i;
            }
            
            if (len < min_length) {
                min_length = len;
                last_min_index = i;
            } else if (len == min_length) {
                last_min_index = i;
            }
        }
    }
    
    if (first_max_index == -1 || last_min_index == -1) {
        cout << "Error: Not enough words to perform swap" << endl;
        return 1;
    }
    
    swap(segments[first_max_index].content, segments[last_min_index].content);
    
    string result;
    for (const auto& seg : segments) {
        result += seg.content;
    }
    
    cout << "Result: " << result << endl;
    
    return 0;
}