#include <stdio.h>
#include <stdarg.h>

typedef enum
{
	MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
} drink;

double price(drink d)
{
	switch (d)
	{
		case MUDSLIDE:
			return 6.79;
		case FUZZY_NAVEL:
			return 5.31;
		case MONKEY_GLAND:
			return 4.82;
		case ZOMBIE:
			return 5.89;
		default:
			return 0.0;
	}

	return 0.0;
}

double get_price(int args, ...)
{
	int i = 0;
	drink d = 0;
	double total = 0.0;

	va_list ap;
	va_start(ap, args);

	for (i = 0; i < args; i++)
	{
		d = va_arg(ap, drink);
		total += price(d);
	}

	va_end(ap);

	return total;
}

int main(void)
{
	printf("Price is %.2f\n", get_price(2, MONKEY_GLAND, MUDSLIDE));
	printf("Price is %.2f\n", get_price(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
	printf("Price is %.2f\n", get_price(1, ZOMBIE));

	return 0;
}