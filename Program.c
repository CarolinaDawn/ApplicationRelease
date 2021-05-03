#include <stdio.h> 
#include <string.h>

/*This section sets up budgetItem as a new type to be used later
Also sets up character to allow 500 characters in category list*/
typedef struct _budgetItem
{
	struct _budgetItem* next;
	int cost;
	char name[500]; //means char* name; //copiler statically initializes 500 elements for you, 
		//if you did your self you'd have to malloc(name, sizeof(char)*500);
	//#define sizeOfName  500;
} budgetItem;
budgetItem budget[100];


//Program asks user for input on what they will be spending, uses pointers to indicate what part of the typedef to use
int budgetThing(budgetItem* b, int whatigot) {
	printf("What I got: %i\n", whatigot);

int choice;

	printf("Choose a category using numbers 1-7:\n 1. Food\n 2. Gas\n 3. Phone\n 4. Rent/Mortgage\n 5. Entertainment\n 6. Groceries\n 7. Custom\n");
	scanf_s("%i", &choice); //TODO Carolina finish this scan_f call
	if (choice == 7)
	{
		scanf_s("%s", b->name, 500);
	}
	else if (choice == 1)
	{
		printf("Food\n");
	}
	else if (choice == 2)
	{
		printf("Gas\n");
	}
	else if (choice == 3)
	{
		printf("Phone\n");
	}
	else if (choice == 4)
	{
		printf("Rent/Mortgage\n");
	}
	else if (choice == 5)
	{
		printf("Entertainment\n");
	}
	else if (choice == 6)
	{
		char src[20] = "Groceries";
		printf("%s", &b->name, 500);
	}
	//TODO consider 10 categories and the user inputs "16". What happens?
	
	printf("How much are you spending? \n");
	scanf_s("%i", &b->cost);
	//Structure to set up budget end when it gets to 0

	while (b->cost > whatigot) {
		printf("That cost too much!");
		printf("How much are you spending? \n");
		scanf_s("%i", &b->cost);
	}
	return 0;
}


int main(int argc, const char* argv[])
{
	int cost;
	char* name;
	int totalIncome = 0;
	int numberofHours;
	int amountPaid;
	int paytype;
	int salarypay;

	printf("Select 1 for hourly employee, or 2 for salaried employee (1-2): ");
	scanf_s("%i", &paytype);
	if (paytype == 1)
	{
		//program will ask how many hours they work
		// program will ask how much they are paid

		printf("How much do you get paid per hour? ");
		scanf_s("%i", &amountPaid);

		printf("How many hours per week do you work? ");
		scanf_s("%i", &numberofHours);

		//calculation of monthly income

		if (numberofHours == 40)
		{
			totalIncome = amountPaid * 2080 / 12;
		}
		else
		{
			totalIncome = numberofHours * amountPaid * 52 / 12;
		}
	}
	else 
	{
			//User will enter total monthly income
		printf("How much do you get paid per month? ");
		scanf_s("%i", &salarypay);

		totalIncome = salarypay;
	}
		

		int spendAmount = 0;
		int budgetAmount = totalIncome;
		
		budgetItem* currentLineItem =  budget;
		int numberofitems = 0;

//Program will calculate based on user input and outpt what category is, how much is left, and how much is currently being spent
		while (budgetAmount > 0)
		{
			int ok = budgetThing(currentLineItem, budgetAmount);
			budgetAmount = budgetAmount - currentLineItem->cost;
			printf("\n%s: %i, Amount Left: %i\n", currentLineItem->name, currentLineItem->cost, budgetAmount);
			currentLineItem++;
			numberofitems++;
		}

		int i = 0;
		for (budgetItem* currentLineItem = budget; i < 10; i++) 
		{
			printf("\n%s: Cost: %i\n", currentLineItem->name, currentLineItem->cost);
			currentLineItem++;
		}

		return 0;

}