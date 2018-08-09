#include <iostream>
#include <string>

#include <amcl/pair_BN254.h>

int main(int argc, char const *argv[])
{
    BN254_BIG::BIG big_one;
    BN254_BIG::BIG big_two;
    std::string one = "1";
    std::string two = "2";
    BN254_BIG::BIG_fromBytes(big_one, (char *)one.c_str());
    BN254_BIG::BIG_fromBytes(big_two, (char *)two.c_str());

    BN254::ECP2 g2;
    BN254::ECP2_generator(&g2);
    std::cout << "g2:" << std::endl;
    BN254::ECP2_output(&g2);
    std::cout << std::endl;

    BN254::ECP2 w1;
    BN254::ECP2_copy(&w1, &g2);
    std::cout << "w1_1:" << std::endl;
    BN254::ECP2_output(&w1);
    BN254::ECP2_mul(&w1, big_one);
    std::cout << "w1_2:" << std::endl;
    BN254::ECP2_output(&w1);
    std::cout << std::endl;

    BN254::ECP2 w2;
    BN254::ECP2_copy(&w2, &g2);
    std::cout << "w2_1:" << std::endl;
    BN254::ECP2_output(&w2);
    BN254::ECP2_mul(&w2, big_two);
    std::cout << "w2_2:" << std::endl;
    BN254::ECP2_output(&w2);
    std::cout << std::endl;

    BN254::ECP2 w1p1;
    BN254::ECP2_copy(&w1p1, &w1);
    std::cout << "w1p1_1:" << std::endl;
    BN254::ECP2_output(&w1p1);
    BN254::ECP2_add(&w1p1, &w1p1);
    std::cout << "w1p1_2:" << std::endl;
    BN254::ECP2_output(&w1p1);
    std::cout << std::endl;

    return 0;
}
