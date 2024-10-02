#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NGE(vector<int> array);
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

    vector<int> nle = NGE(arr);

    for(int i:nle){
        cout<<i<<"\t";
    }
    cout<<endl;
    return 0;
}




vector<int> NGE(vector<int> array){
        int n = array.size();
        stack<int> st;
        vector<int> nge(n);

        for(int i=n-1;i>=0;i--){
        while(!st.empty() && array[i]>=array[st.top()]){
            st.pop();
        }
        nge[i] = st.empty()?-1:array[st.top()];
        st.push(i);


        }
        return nge;

}
