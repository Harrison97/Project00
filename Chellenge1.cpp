#include <iostream>
#include <cmath>
using namespace std;

/*
	Name: Challenge 1
	Author: Harrison Hayes
	Date: 29/01/16 12:45
	Description: Find s max combined area of perimeter <= p of all possible triangles (or something like that, it's hard to explain..)
*/

int findTotalArea(int p) {

		int x = 1;
		int y = 1;
		double z;
		int area = -1;
		int total = 0;

		cout << "Perimeter : " << p << endl;

		do{

			do{
				z = sqrt(pow(x,2) + pow(y,2));

				if((x+y+z == p) && ((x*y)/2 > area)) {

					area = (x*y)/2;
					cout << "{" << x << "," << y << "," << z << "}" << "  Area : " << area << endl;
					total += area;
				}

				y++;

			}while(x+y+z <= p);

			x++;
			y=1;
			z=1;

		}while(x+y+z <= p);

		do{
			z = sqrt(pow(x,2) + pow(y,2));
			y++;

		}while(x+y+z <= p);

		return total;
	}

	int main() {
						//2345
		int perimeter = 2345;
		int total;
		int maxTotal = -1;
		int maxPerimeter = -1;

		for(int p=1; p <= perimeter; p++) {
			total = findTotalArea(p);

			if(total != 0){
				cout << "Total Area : " << total << endl;
				cout << endl << endl << endl;
			}
			if(total > maxTotal) {
				maxTotal = total;
				maxPerimeter = p;
			}
		}
		
		cout << "Max Total : " << maxTotal << " @ Perimeter : " << maxPerimeter << endl;

		return 0;
}


