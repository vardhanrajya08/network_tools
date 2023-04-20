// This program takes an IP address in classful notation as input (e.g. 192.168.0.0) and converts it to classless addressing (CIDR notation) 
// by counting the number of set bits in each octet and adding up the total number of bits. 
// Resulting CIDR notation is stored in a dynamically allocated string, which is returned by the function ip_classless.

//code starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ip_classless(char *ip_address) {
	int i, j, k;
	int octets[4];
	char *mask = (char *) malloc(sizeof(char) * 16);
	int bits = 0;
	for (i = 0, j = 0, k = 0; i < strlen(ip_address); i++) {
		if (ip_address[i] == '.') {
			octets[j++] = atoi(ip_address + k);
			k = i + 1;
		}
	}
	octets[j] = atoi(ip_address + k);
	for (i = 0; i < 4; i++) {
		int octet = octets[i];
		for (j = 7; j >= 0; j--) {
			if (octet >= (1 << j)) {
				bits++;
				octet -= (1 << j);
			} else if (bits % 8 != 0) {
				break;
			}
		}
	}
	sprintf(mask, "%s/%d", ip_address, bits);
	return mask;
}

int main() {
	char ip_address[16];
	printf("Enter an IP address in classful notation: ");
	scanf("%s", ip_address);
	printf("Classless address: %s\n", ip_classless(ip_address));
	return 0;
}
//code ends