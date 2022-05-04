#include <stdio.h>
#include <stdlib.h>
#define bool int

// Yýðýt düðümü için oluþturduðumuz yapý
struct stackNode {
	char data;
	struct stackNode* next;
};

// Yýðýta item ekleme fonksiyonu
void push(struct stackNode** top_ref, int new_data);

// Yýðýttan item çekme fonksiyonu
int pop(struct stackNode** top_ref);

// Eðer character1 ve character 2 eþleþirse 1 dönderilir.
// and right Brackets
bool isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

// Parantezler doðru bir þekilde eþleþirse 1 return edilir
bool areBracketsBalanced(char exp[])
{
	int i = 0;

	// Boþ bir karakter yýðýtý tanýmlandý.
	struct stackNode* stack = NULL;

	// Parantezlerin eþleþip eþleþmediði kontrol edilir
	
	while (exp[i])
	{
		// Eðer exp[i] parantezle baþlýyorsa bu parantez yýðýta pushlanýr.
		
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]);

		// Eðer exp[i] parantezle bitiyor ise 
		// yýðýttaki parantez pop edilir ve eþleþme kontrol edilir
		if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') {

			// Eðer son gelen parantezin çifti yoksa
			// 0 return edilir
			
			if (stack == NULL)
				return 0;

			// Yýðýtýn tepesindeki eleman getirilir
			// ve eðer getirilen parantezin çifti yoksa
			// eþleþmemezlik durumu vardýr.
			// örneðin: {(}) bu durumda da 0 return edilir
			else if (!isMatchingPair(pop(&stack), exp[i]))
				return 0;
		}
		i++;
	}

	// Eðer geriye ifade kaldýysa açýlan parantez
	//kapatýlmamýþtýr
	
	if (stack == NULL)
		return 1; // Parantezler eþleþiyor
	else
		return 0; // Eþleþmiyor
}


int main()
{   char *cp;
	char exp[100] = "{(})[]";
     cp = fgets(exp, 100, stdin);

	// Fonksiyon çaðýrýlýr
	if (areBracketsBalanced(exp))
		printf("Parantezler eslesiyor \n");
	else
		printf("Eslesmiyor \n");
	return 0;
}

// Yýðýta item pushlama fonksiyonu
void push(struct stackNode** top_ref, int new_data)
{
	// düðüm oluþturmak
	struct stackNode* new_node
		= (struct stackNode*)malloc(sizeof(struct stackNode));

	if (new_node == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}

	// yeni veri ekleme
	new_node->data = new_data;

	// eski listeyi yeni düðüme baðlar
	new_node->next = (*top_ref);

	// yeni düðüme ulaþmak için eski düðümün baþý
	// yeni düðüme baðlanýr
	(*top_ref) = new_node;
}

// Yýðýttan item getirme(pop) fonksiyonu
int pop(struct stackNode** top_ref)
{
	char res;
	struct stackNode* top;

	// Yýðýt boþsa hata verilir
	if (*top_ref == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}
	else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}
