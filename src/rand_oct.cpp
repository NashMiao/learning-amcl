#include <iostream>
#include <string>

#include <amcl/amcl.h>
#include <amcl/randapi.h>

int main(int argc, char const *argv[])
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
    amcl::OCT_output(&oct);
    std::cout << s << std::endl;
    return 0;
}
