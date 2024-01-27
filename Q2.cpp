//Q2: Find the factorial of a large number.

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using Digits = std::vector<int>;
    
#define MAX 20
    
void multiply(int x,Digits res,int res_size)
{
    int carry=0;
    for(int i=0;i<res_size;i++)
    {
        int prod=carry+ x*res[i];
        res[i] = prod%10;
        carry = prod/10;
    }
    
    while(carry)
    {
        res[res_size] = carry%10;
        carry/=10;
        (res_size)++;
    }
}
    
Digits factorial(int n)
{
    Digits res(MAX);  
    res[0] = 1;
    int res_size=1;
    for(int i=2;i<=n;i++)
    {
        multiply(i,res,res_size);
    }
    reverse(res.begin(),res.end());
    return res;
}
    
int main()
{
      for(auto i: factorial(20))
      {
        cout << i;     
      }
      cout << endl;
      return 0;
}