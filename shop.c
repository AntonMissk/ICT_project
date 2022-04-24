#include <cstring>
#include <iostream>

#define SIZE 20
int amount = 1000; 

struct book {
	char name[SIZE]; 
	int id; 
	int coast;
	struct book* next; 
};

void add(char* name, int id, int coast,  struct book** first)
{
	struct book* newBook;
	struct book* thisBook;

	// alokace dynamicke promenne
	newBook = (struct book*)malloc(sizeof(struct book));

	strncpy(newBook->name,name,SIZE); // naplneni struktury
	newBook->id = id;
	newBook->coast = coast;
	newBook->next = NULL;

	if (*first == NULL) // linearni seznam je prazdny
	{
		*first = newBook;
		return;
	}
	else // vlozime na zacatek
	{
		newBook->next = *first;
		*first = newBook;
		return;
	}
}


int buy(int id, struct book** first) {
	struct book* aktBook; 
	aktBook = *first;
	
	while (aktBook) 
	{
		if (aktBook->id == id) 
		{
			return aktBook->coast;
		}
		aktBook = aktBook->next;
	}
}


void del(int id, struct book** next)
{
	struct book* aktBook;

	while (*next && (*next)->id == id)
	{
		struct book* newPrvni = (*next)->next;
		free(*next);  
		*next = newPrvni;
	}

	aktBook = *next;
	while (aktBook && aktBook->next) // prochazeni seznamu
	{
		if (aktBook->next->id == id) // je ke smazani
		{
			struct book* newDalsi = aktBook->next->next;
			free(aktBook->next);  // uvolneni z pameti
			aktBook->next = newDalsi;
		}
		aktBook = aktBook->next; // posun na dalsi 
	}
}



struct book* prvni = NULL; // globalni ukazatel na prvni

void OnAdd()
{
	char my_name[SIZE];
	int my_id;
	int coast; 

	printf("\nName : ");         // dotazeme se na polozky
	scanf("%s", my_name);
	printf("\nID : ");
	scanf("%d", &my_id);
	while (getchar() != '\n');
	printf("\nCoast : ");
	scanf("%d", &coast);
	add(my_name, my_id,coast, &prvni);         // volame pridavaci funkci
}

void onBuy(int kol) {
	int my_id;
	printf("\nID : ");
	scanf("%d", &my_id);
	int coast = buy(my_id, &prvni);
	printf("coast %d", coast);
	while (getchar() != '\n');
	amount-= coast * kol;
 }

void OnDel()
{
	int my_id;

	printf("\nID : ");
	scanf("%d", &my_id);
	while (getchar() != '\n');
	del(my_id, &prvni);         // volame mazaci funkci
}

void ShowCars()
{
	struct book* aktBook = prvni; // ukazatel na aktualni 
	printf("\n\n");
	while (aktBook) // prochazeni seznamu
	{
		printf("%d: %s %d\n", aktBook->id, aktBook->name, aktBook->coast); // tisk radku
		aktBook = aktBook->next; // posun na dalsi 
	}
	getchar();
}


int main()
{	
	int id;
	int kol; 
	char  cmd;

	do
	{
		system("clear");		// smaze obrazovku
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("B: Koupit     ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();					// volame pridani
			break;
		case 'd':
			OnDel();					// volame mazani
			break;
		case 'p':
			ShowCars();
			break;
		case 'b':
		
			printf("kol :");
			scanf("%d", &kol);
			onBuy(kol);
			printf("amount : %d ", amount);
			break;
		}

	} while (cmd != 'q');     // koncime az pri Q
	printf("amount : %d ", amount);
	return 0;
}
