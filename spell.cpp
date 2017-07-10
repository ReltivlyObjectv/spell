#include <cstdio>
#include <fstream>
#include <iostream>
//const char filename[] = "/usr/share/dict/cracklib-small";
const char filename[] = "/usr/share/dict/words";

int main()
{
	bool isFound = false;
	char word[100];
	//printf("Enter a word: ");
	//std::cin >> word;
	strcpy(word, "zebra");
	for (int i = 0; i < 100; i++) {
		std::ifstream fin;
		fin.open(filename);
		if (fin.fail()) {
			printf("error opening file\n");
			exit(1);
		}
		char line[1000];
		char save[1000];
		fin >> line;
		while (!fin.eof()) {
			if (strlen(save) > 0) {
				if (strcmp(save, line) >= 0) {
					printf("Not sorted at %s\n", line);
				}
			}
			strcpy(save, line);
			//printf("Found: %s\n", line);
			if (strcmp(line, word) == 0) {
				isFound = true;
				break;
			}
			fin >> line;
		}
		fin.close();

	}
	if (isFound) {
		printf("%s was found!\n", word);
	} else {
		printf("%s was not found!\n", word);
	}
	return 0;
}
