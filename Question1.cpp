#include <iostream>

using namespace std;

float silver = 0.05;
float gold = 0.1;
float platinum = 0.15;

float CalcDiscount(float totalBill, float discountPercentage)
{
    return totalBill * discountPercentage;
}

float CalcDiscount(float totalBill, float discountPercentage, float specialDiscount)
{
    return (totalBill * discountPercentage) + (totalBill * specialDiscount);
}

int main()
{
    float discount = 0;
   cout << "Please enter the total bill amount..." << endl;
   float totalBill = 100.25;
   cout << totalBill << endl;
   cout << "Please enter the membership status..." << endl;
   char status = 'P';
   cout << status << endl;
   float discountPercentage = 0;
   switch (status)
   {
       case 'G':
       {
           discountPercentage = gold;
           break;
       }
       case 'P':
       {
           discountPercentage = platinum;
           break;
       }
       default:
       {
           discountPercentage = silver;
       }
   }
   
   cout << "Is today a Thursday? Enter 'Y' for yes and 'N' for no..." << endl;
   bool isThursday = true;
   if (isThursday)
   {
        cout << "Please enter today's special discount..." << endl;
        float specialDiscount = 0.175;
        cout << "Special discount: " << specialDiscount << endl;
        discount = CalcDiscount(totalBill, discountPercentage, specialDiscount);
   } else {
       discount = CalcDiscount(totalBill, discountPercentage);
   }
   
   float amountDue = totalBill - discount;
   cout << "The discount for bill amount " << totalBill << " is " << discount << endl;
   cout << "Amount due is: " << amountDue << endl;
   cout << "***END OF PROGRAM***" << endl;
   return 0;
}