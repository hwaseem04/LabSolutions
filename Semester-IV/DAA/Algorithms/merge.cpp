# include <iostream>
# include <vector>

using namespace std;

void files()
{
    // Give inputs in input.txt
    // Result displayed in output.txt
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

void display(vector<int>& v){
    for (auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
    cout << "\n";
}

void merge(vector<int>& v, int beg, int mid, int end){
    int i = beg;
    int j = mid + 1;
    
    vector<int> v2;

    while (i <= mid && j <= end){
        if (v[i] <= v[j]){
            v2.push_back(v[i]);
            i++;
        }else{
            v2.push_back(v[j]);
            j++; 
        }
    }
    while (i <= mid){
        v2.push_back(v[i]);
        i++;
    }
    while (j <= end){
        v2.push_back(v[j]);
        j++;
    }
    // cout << "C3\n";

    for (int i = beg, j = 0; j <= v2.size() - 1; i++, j++){
        v[i] = v2[j];
    }
    // display(v);
    return;
}

void merge_sort(vector<int>& v, int beg, int end){
    // cout << beg << " " << end << "\n";
    while(beg < end){
        int mid = (end + beg)/2;
        merge_sort(v, beg, mid);
        merge_sort(v, mid+1, end);
        merge(v, beg, mid, end);
        return;
    }
    // return;
}

int main(void){
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
    files();

    vector<int> v1;
    
    int n;
    cin >> n;
    int input;
    for (int i = 0; i < n; i++){
        cin >> input;
        v1.push_back(input);
    }

    cout << "UnSorted: ";
    display(v1);
    merge_sort(v1, 0, n-1);
    cout << "Sorted: ";
    display(v1);
}
