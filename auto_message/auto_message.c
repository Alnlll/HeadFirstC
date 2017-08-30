#include <stdio.h>

//#define ORIGIN

typedef enum
{
	DUMP,
	SECOND_CHANCE,
	MARRIGE,
} response_type;

#ifdef ORIGIN
typedef struct
{
	char *name;
	response_type type;
} response;

void dump(response r)
{
	printf("Dear %s,\n", r.name);
	puts("Unfortunate your last date contacted us to");
	puts("say that will not be seeing you again.");
}

void second_chance(response r)
{
	printf("Dear %s,\n", r.name);
	puts("Good news: your last date has asked us to");
	puts("arrange another meeting.");
}

void marrige(response r)
{
	printf("Dear %s,\n", r.name);
	puts("Congratulations! Your last date has contacted");
	puts("us with a proposal of marrige");
}

#else
typedef void (*REPLIES)(char *);
typedef struct
{
	char *name;
	REPLIES reply;
} response;

void dump(char *name)
{
	printf("Dear %s,\n", name);
	puts("Unfortunate your last date contacted us to");
	puts("say that will not be seeing you again.");
}

void second_chance(char *name)
{
	printf("Dear %s,\n", name);
	puts("Good news: your last date has asked us to");
	puts("arrange another meeting.");
}

void marrige(char *name)
{
	printf("Dear %s,\n", name);
	puts("Congratulations! Your last date has contacted");
	puts("us with a proposal of marrige");
}

#endif //ORIGIN

int main(void)
{
	int i = 0;
#ifdef ORIGIN
	void (*replies[])(response) = {dump, second_chance, marrige};
	response r[] = 
	{
		{"Mike", DUMP}, {"Luis", SECOND_CHANCE},
		{"Matt", SECOND_CHANCE}, {"William", MARRIGE}
	};
#else
	response r[] = 
	{
		{"Mike", dump}, {"Luis", second_chance},
		{"Matt", second_chance}, {"William", marrige}
	};
#endif //ORIGIN

	for (i = 0; i < 4; i++)
	{
#ifdef ORIGIN
		replies[r[i].type](r[i]);
#else
		r[i].reply(r[i].name);
#endif //ORIGIN
	}

	return 0;
}