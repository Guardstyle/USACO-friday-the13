#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin ("friday.in");
    ofstream fout ("friday.out");

    int n, day[7], index = 0;
    int month[] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    for(int i = 0; i < 7; i++){
        day[i] = 0;
    }
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
