/*
ID: littlef6
TASK: friday
LANG: C++
*/

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin ("friday.in");
    ofstream fout ("friday.out");

    int n, day[7], index = 0, month[12];
    for(int i = 0; i < 7; i++){
        day[i] = 0;
    }
    month[0] = 31;
    month[1] = 28;
    month[2] = 31;
    month[3] = 30;
    month[4] = 31;
    month[5] = 30;
    month[6] = 31;
    month[7] = 31;
    month[8] = 30;
    month[9] = 31;
    month[10] = 30;
    month[11] = 31;
    fin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++){
            day[index]++;
            if(((i % 4 == 0 && i % 100 != 0) || (i % 100 == 0 && (i + 300) % 400 == 0)) && j == 1){
                index = (index + ((month[j] + 1) % 7)) % 7;
            } else {
                index = (index + (month[j] % 7)) % 7;
            }
        }
    }

    for(int i = 0; i < 7; i++){
        fout << day[i];
        if(i != 6){
            fout << " ";
        }
    }
    fout << "\n";
    return 0;
}
