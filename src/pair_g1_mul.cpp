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

  std::cout << "big_one: ";
  BN254_BIG::BIG_output(big_one);
  std::cout << std::endl;

  std::cout << "big_two: ";
  BN254_BIG::BIG_output(big_two);
  std::cout << std::endl
            << std::endl;

  BN254::ECP fp1, fp2;
  std::cout << "ECP_output1: " << std::endl;
  BN254::ECP_output(&fp1);
  BN254::PAIR_G1mul(&fp1, big_one);
  std::cout << "ECP_output2: " << std::endl;
  BN254::ECP_output(&fp1);
  std::cout << std::endl;

  std::cout << "ECP_output1: " << std::endl;
  BN254::ECP_output(&fp2);
  BN254::PAIR_G1mul(&fp2, big_one);
  std::cout << "ECP_output2: " << std::endl;
  BN254::ECP_output(&fp2);
  std::cout << std::endl;
  return 0;
}
