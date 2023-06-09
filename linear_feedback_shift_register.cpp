// This code will be the scrambled sequence generated by the linear feedback shift register (LFSR) for 32 clock cycles. 
// The exact output will depend on the starting state of the LFSR, which is entered by the user.

// In this code, the LFSR is initialized with an 8-bit state. 
// The TAP positions, which determine the feedback taps in the LFSR, are specified as {8, 7, 6, 1}. 
// The LFSR is then clocked 32 times to generate the scrambled sequence. 
// The output will be the scrambled sequence, where each line represents the state of the LFSR after each clock cycle.

// code starts 
#include <bitset>
#include <iostream>

const int LFSR_LENGTH = 8;
const int TAP_POSITIONS[] = {8, 7, 6, 1};

int main() {
	std::bitset<LFSR_LENGTH> lfsr;
	std::cout << "Enter the starting state of the LFSR: ";
	std::cin >> lfsr;
	
	for (int i = 0; i < 32; ++i) {
		int feedback = 0;
		for (const auto tap_position : TAP_POSITIONS) {
			feedback ^= lfsr[tap_position];
		}
		
		lfsr = (lfsr << 1) | feedback;
		std::cout << lfsr << std::endl;
	}
	
	return 0;
}
//code ends