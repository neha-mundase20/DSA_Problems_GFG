#include<bits/stdc++.h>
using namespace std;

//Set-stores unique elements in sorted order
//Multiset-only stores elements in sorted order, not unique, elements can occur multiple times
//Unordered set-stores unique elements but in unsorted format

int main(){
    set<int> st;
    st.insert(1);   //{1}
    st.insert(2);   //{1,2}
    st.insert(4);   //{1,2,4}
    st.insert(2);   //{1,2,4}
    st.insert(3);   //{1,2,3,4}

    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        cout<<*it<<"\t";
    }

    st.erase(1);

    cout<<"\n";

    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        cout<<*it<<"\t";
    }

    cout<<"\n";

    multiset<int> mst;
    mst.insert(1);  //{1}
    mst.insert(1);  //{1,1}
    mst.insert(4);  //{1,1,4}
    mst.insert(2);  //{1,1,2,4}

    for(multiset<int>::iterator it=mst.begin();it!=mst.end();it++){
        cout<<*it<<"\t";
    }

    cout<<"\n";

    mst.erase(1);   //{2,4} i.e. all occurences of 1's are erased

    for(multiset<int>::iterator it=mst.begin();it!=mst.end();it++){
        cout<<*it<<"\t";
    }

    cout<<"\n";

    mst.erase(mst.find(1)); //find returns the address of the element hence deletes only a single occurence at
                            //the respective address

    unordered_set<int> ust;
    ust.insert(1);
    ust.insert(1);
    ust.insert(4);
    ust.insert(2);

    for(unordered_set<int>::iterator it=ust.begin();it!=ust.end();it++){
        cout<<*it<<"\t";
    }

    cout<<"\n";


    

    return 0;
}