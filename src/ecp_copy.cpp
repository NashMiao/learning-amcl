#include <iostream>
#include <string>

#include <amcl/pair_BN254.h>

int main(int argc, char const *argv[])
{
    BN254::ECP2 g2;
    BN254::ECP2_generator(&g2);
    std::cout << "g2:" << std::endl;
    BN254::ECP2_output(&g2);

    BN254::ECP2 w;
    std::cout << "w1:" << std::endl;
    BN254::ECP2_output(&w);
    BN254::ECP2_copy(&w, &g2);
    std::cout << "w2:" << std::endl;
    BN254::ECP2_output(&w);
    return 0;
}
