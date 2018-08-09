#include <iostream>
#include <memory>
#include <string>

#include <amcl/amcl.h>
#include <amcl/randapi.h>

void rand_oct1()
{
    // Crypto Strong RNG
    amcl::csprng RNG;
    std::string raw = "onchain";
    amcl::octet RAW = {0, (int)raw.size(), (char *)raw.c_str()};
    // initialise strong RNG
    amcl::CREATE_CSPRNG(&RNG, &RAW);
    char s[256];
    amcl::octet oct = {0, sizeof(s), s};
    amcl::OCT_rand(&oct, &RNG, 256);
    amcl::KILL_CSPRNG(&RNG);
    amcl::OCT_output(&oct);
    std::cout << s << std::endl;
}

void rand_oct2()
{
    amcl::csprng RNG;
    std::string raw = "onchain";
    amcl::octet RAW = {0, (int)raw.size(), (char *)raw.c_str()};
    amcl::CREATE_CSPRNG(&RNG, &RAW);
    char s[512];
    amcl::octet oct = {0, sizeof(s), s};
    amcl::OCT_rand(&oct, &RNG, 512);
    amcl::KILL_CSPRNG(&RNG);
    amcl::OCT_output(&oct);
    std::cout << s << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "rand_oct1()" << std::endl
              << "----------------------------------------------------"
              << std::endl;
    rand_oct1();
    std::cout << "----------------------------------------------------"
              << std::endl;
    std::cout << "rand_oct2()" << std::endl
              << "----------------------------------------------------"
              << std::endl;
    rand_oct2();
    std::cout << "----------------------------------------------------"
              << std::endl;
    return 0;
}
