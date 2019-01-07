int Sim(char *p,int n)
{ for(int i=0; i<n/2; i++)
   if (p[i]!=p[n-i-1]) return 0;
  return 1;
}

 
void main()
{ char **a;
  int *m,i,j,n,k=0;
 
  cout << "n="; 
  cin >> n;
  a = new char*[n];
  m = new int[n];   // массив размерностей строк
  
  cout << endl;
  for(i=0; i<n;i++)
  { cout <<"-----------------------"<<endl;
    cin >> m[i];
    a[i]= new char[ m[i]];
    for (j=0; j<m[i];j++) cin >> a[i][j];
  }
  cout << endl;
 
  for (i=0;i<n;i++)
  { for (j=0;j<m[i];j++) cout<<a[i][j];
    cout<<endl;
  }
  cout<< endl;
 
  for (i=0; i<n; i++)
    if ( Sim(&a[i][0],m[i]) == 1)  k++;
  cout << "kolvo simm = " << k << endl;
  return;
}
