#include <stdio.h>
#include <ctype.h>

typedef struct {
    char c;
    int frequency;
} Character;

int main() {
    char string[] =
        "Yd jxu qwu ev ydvehcqjyed, tqjq iuskhyjo rusecui shksyqb. Cqdo "
        "ioijuci hubo ed udshofjyed je fhejusj iudiyjylu ydvehcqjyed vhec "
        "kdqkjxehyput qssuii. Kdtuhijqdtydw xem je rhuqa iycfbu syfxuhi byau "
        "jxu Squiqh syfxuh sqd xubf yd tulubefydw ijhedwuh iuskhyjo cuqikhui";

    Character letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i].frequency = 0; // every letter starts with frequency = 0
        letters[i].c = 'a' + i;
    }

    for (int i = 0; string[i]; i++) {
        if (isalpha((unsigned char)string[i])) {
            char lower = tolower((unsigned char)string[i]);
            letters[lower - 'a'].frequency++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%-5c", letters[i].c);
    }
    putchar('\n');
    for (int i = 0; i < 26; i++) {
        printf("%-5d", letters[i].frequency);
    }
    putchar('\n');

    //Find the most frequent letter
    int max = letters[0].frequency;
    char mostFrequentchar = 'a';
    for (int i = 1; i < 26; i++) {
        if (letters[i].frequency > max) {
            max = letters[i].frequency;
            mostFrequentchar = letters[i].c;
        }
    }

    printf("The letter with the biggest frequency is %c (%d)\n",
           mostFrequentchar, max);

    //Shift based on the assumption that the most frequent letter in english is 'e'
    int jump = (mostFrequentchar - 'e' + 26) % 26;
    printf("Hypothesized shift: %d\n", jump);

    //Decrypting
    for (int i = 0; string[i]; i++) {
        if (isalpha((unsigned char)string[i])) {
            char base = isupper((unsigned char)string[i]) ? 'A' : 'a';
            string[i] = ((string[i] - base - jump) % 26 + 26) % 26 + base;
        }
    }
    printf("%s\n", string);
    
}
