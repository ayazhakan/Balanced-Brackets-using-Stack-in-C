#include <stdio.h>
#include <stdlib.h>
#define bool int

// Y���t d���m� i�in olu�turdu�umuz yap�
struct stackNode {
	char data;
	struct stackNode* next;
};

// Y���ta item ekleme fonksiyonu
void push(struct stackNode** top_ref, int new_data);

// Y���ttan item �ekme fonksiyonu
int pop(struct stackNode** top_ref);

// E�er character1 ve character 2 e�le�irse 1 d�nderilir.
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

// Parantezler do�ru bir �ekilde e�le�irse 1 return edilir
bool areBracketsBalanced(char exp[])
{
	int i = 0;

	// Bo� bir karakter y���t� tan�mland�.
	struct stackNode* stack = NULL;

	// Parantezlerin e�le�ip e�le�medi�i kontrol edilir
	
	while (exp[i])
	{
		// E�er exp[i] parantezle ba�l�yorsa bu parantez y���ta pushlan�r.
		
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]);

		// E�er exp[i] parantezle bitiyor ise 
		// y���ttaki parantez pop edilir ve e�le�me kontrol edilir
		if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') {

			// E�er son gelen parantezin �ifti yoksa
			// 0 return edilir
			
			if (stack == NULL)
				return 0;

			// Y���t�n tepesindeki eleman getirilir
			// ve e�er getirilen parantezin �ifti yoksa
			// e�le�memezlik durumu vard�r.
			// �rne�in: {(}) bu durumda da 0 return edilir
			else if (!isMatchingPair(pop(&stack), exp[i]))
				return 0;
		}
		i++;
	}

	// E�er geriye ifade kald�ysa a��lan parantez
	//kapat�lmam��t�r
	
	if (stack == NULL)
		return 1; // Parantezler e�le�iyor
	else
		return 0; // E�le�miyor
}


int main()
{   char *cp;
	char exp[100] = "{(})[]";
     cp = fgets(exp, 100, stdin);

	// Fonksiyon �a��r�l�r
	if (areBracketsBalanced(exp))
		printf("Parantezler eslesiyor \n");
	else
		printf("Eslesmiyor \n");
	return 0;
}

// Y���ta item pushlama fonksiyonu
void push(struct stackNode** top_ref, int new_data)
{
	// d���m olu�turmak
	struct stackNode* new_node
		= (struct stackNode*)malloc(sizeof(struct stackNode));

	if (new_node == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}

	// yeni veri ekleme
	new_node->data = new_data;

	// eski listeyi yeni d���me ba�lar
	new_node->next = (*top_ref);

	// yeni d���me ula�mak i�in eski d���m�n ba��
	// yeni d���me ba�lan�r
	(*top_ref) = new_node;
}

// Y���ttan item getirme(pop) fonksiyonu
int pop(struct stackNode** top_ref)
{
	char res;
	struct stackNode* top;

	// Y���t bo�sa hata verilir
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
