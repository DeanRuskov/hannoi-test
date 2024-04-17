#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>

struct point {
    int x;
    

    point* pnext = NULL;
};

void add(point** h, int x)
{
    point* temp = (point*)malloc(sizeof(point));
    temp->x = x;
    
    temp->pnext = *h;
    *h = temp;

}
int count(point* h)
{
    int a = 0;
    while (h != NULL)
    {
        a++;
        h = h->pnext;
    }
    return a;
}

int pop(point** h)
{
    point* temp;
    temp = (*h)->pnext;
    int x = (*h)->x;
    free(*h);
    *h = temp;
    return x;
}
void del(point** h, int x, int y)
{
    point* temp = *h;
    point* prev = NULL;
    while (temp != NULL)
    {
        if (temp->x == x )
        {
            if (prev == NULL)
            {
                *h = temp->pnext;
            }
            else
            {
                prev->pnext = temp->pnext;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->pnext;
    }

}

void towerOfHanoi(int n, point* headA, point* headC,
    point* headB)
{
    if (n == 0) {
        return;
    }
    
    towerOfHanoi(n - 1, headA, headB, headC);
    
    add(&headC, pop(&headA));
    
  // cout << "Move disk " << n << " from rod " << from_rod
  //     << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, headB, headC, headA);
}


// Driver code 
int main()
{
    int N = 3;
    point* headA =new point() ;
    point* headB= new point();
    point* headC= new point();
    point* temp = headC;
   // int hui = pop (&headA);
    // A, B and C are names of rods 
    for (int i = N; i >= 1; i--)
    {
        add(&headA, i);

    }
    towerOfHanoi(N, headA, headC, headB);
    int test;
   
}