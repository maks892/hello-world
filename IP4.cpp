#include <iostream>
#include <regex>


using namespace std;
#pragma warning(disable: 4996)

int main() {
	string ip4, mask;
	int oct_ip4[4], oct_mask[4], oct_newnet[4];

	regex sample("([0-9]{1,3}\.){3}\.[0-9]{1,3}");
	
	string str_ip, str_mask;
	bool right_ip = false, right_mask = false;

	while (!right_ip) {


		printf("Enter your IP4 adress(ex: 192.168.132.0)\n");
		cin >> str_ip;

		if (regex_match(str_ip.c_str(), sample)) { cout << "\nvalid IP\n" << endl; right_ip = true; }
		else { cout << "please, enter a valid ip!" << endl; }
	}

	while (!right_mask) {

		printf("Enter your mask adress(ex: 255.255.255.0)\n");
		cin >> str_mask;

		if (regex_match(str_mask.c_str(), sample)) { cout << "\nvalid mask adress\n" << endl; right_mask = true; }
		else { cout << "please, enter a valid mask adress!" << endl; }

	}

	int j = 0;
	for (int i = 0; i < 4; i++) {

		char buf[4] = "";
		int buf_ind = 0;
		int k = 0;
		
		while (str_ip[j] != '.' && j < str_ip.length()) {

			k++;

			buf[buf_ind] = str_ip[j];
			buf_ind++;
			j++;
		}
		j++;

		if (k == 1) { oct_ip4[i] = (buf[0] - '0'); }
		else if (k == 2) { oct_ip4[i] = (buf[1] - '0') * 10 + (buf[2] - '0'); }
		else if (k == 3) {
			oct_ip4[i] = (buf[0] - '0') * 100 + (buf[1] - '0') * 10 + (buf[2] - '0');
		}

	}

	j = 0;
	for (int i = 0; i < 4; i++) {

		char buf[4] = "";
		int buf_ind = 0;
		int k = 0;

		while (str_mask[j] != '.' && j < str_mask.length()) {

			k++;

			buf[buf_ind] = str_mask[j];
			buf_ind++;
			j++;
		}
		j++;

		if (k == 1) { oct_mask[i] = (buf[0] - '0'); }
		else if (k == 2) { oct_mask[i] = (buf[1] - '0') * 10 + (buf[2] - '0'); }
		else if (k == 3) {
			oct_mask[i] = (buf[0] - '0') * 100 + (buf[1] - '0') * 10 + (buf[2] - '0');
		}

	}
	

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
