#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

//calculates (a * b) % c 
long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

//Modular exponentiation
long long modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}


//miller rabin test
bool longer(long long p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    long long s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

//Main
int main()
{
    int iteration = 4;
    long long num = 0;

    vector<long long int> nums = {31531,520482,485827,15485863};

    for(int i = 0; i < nums.size(); i++){
    	num = nums[i];
    	if (longer(num, iteration)){
        	cout<<num<<" is prime"<<endl;
    	}
    	else{
        cout<<num<<" is not prime"<<endl;
    	}
    }

    return 0;
}
