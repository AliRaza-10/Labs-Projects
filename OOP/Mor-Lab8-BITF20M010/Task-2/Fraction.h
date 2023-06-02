#ifndef "FRACTION_H"
#define " FRACTION_H"
class Fraction
{
private:
 	 int num , den;
public:
   Fraction(int,int);  
   Fraction();
   double convertToDouble();
   void setFraction(int a , int b);
   	void display()const;
   	Fraction operator+ (Fraction );
   	Fraction operator+ (int)const;
   	friend Fraction operator+ (int, const Fraction& );
   	
};
#endif