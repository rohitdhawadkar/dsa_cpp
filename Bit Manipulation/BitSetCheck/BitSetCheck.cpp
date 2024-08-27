#include <iostream>
using namespace std;
bool checkSetBit(int x,int k);
void swap(int a,int b);
int setBit(int x,int k);
int clearSetBit(int x,int k);
int toggleBit(int x ,int k);
int removeLastSetBit(int x);
bool checkPowerOfTwo(int x);
int countSetBits(int x);

int main(){
    bool ans = checkSetBit(13,2);
    cout << ans <<endl;
    int a = 10;
    int b = 20;
    a = a^b;
    b=a^b;
    a = a^b;
    cout<<a<<" "<<b<<endl;
    int e = setBit(13,1);
    cout<<e<<endl;
    int d = clearSetBit(13,2);
    cout<<d<<endl;
    int f = toggleBit(13, 2);
    cout<<f<<endl;
    int h = removeLastSetBit(16);
    cout<<h<<endl;
    bool i = checkPowerOfTwo(16);
    cout<<i<<endl;
    int j = countSetBits(15);
    cout<<j<<endl;
    return 0;

}

void swap(int a,int b){
    a = a^b;
    b=a^b;
    a = a^b;
}
bool checkSetBit(int x,int k){
    return (x & (1<<k));
}

int setBit(int x,int k){
    int ans = (x | (1<<k));
    return ans;
}

int clearSetBit(int x,int k){
    int ans = (x  & ~(1<<k));
    return ans;
}
int toggleBit(int x ,int k){
    int ans = (x ^ (1<<k));
    return ans;
}


int removeLastSetBit(int x){
    int ans = x & x-1;
    return ans;
}

bool checkPowerOfTwo(int x){
    return (x>0  &  (x&x-1)==0);
}

// int countSetBits(int x){
//     int count = 0;
//     while(x!=1){
//         if(x%2==1){
//             count++;
//         }
//         x = x/2;
//     }

//     return count+1;
// }

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) { // Check if the least significant bit is set
            count++;
        }
        n = n >> 1; // Shift right to check the next bit
    }
    return count;
}
