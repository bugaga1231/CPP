struct List
{ int data;
  List *next;
};
typedef List *yzel;
yzel top=NULL;

void Circle(yzel &p)
{ int x;
  cin >> x;
  if(x)
   { p = new List;
     p->data=x;
     Circle(p->next);
   }
  else p =top;
  return;
}

void Vyv_C(yzel p)
{ if (p!=NULL)
  { cout << p->data << endl;
    if (p->next != top) Vyv_C(p->next);
  }
  return;
}

void main()
{ 
  yzel q=NULL,p=NULL;
  int k;
  Circle(top);
  cout << endl;
  Vyv_C(top);
  cout << endl;
  cout << "Which element should programm delete? It's  ";
  cin >> k;
  p=top;
  if (p==NULL) cout <<endl << "It's empty" << endl;
  else if (p->next==p) cout <<endl << "There is only one element: ";
  else while(p->next != p)
       { for(int i=1; i<k; i++)
	     { q=p;
           p=p->next;
         }
         if (p!=top) q->next=p->next;
	     else
	     { q->next=p->next;
           top = q->next;
	     }
         p=q->next;
       }
  
  Vyv_C(top);
  return;
}
