#include <iostream> 
#include <cstring>
using namespace std; 
  
// Modular Exponentiation 
int power(int x, unsigned int y, int p) 
{ 
    // Initialize result 
    int res = 1;      
   
    x = x % p; // Update x if it is more than or 
                // equal to p 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
  
// Generates prime numbers less than 
// or equal to n using Sieve of Eratosthenes 
void generatePrimeNumbers(unsigned int n, int *result) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Store all prime numbers 
    int j = 0; 
    for (int p=2; p<=n; p++) 
    { 
        if (prime[p]) 
        { 
           if(j < 500) 
             result[j++] = p; 
           else
               break; 
        } 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    int result[500]; 
    generatePrimeNumbers(1000,result); 
    cout << "Two random prime numbers are: " <<  
             result[rand() % 500] <<"  "<<  result[rand() % 500]; 
    return 0; 
}