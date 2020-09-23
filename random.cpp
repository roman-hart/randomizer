const int MAX_INT_NUMBER = 2147483647;
const double E = 2.7182818284;
const double PI = 3.14159265359;
const int m = 10000;
int a = 21; int c = 20; int d = 3;

double x1, x2, x;
std::vector<double> result;

double r() {
    return (double)rand()/RAND_MAX;
}

double linear(unsigned int prev) {
    prev=(a*prev+c)%m;
    return double(prev)/(m-1);
}

double square(unsigned int prev) {
    prev=(d*prev*prev+a*prev+c)%m;
    return double(prev)/(m-1);
}

double fibo(unsigned int prev) { // simplificated
    prev=((unsigned int)(prev*2.61803398875*2.618033989))%m;
    return double(prev)/(m-1);
}

double inverse(unsigned int prev) {
    if (prev == 0) prev=MAX_INT_NUMBER;
    for (int x1 = 0; x1 < m; x1++) {
		if ((prev*x1) % m == 1) prev = x1;
    } 
    prev = (a*prev+c)%m;
    return double(prev)/(m-1);
}

double combination(unsigned int prev) {
    return abs(linear(prev)+square(square(prev))-1);
}

double sigma(unsigned int prev) {
    return (r()+r()+r()+r()+r()+r()+r()+r()+r()+r()+r()+r())/12;
} 

double polar(unsigned int prev) {
    do{
        x1 = 2*r()-1;
        x2 = 2*r()-1;
        x = x1*x1+x2*x2;
    }while (x>=1.);
    x1=x1*sqrt(-2*log(x)/x);
    x2=x2*sqrt(-2*log(x)/x);
    return (x1+3.)/6.;
}

double fraction(unsigned int prev) {
    do {
        do {
            x1 = r();
            x2 = r();
        } while (x2 < 0.0001);
        x = sqrt(8 / E) * ((x1 - 0.5) / x2);
    } while ((x<-2.5 || x>2.5) || (x*x>(5-4*x2*pow(E, 0.25))) || (x*x>=((4*pow(E, -1.35)/x2)+1.4)) || (x*x>-4*log(x2)));
    return (x+2.5)/5;
}

double logarithm(unsigned int prev) {
    do {
        x = -1.5*log(r());
    } while (x > 12);
    return x/12;
}

double arens(unsigned int prev) {
    x1 = tan(PI*r());
    x2 = (sqrt(2*a-1)*x1+a-1);
    if (x2 <= 0) return arens(prev);
	if (r() > (1 + x1 * x1)*exp((a - 1)*log(x2 / (a - 1)) - sqrt(2 * a - 1)*x1) || x2<16) return arens(prev);
	return x2/16-1;
}