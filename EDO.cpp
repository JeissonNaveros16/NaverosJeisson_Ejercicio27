#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

float expliEuler(float *y, float wdt);
float impliScheme(float *y, float wdt);
void writefile(string filename, float *t, float *yy, int n_points);

int main()
{
    float W = 0.1;
    float wDeltaT1 = 0.1;
    float wDeltaT2 = 0.01;
    float wDeltaT3 = 1;
    
    float step1 = wDeltaT1/W;
    float step2 = wDeltaT2/W;
    float step3 = wDeltaT3/W;
    
    int n1 = 4/step1;
    int n2 = 4/step2;
    int n3 = 4/step3;
    
    float *t1 = NULL;
    t1 = new float[n1];
    float *p1 = t1;
    
    float *t2 = NULL;
    t2 = new float[n2];
    float *p2 = t2;
    
    float *t3 = NULL;
    t3 = new float[n3];
    float *p3 = t3;
    
    // Con el método explícito
    float *ye1 = NULL;
    ye1 = new float[n1];
    float *q1 = ye1;
    
    float *ye2 = NULL;
    ye2 = new float[n2];
    float *q2 = ye2;
    
    float *ye3 = NULL;
    ye3 = new float[n3];
    float *q3 = ye3;
    
    // con el método implícito
    float *yi1 = NULL;
    yi1 = new float[n1];
    float *r1 = yi1;
    
    float *yi2 = NULL;
    yi2 = new float[n2];
    float *r2 = yi2;
    
    float *yi3 = NULL;
    yi3 = new float[n3];
    float *r3 = yi3;
    
    // Condiciones iniciales
    *p1 = 0.0;
    *p2 = 0.0;
    *p3 = 0.0;
    
    *q1 = 1.0;
    *q2 = 1.0;
    *q3 = 1.0;
    
    *r1 = 1.0;
    *r2 = 1.0;
    *r3 = 1.0;
    
    for(int i = 1; i<n1; i++)
    {
        *(p1+i) = i*step1;
        *(q1+i) = expliEuler( q1+i-1, wDeltaT1 );
        *(r1+i) = impliScheme( r1+i-1, wDeltaT1 );
    }
    writefile("valoresEuler1.dat", p1, q1, n1);
    writefile("valoresImplic1.dat", p1, r1, n1);
    
    for(int i = 1; i<n2; i++)
    {
        *(p2+i) = i*step2;
        *(q2+i) = expliEuler( q2+i-1, wDeltaT2 );
        *(r2+i) = impliScheme( r2+i-1, wDeltaT2 );
    }
    writefile("valoresEuler2.dat", p2, q2, n2);
    writefile("valoresImplic2.dat", p2, r2, n2);
    
    for(int i = 1; i<n3; i++)
    {
        *(p3+i) = i*step3;
        *(q3+i) = expliEuler( q3+i-1, wDeltaT3 );
        *(r3+i) = impliScheme( r3+i-1, wDeltaT3 );
    }
    writefile("valoresEuler3.dat", p3, q3, n3);
    writefile("valoresImplic3.dat", p3, r3, n3);
	
	delete[] t1;
	delete[] t2;
	delete[] t3;
	
	delete[] ye1;
	delete[] ye2;
	delete[] ye3;
	
	delete[] yi1;
	delete[] yi2;
	delete[] yi3;
    
    return 0;
}

float expliEuler(float *y, float wdt)
{
    return (*y)*(1 - wdt);
}

float impliScheme(float *y, float wdt)
{
    return (*y)/(1 + wdt);
}

void writefile(string filename, float *t, float *yy, int n_points)
{
    // Aquí se abre el archivo con el nombre dado por parámetro
    ofstream outfile;
    outfile.open(filename);
    
    // Luego se va imprimiendo en este los valores
    for (int j=0; j < n_points; j++)
    {
		outfile << *(t+j);
		outfile << "  ";
		outfile << *(yy + j) << endl;
    }
    
    outfile.close();
}