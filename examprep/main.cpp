#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <set>


using namespace std;

void readfile(){
    ifstream doc("cars.txt");
    istream_iterator<string> start(doc),end;
    set<string> vec(start,end);
    //sort(vec.begin(), vec.end());
    for (auto it = vec.cbegin(); it != vec.cend(); ++it){
        if((*it)[0]=='A'){ //dereference it to get value, then acces first character for comparison
            cout<< *it <<endl;
        }
    }
    for (auto c: vec){
        if(c.front()=='A'){
            cout<<c<<endl;
        }
    }
    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n"));
}

void splice(){
    // initializing lists and iterator
        list<int> l1 = { 1, 2, 3, 4, 5 };
        list<int> l2 = { 6, 7, 8 };
        list<int>::iterator it;

        // iterator pointing to 1
        it = l1.begin();

        // advance the iterator by 2 positions
        advance(it, 2);

        // transfer 3, 4 and 5 at the
        // beginning of l2
        l2.splice(l2.begin(), l1, it, l1.end());

        cout << "list l2 after splice operation" << endl;
        for (auto x : l2)
            cout << x << " ";
        cout << endl;
}

int main()
{
//    list<int> l = {5, 2, 9} ;
//    l.push_back(6);
//    l.push_front(4);
//    // l : {5 , 2 , 9 , 6}
//    // l : {4 , 5 , 2 , 9 , 6}

//    list<int>::iterator itr = find(l.begin(), l.end(), 2); // i t r −> 2
//    l.insert(itr,8);
//    // l : {4 , 5 , 8 , 2 , 9 , 6}
//    // O( 1 ) , f a s t e r than vector
//    itr++;
//    // i t r −> 9
//    l.erase(itr);
//    // l : {4 , 5 , 8 , 2 , 6} O( 1 )
//    // Main reason to use l i s t :
//    splice();

    vector<int> vec = { 4, 2, 5, 1, 3, 9};
    vector<int>::iterator it = min_element(vec.begin(), vec.end());
    cout<< *it <<endl;

    sort(vec.begin(), it); // sort process in  Algorithm process ranges in a half −open way : [ begin , end )
    //-> begin is included, but only up to (non-including) the end!
    for (auto v : vec){
        cout<< v << " ";
    }




    return 0;
}
