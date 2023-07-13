#include <bits/stdc++.h>
using namespace std;

int main()
{
	string all_letrs = 'Mewa wa mey twsam iepjoys gt mey ipbya.
        Pa xgn iph ayy, meysy wa hgmewhr gt
        whmysyam wh mey iepjoys. Agjy gt mey kpmys
        iepjoysa vwkk oy jgsy whmysyamwhr meph
        mewa ghy! Mey iguy nayu tgs mewa jyaapry
        wa p awjfky anoamwmnmwgh iwfeys wh vewie
        uwrwma epby oyyh aewtmyu ox 8 fkpiya.
        Mey fpaavgsu wa "mxSrN03uwdd" vwmegnm mey
        dngmya.';

	// create a dictionary to store the substitution for the
	// given alphabet in the plain text based on the key
	map<char, char> dict1;
	int key = 4;
	for (int i = 0; i < all_letrs.length(); i++) {
		dict1[all_letrs[i]]
			= all_letrs[(i + key) % all_letrs.length()];
	}

	string plain_txt = "I am studying Data Encryption";
	string cipher_txt;

	// loop to generate ciphertext
	for (char& c : plain_txt) {
		if (all_letrs.find(c) != string::npos) {
			cipher_txt += dict1;
		}
		else {
			cipher_txt += c;
		}
	}

	cout << "Cipher Text is: " << cipher_txt << endl;

	// create a map to store the substitution for the given
	// alphabet in the cipher text based on the key
	map<char, char> dict2;
	for (int i = 0; i < all_letrs.length(); i++) {
		dict2[all_letrs[i]]
			= all_letrs[(i - key) % all_letrs.length()];
	}

	string decrypt_txt;

	// loop to recover plain text
	for (char& c : cipher_txt) {
		if (all_letrs.find(c) != string::npos) {
			decrypt_txt += dict2;
		}
		else {
			decrypt_txt += c;
		}
	}

	cout << "Recovered plain text : " << decrypt_txt
		<< endl;

	return 0;
}
