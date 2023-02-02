#include <iostream>
#include <cmath>
using namespace std;
int main() //ã^4+bx^2+c=0
{
    /*
    sjvisov
    sdjidof
    skopb
    */
    int a,b,c ;
    cin >> a >> b >> c ;
    cout << fixed ;
    cout.precision(5) ;
    double x= sqrt((double)-c/b) ;
    if ( a==0 && b==0 && c==0 ) cout << "phuong trinh co vo so nghiem" ;
    else if ( a==0 && b==0 &&c!=0 ) cout << "phuong trinh vo nghiem" ;
    else if (( a==0 && b!=0 && c==0 ) || ( a!=0 && b==0 && c==0 )) cout << "phuong trinh co 1 nghiem\n" << "0.00000" ;
    else if ( a==0 && b!=0 && c/b<0 ) cout << "phuong trinh co 2 nghiem\n" << -x << " " << x ;
    else if ( a!=0 && b==0 && c/a<0 ) cout << "phuong trinh co 2 nghiem\n" << -sqrt(sqrt((1.0*c/a))) << " " << sqrt(sqrt(1.0*c/a)) ;
    else if ( c==0 && b/a<0 ) cout << "phuong trinh co 3 nghiem\n" << -sqrt(-b/a*1.0) << " " << "0.00000" << " " << sqrt(-b/a*1.0) ;
    else if ( c==0 && b/a>0 ) cout << "phuong trinh co 1 nghiem\n" << "0.00000" ;
    else
    {
        float delta = pow(b,2) -4*a*c ;
        if (delta<0) cout << "phuong trinh vo nghiem" ;
        else if (delta==0) 
        {
            if ( b/a<0 ) cout << "phuong trinh co 2 nghiem\n" << -sqrt(-b/(2*a)*1.0) << " " << sqrt(-b/(2*a)*1.0) ;
            else cout << "phuong trinh vo nghiem" ;
        }
        else if (delta>0) 
        {
            if ((-b- sqrt(delta))/a>0) cout << "phuong trinh co 4 nghiem\n" << -sqrt(( -b+sqrt(delta) )/(2*a)) << " " << -sqrt(( -b-sqrt(delta))/(2*a)) << " "
                                                                            << sqrt((-b-sqrt(delta))/(2*a)) << " " << sqrt((-b+sqrt(delta))/(2*a)) ;
            else if ((-b-sqrt(delta))/a < 0 && (-b+sqrt(delta))/a > 0) cout << "phuong trinh co 2 nghiem\n" << -sqrt((-b+sqrt(delta))/(2*a)) << " " << sqrt((-b+sqrt(delta))/(2*a)) ;
            else cout << "phuong trinh vo nghiem" ;
        }
    }
    return 0;
}