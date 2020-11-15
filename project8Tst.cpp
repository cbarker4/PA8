#include <iostream>
using namespace std;

#include "project8.h"


int main()
{
 List2 <int>* lst = new List2 <int>;
 
 for (int i = 1; i <= 10; i++)
  lst->Insert(i,i);

 lst->PrintForward();
 cout << endl;
 List2<int>* lst1 = new List2<int>(lst);

 lst->PrintBackwards();
 cout << endl;
 lst->Delete(10);
 lst->Delete(5);
 lst->Delete(1);
 lst->PrintForward();
 cout <<"values deleted"<<lst->DeleteAll(1)<<endl;
 cout << endl<<endl;
 lst->PrintForward();

 return 0;
}
