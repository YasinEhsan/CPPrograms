//Yasin Ehsan
// Rat class i.e. a class for rational numbers
//Learned: friend function implementation and plus operators
#include <iostream>
using namespace std;
class Rat{
  private:
     int n;
     int d;

  public:
   Rat(){
     n=0;
     d=1;
   }

   Rat(int i, int j){
     n = i;
     d = j;
   }

   Rat(int i){
     n=i;
     d=1;
   }

   int getN(){ return n;}
   int getD(){ return d;}
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}

   Rat operator+(Rat r){
     Rat t;
     t.n = n*r.d + d*r.n; //'this' makes it more clear to me. NOT WORKING
     t.d = d*r.d;
     return t;
   }

    Rat operator-(Rat r){
     Rat t;
     t.n = n*r.d - d*r.n;
     t.d = d*r.d;
     return t;
   }

   Rat operator*(Rat r){
     Rat t;
     t.n = n*(r.n);
     t.d = d*r.d;
     return t;
   }

   Rat operator/(Rat r){
     Rat t;
     t.n = n*(r.d);
     t.d = d*r.n;
     return t;
   }

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
   //end Rat
  };

  int gcd(int a, int b){ // a is greater and b is smaller...Though it doesnt matter
      if(b == 0)
        return a;
      return gcd(b, a%b);
  }

  ostream& operator<<(ostream& os, Rat r){
    if(r.n > r.d){
      if(r.n % r.d == 0)
        os << r.n / r.d << endl;//simplfies to integer
      else
        os<<r.n/r.d<< " " << r.n%r.d  << " / " << r.d <<endl;//creates mixed number
    }
    else
      os<< r.n / gcd(r.n, r.d) << " / " << r.d / gcd(r.n, r.d) <<endl; //reduces function
   return os;
  }

  istream& operator>>(istream& is, Rat& r){
   is>>r.n>>r.d;
   return is;
  }

  int main(){
   Rat x(1,2), y(2,3), z;
   z=x*y; // returns 2/6
   cout<<z; // returns 1/3 simplified

   x.setN(3);
   y.setD(2);

   z=x+y;
   cout<<z;

   printf("%s", "\nAyoo, enter a rat");

   cin>>x;
   cout<<x;
   Rat v(5);
   z = x+v;
   cout<<z;

   return 0;
}
