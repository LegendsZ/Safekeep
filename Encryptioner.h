#pragma once

enum EncryptionLevel {
	//set various styles
	Basic = 0,
	Intermediate = 1,
};

class Encryptioner {
private:
	static EncryptionLevel elvl;
	static struct BasicEncryptionStyle {
	private:
		static const int valChange = 3;
	public:
		static std::string Encrypt(std::string input) {
			std::string newStr;
			for (int i = 0; i < input.length(); i++) {
				int val = int(input[0]);
				newStr += char( val += valChange);
			}
			return newStr;
		}
		static std::string Decrypt(std::string input) {
			std::string newStr;
			for (int i = 0; i < input.length(); i++) {
				int val = int(input[0]);
				newStr += char(val += (-1 * valChange));
			}
			return newStr;
		}
	};
	static struct IntermediateEncryptionStyle {
	public:
		static std::string Encrypt(std::string input) {
			return input;
		}
		static std::string Decrypt(std::string input) {
			return input;
		}
	};
public:
	static std::string Encrypt(std::string input, EncryptionLevel elvlG) {
		switch (elvlG) {
		case EncryptionLevel::Basic:
			return BasicEncryptionStyle::Encrypt(input);
			break;
		case EncryptionLevel::Intermediate:
			return IntermediateEncryptionStyle::Encrypt(input);
			break;
		default:
			return NULL;
		}
	}
	static std::string Decrypt(std::string input, EncryptionLevel elvlG) {
		switch (elvlG) {
		case EncryptionLevel::Basic:
			return BasicEncryptionStyle::Decrypt(input);
			break;
		case EncryptionLevel::Intermediate:
			return IntermediateEncryptionStyle::Decrypt(input);
			break;
		default:
			return NULL;
		}
	}

	static std::string Encrypt(std::string input) {
		switch (elvl) {
		case EncryptionLevel::Basic:
			return BasicEncryptionStyle::Encrypt(input);
			break;
		case EncryptionLevel::Intermediate:
			return IntermediateEncryptionStyle::Encrypt(input);
			break;
		default:
			return NULL;
		}
	}
	static std::string Decrypt(std::string input) {
		switch (elvl) {
		case EncryptionLevel::Basic:
			return BasicEncryptionStyle::Decrypt(input);
			break;
		case EncryptionLevel::Intermediate:
			return IntermediateEncryptionStyle::Decrypt(input);
			break;
		default:
			return NULL;
		}
	}
	static bool setEncryptionLvl(int lvl) {
		elvl = (EncryptionLevel)lvl;
	}
};