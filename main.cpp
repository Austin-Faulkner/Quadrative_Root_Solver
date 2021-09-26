/****************************************************************
Austin Faulkner
faulkner.austin@utexas.edu
akf354

Solve ax^2 + bx + c = 0 for real, complex, and repeated roots.
****************************************************************/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

enum status {COMPLEX, REPEATED, REAL, ERROR};

status quadraticFormula(double a, double b, double c, double& r1, double& r2) {

    double discriminant = b * b - 4 * a * c;
    const double eps = 1e-20;

    if ((fabs(a) < eps)) {
        return ERROR;
    }

    if (discriminant < 0)
    {
        cout << "\t\tRoots are complex: "
             << - b / (2 * a) << " + i * " << sqrt(abs(discriminant)) / (2 * a)
             << " and "
             << - b / (2 * a) << " - i * " << sqrt(abs(discriminant)) / (2 * a)
             << "\n\n";
        return COMPLEX;
    }
    else if (discriminant == 0)
    {
        cout << "\t\tRepeated Roots: " << - b / (2 * a)
             << " and " << - b / (2 * a) << "\n\n";
        return REPEATED;
    }
    else
    {
        if(b < 0) {
            // multiply through by -1, so now b>=0
            a = -a; b = -b; c = -c;
        }

        r1 = -(b + sqrt(discriminant)) / (2 * a);
        r2 = -2 * c / (b + sqrt(discriminant));

        cout << "\t\tReal roots: " << r1 << " and " << r2
             << endl << endl;
        return REAL;
    }
}

int main() {

  double a, b, c, r1, r2;
  char response;

  cout << "\n\n\t\t\t\t\t\t\tQUADRATIC ROOT SOLVER\n"
       << "\t\t----------------------------------------------------------"
       << "---\n";

  do {
      cout << "\t\tSolve ax^2 + bx + c = 0 for real, complex, or repeated "
           << "roots.\n"
           << "\t\tEnter a, b, c: ";
      cin >> a >> b >> c;

      status s = quadraticFormula(a, b, c, r1, r2);

      switch(s)
      {
          case COMPLEX:
              break;
          case REPEATED:
              break;
          case REAL:
              break;
          case ERROR:
              cout << "\n\t\tERROR: Leading coefficient a = 0" << endl;
              break;
      }

      cout << "\t\tWould you like to play again (y/n)? ";
      cin >> response;
      cout << "\n";

  } while(toupper(response) == 'Y');

  return EXIT_SUCCESS;
}
