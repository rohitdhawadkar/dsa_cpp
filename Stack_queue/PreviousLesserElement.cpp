#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> PLE(vector<int> array);
int main(){
    vector<int> arr ;
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(6);

    vector<int> ple = PLE(arr);

    for(int i:ple){
        cout<<i<<"\t";
    }

    return 0;
}

vector<int> PLE(vector<int> array){
    int n = array.size();
    vector<int> ple(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && array[i]<=array[st.top()]){
            st.pop();
        }
        ple[i]=st.empty()?-1:array[st.top()];
        st.push(i);
    }

    return ple;
}
