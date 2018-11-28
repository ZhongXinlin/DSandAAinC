#include<stdlib.h>
#include<stdio.h>

struct PolyNode
{
	int coef, expon;
	struct PolyNode *Next;
};
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;

Polynomial ReadPoly();
void Attach(int c, int e, Polynomial *pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);

int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP=Mult(P1, P2);
	PrintPoly(PP);
	PS=Add(P1, P2);
	PrintPoly(PS);

	return 0;
}

Polynomial ReadPoly()
{
	Polynomial first, rear, t;
	int N, c, e;
	scanf_s("%d", &N);

	first = (Polynomial)malloc(sizeof(Polynomial));
	first->Next = NULL;
	rear = first;
	while (N--)
	{
		scanf_s("%d %d", &c, &e);
		Attach(c, e, &rear);
	}
	t = first;
	first = first->Next;
	free(t);
	return first;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial first, rear, temp, sP2;
	int c, e;
	if (!P1 || !P2)return NULL;

	first = (Polynomial)malloc(sizeof(Polynomial));
	first->Next = NULL;
	rear = first;

	sP2 = P2;

	while (P2)
	{
		Attach(P1->coef*P2->coef, P1->expon + P2->expon, &rear);
		P2 = P2->Next;
	}
	P1 = P1->Next;
	while (P1)
	{
		P2 = sP2;
		rear = first;
		while (P2)
		{
			c = P1->coef*P2->coef;
			e = P1->expon + P2->expon;
			while (rear->Next&&rear->Next->expon > e)//指针的指针。结果多项式链表中的数据项指数较大
			{
				rear = rear->Next;
			}
			if (rear->Next&&rear->Next->expon == e) {
				if (rear->Next->coef + c)
					rear->Next->coef += c;
				else {
					temp = rear->Next;
					rear->Next = temp->Next;
					free(temp);
				}
			}
			else
			{
				temp = (Polynomial)malloc(sizeof(Polynomial));
				temp->coef = c;
				temp->expon = e;
				temp->Next = rear->Next;
				rear->Next = temp;
				rear = rear->Next;
			}
			P2 = P2->Next;
		}
		P1 = P1->Next;
	}
	temp = first;
	first = first->Next;
	free(temp);
	return first;
}

Polynomial Add(Polynomial P1,Polynomial P2)
{
	Polynomial first, rear, t;
	int sum;
	first = (Polynomial)malloc(sizeof(Polynomial));
	first->Next = NULL;
	rear = first;
	while (P1&&P2)
	{
		if (P1->expon == P2->expon)
		{
			sum = P1->coef + P2->coef;
			if (sum)
			{
				Attach(sum, P1->expon, &rear);
			}
			P1 = P1->Next;
			P2 = P2->Next;
		}
		else if (P1->expon>P2->expon)
		{
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->Next;
		}
		else
		{
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->Next;
		}
	}
	for (; P1; P1 = P1->Next)
		Attach(P1->coef, P1->expon, &rear);
	for (; P2; P2 = P2->Next)
		Attach(P2->coef, P2->expon, &rear);

	t = first;
	first = first->Next;
	free(t);

	return first;
}

void PrintPoly(Polynomial P)
{
	int flag=0;
	if (!P)
	{
		printf("0 0\n");
		return;
	}
	while (P)
	{
		if (!flag)
		{
			flag = 1;
		}
		else
		{
			printf(" ");
		}
		printf("%d %d", P->coef, P->expon);
		P = P->Next;
	}
	printf("\n");
}

void Attach(int c, int e, Polynomial*pRear)//指针的指针,pRear是一个定义好的值，attach需要修改它的值，所以要传它的指针
{
	Polynomial P =(Polynomial)malloc(sizeof(Polynomial));
	P->coef = c;
	P->expon = e;
	P->Next = NULL;
	(*pRear)->Next = P;
	*pRear = P;
}
