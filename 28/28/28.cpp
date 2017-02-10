#include <iostream>
#include <cassert>
#include "list.h"
using namespace std;

int main(){
	my::list<int> dlist;

	dlist.push_back(1);
	dlist.push_back(2);
	dlist.push_back(3);

	// TEST should pass when methods are implemented

	            assert(dlist.empty()==false);

	            for(auto& elem: dlist)
	            {
	                cout << elem << endl;
	            }

	            //cout << "dlist: " << dlist << endl;
	            my::list<int> dlist2 = dlist;
	            //cout << "dlist2: " << dlist2 << endl;

	            assert(dlist.back() ==dlist2.back());
	            assert(dlist.front()==dlist2.front());

	            cout << "--reversed--" << endl;
	            for(auto it = dlist.rbegin(); it!=dlist.rend(); ++it)
	            {
	                cout << *it << endl;
	            }

	            cout << *(dlist.rbegin()) << endl;
	            assert(dlist.back() ==*(dlist.rbegin()));

	            dlist.pop_back();
	            //cout << "popped back: " << dlist << endl;
	            assert(dlist.empty()==false);

	            dlist.pop_front();
	            //cout << "popped front: " << dlist << endl;
	            assert(dlist.empty()==false);

	            dlist.pop_front();
	            //cout << "popped front: " << dlist << endl;
	            assert(dlist.empty()==true);

	            dlist.push_front(11);
	            auto it = dlist.begin();
	            *(it) = 42;
	            //cout << "push & modify: " << dlist << endl;

	            assert(*(  dlist.begin())   ==dlist.front());
	            assert(*(--dlist.end())     ==dlist.back());
	            assert(*(  dlist.rbegin())  ==dlist.back());
	            assert(*(--dlist.rend())    ==dlist.front());
	            assert(42 == dlist.front());

	            dlist.pop_back();
	            //cout << "popped back: " << dlist << endl;
	            assert(dlist.empty()==true);

				return 0;
}