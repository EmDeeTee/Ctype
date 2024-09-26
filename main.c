#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdint.h>

#pragma warning(disable:4996)

// [SUBJECT] [ACTION] [ADVERB] [VERB] [ADJECTIVE] [NOUN] [CONCLUSION].

const char* const SUBJECT[] = { "ancestor","he", "she" };
const char* const VERBS[] = { "think","practice", "exist", "drive", "explore", "imagine", "construct"};
const char* const ADVERBS[] = { "slowly", "gently", "quickly", "boldly"};
const char* const NOUNS[] = { "vehicle","vessel", "witchcraft", "generosity" };
const char* const ADJECTIVES[] = { " damaged ","mundane","huge", "fragile", "vibrant" };
const char* const ACTION[] = { "felt a strong urge to","snapped and began to" };
const char* const CONCLUSIONS[] = { "without hesitation.", "would be the end of all.", "never paid off." };

const size_t LEN_SUBJECT = sizeof(SUBJECT) / sizeof(SUBJECT[0]);
const size_t LEN_VERBS = sizeof(VERBS) / sizeof(VERBS[0]);
const size_t LEN_ADVERBS = sizeof(ADVERBS) / sizeof(ADVERBS[0]);
const size_t LEN_NOUNS = sizeof(NOUNS) / sizeof(NOUNS[0]);
const size_t LEN_ADJECTIVES = sizeof(ADJECTIVES) / sizeof(ADJECTIVES[0]);
const size_t LEN_ACTION = sizeof(ACTION) / sizeof(ACTION[0]);
const size_t LEN_CONCLUSIONS = sizeof(CONCLUSIONS) / sizeof(CONCLUSIONS[0]);

char str[1024];

 const char* RandomFromArray(const char** const org, const size_t s) {
	return org[rand() % s];
}
 
int main(void) {
	srand(time(NULL));

	const char* subject = RandomFromArray(SUBJECT, LEN_SUBJECT);
	const char* action = RandomFromArray(ACTION, LEN_ACTION);
	const char* adverb = RandomFromArray(ADVERBS, LEN_ADVERBS);
	const char* verb = RandomFromArray(VERBS, LEN_VERBS);
	const char* adjective = RandomFromArray(ADJECTIVES, LEN_ADJECTIVES);
	const char* noun = RandomFromArray(NOUNS, LEN_NOUNS);
	const char* conclusion = RandomFromArray(CONCLUSIONS, LEN_CONCLUSIONS);

	sprintf(str, "%s %s %s %s %s %s %s", subject, action, adverb, verb, adjective, noun, conclusion);
	printf("%s\n", str);
	const char* p = str;
	char strC = *p;
	uint32_t errors = 0;

	while (*p != '\0') {
		const char userC = _getch();
		if (userC == strC) {
			putchar(userC);
			p++;
		} else {
			errors++;
		}
		strC = *p;
	}

	printf("\nYou made: %i errors\n", errors);
}