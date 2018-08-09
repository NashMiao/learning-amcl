#include <iostream>
#include <string>

#include <amcl/amcl.h>
#include <amcl/big_B1024_28.h>
#include <amcl/randapi.h>

int main(int argc, char const *argv[])
{
    std::string raw = "onchain";
    amcl::octet RAW = {0, (int)raw.size(), (char *)raw.c_str()};
    amcl::csprng RNG; // Crypto Strong RNG

    B1024_28::BIG num;
    amcl::CREATE_CSPRNG(&RNG, &RAW); // initialise strong RNG
    B1024_28::BIG_random(num, &RNG);
    char *a = new char[1024];
    B1024_28::BIG_toBytes(a, num);
    std::cout << a << std::endl;
    amcl::KILL_CSPRNG(&RNG);
    return 0;
}