///Prime Generation
bitset<mx> isPrime;
vector<int> prime_numbers; /// i to n sob number er maje je koyta prime ase ta stroed ase;

void primeGen(int n)
{
    for(int i = 2; i <= n; i++) isPrime[i] = 1;
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i + i; j <= n; j += i)
        {
            isPrime[j] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(isPrime[i] == 1) prime_numbers.push_back(i);
    }
}
