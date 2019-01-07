struct List
{ int data;
  List *next;
};
typedef List *yzel;
yzel top=NULL;

void Ocher(yzel &p)
{ int x;
  cin >> x;
  if(x)
  { p = new List;
    p->data=x;
    p->next=NULL;
    Ocher(p->next);
  }
  return;
}

void Print(yzel p)
{ while(p)
  { cout << p->data<<endl;
    p=p->next;
  }
  return;
}

void DeleteN(yzel &p)
{ yzel z=p;
  while(z->next!=NULL)
  { if ( z->next->data < 0) z->next=z->next->next;
    else z=z->next;
  }
  if (p->data<0) p=p->next;
  return;
}

void main()
{ yzel t=NULL;
  Ocher(t);
  Print(t);
  cout << endl << endl;
  DeleteN(t);
  if (t) Print(t);
  else cout << "it's empty"<< endl; 
  return;
}
