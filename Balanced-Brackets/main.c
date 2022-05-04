#include <stdio.h>
#include <stdlib.h>
#define bool int

// Yığıt düğümü için oluşturduğumuz yapı
struct stackNode {
	char data;
	struct stackNode* next;
};

// Yığıta item ekleme fonksiyonu
void push(struct stackNode** top_ref, int new_data);

// Yığıttan item çekme fonksiyonu
int pop(struct stackNode** top_ref);

// Eğer character1 ve character 2 eşleşirse 1 dönderilir.
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

// Parantezler doğru bir şekilde eşleşirse 1 return edilir
bool areBracketsBalanced(char exp[])
{
	int i = 0;

	// Boş bir karakter yığıtı tanımlandı.
	struct stackNode* stack = NULL;

	// Parantezlerin eşleşip eşleşmediği kontrol edilir
	
	while (exp[i])
	{
		// Eğer exp[i] parantezle başlıyorsa bu parantez yığıta pushlanır.
		
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]);

		// Eğer exp[i] parantezle bitiyor ise 
		// yığıttaki parantez pop edilir ve eşleşme kontrol edilir
		if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') {

			// Eğer son gelen parantezin çifti yoksa
			// 0 return edilir
			
			if (stack == NULL)
				return 0;

			// Yığıtın tepesindeki eleman getirilir
			// ve eğer getirilen parantezin çifti yoksa
			// eşleşmemezlik durumu vardır.
			// örneğin: {(}) bu durumda da 0 return edilir
			else if (!isMatchingPair(pop(&stack), exp[i]))
				return 0;
		}
		i++;
	}

	// Eğer geriye ifade kaldıysa açılan parantez
	//kapatılmamıştır
	
	if (stack == NULL)
		return 1; // Parantezler eşleşiyor
	else
		return 0; // Eşleşmiyor
}


int main()
{   char *cp;
	char exp[100] = "{(})[]";
     cp = fgets(exp, 100, stdin);

	// Fonksiyon çağırılır
	if (areBracketsBalanced(exp))
		printf("Parantezler eslesiyor \n");
	else
		printf("Eslesmiyor \n");
	return 0;
}

// Yığıta item pushlama fonksiyonu
void push(struct stackNode** top_ref, int new_data)
{
	// düğüm oluşturmak
	struct stackNode* new_node
		= (struct stackNode*)malloc(sizeof(struct stackNode));

	if (new_node == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}

	// yeni veri ekleme
	new_node->data = new_data;

	// eski listeyi yeni düğüme bağlar
	new_node->next = (*top_ref);

	// yeni düğüme ulaşmak için eski düğümün başı
	// yeni düğüme bağlanır
	(*top_ref) = new_node;
}

// Yığıttan item getirme(pop) fonksiyonu
int pop(struct stackNode** top_ref)
{
	char res;
	struct stackNode* top;

	// Yığıt boşsa hata verilir
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
