#include <stdio.h>

int main(int argc, const char* argv[])
{
	float spendAmount = 0;
	int budgetAmount = 1600;
	char budgetCategory[500];

	printf("What category does this fall under? \n");
	scanf_s("%s", &budgetCategory, 500);
	return budgetCategory;


	printf("What do you want to spend?\n");
	scanf_s("%i", &spendAmount);
	return budgetAmount - spendAmount;

	int h;

	while (budgetAmount >= 0)
	{
		budgetAmount = budgetAmount - spendAmount;
	}

	for (h = 1; h <= spendAmount; ++h);

	//program shows budget category and entered amount
	printf("\n%s: %i\n", budgetCategory, spendAmount);

	return 0;
}