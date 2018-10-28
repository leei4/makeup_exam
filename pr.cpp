//Pollard Rho implementation
//Ian Lee

#include<bits/stdc++.h> 
using namespace std; 

//Calculate power
long long int modular_pow(long long int base, int exponent, 
						long long int modulus) 
{ 
	long long int result = 1; 

	while(exponent > 0){ 
		//if y is odd, multiply base with result
		if (exponent & 1){
			result = (result * base) % modulus; 
		}

		// exponent = exponent/2
		exponent = exponent >> 1; 

		// base = base * base
		base = (base * base) % modulus; 
	} 
	return result; 
} 

//return prime divisor of n
long long int PollardRho(long long int n) 
{ 
	//random seed
	srand (time(NULL)); 

	//edge case for if n = 1
	if(n ==1){
		return n; 
	}

	if(n == 2){
		return n
	}
	//divisible by 2 check
	if(n % 2 == 0){
		return 2; 
	}

	//choose random int on range 
	long long int x = (rand()%(n-2))+2; 
	long long int y = x; 

	long long int c = (rand()%(n-1))+1; 
	long long int d = 1; 

	while (d==1) { 
		x = (modular_pow(x, 2, n) + c + n)%n; 

		y = (modular_pow(y, 2, n) + c + n)%n; 
		y = (modular_pow(y, 2, n) + c + n)%n; 

		d = __gcd(abs(x-y), n); 

		if( d == 1){
			return d;
		}

		//retry if necessary
		if(d == n){ 
			return PollardRho(n);
		}
	} 

	return d; 
} 

//Main function
int main() 
{ 	
	vector<long long int> nums = {31531,520482,485827,15485863};
	
	for(int t = 0; t < nums.size(); t++){
		long long int i  = PollardRho(nums[t]);
		if(i == 1 || i == 2){
			printf("%lld is prime!", nums[t]);
			printf("\n");
		}
		else{
		printf("Divisor for %lld is %lld.", 
			nums[t], PollardRho(nums[t]));
		printf("\n"); 
		}
	}
	return 0; 
} 
