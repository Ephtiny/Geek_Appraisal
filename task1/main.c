//对y'+y=0, y(0)=a
//用Euler法实现对此简单微分方程的各个瞬时值与最终定态
//y=a*e^(-x)
//令h=0.001
//y(n+1)=y(n)+h*f（x(n)，y(n)）=y(n)-h*y(n)

//最终定态（收敛值）指前后两个数的差的绝对值小于所给的定态误差*步长，那么这个值就是收敛值

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	double y,a,h,last;
	scanf_s("%lf", &a);
	//a=1;
	n = 0;
	y = a;
	h = 0.001;
	while (1) {
		printf("f(x%d*%lf)=%.15f\n", n, a, y);
		last = y;
		y = y - h*y;
		if (last > y) {
			if (last - y < 0.001*h) {
				break;
			}
		}
		else if (y - last < 0.001*h) {
			break;
		}
		n++;
	}

	printf("f(x%d*%lf)=%.15f\n", n, a, y);

	return 0;
}