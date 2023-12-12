#include<iostream>
#include<string>
int t,k,k2;
using namespace std;
int isprime(int n)
{
   int i,c=0;
   for(i=1;i<=n/2;i++)
   {
    if(n%i==0)
     c++;
   }
   if(c==1) return 1;
   else return 0;
}
int step()
 {
  while(1) {
  if(isprime(k))
  {
   int temp=k-t;
   t=k;k++;
   return temp;
   }
  else
  k++;
  }
 }
void encode(string s)
{
 int a;
 for(int i=0;i<s.size();i++)
 { 
   a=step();
   s[i]=((s[i]-32+a)%94+32);
 }
 cout<<"ENCODED Message With Key "<<k2<<" Is:\n";
 cout<<s;
}
void decode(string s)
{
 int a;
 for(int i=0;i<s.size();i++)
 {
  a=step();
  a=a%94;
  if(a<=s[i]-32)
   s[i]=((s[i]-32-a)%94+32);
  else
   s[i]=((s[i]-32+94-a)%94+32);
 }
cout<<"DECODED Message With Key "<<k2<<" Is:\n";
 cout<<s;
}
int main()
{
 string s;
 cout<<"\"Enter Message\"\n--> ";
 getline(cin,s);
cout<<"\"Enter Key(large value for better encryption):\"\n--> ";
 cin>>k;
 k2=k;
 t=k;
 
 int ch;
 cout<<"ENTER \'1\' TO ENCODE"<<endl;
 cout<<"ENTER \'2\' TO DECODE\n--> ";
 cin>>ch;
 switch(ch)
 {
  case 1: encode(s);
          break;
  case 2: decode(s);
          break;
  default: break;
 }
}