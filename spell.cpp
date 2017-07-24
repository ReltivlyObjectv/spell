#include <cstdio>
#include <fstream>
#include <iostream>
#ifdef __APPLE__
const char filename[] = "/usr/share/dict/words";
#else
const char filename[] = "/usr/share/dict/cracklib-small";
#endif

int main()
{
	bool isFound = false;
	char word[100];
	//printf("Enter a word: ");
	//std::cin >> word;
	strcpy(word, "zebra");
	int n = 0;
	char data[70000][45];
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
					//data[i] = line;
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
			strcpy(data[n], line);
			n++;
		}
		fin.close();

	}
	int start, end, mid;
	//bubble sort
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if (strcmp(data[j], data[j+1]) > 0) {
				std::swap(data[j], data[j+1]);
			}
		}
	}
	//binary search
	start = 0;
	end = n-1;
	while (start <= end) {
		mid = start+(end/2);
		int compare = strcmp(data[mid], word);
		if (compare == 0) {
			printf("DOUNE with binary search\n");
		}
		if (compare > 0) {
			end = mid-1;
		}
		if (compare < 0) {
			start = mid+1;
		}
	}
	

	if (isFound) {
		printf("%s was found!\n", word);
	} else {
		printf("%s was not found!\n", word);
	}
	return 0;
}
