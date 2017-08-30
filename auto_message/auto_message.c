#include <stdio.h>

typedef enum
{
	DUMP,
	SECOND_CHANCE,
	MARRIGE,
} response_type;

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

int main(void)
{
	int i = 0;
	void (*replies[])(response) = {dump, second_chance, marrige};
	response r[] = 
	{
		{"Mike", DUMP}, {"Luis", SECOND_CHANCE},
		{"Matt", SECOND_CHANCE}, {"William", MARRIGE}
	};

	for (i = 0; i < 4; i++)
	{
		replies[r[i].type](r[i]);
	}

	return 0;
}