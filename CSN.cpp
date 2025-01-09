#include<stdio.h>
#include<cstdlib>
#include<ctime>
struct NODE
{
  int data;
  struct NODE *pRight,*pLeft;
};
struct STACK
{
  NODE *a[1000];
  int top;
};
typedef NODE*TREE;


void Init(TREE &root)
{
  root = NULL;
}

int IsEmpty(STACK stack)
{
  return stack.top == -1;
}

void Push(STACK &stack, NODE *p) 
{
  stack.a[++stack.top] = p;
}

NODE *Pop(STACK &stack)
{
  if(IsEmpty(stack))
  {
    return NULL;
  }
  return stack.a[stack.top--];
}

void InsertTree(TREE &root,int x)
{
  if(root != NULL)
  {
    if(root->data == x)
	{
      return;	
    }
    if(root->data > x)
    {
	  InsertTree(root->pLeft,x);
	}
	else
	{
	  InsertTree(root->pRight,x);
    }
  }  
  else
  {
	root = new NODE;
	root->data= x;
	root->pLeft = root->pRight = NULL;
  }
}

void BuildTree(TREE &root)
{
  int x,n;
  printf("Nhap so nut:");
  scanf("%d",&n);
  for(int i = 1;i <= n;i++)
  {
	printf("Nhap nut thu %d:",i);
	scanf("%d",&x);
	InsertTree(root,x);
  }
  printf("Da tao cay voi %d phan tu.",n);
}
void CreateRandomTree(TREE &root) 
{
  int n, minValue, maxValue;
  printf("Nhap so luong nut: ");
  scanf("%d", &n);
  printf("Nhap khoang gia tri: ");
  scanf("%d %d", &minValue, &maxValue);
  srand(time(0));
  for (int i = 0; i < n; i++) 
  {
    int x = minValue + rand() % (maxValue - minValue + 1);
    InsertTree(root, x);
  }
  printf("Da tao cay voi %d phan tu ngau nhien.\n", n);
}
void NLRRecursive(TREE root)
{
  if(root!=NULL)
  {
	printf("%d\t",root->data);
	NLRRecursive(root->pLeft);
	NLRRecursive(root->pRight);
  }
}

void LNRRecursive(TREE root)
{
  if(root != NULL)
  {
	LNRRecursive(root->pLeft);
	printf("%d\t",root->data);
	LNRRecursive(root->pRight);
  }
}

void LRNRecursive(TREE root)
{
  if(root != NULL)
  {
	LRNRecursive(root->pLeft);
	LRNRecursive(root->pRight);
	printf("%d\t",root->data);
  }
}

void NLRIterative(TREE root) 
{
  NODE* p = root;
  STACK stack;
  stack.top = -1;
  while (p != NULL || !IsEmpty(stack)) 
  {
    if (p != NULL)
	{
      printf("%d\t", p->data); 
      Push(stack, p);
      p = p->pLeft; 
    }
    else
	{
      p = Pop(stack);
      p = p->pRight;
    }
  }
}

void LNRIterative(TREE root)
{
  NODE *p = root;
  STACK stack;
  stack.top = -1;
  while(p != NULL || !IsEmpty(stack))
  {
	if(p != NULL)
	{
	  Push(stack,p);
	  p = p->pLeft;
	}
	else
	{
	  p = Pop(stack);
	  printf("%d\t", p->data);
	  p = p->pRight;
	}
  }
}


void LRNIterative(TREE root)
{
  NODE *p = root;
  STACK stack;
  stack.top = -1;
  NODE *lastVisited = NULL;
  while(p != NULL || !IsEmpty(stack))
  {
	if(p != NULL)
	{
	  Push(stack,p);
	  p = p->pLeft;
	}
	else
	{
	  if(stack.a[stack.top]->pRight != NULL && lastVisited != stack.a[stack.top]->pRight)
	  {
	    p = stack.a[stack.top]->pRight;
	  }
	  else
	  {
	    printf("%d\t",stack.a[stack.top]->data);
	    lastVisited = Pop(stack);
	  }
	}
  }
}
void Solve() 
{
  TREE root;
  Init(root);
  int option;
  while (true) 
  {
    printf("\n===== MENU =====\n");
    printf("1. Nhap du lieu thu cong de tao cay\n");
    printf("2. Tao cay voi du lieu ngau nhien\n");
    printf("3. Duyet cay\n");
    printf("4. Thoat\n");
    printf("Lua chon: ");
    scanf("%d", &option);
    if (option == 1) 
	{
	  printf("\n===== TAO CAY THU CONG =====\n");
      BuildTree(root);
    } 
    else if (option == 2) 
	{
      printf("\n===== TAO CAY TU DONG =====\n");
      CreateRandomTree(root);
    } 
    else if (option == 3) 
	{
      if (root == NULL) 
	  {
        printf("Cay hien tai dang rong. Vui long tao cay truoc.\n");
      } 
	  else 
	  {
		printf("\n===== MENU =====\n");
        int traverseOption;
        printf("1. Duyet Pre-order (NLR)\n");
        printf("2. Duyet In-order (LNR)\n");
        printf("3. Duyet Post-order (LRN)\n");
        printf("Lua chon: ");
        scanf("%d", &traverseOption);
        int methodOption;
        printf("\n===== MENU =====\n");
        printf("1. De quy\n");
        printf("2. Khu de quy\n");
        printf("3. Ca hai\n");
        printf("Lua chon: ");
        scanf("%d", &methodOption);
        if (traverseOption == 1) 
		{
          if (methodOption == 1) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("Duyet Pre-order (De quy): ");
            NLRRecursive(root);
          } 
		  else if (methodOption == 2) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("Duyet Pre-order (Khu de quy): ");
            NLRIterative(root);
          } 
		  else if (methodOption == 3) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("Duyet Pre-order (De quy):\t");
            NLRRecursive(root);
            printf("\nDuyet Pre-order (Khu de quy): ");
            NLRIterative(root);
          } 
		  else 
		  {
            printf("Lua chon khong hop le.\n");
          }
        } 
        else if (traverseOption == 2) 
		{
          if (methodOption == 1) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("Duyet In-order (De quy): ");
            LNRRecursive(root);
          } 
		  else if (methodOption == 2) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("Duyet In-order (Khu de quy): ");
            LNRIterative(root);
          } 
		  else if (methodOption == 3) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("Duyet In-order (De quy):\t");
            LNRRecursive(root);
            printf("\nDuyet In-order (Khu de quy):");
            LNRIterative(root);
          } 
		  else 
		  {
            printf("Lua chon khong hop le.\n");
          }
        } 
        else if (traverseOption == 3) 
		{
          if (methodOption == 1) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("\nDuyet Post-order (De quy): ");
            LRNRecursive(root);
          } 
		  else if (methodOption == 2) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("\nDuyet Post-order (Khu de quy): ");
            LRNIterative(root);
          } 
		  else if (methodOption == 3) 
		  {
		  	printf("\n===== KET QUA =====\n");
            printf("\nDuyet Post-order (De quy):\t");
            LRNRecursive(root);
            printf("\nDuyet Post-order (Khu de quy): ");
            LRNIterative(root);
          } 
		  else 
		  {
            printf("Lua chon khong hop le.\n");
          }
        } 
        else 
		{
          printf("Lua chon khong hop le.\n");
        }
        printf("\n");
      }
    } 
    else if (option == 4) 
	{
      printf("Dang thoat chuong trinh. Tam biet!\n");
      break;
    } 
    else 
	{
      printf("Lua chon khong hop le. Vui long thu lai.\n");
    }
  }
}


int main()
{ 
  Solve();
  return 0;
}


