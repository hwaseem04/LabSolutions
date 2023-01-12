/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

# define match 3
# define o -2
# define e -1

# define Left 1
# define diag 2
# define up 3


int main()
{
    string s1 = " aaccttggttcc";
    string s2 = " aaccttggtaac";

    int m = s1.length();
    int n = s2.length();

    int matrix[m+1][n+1];
    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i < m+1; i++){
        for (int j = 1; j < n+1; j++){
            if (s1[i-1] == s2[j-1]){
                matrix[i][j] = matrix[i-1][j-1] + match; 
            }
            else{
                int Max = max(matrix[i-1][j] + o, matrix[i-1][j-1] + o);
                Max = max(Max, matrix[i][j-1] + o);
                matrix[i][j] = Max;
            }
        }
    }

    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    int arr[10];
    for (int i = 0; i < 10; i++){
        arr[i] = 0;
    }

    int gap_index_s1[8];
    int gap_index_s2[8];

    for (int i = 0; i < 8; i++){
        gap_index_s1[i] = 0;
        gap_index_s2[i] = 0;
    }

    int i = m, j = n, k=0;
    while (i != 0 && j != 0){
        arr[k] = matrix[i][j];
        if (s1[i-1] == s2[j-1]){
            i -= 1;
            j -= 1;
        }
        else{
            if ((matrix[i-1][j-1] + o) == matrix[i][j]){
                i -= 1;
                j -= 1;
            }   
            else if ((matrix[i-1][j] + o) == matrix[i][j]){
                i -= 1;
                gap_index_s1[k] = 1;
            }
            else{
                j -= 1;
                gap_index_s2[k] = 1;
            }
        }
        k += 1;
    }
    cout << "Trace Back : ";
    for (int iter = 0; iter < k; iter++){
        cout << arr[iter] << " ";
    }

    cout << "\n";
    i = 0;

    while(i < m){
       if (gap_index_s1[i] == 1){
            cout << "- ";
            gap_index_s1[i] = 0;
       }else{
            cout << s1[i] << " ";
            i++;
       }
    }
    cout << "\n";
    i = 0;
    while(i < n){
       if (gap_index_s2[i] == 1){
            cout << "- ";
            gap_index_s2[i] = 0;
       }else{
            cout << s2[i] << " ";
            i++;
       }
    }

}
