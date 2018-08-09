#include <iostream>
#include <string>

#include <amcl/pair_BN254.h>

int main(int argc, char const *argv[])
{
    BN254::ECP g1;
    BN254::ECP_generator(&g1);
    BN254::ECP_output(&g1);

    BN254::ECP2 g2;
    BN254::ECP2_generator(&g2);
    BN254::ECP2_output(&g2);
    return 0;
}
