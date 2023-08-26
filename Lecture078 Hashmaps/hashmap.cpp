#include <iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main() {
    unordered_map<string, int> m;
    
    //way 1
    pair<string, int> p1 = make_pair("Aman", 1);
    m.insert(p1);
    
    //way 2
    pair<string, int> p2("Baluni", 2);
    m.insert(p2);
    
    //way 3
    m["Coding"] = 3;
    
    //searching
    cout << m["Aman"] << endl;
    cout << m.at("Baluni") << endl;
    //it will terminate
    //cout << m.at("unknown") << endl;
    //it will create a new entry for unknown
    cout << m["unknown"] << endl;
    cout << m.at("unknown") << endl;
    
    //check size
    cout << m.size() << endl;
    
    //to check presence
    cout << m.count("bro") << endl;
    cout << m.count("Aman") << endl;
    
    //to delete
    m.erase("Aman");
    
    // to traverse using for loop
    for(auto i : m){
        cout<< i.first << " " << i.second << endl;
    }
    
    //to traverse using iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << " " << it->second <<endl;
        it++;
    }
    
    return 0;
}
