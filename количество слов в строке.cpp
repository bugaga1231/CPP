void main()
{ string S;
  int k=0;
  getline(cin, S);
  int i=0;
  if (S.size() !=0)
  { for(int i=0; i< S.size(); i++) if ((S[i]!=' ') && (S[i+1]==' ')) k++;
    if (S[S.size()-1] !=' ') k++;
  }
  cout << k << endl; 
  return;
}
