#include <iostream>

using namespace std;
#pragma warning(disable: 4996)

int main() {
	string ip4, mask;
	int oct_ip4[4], oct_mask[4], oct_newnet[4];


	printf("Enter your IP4 adress(ex: 192.168.132.0)\n");
	scanf("%d.%d.%d.%d",oct_ip4, oct_ip4+1, oct_ip4+2, oct_ip4+3);
	printf("Enter your mask adress(ex: 255.255.255.0)\n");
	scanf("%d.%d.%d.%d", oct_mask, oct_mask+1, oct_mask + 2, oct_mask + 3);
	printf("\n");
	

	for (int i = 0; i < 4; i++) {
		oct_newnet[i] = oct_ip4[i] & oct_mask[i];
	}
	
	
	printf("IP4 decimal adress: %d.%d.%d.%d", oct_ip4[0], oct_ip4[1], oct_ip4[2], oct_ip4[3]);
	printf("\n");
	printf("Mask decimal adress: %d.%d.%d.%d", oct_mask[0], oct_mask[1], oct_mask[2], oct_mask[3]);
	printf("\n");
	printf("Subnet decimal adress: %d.%d.%d.%d", oct_newnet[0], oct_newnet[1], oct_newnet[2], oct_newnet[3]); 
	printf("\n\n");

	printf("IP4 hexadecimal adress: %x.%x.%x.%x", oct_ip4[0], oct_ip4[1], oct_ip4[2], oct_ip4[3]);
	printf("\n");
	printf("Mask hexadecimal adress: %x.%x.%x.%x", oct_mask[0], oct_mask[1], oct_mask[2], oct_mask[3]);
	printf("\n");
	printf("Subnet hexadecimal adress: %x.%x.%x.%x", oct_newnet[0], oct_newnet[1], oct_newnet[2], oct_newnet[3]);
	printf("\n\n");
	
	printf("IP4 binary adress: ");
	for (int i = 0; i < 4; i++) {

		for (int j = 7; j >= 0; j--) {
			printf("%d", (oct_newnet[i] >> j) & 1);
		}
		printf(".");
	}
	printf("\n");

	printf("Mask binary adress: ");
	for (int i = 0; i < 4; i++) {

		for (int j = 7; j >= 0; j--) {
			printf("%d", (oct_newnet[i] >> j) & 1);
		}
		printf(".");
	}
	printf("\n");

	printf("Subnet binary adress: ");
	for (int i = 0; i < 4; i++) {
	
		for (int j = 7; j >= 0; j--) {
			printf("%d", (oct_newnet[i] >> j)&1);
		}
		printf(".");
	}
	printf("\n");



	return 0;
}