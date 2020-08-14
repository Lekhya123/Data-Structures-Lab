#include<stdio.h>
typedef struct complex
{
	float real;
	float imag;
}complex;
complex addition(struct complex c1,struct complex c2)
{
	complex a;
	a.real = c1.real + c2.real;
	a.imag = c1.imag + c2.imag;
	return a;
}
complex subtraction(struct complex c1,struct complex c2)
{
	complex s;
	s.real = c1.real - c2.real;
	s.imag = c1.imag - c2.imag;
	return s;
}
complex multiplication(struct complex c1,struct complex c2)
{
	complex m;
	m.real = (c1.real * c2.real) - (c1.imag*c2.imag);
	m.imag = (c1.real * c2.imag) + (c1.imag*c2.real);
	return m;
}
int main(){
struct complex c1,c2,add,sub,mul;
scanf("%f%f%f%f",&c1.real,&c2.real,&c1.imag,&c2.imag);
add = addition(c1,c2);
printf("addition  = %f + %f\n",add.real,add.imag);
sub = subtraction(c1,c2);
printf("subtraction = %f + %f\n",sub.real,sub.imag);
mul = multiplication(c1,c2);
printf("multiplication = %f + %f\n",mul.real,mul.imag);

}
