#include<stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
int Isomophic(Tree R1, Tree R2);

int main()
{
	Tree R1, R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);

	if (Isomophic(R1, R2))	printf("Yes\n");
	else printf("No\n");

	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	int N, i, check[MaxTree], Root=Null;//why Root=Null?
	char cl, cr;

	scanf_s("%d\n", &N);
	if (N)
	{
		for (i = 0; i < N; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			scanf_s("%c %c %c\n", &T[i].Element, &cl, &cr);//difference between \n or not
			if (cl!='-'){
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else	T[i].Right = Null;
		}
		for (i = 0; i < N; i++)
			if (!check[i])	break;
		Root = i;
	}
	return Root;
}

int Isomophic(Tree R1, Tree R2)
{
	if ((R1 == Null) &&( R2 == Null))
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null )&&( R2 == Null)))
		return 0;
	if (T1[R1].Element != T2[R2].Element)
		return 0;
	if ((T1[R1].Left == Null) &&( T2[R2].Left == Null))
		return Isomophic(T1[R1].Right, T2[R2].Right);
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) &&
		((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
		return (Isomophic(T1[R1].Left, T2[R2].Left) &&
			Isomophic(T1[R1].Right, T2[R2].Right));
	else
		return(Isomophic(T1[R1].Left, T2[R2].Right) && 
			Isomophic(T1[R1].Right, T2[R2].Left));
}