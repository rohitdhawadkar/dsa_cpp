#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> NLE(vector<int> arr);
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

    vector<int> nle = NLE(arr);

    for(int i:nle){
        cout<<i<<"\t";
    }
    cout<<endl;
    return 0;
}


vector<int> NLE(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nle(n);


    for(int i=n-1;i>=0;i--){

        while(!st.empty() && arr[i]<=arr[st.top()] ){
            st.pop();

        }
        nle[i]=st.empty()?-1:arr[st.top()];
        st.push(i);
    }

    return nle;

}
