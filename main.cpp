#include <iostream>
using namespace std;
class Distance {
   private:
      int feet;
      int inches;
   public:
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
    void displayDistance() {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      bool operator >(Distance& d) {
          int q;
          int r;
          if(inches>=12 ){
            q=inches/12;
            r=inches%12;
            feet=feet +q;
            inches=r;
          }
    if(d.inches>=12 || d.inches >=12){
            q=d.inches/12;
            r=d.inches%12;
            d.feet=d.feet +q;
            d.inches=r;
          }



         if(feet > d.feet) {
            return true;
         }
         else if(feet == d.feet && inches > d.inches) {
            return true;
        }
         return false;
      }
};
int main() {
   Distance D1(10, 11), D2(9, 377);
   D1.displayDistance();
   D2.displayDistance();
   if( D1 > D2 ) {
      cout << "D1 is greater than D2 " << endl;
      D1.displayDistance();
   D2.displayDistance();

   } else {
      cout << "D2 is greater than D1 " << endl;
      D1.displayDistance();
   D2.displayDistance();
   }
   return 0;
}
