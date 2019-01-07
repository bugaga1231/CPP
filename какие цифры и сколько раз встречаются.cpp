void main()
{ const int N=10;
  char stroka[N]={};
  int Kolvo[10]= {0};
  
 for (int i=0; i<N; i++) cin >> stroka[i];
  
  for (int i=0; i<N; i++) 
   if ( (stroka[i] >='0') && (stroka[i]<= '9') )
     Kolvo[stroka[i] -'0' ]++; //увеличиваем кол-во конкретного числа
 
  for (int i=0;i<10; i++)
   if  (Kolvo[i]!=0) cout << i << " is there " << Kolvo[i] << " times. " << endl;
  return;
}
