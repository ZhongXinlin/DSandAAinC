#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */
List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);

 	return 0;
}
List Merge(List L1, List L2) {
	List r;
	List p = L1->Next;
	List q = L2->Next;

	List L = (List)malloc(sizeof(List));
	r = L;
	L->Next = NULL;//忘记
	while (p!=NULL&&q!=NULL)
	{
		if (p->Data< q->Data) {
			r->Next = p;
			r = r->Next;
			p = p->Next;
		}
		else
		{
			r->Next = q;
			r = r->Next;
			q = q->Next;
		}
	}
	r->Next = NULL;//wang
	if (p!=NULL)
	{
		r->Next = p;
	}
	if (q!=NULL)
	{
		r->Next = q;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}
List Read()
{
	int len = 0;
	int num = 0;
	PtrToNode h = NULL;
	PtrToNode last = NULL;

	scanf_s("%d", &len);
	if (len == 0)
		return NULL;

	h = (PtrToNode)malloc(sizeof(struct Node));//建立头结点
	h->Next = NULL;
	last = h;
	while (len) {
		scanf_s("%d", &num);
		PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));
		node->Data = num;
		node->Next = NULL;
		last->Next = node;
		last = node;
		len--;
	}
	return h;
}
void Print(List L)
{
	if (L->Next == NULL) {
		printf("NULL\n");
		return;
	}
	L = L->Next;
	while (L != NULL) {
		printf("%d ", L->Data);
		L = L->Next;
	}
	putchar('\n');
}