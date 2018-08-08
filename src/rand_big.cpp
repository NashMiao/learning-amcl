#include <iostream>
#include <string>

#include <amcl/amcl.h>
#include <amcl/randapi.h>
#include <amcl/big_B1024_58.h>
int main()
{
    std::string raw = "onchain";
    amcl::octet RAW = {0, (int)raw.size(), (char *)raw.c_str()};
    amcl::csprng RNG; // Crypto Strong RNG

    B1024_58::BIG num;
    amcl::CREATE_CSPRNG(&RNG, &RAW); // initialise strong RNG
    B1024_58::BIG_random(num, &RNG);
    char *a = new char[1024];
    B1024_58::BIG_toBytes(a, num);
    std::cout << a << std::endl;
    return 0;
}