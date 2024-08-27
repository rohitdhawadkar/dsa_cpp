#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string convert(int);
string reverse(string);
int convert2(string);
int main(){
    int x = 13;
    string y = convert(x);
    cout<<y<<endl;
    string z = "1010";
    int n = convert2(z);
    cout<<n<<endl;
    return 0;
}

string convert(int x){
    string bin = "";
    while(x!=0){
        if(x%2==0){
            bin = bin +"0";
        }else {
            bin = bin + "1";
        }
        x = x/2;
    }
      return reverse(bin);
}

string reverse(string binary) {
    int x = binary.length();
    string rev = "";
    for (int i = 0; i < x; i++) {
        rev.push_back(binary[x - i - 1]);
    }
    return rev;
}

int convert2(string num){
    int x = num.length();
    int power= 0;
    int ans = 0;
    for(int i=x-1;i>=0;i--){

        if(num[i]=='1'){
            ans = ans + pow(2,power);
        }
        power++;
    }
    return ans;
}
