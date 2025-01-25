//2022-23
/*


1(a)



A function can be overloaded in the following two ways: 1.Number of parameters are different
                                                        2.Sequence of parameters are different
Example:
1. double Area(int radius) //Area of circle
     {
         return 3.14*radius;
     }
     double Area(int length,int width) //Area of rectangle
     {
         return length*width;
     }
2. double Volume(int radius,double height) //Volume of a cone
           {
               return (1/3)*3.14*radius*radius*height;
           }
    double Volume(double height,int radius) //Volume of a cylinder
           {
               return 3.14*radius*radius*height;
           }
*/




//1(b)




/*

#include<iostream>
using namespace std;
class Account
{
    int accNo; double balance;
public:
    Account()
    {
        cout<<"In the default constructor.\n";
        accNo=-1;balance=0;
    }
    Account(int a,double b)
    {
        cout<<"In the parameterized constructor of "<<a<<endl;
        accNo=a;balance=b;
    }
    ~Account()
    {
        cout<<"In the destructor of "<<accNo<<endl; //Destructors are called in reverse order
    }
    Account transferFrom(Account a, double b)
    {
        balance=balance+b;
        a.balance=a.balance-b;
        return a;
    }
    void print()
    {
        cout<<"Acc No: "<<accNo<<", Balance: "<<balance<<endl;
    }
};

int main()
{
    Account a[2]={Account(1,1000),Account(2,2000)}; //Parameterized constructor is called
    for(int i=0;i<2;i++)
    {
        a[i].print();
    }
    a[0]=a[1].transferFrom(a[0],500);
    //This deducts 500 from acc 1, and adds 500 to acc 2.
    //Due to this line, 2 temporary copies of a[0] are destroyed, one for the passed parameter, and one for the a[0] declared previously by Account(1,1000). But no constructor call occurs here as there is parameterized constructor but no parameterized destructor
    for(int i=0;i<2;i++)
    {
        a[i].print();
    }
}

*/




//1(c)




/*

#include<iostream>
using namespace std;

class Shape
{
    int length,width;
public:
    Shape(int length,int width) //Parameterized constructor for Shape
    {
        this->length=length;
        this->width=width;
    }
    virtual int perimeter(){return -1;} //Virtual functions so that they can me overriden later
    virtual int area(){return -1;}
    int getLength(){return length;}
    int getWidth(){return width;}
    void setWidth(int width){this->width=width;} //This is needed for the rectangle
};
class Line:public Shape
{
public:
    Line(int length):Shape(length,0){}; //Line constructor derived from Shape
    int area() override {return 0;} //0 According to output
};
class Rectangle:public Line
{
public:
    Rectangle(int length,int width):Line(length)
    {
        setWidth(width); //Length was initialized earlier;
    }
    int area () override
    {
        return getLength()*getWidth();
    }
    int perimeter() override
    {
        return 2*(getLength()+getWidth());
    }
};
int main()
{
    Line l(5);
    cout<<l.area()<<endl;
    cout<<l.perimeter()<<endl;

    Rectangle r(5,2);
    cout<<r.area()<<endl;
    cout<<r.perimeter()<<endl;
}

*/





//4(a)




/*
i)The size of a Union is determined by the size of the highest memory occupying data type in the union
Example:
union Shape
{
    int radius;
    float length;
    double height;
    long double volume;
};
Here, the size of the union will be that of a long double
ii) Base type of a pointer is essential to indicate what type of data is being pointed to, dereferencing it properly and for pointer arithmetic
Example:
int a=10;
int *p=&a;
Here, the base type indicates that p will be an integer. Also, if we use p+1, it will shift by 4 bytes. It would have shifted by 1 byte if the pointer was a character
*/




//4(b)




/*
#include <iostream>
using namespace std;
class Complex
{
    float real;
    float imag;
public:
    Complex(float r,float i)
    {
        real=r;imag=i;
    }
    Complex operator+(Complex C1) //Syntax for overloading + operator/defining + operator for complex numbers and return a complex number
    {
        Complex result(0,0);
        result.real=real+C1.real;
        result.imag=imag+C1.imag;
        return result;
    }
    void printComplex()
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
};
int main()
{
    Complex complex1(4,5), complex2(6,7), result(0,0);
    result=complex1+complex2;
    result.printComplex();
}
*/




//4(c)



#include<iostream>
using namespace std;
class base
{
public:
    base()
    {
        cout<<"Inside base constructor"<<endl;
    }
    void show()
    {
        cout<<"base\n";
    }
};
class derived1:public base
{
public:
    derived1()
    {
        cout<<"Inside derived1 constructor"<<endl;
    }
    void show()
    {
        cout<<"derived-1\n";
    }
};
int main()
{
    base *pb1,*pb2;
    base b1;derived1 d1;
    pb1=&b1;pb2=&d1;
    pb1->show(); pb2->show();
}
