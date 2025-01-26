//2020-21




//8(a)


/*
#include<iostream>
#include<cmath>
using namespace std;
class Polar
{
    double r;
    double theta;
public:
    Polar():r(0.0),theta(0.0){}
    Polar(double r,double theta)
    {
        this->r=r;
        this->theta=theta;
    }
    Polar(const Polar &P)
    {
        r=P.r;
        theta=P.theta;
    }
    double getr(){return r;}
    double gettheta(){return theta;}
    void setr(double R){r=R;}
    void settheta(double THETA){theta=THETA;}
    int operator==(Polar P)
    {
        return((r==P.r)&&(theta==P.theta));
    }
    Polar& operator=(const Polar &P)
    {
        if(this!=P)
        {
            r=P.r;
            theta=P.theta;
        }
        return *this;
    }
    double dotProduct(Polar p1,Polar p2)
    {
        return ((p1.r)*(p2.r)*cos((p1.theta)-(p2.theta)));
    }
    Polar operator*(Polar p1)
    {
        Polar pr;
        pr.r=r*(p1.r);
        pr.theta=theta+(p1.theta);
        return pr;
    }
    Polar operator/(Polar p1)
    {
        Polar pr;
        pr.r=r/(p1.r);
        pr.theta=theta-(p1.theta);
        return pr;
    }
};
*/



//8(c)


//Here either using namespace std; or std::cin, std::cout and std::endl must be used.
/*
#include<iostream>
int main()
{
    int i,j;
    std::cin>>i>>j;
    i++;++j;
    std::cout<<i<<" "<<j<<std::endl;
    return 0;
}
*/
