#include <bitset>
#include <iostream>
#include <math.h>

// Poziv funkcije printBits rezultovace sa ispisom
// proslijedjenog broja u binarnoj formi.
//
// Primjer:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// unsigned short s = 5;
// printBits(s);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Ispis:
// 0000000000000101
// 
void printBits(unsigned short reg) {
  std::bitset<16> bits(reg);
  std::cout << bits << std::endl;
}


int main() {
  unsigned short reg1 = 0, reg2 = 0;
  
  while(true) {
    unsigned short x;
    do {
      std::cout << "Choose which registry:" << std::endl;
      std::cout << "1. Reg1\n2. Reg2" << std::endl;
      std::cout << "Your input: ";
      std::cin >> x;
    } while (x != 1 && x != 2);

    unsigned short *reg_arr[] = {&reg1, &reg2};
    unsigned short *registry = reg_arr[x-1];
    
    std::cout << "1. Print register" << std::endl;
    std::cout << "2. Set bit in register" << std::endl;
    std::cout << "3. Reset bit in register" << std::endl;
    std::cout << "4. Swap registries" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter option: ";
    int option;
    std::cin >> option;

    
    if (option == 1) { 
      printBits(*registry);
    } else 
  
    if (option == 2) {
      unsigned short bit;
      std::cout << "Enter bit number: ";
      std::cin >> bit;

      *registry |= 1 << bit; //number 1 is converted to 16bit binary 
      //then shifted to location bit 000000000000001 => 0000000000000100 for bit = 2
      // then each bit is compared using OR | with the number in registry and is stored there again
      // so registry = 0000000000000 
      //             | 0000000000100
      //            ------------------
      //    registry = 0000000000100
      std::cout << "New register value: " << *registry << std::endl;
      printBits(*registry);
    } else 
    
    if (option == 3) {
      unsigned short bit;
      std::cout << "Enter bit number: ";
      std::cin >> bit;

      *registry &= ~(1<<bit); //1 is shifted to left by bit and then all zeros are inverted to one and vice versa
      // after that each bit is compared to the registry number in bits but with AND instead of OR
      std::cout << "New register value: " << *registry << std::endl;
      printBits(*registry);
    }  else 
    
    if (option == 4) {
      reg1 = reg1 ^ reg2;
      reg2 = reg1 ^ reg2;
      reg1 = reg1 ^ reg2;
      std::cout << "Registers 1 and 2 have been swapped.\n";
    } else

    if (option == 5) {
      break;
    }
    
    std::cout << std::endl;
  }

  return 0;
}
