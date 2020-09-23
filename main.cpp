#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include "random.cpp"
using namespace std;

int generate_num = 1000;
int numbers_to_show = 10;
int freq_step_num = 10;
float freq_step = (float)1 / freq_step_num;

string methods[10] = { "Linear", "Square", "Fibbo", "Inverse", "United", "3-sigma", "Polar coordinates", "Fraction", "Logarithm", "Arens'" };
double (*methods_ptrs[])(unsigned int) = {linear, square, fibo, inverse, combination, sigma, polar, fraction, logarithm, arens};

void show_options() {
    cout << "Here are all available methods to generate a sequence:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "\t" << i + 1 << " -> " << methods[i] << endl;
	}
}

int get_method_number() {
    int n;
    cout << "Choose a method:";
    cin >> n;
    if ( 0 < n && n < 11 ) {
        return n-1;
    }
    throw invalid_argument("received inappropriate value");
}

void show_result(vector<double> &result) {
    int size = result.size();
    int freq[freq_step_num];
    for (int i=0; i<freq_step_num; i++) freq[i] = 0;  
    
    string s = "First " + std::to_string(numbers_to_show) + " numbers: ";
    for (int i=0; i<numbers_to_show; i++) s += std::to_string(result[i]) + ", ";
    cout << s << " ..." << endl;
    
    for (int i=0; i<size; i++)  
    {
        freq[int(result.back() / freq_step)] += 1;
        result.pop_back();
    } 
    
    float a, b, freq_perc;
    for (int i=0; i<freq_step_num; i++)  
    {
        a = i * freq_step; 
        b = a + freq_step;
        freq_perc = (float)freq[i] / generate_num * 100;
        std::string xs(freq_perc*3, 'X');
        cout << fixed; 
        cout.precision(1);
        cout << "[" << a << ", " << b << "): " << setw(6) << freq_perc << " " << xs << endl;
    } 
}

int main() {
    int t = time(nullptr);
    srand(t);
    double seed = (double)(t%m)/m;
    
    show_options();
    unsigned int n = get_method_number();
    
    cout << endl << methods[n] << " method" << endl;
    for (int i=0; i<generate_num; i++)  
    {
        seed = (*methods_ptrs[n])(seed*m);
        result.push_back(seed);
    }
    show_result(result);
    return 0;
}
