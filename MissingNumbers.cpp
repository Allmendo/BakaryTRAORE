#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the missingNumbers function below.
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {

  // By Bakary TRAORE
    //traoreb956@gmail.com
    //Copyright
  
  int n,n1=0;

  //size of  / sizeof(arr[0])
  n = arr.size();

  //size of brr
  n1 = brr.size();// / sizeof(brr[0]);

// sorted arr
   sort(arr.begin(), arr.end()); 
   // sorted brr
  sort(brr.begin(), brr.end()); 
  
    int sk = 0;
    int sn=n1-n;
      int sc=0;
    vector<int> rer(sn);

//finding the missed elements
  for (int i = 0; i < n1; i++) 
  {
  
    if (brr[i]!= arr[sk])
    {
        int p=brr[i];
         rer[sc]=p;
         sc++;
    }
    else sk++;

  }

// counting element without counting the repeated elements
    int tt=0;

  for (int i = 1; i < sn; i++) 
  {
       if (rer[i-1]!= rer[i])
       {
         
         tt++;
         
      }
  } //By Bakary TRAORE
      //traoreb956@gmail.com
      //Copyright

    //removing repeated elements
    vector<int> res(tt+1);
    res[0]=rer[0];
    int tc=1;
    for (int i = 1; i <=sn; i++) 
    {
        if (rer[i-1]!= rer[i])
        {
         int p=rer[i];
         res[tc]=p;
         tc++;
         
       }
    }
    
      return res;

      //By Bakary TRAORE
          //traoreb956@gmail.com
          //Copyright
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split_string(brr_temp_temp);

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    vector<int> result = missingNumbers(arr, brr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
