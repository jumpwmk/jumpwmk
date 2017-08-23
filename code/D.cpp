#include <stdio.h>

// using namespace std;

/*input
0 0 0
2
0 1 0 1 1 0
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
struct vec{
	double x,y,z;
};
double abso(vec a){
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
double dot(vec a,vec b){
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}
int main()
{
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	int l,type;
	double x,y,z;
	cin >> x >> y >>z;
	cin >> type;
	if (type == 1){
		double x2,y2,z2;
		cin >> x2 >> y2 >> z2;
		printf("%lf %lf %lf",2*(x2-x)+x,2*(y2-y)+y,2*(z2-z)+z);
	}
	if (type == 2){
		vec v1,v2,m,temp,a,bp,last_vec;
		double size_a,dots;
		cin >> v1.x >> v1.y >> v1.z >> v2.x >> v2.y >> v2.z;
		a.x = v2.x-v1.x;
		a.y = v2.y-v1.y;
		a.z = v2.z-v1.z;
		bp.x = x-v2.x;
		bp.y = y-v2.y;
		bp.z = z-v2.z;
		size_a = abso(a);
		size_a *= size_a;
		dots = dot(bp,a);
		a.x *= (dots/size_a);
		a.y *= (dots/size_a);
		a.z *= (dots/size_a);
		m.x = v2.x+a.x;
		m.y = v2.y+a.y;
		m.z = v2.z+a.z;
		last_vec.x = 2*(m.x-x);
		last_vec.y = 2*(m.y-y);
		last_vec.z = 2*(m.z-z);
		printf("%lf %lf %lf",last_vec.x+x,last_vec.y+y,last_vec.z+z);
	}
	if(type == 3){
		double a,b,c,d;
		cin >> a >> b >> c >> d;
		double t = (d - a*x - b*y - c*z) / (a*a + b*b + c*c);
		double x1 = a * t + x;
		double y1 = b * t + y;
		double z1 = c * t + z;
		printf("%lf %lf %lf",2*(x1-x)+x,2*(y1-y)+y,2*(z1-z)+z);
	}
}