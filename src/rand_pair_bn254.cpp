#include <iostream>
#include <string>

#include <amcl/amcl.h>
#include <amcl/pair_BN254.h>
#include <amcl/randapi.h>

int main()
{
    BN254_BIG::BIG x;
    amcl::csprng RNG;
    std::string raw = "onchain";
    amcl::octet RAW = {0, (int)raw.size(), (char *)raw.c_str()};
    amcl::CREATE_CSPRNG(&RNG, &RAW);
    BN254_BIG::BIG_random(x, &RNG);
    BN254_BIG::BIG_output(x);
    return 0;
}