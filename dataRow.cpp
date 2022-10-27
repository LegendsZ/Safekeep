#include "dataRow.h"

std::vector<int> DataRowCustom::includes(std::string toLookFor)
{
	std::vector<int> indices;
	for (int i = 0; i < accs.size(); i++) {
		if (accs.at(i)->includes(toLookFor)) {
			indices.push_back(i);
		}
	}
	return indices;
}

bool DataRowCustom::changeEncryptionLvl(int lvl) {
	elvl = (EncryptionLevel)lvl;
	return true;
}
EncryptionLevel DataRowCustom::retEncryptionLvl() {
	return elvl;
}