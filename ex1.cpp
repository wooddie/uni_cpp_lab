#include <iostream>
#include<cmath>
using namespace std;

int cat = 0;
int dog = 0;

vector<int> humanYearsCatYearsDogYears(int humanYears) {
    cat = 0;
    dog = 0;
    
    if(humanYears == 1) {
        cat += 15;
        dog += 15;
    }
    else if(humanYears == 2) {
        cat += 24;
        dog += 24;
    }
    else if (humanYears > 2) {
        cat += 24;
        dog += 24;
        for (int i = 3; i <= humanYears; i++) {
            cat += 4;
            dog += 5;
        }
    }

    return {humanYears, cat, dog};
}

int main() {

   vector<int> res = humanYearsCatYearsDogYears(1);

   cout << "H" << res[0] << " C" << res[1] << " D" << res[2] << endl;
   
   res = humanYearsCatYearsDogYears(2);

   cout << "H" << res[0] << " C" << res[1] << " D" << res[2] << endl;
   
   res = humanYearsCatYearsDogYears(10);

   cout << "H" << res[0] << " C" << res[1] << " D" << res[2] << endl;

    return 0;
}