// #include<iostream>
// #include<algorithm>
// using namespace std;

// int main(){
//  cout<<"9.0 7.6";
//  return 0;
// }

//第一种方法的时间为9分钟
//第二种方法的时间为7.6分钟


#include <iostream>
using namespace std;

int main() {
    //First solution is 9 min obviously.
    //Discuss the second queuing method:
    int sum = 0, T;
    for (int f = 0; f < 10; ++f) {
        //先算排在该5分钟客户前面的人花了多少时间
        T = f / 2;
        T += 5;
        //判断该客户是在队伍前面还是后面，不同的排法导致后面的时间不一样
        if (f < 5)T += (10 - f - 5) / 2;
        sum += T;
    }

    cout << "First solution is 9.0 min obviously." << endl;
    cout << "Second solution average time is: " << (double) sum / 10 << " min" << endl;
    return 0;
}
