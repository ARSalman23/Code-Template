//Sieve Algorithm

bitset<mx> isPrime;
vector<int> prime_numbers; /// 1 to n sob number er majhe je koyta prime ase sobghula stored ase ai vector a;
void primeGen(int n) ///sieve algorithm
{
    for(int i = 3; i <= n; i += 2) isPrime[i] = 1;
    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(isPrime[i]) for(int j=i*i; j<=n; j+=i) isPrime[j] = 0;
    }
    prime_numbers.push_back(2);
    for(int i = 3; i <= n; i += 2) if(isPrime[i] == 1) prime_numbers.push_back(i);
}
