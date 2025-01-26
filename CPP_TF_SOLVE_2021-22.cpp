//2021-22


//11(a)
/*
#include <stdio.h>
#include <string.h>
int main()
{
   FILE *fp=fopen("C:\\Users\\Della\\Documents\\pollution.txt","r+"); // r+ for reading and writing to the file, need to use \\ for file path
   if (fp==NULL)
   {
   printf("Error opening file");
   return 1;
   }
   fseek(fp,16,SEEK_SET);
   fwrite("crucial",1,strlen("crucial"),fp);
   fclose(fp);
   return 0;
}
*/




//11(b)


/*
#include<iostream>
using namespace std;
class C
{
public:
    static string x;
    int y;
    void printVars()
    {
        cout<<x<<" "<<y<<endl;
    }
};
string C::x="something";
int main()
{
    C o1,o2;
    o1.y=5;
    o2=o1;
    o1.printVars();
    o2.printVars();
    o2.y=10;
    o2.x="something else";
    o1.printVars();
    o2.printVars();
    return 0;
}
*/
// i) The problem with printVars() is due to the incorrect access of static members. The function is declared as static and can only use static objects. Though x is static, y isn't. So it fails to work.
// ii) To fix the problem we just need to remove the 'static' keyword from the function.
// iii)The program will output something 5 something 5 something else 5 something else 10. As x is a static member, its value will be the same for any member of its parent class.




//12(a)



/*
Public members: These can be used throughout the program in any function, class.
Private members: These can only be accessed by the class it is a member of and needs seperate public methods (getter,setter functions) to be accessible to others
Protected members: These can be accessed by the class and its derived classes. It is more protective than public, but less than private
*/


//12(b)


/*
#include <iostream>
using namespace std;
class C
{
private:
    int *x;
public:
    void Print()
    {
        cout<< *x<<endl;
    }
    C f(C o)
    {
        *o.x=10;
        return o;
    }
};
int main()
{
    C o1(5);
    C o2=o1;
    o1.f(o2).Print();
    o1.Print();
    o2.Print();
    return 0;
}
*/


//i) The program with constructor is as follows:
/*
#include <iostream>
using namespace std;
class C
{
private:
    int *x;
public:
    C(int a)
    {
        x=new int;
        *x=a;
    }
    void Print()
    {
        cout<< *x<<endl;
    }
    C f(C o)
    {
        *o.x=10;
        return o;
    }
};
int main()
{
    C o1(5);
    C o2=o1;
    o1.f(o2).Print();
    o1.Print();
    o2.Print();
    return 0;
}
*/


// ii)The output will be 10 10 10


// iii) The code with destructor is given below


/*
#include <iostream>
using namespace std;
class C
{
private:
    int *x;
public:
    C(int a)
    {
        x=new int;
        *x=a;
    }
    ~C()
    {
        delete x;
    }
    void Print()
    {
        cout<< *x<<endl;
    }
    C f(C o)
    {
        *o.x=10;
        return o;
    }
};
int main()
{
    C o1(5);
    C o2=o1;
    o1.f(o2).Print();
    o1.Print();
    o2.Print();
    return 0;
}
*/



/* iv) The code will not work properly due to the destructor.
This is because due to the pointer *x, memory is shared between o1 and o2.
So when we declare o1 with parameterized constructor and assign o2 to o1, o2
uses the default constructor and a shallow copy is created. When o1.f(o2).Print()
is called, *x of a copy of o2 becomes 10 and is printed under the object o1.
But as *x is shared across o1,o2 and the copy of o2 which was passed as argument
its value for o1 and o2 also become 10.
To fix this, we add a copy constructor and pass the argument to C f(C o) by address, not value
*/

/*
#include <iostream>
using namespace std;
class C
{
private:
    int *x;
public:
    C(int a)
    {
        x=new int;
        *x=a;
    }
    C(C &o) //Added copy constructor
    {
        x=new int;
        *x=*(o.x);
    }
    ~C()
    {
        delete x;
    }
    void Print()
    {
        cout<< *x<<endl;
    }
    C f(C &o) //Added & before o
    {
        *o.x=10;
        return o;
    }
};
int main()
{
    C o1(5);
    C o2=o1;
    o1.f(o2).Print();
    o1.Print();
    o2.Print();
    return 0;
}
*/


//12(c)

/*
#include<iostream>
using namespace std;
class Person
{
private:
    int age;
public:
    Person (int age)
    {
        this->age=age;
    }
    void printAge()
    {
        cout<<age<<endl;
    }
    Person operator++(int)
    {
        Person pt=*this;
        this->age+=1;
        return pt;
    }
    int operator>(Person p)
    {
        if(age>p.age)
            return 1;
            else return 0;
    }
};
int main()
{
    Person p1(15);
    Person p2=p1;
    (p2++).printAge();
    p2.printAge();
    if(p2>p1)
        cout<<"p2 is older"<<endl;
    else if(p1>p2)
        cout<<"p1 is older"<<endl;
    else
        cout<<"They are of equal age"<<endl;
    return 0;
}
*/


//13(a)
/*Virtual Destructors should be used when pointers to derived classes are used.
If pointers to derived classes are used without virtual destructors, destructor in
the derived class will not be called, rather only the base class' destructor wiill be called
So, to ensure proper memory management of the derived objects, virtual destructor
should be used
*/


//13(b)

/*
#include<iostream>
using namespace std;
class A
{
public:
    A(){cout<<"Constructor of class A"<<endl;}
    void f1(){cout<<"A's f1"<<endl;}
    virtual void f2(){cout<<"A's f2"<<endl;}
    ~A(){cout<<"Destructor of class A"<<endl;}
};
class B:public A
{
public:
    B(){cout<<"Constructor of class B"<<endl;}
    virtual void f1(){cout<<"B's f1"<<endl;}
    virtual void f2(){cout<<"B's f2"<<endl;}
    ~B(){cout<<"Destructor of class B"<<endl;}
};
void fval(A a)
{
    a.f1();
    a.f2();
}
void fref(A &a)
{
    a.f1();
    a.f2();
}
void fptr(A *a)
{
    a->f1();
    a->f2();
}
int main()
{
    A *a1,*a2;
    a1=new A();
    a2=new B();
    a1->f1();a1->f2();
    a2->f1();a2->f2();
    fval(*a1);fref(*a1);fptr(a1); //Passing by value(*) creates a local copy which is then destroyed
    fval(*a2);fref(*a2);fptr(a2); //Passing by value(*) creates a local copy which is then destroyed
    delete a1;delete a2; //As virtual destructors aren't used, only destructor of A will appear
    return 0;
}
*/



//13(c)


/*
#include<iostream>
using namespace std;
class Equilateral
{
protected:
    int side;
public:
    virtual double getArea()=0; //This makes the class abstract
    Equilateral(int a):side(a){};
};
class Square:public Equilateral
{
public:
    Square(int side):Equilateral(side){};
    double getArea() override //pure virtual functions must be overriden
    {
        return side*side;
    }
};
class Triangle:public Equilateral
{
public:
    Triangle(int side):Equilateral(side){};
    double getArea() override
    {
        return (3.0/4)*side*side;
    }
};
int main()
{
    Equilateral *e1,*e2;
    e1=new Square(3);
    e2=new Triangle(5);
    cout<<e1->getArea()<<endl;
    cout<<e2->getArea()<<endl;
    delete e1;
    delete e2;
    return 0;
}
*/
