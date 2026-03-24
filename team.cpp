#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int counter = 0;
    for(int i = 0; i <n; i++)
    {
        short op1, op2, op3;
        cin >> op1>> op2 >> op3;
        if ((op1+ op2+ op3) >= 2){
            counter++;
        }
    }
    cout << counter << endl;
}